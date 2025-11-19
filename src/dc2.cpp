#include "dc2.h"
#include <wx/tokenzr.h>
#include "dc2mApp.h"
DECLARE_APP(dc2mApp)

C_ChatEventThread::C_ChatEventThread(wxEvtHandler *evhan ,dc_context_t* ctxt)
{
  EH=evhan;
  th_context=ctxt;
}

C_ChatEventThread::~C_ChatEventThread()
{

}

DEFINE_EVENT_TYPE(E_ChatEvent)

void C_ChatEventThread::SendThreadMessage(wxString str,int type)
{
  if(EH)
  {
    C_ChatEvent event(E_ChatEvent,type);
    event.SetText(str);
    event.SetInt(type);
    wxPostEvent(EH,event);
  }
}

void *C_ChatEventThread::Entry()
{
  SendThreadMessage(_("Entrata"),THDEBUG);
    dc_event_emitter_t* emitter;
    emitter=dc_get_event_emitter(th_context);
    dc_event_t* event;
    int datai;
    wxString datas;
    wxString msg;
    int event_id;

    while ((event = dc_get_next_event(emitter)) != NULL) {

      event_id=dc_event_get_id(event);
      if(event_id==DC_EVENT_ERROR) {
        datas=dc_event_get_data2_str(event);
        msg="[ERROR]:"+datas;
        SendThreadMessage(msg,THERROR);
      }
      else if (event_id==DC_EVENT_WARNING) {
        datas=dc_event_get_data2_str(event);
        msg="[WARNING]:"+datas;
        SendThreadMessage(msg,THERROR);
      }
      else if (event_id==DC_EVENT_INFO) {
        datas=dc_event_get_data2_str(event);
        msg="[INFO]:"+datas;
        SendThreadMessage(msg,THVERBOSE);
      }
      else if (event_id==DC_EVENT_CONFIGURE_PROGRESS) {
        datai=dc_event_get_data1_int(event);
        datas=dc_event_get_data2_str(event);
        if (datai==0) {
          msg="[CONFIGURE]:configuration failed, look for error message and restart to try again";
          SendThreadMessage(msg,THERROR);
        }
        else if(datai==1000) {
          msg="[CONFIGURE]:configuration sucesfull, starting io";
          SendThreadMessage(msg,THVERBOSE);
          dc_start_io(th_context);
        }
        else {
          msg="[CONFIGURE]:configuration in progress";
          SendThreadMessage(msg,THVERBOSE);
        }
      }
      else if (event_id==DC_EVENT_CONNECTIVITY_CHANGED) {
        datai=dc_get_connectivity(th_context);
        if (datai>=4000) {
          msg="[id 2100]:connected";
          SendThreadMessage(msg,THVERBOSE);
        }
        else if (datai>=3000) {
          msg="[id 2100]:getting new message";
          SendThreadMessage(msg,THVERBOSE);
        }
        else if (datai>=3000) {
          msg="[id 2100]:connecting";
          SendThreadMessage(msg,THVERBOSE);
        }
        else if (datai>=3000) {
          msg="[id 2100]:not connected";
          SendThreadMessage(msg,THVERBOSE);
        }
        else {
          msg="[id 2100]:??";
          SendThreadMessage(msg,THVERBOSE);
        }
      }
      else if (event_id==DC_EVENT_INCOMING_MSG) {
        uint32_t chat_id=dc_event_get_data1_int(event);

      //  wxGetApp().deltac->solo_per_test=chat_id;
        uint32_t message_id=dc_event_get_data2_int(event);
        msg.Printf("[incoming message] %d %d",chat_id,message_id);
        SendThreadMessage(msg,THVERBOSE);
        //handle_message(th_context,chat_id,message_id);
        dc_chat_t *chat=dc_get_chat(th_context,chat_id);
        if(dc_chat_get_type(chat)==DC_CHAT_TYPE_SINGLE) {
          dc_msg_t* msgcc=dc_get_msg(th_context,message_id);
          if (msgcc!=0) {
            char* text=dc_msg_get_text(msgcc);
            msg=text;
            SendThreadMessage(msg,THRECEIVEMESSAGEBASE+chat_id);
            dc_markseen_msgs(th_context,&message_id,1);
            //dc_marks
        //    dc_send_text_msg(th_context,chat_id,text);
            dc_str_unref(text);
            dc_msg_unref(msgcc);
          }
        }
      }
      else {
        msg.Printf("[unandled event] %d" ,event_id);
        SendThreadMessage(msg,THVERBOSE);
      }

        // use the event as needed, e.g. dc_event_get_id() returns the type.
        // once you're done, unref the event to avoid memory leakage:
        dc_event_unref(event);
    }
 //   dc_event_emitter_unref(emitter);
    return NULL;

}

C_Chat::C_Chat(wxEvtHandler *evhan)
{
  EHc=evhan;
}

C_Chat::~C_Chat()
{
  //dtor
}


