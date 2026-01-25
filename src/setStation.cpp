#include "setStation.h"

//(*InternalHeaders(Set_station)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(Set_station)
const wxWindowID Set_station::ID_CHECKBOX1 = wxNewId();
const wxWindowID Set_station::ID_STATICTEXT1 = wxNewId();
const wxWindowID Set_station::ID_TEXTCTRL1 = wxNewId();
const wxWindowID Set_station::ID_STATICTEXT2 = wxNewId();
const wxWindowID Set_station::ID_TEXTCTRL2 = wxNewId();
const wxWindowID Set_station::ID_STATICLINE1 = wxNewId();
const wxWindowID Set_station::ID_STATICTEXT4 = wxNewId();
const wxWindowID Set_station::ID_RADIOBOX1 = wxNewId();
const wxWindowID Set_station::ID_RADIOBOX2 = wxNewId();
const wxWindowID Set_station::ID_STATICLINE2 = wxNewId();
const wxWindowID Set_station::ID_RADIOBOX3 = wxNewId();
const wxWindowID Set_station::ID_BUTTON2 = wxNewId();
const wxWindowID Set_station::ID_STATICLINE3 = wxNewId();
const wxWindowID Set_station::ID_BUTTON1 = wxNewId();
const wxWindowID Set_station::ID_CANCEL = wxNewId();
//*)

BEGIN_EVENT_TABLE(Set_station,wxDialog)
    //(*EventTable(Set_station)
    //*)
END_EVENT_TABLE()

