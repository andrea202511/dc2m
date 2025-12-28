/***************************************************************
 * Name:      dc2mMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    Andrea Fabbri ()
 * Created:   2025-09-27
 * Copyright: Andrea Fabbri ()
 * License:
 **************************************************************/

#include "dc2mMain.h"
#include <wx/msgdlg.h>
#include <wx/dc.h>
#include "dc2mApp.h"
DECLARE_APP(dc2mApp)
//(*InternalHeaders(dc2mFrame)
#include <wx/bitmap.h>
#include <wx/icon.h>
#include <wx/image.h>
#include <wx/intl.h>
#include <wx/string.h>
//*)

//#include "cSettings.h"
//extern C_Settings settings;
//extern C_Buffer buffer;

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI bui#include "dc2.h"ld");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(dc2mFrame)
const wxWindowID dc2mFrame::ID_TEXTCTRL1 = wxNewId();
const wxWindowID dc2mFrame::ID_MENUITEM2 = wxNewId();
const wxWindowID dc2mFrame::ID_MENUITEM1 = wxNewId();
const wxWindowID dc2mFrame::ID_MENUITEM3 = wxNewId();
const wxWindowID dc2mFrame::ID_MENUITEM4 = wxNewId();
const wxWindowID dc2mFrame::ID_MENUITEM5 = wxNewId();
const wxWindowID dc2mFrame::idMenuQuit = wxNewId();
const wxWindowID dc2mFrame::idMenuAbout = wxNewId();
const wxWindowID dc2mFrame::ID_STATUSBAR1 = wxNewId();
const wxWindowID dc2mFrame::ID_TIMER1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(dc2mFrame,wxFrame)
    //(*EventTable(dc2mFrame)
    //*)
END_EVENT_TABLE()

dc2mFrame::dc2mFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(dc2mFrame)
    wxBoxSizer* BoxSizer1;
    wxMenu* Menu1;
    wxMenu* Menu2;
    wxMenuBar* MenuBar1;
    wxMenuItem* MenuItem1;
    wxMenuItem* MenuItem2;

    Create(parent, id, _("dc2m"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
    SetClientSize(wxSize(790,357));
    {
      wxIcon FrameIcon;
      FrameIcon.CopyFromBitmap(wxBitmap(wxImage(_T("dc2mLogo.ico"))));
      SetIcon(FrameIcon);
    }
    BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
    LogText = new wxTextCtrl(this, ID_TEXTCTRL1, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE|wxVSCROLL|wxHSCROLL|wxALWAYS_SHOW_SB, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    BoxSizer1->Add(LogText, 1, wxALL|wxEXPAND, 5);
    SetSizer(BoxSizer1);
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem4 = new wxMenuItem(Menu1, ID_MENUITEM2, _("Station setting"), wxEmptyString, wxITEM_NORMAL);
    Menu1->Append(MenuItem4);
    MenuItem3 = new wxMenuItem(Menu1, ID_MENUITEM1, _("QRCode"), _("Show QRCode to join"), wxITEM_NORMAL);
    Menu1->Append(MenuItem3);
    Menu1->AppendSeparator();
    MenuItem5 = new wxMenuItem(Menu1, ID_MENUITEM3, _("Channel #1 setting"), wxEmptyString, wxITEM_NORMAL);
    Menu1->Append(MenuItem5);
    MenuItem6 = new wxMenuItem(Menu1, ID_MENUITEM4, _("Channel #2 setting"), wxEmptyString, wxITEM_NORMAL);
    Menu1->Append(MenuItem6);
    MenuItem7 = new wxMenuItem(Menu1, ID_MENUITEM5, _("Channel #3 setting"), wxEmptyString, wxITEM_NORMAL);
    Menu1->Append(MenuItem7);
    Menu1->AppendSeparator();
    MenuItem1 = new wxMenuItem(Menu1, idMenuQuit, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuBar1->Append(Menu1, _("dc2m"));
    Menu2 = new wxMenu();
    MenuItem2 = new wxMenuItem(Menu2, idMenuAbout, _("About\tF1"), _("Show info about this application"), wxITEM_NORMAL);
    Menu2->Append(MenuItem2);
    MenuBar1->Append(Menu2, _("Help"));
    SetMenuBar(MenuBar1);
    StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, wxST_SIZEGRIP|wxBORDER_SUNKEN, _T("ID_STATUSBAR1"));
    int __wxStatusBarWidths_1[4] = { -10, -10, -10, -10 };
    int __wxStatusBarStyles_1[4] = { wxSB_NORMAL, wxSB_NORMAL, wxSB_FLAT, wxSB_NORMAL };
    StatusBar1->SetFieldsCount(4,__wxStatusBarWidths_1);
    StatusBar1->SetStatusStyles(4,__wxStatusBarStyles_1);
    SetStatusBar(StatusBar1);
    Timer1.SetOwner(this, ID_TIMER1);
    Timer1.Start(500, false);
    Layout();

    Connect(ID_MENUITEM2, wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction)&dc2mFrame::OnMenuItem4Selected);
    Connect(ID_MENUITEM1, wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction)&dc2mFrame::OnMenuQrcodeShow);
    Connect(ID_MENUITEM3, wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction)&dc2mFrame::OnMenuItemChannel1);
    Connect(ID_MENUITEM4, wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction)&dc2mFrame::OnMenuItemChannel2);
    Connect(ID_MENUITEM5, wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction)&dc2mFrame::OnMenuItemChannel3);
    Connect(idMenuQuit, wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction)&dc2mFrame::OnQuit);
    Connect(idMenuAbout, wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction)&dc2mFrame::OnAbout);
    Connect(ID_TIMER1, wxEVT_TIMER, (wxObjectEventFunction)&dc2mFrame::OnTimer1Trigger);
    //*)

    Connect(wxID_ANY,E_ChatEvent,MyChatEventHandler(dc2mFrame::DoMyEvent),NULL,this);

    ChannelSettingDialog=new Set_channel(this);
    StationSettingDialog=new Set_station(this);
    QRDialog=new QrcodeDialog(this);
    AboutDialog=new About(this);

    settings.LoadValue();

    StatusBar1->SetStatusText(_("$1 "),0);

}