void C_Chat::init(void)
{
//  settings.ToLog(1,"Init\n");

  wxThreadError eth;
  dc_context_t* context = dc_context_new(NULL, "dc2m.db", NULL);
  chat_event_thread=new C_ChatEventThread(EHc,context);
  eth=chat_event_thread->Create();
  if (eth == wxTHREAD_NO_ERROR)
  {
 //settings.ToLog(1,"Thread run\n");
    chat_event_thread->Run();

    if(!dc_is_configured(context))
    {
stop_context(context);
//      dc_set_config(context, "addr", "epwxog2fw@nine.testrun.org");
//      dc_set_config(context, "mail_user", "epwxog2fw@nine.testrun.org");
//      dc_set_config(context, "mailtx_receipe_pw", "2G<wyZ\\I<N\"b");

  //    dc_set_config(context, "addr", "zzzxog2fw@nine.testrun.org");
  //    dc_set_config(context, "mail_user", "zzzxog2fw@nine.testrun.org");
  //    dc_set_config(context, "mail_pw", "2G9ufZ\\I<N\"b");

      dc_set_config_from_qr(context, "dcaccount:https://nine.testrun.org/new");

 //  dc_set_config(context, "displayname", "abcdefghi");
//  dc_set_config(context, "is_chatmail", "1");
      dc_set_config(context, "bot","1");
 //??     dc_set_config(context,"fetch_existing_msgs","0");
dc_set_config(context, "fetch_existing_msgs", "0");
    dc_set_config(context, "verified_one_on_one_chats", "1");

      dc_configure(context);
    }
    else
    {
      dc_start_io(context);

    }
///dc_start_io(context);
ccontext=context;
  }

 // Thread2->Entry(context);

}

void C_Chat::stop_context(dc_context_t* context)
{
  dc_stop_io(context);
  dc_stop_ongoing_process(context);
}

/*
void event_handler(dc_context_t* dc2::context)
{
    dc_event_emitter_t* emitter = dc_get_event_emitter(dc2::context);
    dc_event_t* event;
    while ((event = dc_get_next_event(emitter)) != NULL) {
        // use the event as needed, e.g. dc_event_get_id() returns the type.
        // once you're done, unref the event to avoid memory leakage:
        dc_event_unref(event);
    }
    dc_event_emitter_unref(emitter);
}
*/

wxString C_Chat::generate_qrcode(void)
{
char* aaa=dc_get_securejoin_qr(ccontext,0);
char* bbb=dc_create_qr_svg(aaa);
wxString qc=bbb;
return qc;


}

//check if anything to send
int32_t C_Chat::Refresh()
{
  if (tx_code==0)
     return 0;
  if (tx_code==1) {
    dc_send_text_msg(ccontext,tx_receipe,tx_message);
  }
  tx_code=0;
  return 1;
}


int32_t C_Chat::ProcessMessage(wxString msg, int chat_id)
{
  int32_t err=0;
  wxString response="";

  for(int i=0;i<10;i++)
    msg_par[i]=0;

  //code recognition for station
  if (msg[0]=='$') {
    if (msg[1]!='1')
      response="Wrong station number";
    else {
      //extract numerico token

      wxStringTokenizer tok;
      tok.SetString(msg,":");
      int ii=0;
      while ( tok.HasMoreTokens() )
      {
         wxString token = tok.GetNextToken();
         token.ToInt(&msg_par[ii]);
         ii++;
         if (ii>9) {
            response="Too much parameters in station request";
           break;
         }
      }
      switch(msg_par[1]) {
        case 0:
          response="1:Station name\n2:List Channel\n3:Date & time\n4:Status channel\n5:Channels detail";
          break;
        case 1:
          response="Station name: "+settings.station_name;
          break;
        case 2:
          response="2\n3\n4\n5";
          break;
        case 3:
          response="20\n30\n40\n50\n60\n70\n80\n90\n100";
          break;

        default:
          response=wxString::Format(wxT("Code not managed (%i)"), msg_par[1]);

      }
    }
    //send response to $ code if there is one
    if(response!="")
      dc_send_text_msg(ccontext,chat_id,response.mb_str());
    return 0;
  }



  int st;

  if (msg[0]=='#') {
    if (msg[1]=='1') {
      st=wxGetApp().ModbusCh1->GetStatus();
      if (st==0)
        response="Channel #1 is disabled";
      else if (st==1)
        response="Channel #1 is offline";
      else {
        if (wxGetApp().ModbusCh1->from_dc(msg,chat_id)==true)
          msg[1]=0;
      }
    }
    else if (msg[1]=='2') {
      st=wxGetApp().ModbusCh2->GetStatus();
      if (st==0)
        response="Channel #2 is disabled";
      else if (st==1)
        response="Channel #2 is offline";
      else {
        if (wxGetApp().ModbusCh2->from_dc(msg,chat_id)==true)
          msg[1]=0;
      }
    }
    else if (msg[1]=='3') {
      st=wxGetApp().ModbusCh2->GetStatus();
      if (st==0)
        response="Channel #3 is disabled";
      else if (st==1)
        response="Channel #3 is offline";
      else {
        if (wxGetApp().ModbusCh3->from_dc(msg,chat_id)==true)
          msg[1]=0;
      }
    }
    else
      response=wxString::Format(wxT("Wrong channel number (%c)"), msg[1]);

    //send response to # code if there is one
    if(response!="") {
      dc_send_text_msg(ccontext,chat_id,response.mb_str());
      return 0;
    }

    //if I'm here something can sent to channel

  }

return err;
}
