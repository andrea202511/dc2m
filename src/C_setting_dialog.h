#ifndef C_SETTING_DIALOG_H
#define C_SETTING_DIALOG_H

//(*Headers(C_setting_dialog)
#include <wx/dialog.h>
//*)

class C_setting_dialog: public wxDialog
{
  public:

    C_setting_dialog(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
    virtual ~C_setting_dialog();

    //(*Declarations(C_setting_dialog)
    //*)

  protected:

    //(*Identifiers(C_setting_dialog)
    //*)

  private:

    //(*Handlers(C_setting_dialog)
    //*)

    DECLARE_EVENT_TABLE()
};

#endif
