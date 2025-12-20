#include "about.h"
#include "version.h"

//(*InternalHeaders(About)
#include <wx/bitmap.h>
#include <wx/font.h>
#include <wx/image.h>
#include <wx/intl.h>
#include <wx/settings.h>
#include <wx/string.h>
//*)

//(*IdInit(About)
const wxWindowID About::ID_STATICBITMAP1 = wxNewId();
const wxWindowID About::ID_STATICTEXT1 = wxNewId();
const wxWindowID About::ID_TEXTCTRL3 = wxNewId();
const wxWindowID About::ID_TEXTCTRL2 = wxNewId();
const wxWindowID About::ID_TEXTCTRL1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(About,wxDialog)
  //(*EventTable(About)
  //*)
END_EVENT_TABLE()

About::About(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
  //(*Initialize(About)
  wxBoxSizer* BoxSizer1;
  wxBoxSizer* BoxSizer2;
  wxBoxSizer* BoxSizer3;
  wxBoxSizer* BoxSizer4;
  wxBoxSizer* BoxSizer5;

  Create(parent, id, _("About"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
  SetClientSize(wxSize(400,400));
  Move(wxDefaultPosition);
  SetMinSize(wxSize(300,300));
  SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOW));
  BoxSizer1 = new wxBoxSizer(wxVERTICAL);
  BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
  StaticBitmap1 = new wxStaticBitmap(this, ID_STATICBITMAP1, wxIcon(dc2mLogo48_xpm), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICBITMAP1"));
  BoxSizer2->Add(StaticBitmap1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
  StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("DC2M"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE, _T("ID_STATICTEXT1"));
  StaticText1->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOW));
  wxFont StaticText1Font(20,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Sans"),wxFONTENCODING_DEFAULT);
  StaticText1->SetFont(StaticText1Font);
  BoxSizer2->Add(StaticText1, 2, wxEXPAND, 2);
  BoxSizer1->Add(BoxSizer2, 1, wxEXPAND, 5);
  BoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
  TextCtrl3 = new wxTextCtrl(this, ID_TEXTCTRL3, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY|wxTE_CENTRE, wxDefaultValidator, _T("ID_TEXTCTRL3"));
  TextCtrl3->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOW));
  wxFont TextCtrl3Font(15,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_T("Sans"),wxFONTENCODING_DEFAULT);
  TextCtrl3->SetFont(TextCtrl3Font);
  BoxSizer3->Add(TextCtrl3, 2, wxEXPAND, 5);
  BoxSizer1->Add(BoxSizer3, 1, wxEXPAND, 5);
  BoxSizer4 = new wxBoxSizer(wxHORIZONTAL);
  TextCtrl2 = new wxTextCtrl(this, ID_TEXTCTRL2, wxEmptyString, wxDefaultPosition, wxSize(-1,35), wxTE_READONLY|wxTE_RIGHT, wxDefaultValidator, _T("ID_TEXTCTRL2"));
  TextCtrl2->SetBackgroundColour(wxColour(244,136,20));
  BoxSizer4->Add(TextCtrl2, 1, wxEXPAND, 0);
  BoxSizer1->Add(BoxSizer4, 0, wxEXPAND, 5);
  TextCtrl1 = new wxTextCtrl(this, ID_TEXTCTRL1, _("Author: andrea202511 (Andrea Fabbri)\n\nThis program is licensed under the terms\nof the GNU General Public License version 3\nhttp://www.gnu.org/licenses/gpl-3.0.html\n"), wxDefaultPosition, wxSize(400,-1), wxTE_MULTILINE|wxTE_READONLY|wxALWAYS_SHOW_SB, wxDefaultValidator, _T("ID_TEXTCTRL1"));
  BoxSizer1->Add(TextCtrl1, 4, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
  BoxSizer5 = new wxBoxSizer(wxHORIZONTAL);
  Button1 = new wxButton(this, wxID_CANCEL, _("Close"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("wxID_CANCEL"));
  BoxSizer5->Add(Button1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
  BoxSizer1->Add(BoxSizer5, 1, wxALIGN_CENTER_HORIZONTAL, 5);
  SetSizer(BoxSizer1);
  Layout();
  //*)

  TextCtrl3->SetValue(AutoVersion::FULLVERSION_STRING);
  TextCtrl2->SetValue(AutoVersion::STATUS);
}

About::~About()
{
  //(*Destroy(About)
  //*)
}

