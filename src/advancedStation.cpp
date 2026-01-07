#include "advancedStation.h"

//(*InternalHeaders(Advanced_station)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(Advanced_station)
const wxWindowID Advanced_station::ID_STATICTEXT1 = wxNewId();
const wxWindowID Advanced_station::ID_STATICLINE2 = wxNewId();
const wxWindowID Advanced_station::ID_CHECKBOX1 = wxNewId();
const wxWindowID Advanced_station::ID_CHECKBOX2 = wxNewId();
const wxWindowID Advanced_station::ID_CHECKBOX3 = wxNewId();
const wxWindowID Advanced_station::ID_CHECKBOX4 = wxNewId();
const wxWindowID Advanced_station::ID_CHECKBOX5 = wxNewId();
const wxWindowID Advanced_station::ID_CHECKBOX6 = wxNewId();
const wxWindowID Advanced_station::ID_STATICLINE1 = wxNewId();
const wxWindowID Advanced_station::ID_BUTTON1 = wxNewId();
const wxWindowID Advanced_station::ID_CANCEL = wxNewId();
//*)

BEGIN_EVENT_TABLE(Advanced_station,wxDialog)
  //(*EventTable(Advanced_station)
  //*)
END_EVENT_TABLE()

Advanced_station::Advanced_station(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
  //(*Initialize(Advanced_station)
  wxBoxSizer* BoxSizer1;
  wxBoxSizer* BoxSizer4;

  Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
  SetClientSize(wxDefaultSize);
  Move(wxDefaultPosition);
  BoxSizer1 = new wxBoxSizer(wxVERTICAL);
  StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Please, don\'t change these options \nif you don\'t know what you\'re doing!"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
  BoxSizer1->Add(StaticText1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
  StaticLine2 = new wxStaticLine(this, ID_STATICLINE2, wxDefaultPosition, wxSize(10,-1), wxLI_HORIZONTAL, _T("ID_STATICLINE2"));
  BoxSizer1->Add(StaticLine2, 0, wxALL|wxEXPAND, 5);
  CheckBox1 = new wxCheckBox(this, ID_CHECKBOX1, _("Refresh station parameters"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX1"));
  CheckBox1->SetValue(false);
  BoxSizer1->Add(CheckBox1, 1, wxLEFT|wxALIGN_LEFT, 5);
  CheckBox2 = new wxCheckBox(this, ID_CHECKBOX2, _("Acquiring new chatmail address"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX2"));
  CheckBox2->SetValue(false);
  BoxSizer1->Add(CheckBox2, 1, wxLEFT|wxALIGN_LEFT, 5);
  CheckBox3 = new wxCheckBox(this, ID_CHECKBOX3, _("Deleting all chats"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX3"));
  CheckBox3->SetValue(false);
  BoxSizer1->Add(CheckBox3, 1, wxLEFT|wxALIGN_LEFT, 5);
  CheckBox4 = new wxCheckBox(this, ID_CHECKBOX4, _("Label"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX4"));
  CheckBox4->SetValue(false);
  BoxSizer1->Add(CheckBox4, 1, wxLEFT|wxALIGN_LEFT, 5);
  CheckBox5 = new wxCheckBox(this, ID_CHECKBOX5, _("Label"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX5"));
  CheckBox5->SetValue(false);
  BoxSizer1->Add(CheckBox5, 1, wxLEFT|wxALIGN_LEFT, 5);
  CheckBox6 = new wxCheckBox(this, ID_CHECKBOX6, _("Label"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX6"));
  CheckBox6->SetValue(false);
  BoxSizer1->Add(CheckBox6, 1, wxLEFT|wxALIGN_LEFT, 5);
  StaticLine1 = new wxStaticLine(this, ID_STATICLINE1, wxDefaultPosition, wxSize(10,-1), wxLI_HORIZONTAL, _T("ID_STATICLINE1"));
  BoxSizer1->Add(StaticLine1, 0, wxALL|wxEXPAND, 5);
  BoxSizer4 = new wxBoxSizer(wxHORIZONTAL);
  Button1 = new wxButton(this, ID_BUTTON1, _("Help"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
  BoxSizer4->Add(Button1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
  Button2 = new wxButton(this, ID_CANCEL, _("Cancel"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CANCEL"));
  BoxSizer4->Add(Button2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
  Button3 = new wxButton(this, wxID_OK, _("Enter"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("wxID_OK"));
  BoxSizer4->Add(Button3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
  BoxSizer1->Add(BoxSizer4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
  SetSizer(BoxSizer1);
  BoxSizer1->SetSizeHints(this);

  Connect(ID_CHECKBOX2, wxEVT_COMMAND_CHECKBOX_CLICKED, (wxObjectEventFunction)&Advanced_station::OnCheckBox2Click);
  //*)
}

Advanced_station::~Advanced_station()
{
  //(*Destroy(Advanced_station)
  //*)
}


void Advanced_station::OnCheckBox2Click(wxCommandEvent& event)
{
}
