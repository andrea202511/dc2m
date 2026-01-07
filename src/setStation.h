#ifndef SET_STATION_H
#define SET_STATION_H

#include "cSettings.h"
#include "advancedStation.h"

extern C_Settings settings;


//(*Headers(Set_station)
#include <wx/button.h>
#include <wx/checkbox.h>
#include <wx/dialog.h>
#include <wx/radiobox.h>
#include <wx/sizer.h>
#include <wx/statline.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
//*)

class Set_station: public wxDialog
{
    public:

        Set_station(wxWindow* parent,wxWindowID id=wxID_ANY);
        virtual ~Set_station();

        //(*Declarations(Set_station)
        wxButton* Button1;
        wxButton* Button2;
        wxButton* Button3;
        wxButton* Button4;
        wxCheckBox* CheckBox1;
        wxRadioBox* RadioBox1;
        wxRadioBox* RadioBox2;
        wxRadioBox* RadioBox3;
        wxStaticLine* StaticLine1;
        wxStaticLine* StaticLine2;
        wxStaticLine* StaticLine3;
        wxStaticText* StaticText1;
        wxStaticText* StaticText2;
        wxStaticText* StaticText4;
        wxTextCtrl* TextCtrl1;
        wxTextCtrl* TextCtrl2;
        //*)

    protected:

        //(*Identifiers(Set_station)
        static const wxWindowID ID_CHECKBOX1;
        static const wxWindowID ID_STATICTEXT1;
        static const wxWindowID ID_TEXTCTRL1;
        static const wxWindowID ID_STATICTEXT2;
        static const wxWindowID ID_TEXTCTRL2;
        static const wxWindowID ID_STATICLINE1;
        static const wxWindowID ID_STATICTEXT4;
        static const wxWindowID ID_RADIOBOX1;
        static const wxWindowID ID_RADIOBOX2;
        static const wxWindowID ID_STATICLINE2;
        static const wxWindowID ID_RADIOBOX3;
        static const wxWindowID ID_BUTTON2;
        static const wxWindowID ID_STATICLINE3;
        static const wxWindowID ID_BUTTON1;
        static const wxWindowID ID_CANCEL;
        //*)

    private:

        //(*Handlers(Set_station)
        void OnButton3Click(wxCommandEvent& event);
        void OnButton4Click(wxCommandEvent& event);
        //*)
        Advanced_station* AdvancedStationDialog;

        DECLARE_EVENT_TABLE()
};

#endif
