/***************************************************************
 * Name:      dc2mMain.h
 * Purpose:   Defines Application Frame
 * Author:    Andrea Fabbri ()
 * Created:   2025-09-27
 * Copyright: Andrea Fabbri ()
 * License:
 **************************************************************/



#ifndef DC2MMAIN_H
#define DC2MMAIN_H

//(*Headers(dc2mFrame)
#include <wx/frame.h>
#include <wx/menu.h>
#include <wx/sizer.h>
#include <wx/statusbr.h>
#include <wx/textctrl.h>
#include <wx/timer.h>
//*)

#include "cDriver.h"
#include "Set_channel.h"
#include "Set_station.h"
#include "cSettings.h"
#include "QrcodeDialog.h"
#include "mDriver.h"
#include "About.h"

extern C_Settings settings;


class dc2mFrame: public wxFrame
{
    public:

        dc2mFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~dc2mFrame();
        void DisplayStatus(uint16_t field,int32_t status);
 //       C_Chat* deltac;

    private:

        //(*Handlers(dc2mFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnMenuQrcodeShow(wxCommandEvent& event);
        void OnMenuItemChannel1(wxCommandEvent& event);
        void OnMenuItemChannel2(wxCommandEvent& event);
        void OnMenuItemChannel3(wxCommandEvent& event);
        void OnTimer1Trigger(wxTimerEvent& event);
        void OnMenuItem4Selected(wxCommandEvent& event);
        //*)

        //(*Identifiers(dc2mFrame)
        static const wxWindowID ID_TEXTCTRL1;
        static const wxWindowID ID_MENUITEM2;
        static const wxWindowID ID_MENUITEM1;
        static const wxWindowID ID_MENUITEM3;
        static const wxWindowID ID_MENUITEM4;
        static const wxWindowID ID_MENUITEM5;
        static const wxWindowID idMenuQuit;
        static const wxWindowID idMenuAbout;
        static const wxWindowID ID_STATUSBAR1;
        static const wxWindowID ID_TIMER1;
        //*)

        //(*Declarations(dc2mFrame)
        wxMenuItem* MenuItem3;
        wxMenuItem* MenuItem4;
        wxMenuItem* MenuItem5;
        wxMenuItem* MenuItem6;
        wxMenuItem* MenuItem7;
        wxStatusBar* StatusBar1;
        wxTextCtrl* LogText;
        wxTimer Timer1;
        //*)



        void DoMyEvent(C_ChatEvent &event);
        Set_channel* ChannelSettingDialog;
        Set_station* StationSettingDialog;
        About* AboutDialog;
        QrcodeDialog* QRDialog;


        DECLARE_EVENT_TABLE()
};

#endif // DC2MMAIN_H
