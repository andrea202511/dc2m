#ifndef SET_STATION_H
#define SET_STATION_H

//(*Headers(Set_station)
#include <wx/button.h>
#include <wx/dialog.h>
#include <wx/sizer.h>
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
        wxStaticText* StaticText1;
        wxTextCtrl* TextCtrl1;
        //*)

    protected:

        //(*Identifiers(Set_station)
        static const wxWindowID ID_STATICTEXT1;
        static const wxWindowID ID_TEXTCTRL1;
        static const wxWindowID ID_BUTTON1;
        static const wxWindowID ID_BUTTON2;
        static const wxWindowID ID_BUTTON3;
        //*)

    private:

        //(*Handlers(Set_station)
        //*)

        DECLARE_EVENT_TABLE()
};

#endif