Set_station::Set_station(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(Set_station)
    wxBoxSizer* BoxSizer1;
    wxBoxSizer* BoxSizer2;
    wxBoxSizer* BoxSizer3;
    wxBoxSizer* BoxSizer4;
    wxBoxSizer* BoxSizer5;
    wxBoxSizer* BoxSizer6;

    Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
    SetExtraStyle( GetExtraStyle() | wxWS_EX_VALIDATE_RECURSIVELY );
    BoxSizer1 = new wxBoxSizer(wxVERTICAL);
    CheckBox1 = new wxCheckBox(this, ID_CHECKBOX1, _("Station enable (takes effect after restart)"), wxDefaultPosition, wxDefaultSize, 0, wxGenericValidator(&settings.station_enable), _T("ID_CHECKBOX1"));
    CheckBox1->SetValue(false);
    BoxSizer1->Add(CheckBox1, 0, wxALL|wxALIGN_LEFT, 5);
    BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
    StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Alias"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    BoxSizer2->Add(StaticText1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl1 = new wxTextCtrl(this, ID_TEXTCTRL1, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxGenericValidator(&settings.station_name), _T("ID_TEXTCTRL1"));
    BoxSizer2->Add(TextCtrl1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer1->Add(BoxSizer2, 0, wxALL|wxEXPAND, 0);
    BoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
    StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("Posizion"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
    BoxSizer3->Add(StaticText2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl2 = new wxTextCtrl(this, ID_TEXTCTRL2, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxGenericValidator(&settings.station_loc), _T("ID_TEXTCTRL2"));
    BoxSizer3->Add(TextCtrl2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer1->Add(BoxSizer3, 0, wxALL|wxEXPAND, 0);
    StaticLine1 = new wxStaticLine(this, ID_STATICLINE1, wxDefaultPosition, wxSize(100,-1), wxLI_HORIZONTAL, _T("ID_STATICLINE1"));
    BoxSizer1->Add(StaticLine1, 0, wxALL|wxEXPAND, 5);
    BoxSizer5 = new wxBoxSizer(wxVERTICAL);
    StaticText4 = new wxStaticText(this, ID_STATICTEXT4, _("Log area"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT4"));
    BoxSizer5->Add(StaticText4, 0, wxALL|wxALIGN_LEFT, 5);
    BoxSizer6 = new wxBoxSizer(wxHORIZONTAL);
    wxString __wxRadioBoxChoices_1[3] =
    {
      _("Default"),
      _("Verbose"),
      _("Only for debug")
    };
    RadioBox1 = new wxRadioBox(this, ID_RADIOBOX1, _("Station"), wxDefaultPosition, wxDefaultSize, 3, __wxRadioBoxChoices_1, 1, wxRA_SPECIFY_COLS, wxGenericValidator(&settings.StLogLevel), _T("ID_RADIOBOX1"));
    BoxSizer6->Add(RadioBox1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    wxString __wxRadioBoxChoices_2[3] =
    {
      _("Default"),
      _("Verbose"),
      _("Only for debug")
    };
    RadioBox2 = new wxRadioBox(this, ID_RADIOBOX2, _("Channels"), wxDefaultPosition, wxDefaultSize, 3, __wxRadioBoxChoices_2, 1, wxRA_SPECIFY_COLS, wxGenericValidator(&settings.ChLogLevel), _T("ID_RADIOBOX2"));
    BoxSizer6->Add(RadioBox2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer5->Add(BoxSizer6, 1, wxALL|wxEXPAND, 5);
    BoxSizer1->Add(BoxSizer5, 1, wxALL|wxEXPAND, 0);
    StaticLine2 = new wxStaticLine(this, ID_STATICLINE2, wxDefaultPosition, wxSize(100,-1), wxLI_HORIZONTAL, _T("ID_STATICLINE2"));
    BoxSizer1->Add(StaticLine2, 0, wxALL|wxEXPAND, 5);
    wxString __wxRadioBoxChoices_3[2] =
    {
      _("en"),
      _("it")
    };
    RadioBox3 = new wxRadioBox(this, ID_RADIOBOX3, _("Language"), wxDefaultPosition, wxDefaultSize, 2, __wxRadioBoxChoices_3, 1, wxRA_SPECIFY_COLS, wxGenericValidator(&settings.Language), _T("ID_RADIOBOX3"));
    BoxSizer1->Add(RadioBox3, 0, wxALL|wxEXPAND, 5);
    Button4 = new wxButton(this, ID_BUTTON2, _(" Advanced options "), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
    BoxSizer1->Add(Button4, 0, wxALL|wxALIGN_LEFT, 5);
    StaticLine3 = new wxStaticLine(this, ID_STATICLINE3, wxDefaultPosition, wxSize(100,-1), wxLI_HORIZONTAL, _T("ID_STATICLINE3"));
    BoxSizer1->Add(StaticLine3, 0, wxALL|wxEXPAND, 5);
    BoxSizer4 = new wxBoxSizer(wxHORIZONTAL);
    Button1 = new wxButton(this, ID_BUTTON1, _("Help"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    BoxSizer4->Add(Button1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Button2 = new wxButton(this, ID_CANCEL, _("Cancel"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CANCEL"));
    BoxSizer4->Add(Button2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Button3 = new wxButton(this, wxID_OK, _("Ok"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("wxID_OK"));
    BoxSizer4->Add(Button3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer1->Add(BoxSizer4, 0, wxALL|wxALIGN_LEFT, 5);
    SetSizer(BoxSizer1);
    BoxSizer1->SetSizeHints(this);

    Connect(ID_BUTTON2, wxEVT_COMMAND_BUTTON_CLICKED, (wxObjectEventFunction)&Set_station::OnButton4Click);
    Connect(wxID_OK, wxEVT_COMMAND_BUTTON_CLICKED, (wxObjectEventFunction)&Set_station::OnButton3Click);
    //*)

    AdvancedStationDialog=new Advanced_station(this);

}

Set_station::~Set_station()
{
    //(*Destroy(Set_station)
    //*)
}


void Set_station::OnButton3Click(wxCommandEvent& event)
{
    if(Validate() && TransferDataFromWindow()) {
    settings.SaveValue();
    if (IsModal())
      EndModal(wxID_OK);
    else {
      SetReturnCode(wxID_OK);
      this->Show(false);
    }
    }
}

void Set_station::OnButton4Click(wxCommandEvent& event)
{
   AdvancedStationDialog->ShowModal();
}