dc2mFrame::~dc2mFrame()
{
    //(*Destroy(dc2mFrame)
    //*)
}

void dc2mFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void dc2mFrame::OnAbout(wxCommandEvent& event)
{
    AboutDialog->ShowModal();
}

void dc2mFrame::DoMyEvent(C_ChatEvent &event)
{
  int ID=event.GetId();
  wxString str1=event.GetText()+"\n";
  int type=event.GetInt();
  if (type>=30000)
    int32_t pr=wxGetApp().Deltac->ProcessMessage(str1,type-30000);

  if ((type<=THFAILURE) || (settings.LogLevel>=0)) { //type)) {
    LogText->SetDefaultStyle(wxTextAttr(*wxBLACK));
    LogText->AppendText(str1);
  }

 //    ThreadError=1, ThreadFailure, ThreadMessage,  ThreadDebug, ThreadVerbose,

}



void dc2mFrame::OnMenuQrcodeShow(wxCommandEvent& event)
{

  wxString qc;
  qc=wxGetApp().Deltac->generate_qrcode();
  wxSize sz;
  sz.x=200;
  sz.y=200;

  wxBitmapBundle bm=wxBitmapBundle::FromSVG(qc.mb_str(),sz);
  QRDialog->SetBitmap(&bm);

  // la stampa avviene su ONPAINT
//  wxClientDC dc(QRDialog->QRpanel);
//  dc.DrawBitmap(bm.GetBitmap(sz),1,1,false);
 // wxClientDC dc(QRDialog->QRPanel);
 // wxInfoDC dc=new wxInfoDC(QRDialog->QRPanel);
 // dc.DrawBitmap(bm.GetBitmap(sz),1,1,false);
//sz.x=101;
  QRDialog->ShowModal();


}


void dc2mFrame::OnMenuItemChannel1(wxCommandEvent& event)
{
   settings.lastCh=1;
   settings.Chn2Chx(settings.lastCh);
   ChannelSettingDialog->Set_controls();
   ChannelSettingDialog->ShowModal();
}
void dc2mFrame::OnMenuItemChannel2(wxCommandEvent& event)
{
   settings.lastCh=2;
   settings.Chn2Chx(settings.lastCh);
   ChannelSettingDialog->Set_controls();
   ChannelSettingDialog->ShowModal();
}
void dc2mFrame::OnMenuItemChannel3(wxCommandEvent& event)
{
   settings.lastCh=3;
   settings.Chn2Chx(settings.lastCh);
   ChannelSettingDialog->Set_controls();
   ChannelSettingDialog->ShowModal();
}

void dc2mFrame::OnTimer1Trigger(wxTimerEvent& event)
{

  wxGetApp().Refresh();

}

void dc2mFrame::DisplayStatus(uint16_t field,int32_t status)
{
    if (status<0)
      StatusBar1->SetStatusText(wxString::Format(wxT("#%i Error %i "), field,status),field);
    else if (status==0)
      StatusBar1->SetStatusText(wxString::Format(wxT("#%i Off "), field),field);
    else if (status==1)
      StatusBar1->SetStatusText(wxString::Format(wxT("#%i Off line "), field),field);
    else if (status==2)
      StatusBar1->SetStatusText(wxString::Format(wxT("#%i On line "), field),field);
    else
      StatusBar1->SetStatusText(wxString::Format(wxT("#%i - - - "), field),field);
}

void dc2mFrame::OnMenuItem4Selected(wxCommandEvent& event)
{
  StationSettingDialog->ShowModal();
}
