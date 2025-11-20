#ifndef CDRIVER_H
#define CDRIVER_H

#include "deltachat.h"
#include "cSettings.h"

#include <wx/wx.h>
#include <wx/thread.h>


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

    dc_context_t* ccontext;
    C_ChatEventThread* chat_event_thread;
    void stop_context(dc_context_t* context);

    wxString generate_qrcode();
    int32_t ProcessMessage(wxString msg,int chat_id);  //analize message received and extract data

    int32_t Refresh();
    bool tx_free() {return (tx_code==0); };
    void tx_preset(uint16_t cod,uint16_t rec,wxString msg) {tx_code=cod; tx_receipe=rec; tx_message=msg; };


  protected:

  private:

    wxEvtHandler* EHc;

    wxString tx_message;
    uint16_t tx_receipe;
    uint16_t tx_code;
    int32_t msg_par[10];
};


#endif // CDRIVER_H



