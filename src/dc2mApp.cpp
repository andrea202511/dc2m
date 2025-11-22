/***************************************************************
 * Name:      dc2mApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Andrea Fabbri ()
 * Created:   2025-09-27
 * Copyright: Andrea Fabbri ()
 * License:
 **************************************************************/

#include "dc2mApp.h"

//(*AppHeaders
#include "dc2mMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(dc2mApp);


bool dc2mApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
      Frame = new dc2mFrame(0);
      Frame->Show();
      SetTopWindow(Frame);
    }
    //*)
    p_status_ch1=-99;
    p_status_ch2=-99;
    p_status_ch3=-99;

    Deltac=new cDriver(Frame->GetEventHandler());
    Deltac->init();

    ModbusCh1=new mDriver(1);
    ModbusCh2=new mDriver(2);;
    ModbusCh3=new mDriver(3);;



    return wxsOK;

}

void dc2mApp::Refresh(void)
{
  int32_t sc;

  sc=ModbusCh1->Refresh();
  if (sc!=p_status_ch1) {
    p_status_ch1=sc;
    Frame->DisplayStatus(1,sc);
  }

  sc=ModbusCh2->Refresh();
  if (sc!=p_status_ch2) {
    p_status_ch2=sc;
    Frame->DisplayStatus(2,sc);
  }


  sc=ModbusCh3->Refresh();
  if (sc!=p_status_ch3) {
    p_status_ch3=sc;
    Frame->DisplayStatus(3,sc);
  }

  sc=Deltac->Refresh();

}
