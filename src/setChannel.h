#ifndef SET_CHANNEL_H
#define SET_CHANNEL_H

#include "cSettings.h"

extern C_Settings settings;


//(*Headers(Set_channel)
#include <wx/button.h>
#include <wx/checkbox.h>
#include <wx/dialog.h>
#include <wx/filepicker.h>
#include <wx/radiobox.h>
#include <wx/sizer.h>
#include <wx/statline.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
//*)

class Set_channel: public wxDialog
{
  public:

    Set_channel(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
    virtual ~Set_channel();
    void Set_controls(void);

    //(*Declarations(Set_channel)
    wxButton* Button1;
    wxButton* Button2;
    wxButton* Button3;
    wxCheckBox* CheckBox1;
    wxCheckBox* CheckBox2;
    wxFilePickerCtrl* FilePickerCtrl1;
    wxRadioBox* RadioBox1;
    wxRadioBox* RadioBox2;
    wxRadioBox* RadioBox3;
    wxStaticLine* StaticLine1;
    wxStaticLine* StaticLine2;
    wxStaticLine* StaticLine3;
    wxStaticLine* StaticLine4;
    wxStaticLine* StaticLine5;
    wxStaticText* StaticText10;
    wxStaticText* StaticText11;
    wxStaticText* StaticText12;
    wxStaticText* StaticText13;
    wxStaticText* StaticText14;
    wxStaticText* StaticText1;
    wxStaticText* StaticText2;
    wxStaticText* StaticText3;
    wxStaticText* StaticText4;
    wxStaticText* StaticText5;
    wxStaticText* StaticText6;
    wxStaticText* StaticText7;
    wxStaticText* StaticText8;
    wxStaticText* StaticText9;
    wxTextCtrl* TextCtrl10;
    wxTextCtrl* TextCtrl1;
    wxTextCtrl* TextCtrl2;
    wxTextCtrl* TextCtrl3;
    wxTextCtrl* TextCtrl4;
    wxTextCtrl* TextCtrl5;
    wxTextCtrl* TextCtrl6;
    wxTextCtrl* TextCtrl7;
    wxTextCtrl* TextCtrl8;
    wxTextCtrl* TextCtrl9;
    //*)

  protected:

    //(*Identifiers(Set_channel)
    static const wxWindowID ID_CHECKBOX2;
    static const wxWindowID ID_STATICLINE5;
    static const wxWindowID ID_STATICTEXT1;
    static const wxWindowID ID_TEXTCTRL1;
    static const wxWindowID ID_CHECKBOX1;
    static const wxWindowID ID_STATICLINE2;
    static const wxWindowID ID_STATICTEXT2;
    static const wxWindowID ID_TEXTCTRL2;
    static const wxWindowID ID_STATICTEXT4;
    static const wxWindowID ID_TEXTCTRL7;
    static const wxWindowID ID_STATICTEXT12;
    static const wxWindowID ID_TEXTCTRL8;
    static const wxWindowID ID_STATICTEXT13;
    static const wxWindowID ID_TEXTCTRL9;
    static const wxWindowID ID_STATICTEXT14;
    static const wxWindowID ID_TEXTCTRL10;
    static const wxWindowID ID_STATICLINE1;
    static const wxWindowID ID_STATICTEXT11;
    static const wxWindowID ID_STATICTEXT6;
    static const wxWindowID ID_STATICTEXT7;
    static const wxWindowID ID_TEXTCTRL3;
    static const wxWindowID ID_STATICTEXT8;
    static const wxWindowID ID_TEXTCTRL4;
    static const wxWindowID ID_STATICLINE3;
    static const wxWindowID ID_STATICTEXT5;
    static const wxWindowID ID_STATICTEXT9;
    static const wxWindowID ID_TEXTCTRL5;
    static const wxWindowID ID_STATICTEXT10;
    static const wxWindowID ID_TEXTCTRL6;
    static const wxWindowID ID_STATICLINE4;
    static const wxWindowID ID_STATICTEXT3;
    static const wxWindowID ID_FILEPICKERCTRL1;
    static const wxWindowID ID_RADIOBOX1;
    static const wxWindowID ID_RADIOBOX2;
    static const wxWindowID ID_RADIOBOX3;
    static const wxWindowID ID_BUTTON3;
    //*)

  private:

    //(*Handlers(Set_channel)
    void OnRadioBox1Select(wxCommandEvent& event);
    void OnRadioBox1Select1(wxCommandEvent& event);
    void OnButton1Click(wxCommandEvent& event);
    void OnCheckEnableCH(wxCommandEvent& event);
    void OnFilePickerCtrl1FileChanged(wxFileDirPickerEvent& event);
    void OnCheckRunCH(wxCommandEvent& event);
    //*)

    DECLARE_EVENT_TABLE()
};

#endif
