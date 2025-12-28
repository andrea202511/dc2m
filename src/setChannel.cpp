#include "setChannel.h"

//(*InternalHeaders(Set_channel)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(Set_channel)
const wxWindowID Set_channel::ID_CHECKBOX2 = wxNewId();
const wxWindowID Set_channel::ID_STATICLINE5 = wxNewId();
const wxWindowID Set_channel::ID_STATICTEXT1 = wxNewId();
const wxWindowID Set_channel::ID_TEXTCTRL1 = wxNewId();
const wxWindowID Set_channel::ID_CHECKBOX1 = wxNewId();
const wxWindowID Set_channel::ID_STATICLINE2 = wxNewId();
const wxWindowID Set_channel::ID_STATICTEXT2 = wxNewId();
const wxWindowID Set_channel::ID_TEXTCTRL2 = wxNewId();
const wxWindowID Set_channel::ID_STATICTEXT4 = wxNewId();
const wxWindowID Set_channel::ID_TEXTCTRL7 = wxNewId();
const wxWindowID Set_channel::ID_STATICTEXT12 = wxNewId();
const wxWindowID Set_channel::ID_TEXTCTRL8 = wxNewId();
const wxWindowID Set_channel::ID_STATICTEXT13 = wxNewId();
const wxWindowID Set_channel::ID_TEXTCTRL9 = wxNewId();
const wxWindowID Set_channel::ID_STATICTEXT14 = wxNewId();
const wxWindowID Set_channel::ID_TEXTCTRL10 = wxNewId();
const wxWindowID Set_channel::ID_STATICLINE1 = wxNewId();
const wxWindowID Set_channel::ID_STATICTEXT11 = wxNewId();
const wxWindowID Set_channel::ID_STATICTEXT6 = wxNewId();
const wxWindowID Set_channel::ID_STATICTEXT7 = wxNewId();
const wxWindowID Set_channel::ID_TEXTCTRL3 = wxNewId();
const wxWindowID Set_channel::ID_STATICTEXT8 = wxNewId();
const wxWindowID Set_channel::ID_TEXTCTRL4 = wxNewId();
const wxWindowID Set_channel::ID_STATICLINE3 = wxNewId();
const wxWindowID Set_channel::ID_STATICTEXT5 = wxNewId();
const wxWindowID Set_channel::ID_STATICTEXT9 = wxNewId();
const wxWindowID Set_channel::ID_TEXTCTRL5 = wxNewId();
const wxWindowID Set_channel::ID_STATICTEXT10 = wxNewId();
const wxWindowID Set_channel::ID_TEXTCTRL6 = wxNewId();
const wxWindowID Set_channel::ID_STATICLINE4 = wxNewId();
const wxWindowID Set_channel::ID_STATICTEXT3 = wxNewId();
const wxWindowID Set_channel::ID_FILEPICKERCTRL1 = wxNewId();
const wxWindowID Set_channel::ID_RADIOBOX1 = wxNewId();
const wxWindowID Set_channel::ID_RADIOBOX2 = wxNewId();
const wxWindowID Set_channel::ID_RADIOBOX3 = wxNewId();
const wxWindowID Set_channel::ID_BUTTON3 = wxNewId();
//*)

BEGIN_EVENT_TABLE(Set_channel,wxDialog)
  //(*EventTable(Set_channel)
  //*)
END_EVENT_TABLE()

