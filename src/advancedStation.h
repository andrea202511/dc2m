#ifndef ADVANCED_STATION_H
#define ADVANCED_STATION_H

#include "cSettings.h"
extern C_Settings settings;


//(*Headers(Advanced_station)
#include <wx/button.h>
#include <wx/checkbox.h>
#include <wx/dialog.h>
#include <wx/sizer.h>
#include <wx/statline.h>
#include <wx/stattext.h>
//*)

class Advanced_station: public wxDialog
{
  public:

    Advanced_station(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
    virtual ~Advanced_station();

    //(*Declarations(Advanced_station)
    wxButton* Button1;
    wxButton* Button2;
    wxButton* Button3;
    wxCheckBox* CheckBox1;
    wxCheckBox* CheckBox2;
    wxCheckBox* CheckBox3;
    wxCheckBox* CheckBox4;
    wxCheckBox* CheckBox5;
    wxCheckBox* CheckBox6;
    wxStaticLine* StaticLine1;
    wxStaticLine* StaticLine2;
    wxStaticText* StaticText1;
    //*)

  protected:

    //(*Identifiers(Advanced_station)
    static const wxWindowID ID_STATICTEXT1;
    static const wxWindowID ID_STATICLINE2;
    static const wxWindowID ID_CHECKBOX1;
    static const wxWindowID ID_CHECKBOX2;
    static const wxWindowID ID_CHECKBOX3;
    static const wxWindowID ID_CHECKBOX4;
    static const wxWindowID ID_CHECKBOX5;
    static const wxWindowID ID_CHECKBOX6;
    static const wxWindowID ID_STATICLINE1;
    static const wxWindowID ID_BUTTON1;
    static const wxWindowID ID_CANCEL;
    //*)

  private:

    //(*Handlers(Advanced_station)
    void OnCheckBox2Click(wxCommandEvent& event);
    //*)

    DECLARE_EVENT_TABLE()
};

#endif
