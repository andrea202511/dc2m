#include "C_setting_dialog.h"

//(*InternalHeaders(C_setting_dialog)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(C_setting_dialog)
//*)

BEGIN_EVENT_TABLE(C_setting_dialog,wxDialog)
  //(*EventTable(C_setting_dialog)
  //*)
END_EVENT_TABLE()

C_setting_dialog::C_setting_dialog(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
  //(*Initialize(C_setting_dialog)
  Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
  SetClientSize(wxDefaultSize);
  Move(wxDefaultPosition);
  //*)
}

C_setting_dialog::~C_setting_dialog()
{
  //(*Destroy(C_setting_dialog)
  //*)
}

