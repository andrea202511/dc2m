#include "mDriver.h"
#include "dc2mApp.h"
#include <wx/tokenzr.h>

//std::unorder_map

DECLARE_APP(dc2mApp)

extern cDriver* Deltac;


mDriver::mDriver(int32_t ch)
{
  channel=ch;
  error=0;
  comm = new modbus();
}

mDriver::~mDriver()
{

}

void mDriver::Init()
{
  if (comm!=NULL)
    wxGetApp().ToLog(0,wxString::Format("Channel #%i handling: Ok\n",channel));
  else
    wxGetApp().ToLog(2,wxString::Format("Channel #%i handling: FAIL\n",channel));
}




void mDriver::Connect()
{
    settings.Chn2Chw(channel);
    cs=settings.chw;

    //check setting
    if(cs.ipp1<1 || cs.ipp2<0  || cs.ipp3<0 || cs.ipp4<1)
      error=CHERR_INVALID_IPADDRESS;

    if (cs.ipp1>254 || cs.ipp2>254  || cs.ipp3>254 || cs.ipp4>254)
      error=CHERR_INVALID_IPADDRESS;

    if (cs.port<1)
      error=CHERR_INVALID_PORTNUMBER;

    if (cs.lengthrx<5)
     error=CHERR_RXLENGHT_TOOSMALL;

    if (cs.lengthrx>255)
     error=CHERR_RXLENGHT_TOOLARGE;

    if (cs.lengthtx<5)
     error=CHERR_TXLENGHT_TOOSMALL;

    if (cs.lengthtx>255)
     error=CHERR_TXLENGHT_TOOLARGE;

    if(error==0) {
      if (connected)
        comm->modbus_close();

      wxString ip;
      ip=wxString::Format(wxT("%d.%d.%d.%d"), cs.ipp1, cs.ipp2, cs.ipp3, cs.ipp4);
      comm->set_data((std::string)ip,(uint16_t)cs.port,500);

      if (comm->modbus_connect())
        connected=true;
      else {
        connected=false;
        error=CHERR_CONNECT_ERROR;
      }
    }

    buffer_tx[1]=0;
    buffer_rx[1]=0;

    tick=0;
    last_cod_tx=0;
    last_cod_rx=0;
    init=true;
}


void mDriver::Disconnect()
{
  if (comm!=NULL) {
    comm->modbus_close();
    connected=false;
  }
}


void mDriver::WriteRegisters(uint16_t reg,uint16_t num, uint16_t *val)
{
  if (comm->is_connected())
  {
    err=comm->modbus_write_registers(reg,num,val);
    if (err!=0)
      error=CHERR_WRITE_ERROR;
  }
}


void mDriver::ReadRegisters(uint16_t reg,uint16_t num, uint16_t* val)
{
  if (comm->is_connected())
  {
    err=comm->modbus_read_holding_registers(reg,num,val);
    if (err!=0)
      error=CHERR_READ_ERROR;
  }
}

bool mDriver::to_dc()
{
  uint16_t data,data_code,data_recipient;
  wxString msg;
  char ch1,ch2;
  char str_c[] = { ' ', '\0' };

  //if dc busy return and retry
  if (wxGetApp().Deltac->tx_free()==false)
    return false;


  //manage receip
  if(cs.byteord==0)
    data_recipient=buffer_tx[0];
  else
    data_recipient=wxUINT16_SWAP_ALWAYS(buffer_tx[0]);

  //manage code
  if(cs.byteord==0)
    data_code=buffer_tx[1];
  else
    data_code=wxUINT16_SWAP_ALWAYS(buffer_tx[1]);

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
  wxGetApp().Deltac->tx_preset(data_code,data_recipient,msg);

  return true;

}


bool mDriver::from_dc(wxString msg,int chat_id)
{
  uint16_t ch1,ch2;

  //if rx busy return and retry
  if (buffer_rx[1]!=0)
    return false;

  for (int i=0; i<cs.lengthrx; i++) {
    buffer_rx[i]=0;
  }

  //manage code  // #1:x
  if (msg[2]==':') {
    wxStringTokenizer tok;
    tok.SetString(msg,":");
    int ii=0;
    while ( tok.HasMoreTokens() )
    {
      wxString token = tok.GetNextToken();
      token.ToInt(&msg_par[ii]);
      ii++;
      if (ii>9)
        break;
    }
    if(cs.byteord==0){
      buffer_rx[0]=(uint16_t) chat_id;
      buffer_rx[1]=msg_par[1];
    }
    else {
      buffer_rx[0]=wxUINT16_SWAP_ALWAYS(chat_id);
      buffer_rx[1]=wxUINT16_SWAP_ALWAYS(msg_par[1]);
    }
    for (int i=2; i<ii; i++) {
      if(cs.byteord==0)
        buffer_rx[i]=msg_par[i];
      else
        buffer_rx[i]=wxUINT16_SWAP_ALWAYS(msg_par[i]);
    }
  }
  else {
    //it is text message
   if(cs.byteord==0){
      buffer_rx[0]=(uint16_t) chat_id;
      buffer_rx[1]=0x0001;
    }
    else {
      buffer_rx[0]=wxUINT16_SWAP_ALWAYS(chat_id);
      buffer_rx[1]=wxUINT16_SWAP_ALWAYS(0x0001);
    }

    int a=2;
    for (int i=2; i<(cs.lengthrx-2); i+=2) {
      ch1=msg[i];
      ch2=msg[i+1];


      if (cs.charord==0) {
        buffer_rx[a]=ch1;
        a++;
        buffer_rx[a]=ch2;
        a++;
      }
      else if (cs.charord==1) {
        buffer_rx[a]=ch1*256+ch2;
        a++;
      }
      else if (cs.charord==2) {
        buffer_rx[a]=ch2*256+ch1;
        a++;
      }

    }

  }
  WriteRegisters(cs.startrx,20,buffer_rx); //cs.lengthrx ?
  buffer_rx[1]=0;

  return true;

}

int mDriver::GetStatus() {
  if (error!=0) return error;
  else if (!en || !run) return 0;
  else if (connected) return 2;
  else return 1;
}

int32_t mDriver::Refresh()
{
  uint16_t zero=0;

  if (channel==1) {
    en=settings.ch1.enable;
    run=settings.ch1.run;
  }
  else if (channel==2) {
    en=settings.ch2.enable;
    run=settings.ch2.run;
  }
  else if (channel==3) {
    en=settings.ch3.enable;
    run=settings.ch3.run;
  }

  //reset error
  if (!en || !run)
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

  if ((error==0) && en && run && !connected)
    Connect();

  if ((!(error==0) || !en || !run) && connected)
    Disconnect();

  //get message from modbus
  if (connected) {
    if (((cs.trefresh==0) && (tick>2)) || ((cs.trefresh==0) && (tick>4)) || (tick>6)) {
      tick=0;
      ReadRegisters(cs.starttx,2,&buffer_tx[0]);
      //if there is something...
      if (buffer_tx[1]!=0) {
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
      buffer_tx[1]=0;
    }
  }
  else {
    buffer_tx[1]=0;
  }

  if (error!=0) return error;
  else if (!en || !run) return 0;
  else if (connected) return 2;
  else return 1;
}



