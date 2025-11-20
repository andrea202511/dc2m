#ifndef ABOUT_H
#define ABOUT_H

//(*Headers(About)
#include <wx/button.h>
#include <wx/dialog.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
//*)

class About: public wxDialog
{
  public:

    About(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
    virtual ~About();

    //(*Declarations(About)
    wxButton* Button1;
    wxStaticText* StaticText1;
    wxTextCtrl* TextCtrl1;
    wxTextCtrl* TextCtrl2;
    wxTextCtrl* TextCtrl3;
    //*)

  protected:

    //(*Identifiers(About)
    static const wxWindowID ID_STATICTEXT1;
    static const wxWindowID ID_TEXTCTRL3;
    static const wxWindowID ID_TEXTCTRL2;
    static const wxWindowID ID_TEXTCTRL1;
    static const wxWindowID ID_CANCEL;
    //*)

  private:

    //(*Handlers(About)
    //*)

    DECLARE_EVENT_TABLE()
};

#endif
