#ifndef CDRIVER_H
#define CDRIVER_H

#include "deltachat.h"
#include "cSettings.h"

#include <wx/wx.h>
#include <wx/thread.h>
#include <wx/dynlib.h>


typedef dc_event_emitter_t* (*dc_get_event_emitter_type)(dc_context_t*);
typedef dc_event_t* (*dc_get_next_event_type)(dc_event_emitter_t*);
typedef int (*dc_event_get_id_type)(dc_event_t*);
typedef int (*dc_event_get_data1_int_type)(dc_event_t*);
typedef int (*dc_event_get_data2_int_type)(dc_event_t*);
typedef char* (*dc_event_get_data1_str_type)(dc_event_t*);
typedef char* (*dc_event_get_data2_str_type)(dc_event_t*);
typedef void (*dc_start_io_type)(dc_context_t*);
typedef void (*dc_stop_io_type)(dc_context_t*);
typedef int (*dc_get_connectivity_type)(dc_context_t*);
typedef dc_chat_t* (*dc_get_chat_type)(dc_context_t*, uint32_t);
typedef int (*dc_chat_get_type_type)(const dc_chat_t*);
typedef dc_msg_t* (*dc_get_msg_type)(dc_context_t*, uint32_t);
typedef char* (*dc_msg_get_text_type)(const dc_msg_t*);
typedef void (*dc_markseen_msgs_type)(dc_context_t*, const uint32_t*, int);
typedef void (*dc_str_unref_type)(char*);
typedef void (*dc_msg_unref_type)(dc_msg_t*);
typedef void (*dc_event_unref_type)(dc_event_t*);
typedef dc_context_t* (*dc_context_new_type)(const char*, const char*, const char*);
typedef int (*dc_is_configured_type)(const dc_context_t*);
typedef int (*dc_set_config_from_qr_type)(dc_context_t*, const char*);
typedef char* (*dc_get_info_type)(const dc_context_t*);
typedef int (*dc_set_config_type)(dc_context_t*, const char*, const char*);
typedef void (*dc_configure_type)(const dc_context_t*);
typedef void (*dc_stop_ongoing_process_type)(dc_context_t*);
typedef char* (*dc_get_securejoin_qr_type)(dc_context_t*, uint32_t);
typedef char* (*dc_create_qr_svg_type)(const char*);
typedef uint32_t (*dc_send_text_msg_type)(dc_context_t*, uint32_t, const char*);



extern C_Settings settings;

DECLARE_EVENT_TYPE(E_ChatEvent,-1)

/* -----------
  Event class
  ------------*/
class C_ChatEvent : public wxCommandEvent
{
public:
  C_ChatEvent(wxEventType commandType=E_ChatEvent,int id=0):wxCommandEvent(commandType,id){ }
  wxEvent* Clone() const { return new C_ChatEvent(*this);}

  wxString GetText() const {return m_Text;}
  void SetText(const wxString& text) { m_Text=text; }
private:
   wxString m_Text;
};

typedef void(wxEvtHandler::*MyChatEventFunction)(C_ChatEvent &);
#define MyChatEventHandler(func)(wxObjectEventFunction)(wxEventFunction)(wxCommandEventFunction)wxStaticCastEvent(MyChatEventFunction,&func)

#define THERROR 1
#define THFAILURE 2
#define THDEBUG 3
#define THVERBOSE 4
#define THRECEIVEMESSAGEBASE 30000




/* -----------------------------
  Thread to capture chat events
  -----------------------------*/
class C_ChatEventThread : public wxThread
{
public:
    C_ChatEventThread(wxEvtHandler*,dc_context_t*);
    ~C_ChatEventThread();
    void SendThreadMessage(wxString,int);
    virtual void *Entry();
private:
    wxEvtHandler* EH;
    dc_context_t* th_context;


dc_get_event_emitter_type pfn_dc_get_event_emitter;
dc_get_next_event_type pfn_dc_get_next_event;
dc_event_get_id_type pfn_dc_event_get_id;
dc_event_get_data1_int_type pfn_dc_event_get_data1_int;
dc_event_get_data2_int_type pfn_dc_event_get_data2_int;
dc_event_get_data1_str_type pfn_dc_event_get_data1_str;
dc_event_get_data2_str_type pfn_dc_event_get_data2_str;
dc_start_io_type pfn_dc_start_io;
dc_stop_io_type pfn_dc_stop_io;
dc_get_connectivity_type pfn_dc_get_connectivity;
dc_get_chat_type pfn_dc_get_chat;
dc_chat_get_type_type pfn_dc_chat_get_type;
dc_get_msg_type pfn_dc_get_msg;
dc_msg_get_text_type pfn_dc_msg_get_text;
dc_markseen_msgs_type pfn_dc_markseen_msgs;
dc_str_unref_type pfn_dc_str_unref;
dc_msg_unref_type pfn_dc_msg_unref;
dc_event_unref_type pfn_dc_event_unref;
};


/* --------------------------------
  Interface class with chat library
  ---------------------------------*/
class cDriver
{
  public:
    cDriver(wxEvtHandler*);
    virtual ~cDriver();

    void init(void);
    wxString database_name;
    dc_context_t* ccontext;
    C_ChatEventThread* chat_event_thread;
    void stop_context(dc_context_t* context);

    wxString generate_qrcode();
    int32_t ProcessMessage(wxString msg,int chat_id);  //analize message received and extract data

    int32_t Refresh();
    bool tx_free() {return (tx_code==0); };
    void tx_preset(uint16_t rec,uint16_t cod,wxString msg) {tx_receipe=rec; tx_code=cod; tx_message=msg; };


  protected:

  private:

    wxEvtHandler* EHc;

    wxString tx_message;
    uint16_t tx_receipe;
    uint16_t tx_code;
    int32_t msg_par[10];
    wxDynamicLibrary deltachatlib;

//dc_get_event_emitter_type pfn_dc_get_event_emitter;
//dc_get_next_event_type pfn_dc_get_next_event;
//dc_event_get_id_type pfn_dc_event_get_id;
//dc_event_get_data1_int_type pfn_dc_event_get_data1_int;
//dc_event_get_data2_int_type pfn_dc_event_get_data2_int;
//dc_event_get_data1_str_type pfn_dc_event_get_data1_str;
//dc_event_get_data2_str_type pfn_dc_event_get_data2_str;
dc_start_io_type pfn_dc_start_io;
dc_stop_io_type pfn_dc_stop_io;
//dc_get_connectivity_type pfn_dc_get_connectivity;
//dc_get_chat_type pfn_dc_get_chat;
//dc_chat_get_type_type pfn_dc_chat_get_type;
//dc_get_msg_type pfn_dc_get_msg;
//dc_msg_get_text_type pfn_dc_msg_get_text;
//dc_markseen_msgs_type pfn_dc_markseen_msgs;
//dc_str_unref_type pfn_dc_str_unref;
//dc_msg_unref_type pfn_dc_msg_unref;
//dc_event_unref_type pfn_dc_event_unref;
dc_context_new_type pfn_dc_context_new;
dc_is_configured_type pfn_dc_is_configured;
dc_set_config_from_qr_type pfn_dc_set_config_from_qr;
dc_get_info_type pfn_dc_get_info;
dc_set_config_type pfn_dc_set_config;
dc_configure_type pfn_dc_configure;
dc_stop_ongoing_process_type pfn_dc_stop_ongoing_process;
dc_get_securejoin_qr_type pfn_dc_get_securejoin_qr;
dc_create_qr_svg_type pfn_dc_create_qr_svg;
dc_send_text_msg_type pfn_dc_send_text_msg;


};


#endif // CDRIVER_H