Set_channel::Set_channel(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{

  wxIntegerValidator<int32_t> vip1(&settings.chx.ipp1, wxNUM_VAL_THOUSANDS_SEPARATOR);
  vip1.SetMin(1);
  vip1.SetMax(255);
  wxIntegerValidator<int32_t> vip2(&settings.chx.ipp2, wxNUM_VAL_THOUSANDS_SEPARATOR);
  vip2.SetMin(0);
  vip2.SetMax(255);
  wxIntegerValidator<int32_t> vip3(&settings.chx.ipp3, wxNUM_VAL_THOUSANDS_SEPARATOR);
  vip3.SetMin(0);
  vip3.SetMax(255);
  wxIntegerValidator<int32_t> vip4(&settings.chx.ipp4, wxNUM_VAL_THOUSANDS_SEPARATOR);
  vip4.SetMin(1);
  vip4.SetMax(255);
  wxIntegerValidator<int32_t> vport(&settings.chx.port, wxNUM_VAL_THOUSANDS_SEPARATOR);
  vport.SetMin(1);
  vport.SetMax(16000);
  wxIntegerValidator<int32_t> nreg_rx(&settings.chx.lengthrx, wxNUM_VAL_THOUSANDS_SEPARATOR);
  nreg_rx.SetMin(5);
  nreg_rx.SetMax(512);
  wxIntegerValidator<int32_t> nreg_tx(&settings.chx.lengthtx, wxNUM_VAL_THOUSANDS_SEPARATOR);
  nreg_tx.SetMin(5);
  nreg_tx.SetMax(512);

  //(*Initialize(Set_channel)
  wxBoxSizer* BoxSizer10;
  wxBoxSizer* BoxSizer11;
  wxBoxSizer* BoxSizer12;
  wxBoxSizer* BoxSizer13;
  wxBoxSizer* BoxSizer14;
  wxBoxSizer* BoxSizer15;
  wxBoxSizer* BoxSizer16;
  wxBoxSizer* BoxSizer1;
  wxBoxSizer* BoxSizer2;
  wxBoxSizer* BoxSizer3;
  wxBoxSizer* BoxSizer4;
  wxBoxSizer* BoxSizer5;
  wxBoxSizer* BoxSizer6;
  wxBoxSizer* BoxSizer7;
  wxBoxSizer* BoxSizer8;
  wxBoxSizer* BoxSizer9;

  Create(parent, id, _("CHANNEL SETTING"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
  SetClientSize(wxDefaultSize);
  Move(wxDefaultPosition);
  SetExtraStyle( GetExtraStyle() | wxWS_EX_VALIDATE_RECURSIVELY );
  BoxSizer1 = new wxBoxSizer(wxVERTICAL);
  CheckBox2 = new wxCheckBox(this, ID_CHECKBOX2, _(" Channel enable (takes effect after restart)"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX2"));
  CheckBox2->SetValue(false);
  BoxSizer1->Add(CheckBox2, 0, wxALL|wxALIGN_LEFT, 5);
  StaticLine5 = new wxStaticLine(this, ID_STATICLINE5, wxDefaultPosition, wxSize(10,-1), wxLI_HORIZONTAL, _T("ID_STATICLINE5"));
  BoxSizer1->Add(StaticLine5, 0, wxALL|wxEXPAND, 5);
  BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
  StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Alias"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
  BoxSizer2->Add(StaticText1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
  TextCtrl1 = new wxTextCtrl(this, ID_TEXTCTRL1, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxGenericValidator(&settings.chx.name), _T("ID_TEXTCTRL1"));
  BoxSizer2->Add(TextCtrl1, 2, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
  BoxSizer1->Add(BoxSizer2, 0, wxALL|wxEXPAND, 5);
  CheckBox1 = new wxCheckBox(this, ID_CHECKBOX1, _(" Running"), wxDefaultPosition, wxDefaultSize, 0, wxGenericValidator(&settings.chx.run), _T("ID_CHECKBOX1"));
  CheckBox1->SetValue(false);
  BoxSizer1->Add(CheckBox1, 0, wxALL|wxALIGN_LEFT|wxSHAPED, 5);
  StaticLine2 = new wxStaticLine(this, ID_STATICLINE2, wxDefaultPosition, wxSize(10,-1), wxLI_HORIZONTAL, _T("ID_STATICLINE2"));
  BoxSizer1->Add(StaticLine2, 0, wxALL|wxEXPAND, 5);
  BoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
  StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("IP Address"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
  BoxSizer3->Add(StaticText2, 8, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
  TextCtrl2 = new wxTextCtrl(this, ID_TEXTCTRL2, _T("0"), wxDefaultPosition, wxSize(44,33), 0, vip1, _T("ID_TEXTCTRL2"));
  BoxSizer3->Add(TextCtrl2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
  StaticText4 = new wxStaticText(this, ID_STATICTEXT4, _T("."), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT4"));
  BoxSizer3->Add(StaticText4, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
  TextCtrl7 = new wxTextCtrl(this, ID_TEXTCTRL7, _T("0"), wxDefaultPosition, wxSize(44,33), 0, vip2, _T("ID_TEXTCTRL7"));
  BoxSizer3->Add(TextCtrl7, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
  StaticText12 = new wxStaticText(this, ID_STATICTEXT12, _T("."), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT12"));
  BoxSizer3->Add(StaticText12, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
  TextCtrl8 = new wxTextCtrl(this, ID_TEXTCTRL8, _T("0"), wxDefaultPosition, wxSize(44,36), 0, vip3, _T("ID_TEXTCTRL8"));
  BoxSizer3->Add(TextCtrl8, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
  StaticText13 = new wxStaticText(this, ID_STATICTEXT13, _T("."), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT13"));
  BoxSizer3->Add(StaticText13, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
  TextCtrl9 = new wxTextCtrl(this, ID_TEXTCTRL9, _T("0"), wxDefaultPosition, wxSize(44,36), 0, vip4, _T("ID_TEXTCTRL9"));
  BoxSizer3->Add(TextCtrl9, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
  BoxSizer1->Add(BoxSizer3, 0, wxALL|wxEXPAND, 5);
  BoxSizer15 = new wxBoxSizer(wxHORIZONTAL);
  StaticText14 = new wxStaticText(this, ID_STATICTEXT14, _("Port:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT14"));
  BoxSizer15->Add(StaticText14, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
  TextCtrl10 = new wxTextCtrl(this, ID_TEXTCTRL10, _T("0"), wxDefaultPosition, wxDefaultSize, 0, vport, _T("ID_TEXTCTRL10"));
  BoxSizer15->Add(TextCtrl10, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
  BoxSizer1->Add(BoxSizer15, 0, wxALL|wxEXPAND, 5);
  StaticLine1 = new wxStaticLine(this, ID_STATICLINE1, wxDefaultPosition, wxSize(10,-1), wxLI_HORIZONTAL, _T("ID_STATICLINE1"));
  BoxSizer1->Add(StaticLine1, 0, wxALL|wxEXPAND, 2);
  StaticText11 = new wxStaticText(this, ID_STATICTEXT11, _("Modbus register"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT11"));
  BoxSizer1->Add(StaticText11, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxSHAPED, 5);
  BoxSizer8 = new wxBoxSizer(wxHORIZONTAL);
  BoxSizer9 = new wxBoxSizer(wxVERTICAL);
  StaticText6 = new wxStaticText(this, ID_STATICTEXT6, _("plc->dc"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT6"));
  BoxSizer9->Add(StaticText6, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxSHAPED, 5);
  BoxSizer11 = new wxBoxSizer(wxHORIZONTAL);
  StaticText7 = new wxStaticText(this, ID_STATICTEXT7, _("First reg."), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT7"));
  BoxSizer11->Add(StaticText7, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
  TextCtrl3 = new wxTextCtrl(this, ID_TEXTCTRL3, _T("0"), wxDefaultPosition, wxDefaultSize, 0, wxGenericValidator(&settings.chx.starttx), _T("ID_TEXTCTRL3"));
  BoxSizer11->Add(TextCtrl3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
  BoxSizer9->Add(BoxSizer11, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
  BoxSizer14 = new wxBoxSizer(wxHORIZONTAL);
  StaticText8 = new wxStaticText(this, ID_STATICTEXT8, _("Nr.regs"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT8"));
  BoxSizer14->Add(StaticText8, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
  TextCtrl4 = new wxTextCtrl(this, ID_TEXTCTRL4, _T("0"), wxDefaultPosition, wxDefaultSize, 0, nreg_tx, _T("ID_TEXTCTRL4"));
  BoxSizer14->Add(TextCtrl4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
  BoxSizer9->Add(BoxSizer14, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
  BoxSizer8->Add(BoxSizer9, 1, wxLEFT|wxRIGHT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
  StaticLine3 = new wxStaticLine(this, ID_STATICLINE3, wxDefaultPosition, wxSize(10,-1), wxLI_VERTICAL, _T("ID_STATICLINE3"));
  BoxSizer8->Add(StaticLine3, 0, wxALL|wxEXPAND, 5);
  BoxSizer10 = new wxBoxSizer(wxVERTICAL);
  StaticText5 = new wxStaticText(this, ID_STATICTEXT5, _("dc->plc"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT5"));
  BoxSizer10->Add(StaticText5, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxSHAPED, 5);
  BoxSizer12 = new wxBoxSizer(wxHORIZONTAL);
  StaticText9 = new wxStaticText(this, ID_STATICTEXT9, _("First reg."), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT9"));
  BoxSizer12->Add(StaticText9, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
  TextCtrl5 = new wxTextCtrl(this, ID_TEXTCTRL5, _T("0"), wxDefaultPosition, wxDefaultSize, 0, wxGenericValidator(&settings.chx.startrx), _T("ID_TEXTCTRL5"));
  BoxSizer12->Add(TextCtrl5, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
  BoxSizer10->Add(BoxSizer12, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
  BoxSizer13 = new wxBoxSizer(wxHORIZONTAL);
  StaticText10 = new wxStaticText(this, ID_STATICTEXT10, _("Nr.regs"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT10"));
  BoxSizer13->Add(StaticText10, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
  TextCtrl6 = new wxTextCtrl(this, ID_TEXTCTRL6, _T("0"), wxDefaultPosition, wxDefaultSize, 0, nreg_rx, _T("ID_TEXTCTRL6"));
  BoxSizer13->Add(TextCtrl6, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
  BoxSizer10->Add(BoxSizer13, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
  BoxSizer8->Add(BoxSizer10, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
  BoxSizer1->Add(BoxSizer8, 0, wxALL|wxEXPAND, 5);
  StaticLine4 = new wxStaticLine(this, ID_STATICLINE4, wxDefaultPosition, wxSize(10,-1), wxLI_HORIZONTAL, _T("ID_STATICLINE4"));
  BoxSizer1->Add(StaticLine4, 0, wxALL|wxEXPAND, 5);
  BoxSizer16 = new wxBoxSizer(wxHORIZONTAL);
  StaticText3 = new wxStaticText(this, ID_STATICTEXT3, _("Messages list"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
  BoxSizer16->Add(StaticText3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
  FilePickerCtrl1 = new wxFilePickerCtrl(this, ID_FILEPICKERCTRL1, wxEmptyString, wxEmptyString, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxFLP_USE_TEXTCTRL|wxFLP_SMALL, wxDefaultValidator, _T("ID_FILEPICKERCTRL1"));
  BoxSizer16->Add(FilePickerCtrl1, 3, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
  BoxSizer1->Add(BoxSizer16, 0, wxALL|wxEXPAND, 5);
  BoxSizer7 = new wxBoxSizer(wxHORIZONTAL);
  BoxSizer4 = new wxBoxSizer(wxVERTICAL);
  wxString __wxRadioBoxChoices_1[3] =
  {
    _("slow"),
    _("medium"),
    _("fast")
  };
  RadioBox1 = new wxRadioBox(this, ID_RADIOBOX1, _("Pollig rate"), wxDefaultPosition, wxDefaultSize, 3, __wxRadioBoxChoices_1, 1, wxRA_SPECIFY_COLS, wxGenericValidator(&settings.chx.trefresh), _T("ID_RADIOBOX1"));
  BoxSizer4->Add(RadioBox1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
  BoxSizer7->Add(BoxSizer4, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
  BoxSizer6 = new wxBoxSizer(wxVERTICAL);
  wxString __wxRadioBoxChoices_2[2] =
  {
    _("Big endian"),
    _("Little endian")
  };
  RadioBox2 = new wxRadioBox(this, ID_RADIOBOX2, _("Byte order"), wxDefaultPosition, wxDefaultSize, 2, __wxRadioBoxChoices_2, 1, wxRA_SPECIFY_COLS, wxGenericValidator(&settings.chx.byteord), _T("ID_RADIOBOX2"));
  BoxSizer6->Add(RadioBox2, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
  BoxSizer7->Add(BoxSizer6, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
  wxString __wxRadioBoxChoices_3[3] =
  {
    _("-A -B -C -D -E -0 ..."),
    _("AB CD E0 ..."),
    _("BA DC 0E ...")
  };
  RadioBox3 = new wxRadioBox(this, ID_RADIOBOX3, _("Character order"), wxDefaultPosition, wxDefaultSize, 3, __wxRadioBoxChoices_3, 1, wxRA_SPECIFY_COLS, wxGenericValidator(&settings.chx.charord), _T("ID_RADIOBOX3"));
  BoxSizer7->Add(RadioBox3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
  BoxSizer1->Add(BoxSizer7, 1, wxALL|wxEXPAND, 5);
  BoxSizer5 = new wxBoxSizer(wxHORIZONTAL);
  Button3 = new wxButton(this, ID_BUTTON3, _("Help"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON3"));
  BoxSizer5->Add(Button3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
  Button2 = new wxButton(this, wxID_CANCEL, _("Cancel"), wxDefaultPosition, wxDefaultSize, 0,  wxDefaultValidator, _T("wxID_CANCEL"));
  BoxSizer5->Add(Button2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
  Button1 = new wxButton(this, wxID_OK, _("Enter"), wxDefaultPosition, wxDefaultSize, 0,  wxDefaultValidator, _T("wxID_OK"));
  BoxSizer5->Add(Button1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
  BoxSizer1->Add(BoxSizer5, 0, wxALL|wxEXPAND, 5);
  SetSizer(BoxSizer1);
  BoxSizer1->SetSizeHints(this);

  Connect(ID_CHECKBOX1, wxEVT_COMMAND_CHECKBOX_CLICKED, (wxObjectEventFunction)&Set_channel::OnCheckEnableCH);
  Connect(ID_FILEPICKERCTRL1, wxEVT_COMMAND_FILEPICKER_CHANGED, (wxObjectEventFunction)&Set_channel::OnFilePickerCtrl1FileChanged);
  Connect(wxID_OK, wxEVT_COMMAND_BUTTON_CLICKED, (wxObjectEventFunction)&Set_channel::OnButton1Click);
  //*)
}

Set_channel::~Set_channel()
{
  //(*Destroy(Set_channel)
  //*)
}

/**
prova di commentone one one
*/
void Set_channel::OnRadioBox1Select(wxCommandEvent& event)
{
}

void Set_channel::OnRadioBox1Select1(wxCommandEvent& event)
{
}




void Set_channel::OnButton1Click(wxCommandEvent& event)
{
  if(Validate() && TransferDataFromWindow()) {
    settings.Chx2Chn(settings.lastCh);
    if (IsModal())
      EndModal(wxID_OK);
    else {
      SetReturnCode(wxID_OK);
      this->Show(false);
    }

  }
}

void Set_channel::OnCheckEnableCH(wxCommandEvent& event)
{
  if (settings.lastCh==1)
    settings.ch1.enable=CheckBox1->GetValue();
  else if (settings.lastCh==2)
    settings.ch2.enable=CheckBox1->GetValue();
  else if (settings.lastCh==3)
    settings.ch3.enable=CheckBox1->GetValue();

}

void Set_channel::OnFilePickerCtrl1FileChanged(wxFileDirPickerEvent& event)
{

  wxTextCtrl* tc=FilePickerCtrl1->GetTextCtrl();
  settings.chx.filemsg=tc->GetValue();
}

void Set_channel::Set_controls()
{
  wxTextCtrl* tc=FilePickerCtrl1->GetTextCtrl();
  tc->SetValue(settings.chx.filemsg);
}
