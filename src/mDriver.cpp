#include "mDriver.h"
#include "dc2mApp.h"
DECLARE_APP(dc2mApp)

extern C_Chat* deltac;


mDriver::mDriver(int32_t ch)
{
  channel=ch;
  error=0;
  init=false;

}

mDriver::~mDriver()
{

}


void mDriver::Connect()
{
    settings.Chn2Chx(channel);
    cs=settings.chx;

    //check setting
    if(cs.ipp1<1 || cs.ipp2<0  || cs.ipp3<0 || cs.ipp4<1)
      error=-11;

    if (cs.ipp1>254 || cs.ipp2>254  || cs.ipp3>254 || cs.ipp4>254)
      error=-11;

    if (cs.port<1)
      error=-12;

    if (cs.lengthtx<5 || cs.lengthrx<5)
     error=-13;

    if(error==0) {
      wxString ip;
      ip=wxString::Format(wxT("%d.%d.%d.%d"), cs.ipp1, cs.ipp2, cs.ipp3, cs.ipp4);


      comm = new modbus((std::string)ip,(uint16_t)cs.port,500);
      bool b=comm->modbus_connect();
      if (b==true)
        connected=true;
      else {
        connected=false;
        error=-1;
      }
    }
    buffer_tx=new uint16_t[cs.lengthtx+1];
    buffer_rx=new uint16_t[cs.lengthrx+1];

buffer_tx[0]=0;

    tick=0;
    last_cod_tx=0;
    last_cod_rx=0;
    init=true;
}


void mDriver::Disconnect()
{
  comm->modbus_close();
  delete comm;
  delete buffer_tx;
  delete buffer_rx;
  comm=NULL;
  connected=false;
  init=false;
}


void mDriver::WriteRegisters(uint16_t reg,uint16_t num, uint16_t *val)
{
  if (comm->is_connected())
  {
    err=comm->modbus_write_registers(reg,num,val);
    if (err!=0)
      error=-20;
  }
}


void mDriver::ReadRegisters(uint16_t reg,uint16_t num, uint16_t* val)
{
  if (comm->is_connected())
  {
    err=comm->modbus_read_holding_registers(reg,num,val);
    if (err!=0)
      error=-21;

  }
}

bool mDriver::to_dc()
{
  uint16_t data,data_code,data_recipient;
  wxString msg;
  char ch1,ch2;
  char str_c[] = { ' ', '\0' };

  //if dc busy return and retry
  if (wxGetApp().deltac->tx_free()==false)
    return false;


  //manage code
  if(cs.byteord==0)
    data_code=buffer_tx[0];
  else
    data_code=wxUINT16_SWAP_ALWAYS(buffer_tx[0]);


  //manage receip
  if(cs.byteord==0)
    data_recipient=buffer_tx[1];
  else
    data_recipient=wxUINT16_SWAP_ALWAYS(buffer_tx[1]);


  //manage data
  for(int i=2; cs.lengthtx; i++) {
    data=buffer_tx[i];

    if (data==0)
      break;

    if (cs.charord==0) {
      ch1=(char)(data & 0x00FF);
      str_c[0]=ch1;
      msg<<wxString::FromUTF8(str_c);
    }
    else {
      ch1=(char)(data & 0x00FF);
      ch2=(char)((data >>8) & 0x00FF);
      if (ch1>0 && ch1<32)
        ch1=32;
      if (ch2>0 && ch2<32)
        ch2=32;
      if (cs.charord==1) {
        str_c[0]=ch2;
        msg<<wxString::FromUTF8(str_c);
        str_c[0]=ch1;
        msg<<wxString::FromUTF8(str_c);;
      }
      else {
        str_c[0]=ch1;
        msg<<wxString::FromUTF8(str_c);
        str_c[0]=ch2;
        msg<<wxString::FromUTF8(str_c);;
      }
    }
  }
  wxGetApp().deltac->tx_preset(data_code,data_recipient,msg);

  return true;

}
int mDriver::GetStatus() {
  if (connected)
    return 2;
  return 0;
  //da completare con off e offline

}

int32_t mDriver::Refresh()
{
  uint16_t zero=0;
  bool en=false;
  if (channel==1)
    en=settings.ch1.enable;
  else if (channel==2)
    en=settings.ch2.enable;
  else if (channel==3)
    en=settings.ch3.enable;

  //reset error
  if (en==0)
    error=0;

  //auto restart
  if (error==0)
    restart=0;
  else {
    restart++;
    if (restart>10) {
      error=0;
      restart=0;
    }
  }

  if ((error==0) && en && !connected)
    Connect();

  if ((!(error==0) || !en) && connected)
    Disconnect();

  //get message from modbus
  if (connected) {
    if (((cs.trefresh==0) && (tick>2)) || ((cs.trefresh==0) && (tick>4)) || (tick>6)) {
      tick=0;
      ReadRegisters(cs.starttx,2,&buffer_tx[0]);
      //if there is samething...
      if (buffer_tx[0]!=0) {
        ReadRegisters(cs.starttx,cs.lengthtx,&buffer_tx[0]);
      }
    }
    else
      tick++;
  }

  //pull message to deltachat driver
  if (connected && init && buffer_tx[0]!=0 && error==0) {
    if (to_dc()==1) {
      WriteRegisters(cs.starttx,1,&zero); //reset message over modbus
      buffer_tx[0]=0;
    }
  }
  else {
    if (init)
      buffer_tx[0]=0;
  }


  if (error!=0) return error;
  else if (!init) return 0;
  else if (connected) return 2;
  else return 1;
}



