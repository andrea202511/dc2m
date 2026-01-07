#include "mDriver.h"
#include "dc2mApp.h"
#include <wx/tokenzr.h>

//std::unorder_map
/*
#include <wx/string.h>       // Header per wxString
#include <unordered_map>      // Header per std::unordered_map
#include <iostream>

int main() {
    // Definizione della mappa: chiave int, valore wxString
    std::unordered_map<int, wxString> mappaVoti;

    // 1. Inserimento di elementi
    mappaVoti[1] = "Ottimo";
    mappaVoti.insert({2, wxString("Buono")});
    mappaVoti.emplace(3, "Sufficiente");

    // 2. Accesso tramite chiave
    int id = 1;
    if (mappaVoti.find(id) != mappaVoti.end()) {
        // Nota: per stampare su console standard bisogna convertire wxString
        std::cout << "Il valore per " << id << " e': "
                  << mappaVoti[id].ToStdString() << std::endl;
    }

    // 3. Iterazione sulla mappa (C++17)
    std::cout << "\nContenuto della mappa:" << std::endl;
    for (const auto& [codice, descrizione] : mappaVoti) {
        std::cout << "Codice: " << codice
                  << " - Descrizione: " << descrizione.ToStdString() << std::endl;
    }

    return 0;
}



più efficiente per file di dimensioni moderate.
cpp

#include <wx/textfile.h>
#include <wx/tokenzr.h> // Per separare chiave e valore
#include <unordered_map>
#include <iostream>

int main() {
    std::unordered_map<int, wxString> mappaVoti;
    wxTextFile file(wxT("dati.txt"));

    if (file.Open()) {
        // Itera su ogni riga del file
        for (wxString riga = file.GetFirstLine(); !file.Eof(); riga = file.GetNextLine()) {
            if (riga.IsEmpty()) continue;

            // Utilizziamo wxStringTokenizer per separare l'ID dal testo
            // Il primo spazio funge da delimitatore
            wxStringTokenizer tokenizer(riga, wxT(" "));

            if (tokenizer.HasMoreTokens()) {
                wxString idStr = tokenizer.GetNextToken();
                long id;

                // Converte la prima parte in intero e preleva il resto come valore
                if (idStr.ToLong(&id)) {
                    // Restituisce tutto il testo rimanente nella riga
                    wxString valore = tokenizer.GetString();
                    mappaVoti[(int)id] = valore.Trim(false); // Rimuove spazi iniziali
                }
            }
        }
        file.Close();
    } else {
        std::cerr << "Errore: impossibile aprire il file con wxTextFile." << std::endl;
    }

    // Verifica output
    for (const auto& [id, testo] : mappaVoti) {
        std::cout << "ID: " << id << " -> " << testo.ToStdString() << std::endl;
    }

    return 0;
}


*/


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
  settings.Chn2Chw(channel);
  cs=settings.chw;
  CheckPar();

  if (comm!=NULL) {
    if (error==0) {
      wxGetApp().ToLog(0,wxString::Format("Channel #%i handling: Ok\n",channel));
      LoadMessages();
    }
    else
      wxGetApp().ToLog(2,wxString::Format("Channel #%i handling: FAIL (wrong parameters)\n",channel));
  }
  else
    wxGetApp().ToLog(2,wxString::Format("Channel #%i handling: FAIL\n",channel));
}

void mDriver::LoadMessages()
{
  if (cs.filemsg=="") {
    wxGetApp().ToLog(0,wxString::Format("Channel #%i loading messages file: skipped\n",channel));
    return;
  }
  //apro il file
  wxTextFile filemsg(cs.filemsg);

  if (filemsg.Open()) {
    int32_t cnt=0;
    for (wxString riga = filemsg.GetFirstLine(); !filemsg.Eof(); riga = filemsg.GetNextLine()) {
      if (riga.IsEmpty()) continue;
        wxStringTokenizer tokenizer(riga, wxT(";"));
        if (tokenizer.HasMoreTokens()) {
          //estraggo il numero
          wxString str_nr=tokenizer.GetNextToken();
          int nr;
          if (str_nr.ToInt(&nr)) {
            //estraggo il resto
            wxString msg = tokenizer.GetString();
            messages_map[(int16_t)nr] = msg.Trim(false);
            cnt++;
          }
        }
      }
      filemsg.Close();
      wxGetApp().ToLog(0,wxString::Format("Channel #%i loading messages file: %i messages found \n",channel,cnt));
    }
    else {
        wxGetApp().ToLog(2,wxString::Format("Channel #%i loading messages file: FAIL (file not found) \n",channel));
    }
}

void mDriver::CheckPar()
{
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

}

void mDriver::Connect()
{
    settings.Chn2Chw(channel);
    cs=settings.chw;


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



