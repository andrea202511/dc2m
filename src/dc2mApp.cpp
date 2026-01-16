/***************************************************************
 * Name:      dc2mApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Andrea Fabbri ()
 * Created:   2025-09-27
 * Copyright: Andrea Fabbri ()
 * License:
 **************************************************************/

#include "dc2mApp.h"
wxHelpController* m_helpController;

//(*AppHeaders
#include "dc2mMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(dc2mApp);

void dc2mApp::ToLog(uint16_t modo,wxString str)
{
  Frame->AddToLog(modo,str);
}

bool dc2mApp::OnInit()
{
  bool bb;
  m_locale=new wxLocale();
  settings.LoadValue();

  if (settings.Language==1)
    bb=m_locale->Init(wxLANGUAGE_ITALIAN);
  else
    bb=m_locale->Init(wxLANGUAGE_ENGLISH);

  m_locale->AddCatalogLookupPathPrefix("/usr/share/locale");
  m_locale->AddCatalogLookupPathPrefix(".");

  if (bb)
    bb=m_locale->AddCatalog(wxT("dc2m"));


  //Help
  wxFileSystem::AddHandler(new wxZipFSHandler);
  m_helpController= new wxHelpController;
#if defined(__WXMSW__)
  if (settings.Language==1)
    m_helpController->Initialize("./it/dc2m");
  else
    m_helpController->Initialize("./en/dc2m");
#else
  if (settings.Language==1)
    m_helpController->Initialize("/home/andrea/projects/dc2m/src/it/dc2m_it"); //  /usr/share/dc2m/help/dc2m_it");
  else
    m_helpController->Initialize("/usr/share/dc2m/help/dc2m_en");
#endif // defined

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

  st1_enabled=settings.station_enable;
  ch1_enabled=settings.ch1.enable;
  ch2_enabled=settings.ch2.enable;
  ch3_enabled=settings.ch3.enable;

    Frame->AddToLog(0,"Starting dc2m...\n");

    // #1
    if(ch1_enabled) {
      ModbusCh1=new mDriver(1);
      ModbusCh1->Init();
    }
    else
      Frame->AddToLog(0,"Channel #1 handling: skipped\n");

    //#2
    if(ch2_enabled) {
      ModbusCh2=new mDriver(2);
      ModbusCh2->Init();
    }
    else
      Frame->AddToLog(0,"Channel #2 handling: skipped\n");

    //#3
    if(ch3_enabled) {
      ModbusCh3=new mDriver(3);
      ModbusCh3->Init();
   }
    else
      Frame->AddToLog(0,"Channel #3 handling: skipped\n");

    //$1
    if (st1_enabled) {
      Deltac=new cDriver(Frame->GetEventHandler());
      Deltac->init();
    }
    else
      Frame->AddToLog(2,"Station $1 handling: skipped\n");

    return wxsOK;

}

void dc2mApp::Refresh(void)
{
  int32_t sc;
  if (ch1_enabled)
    sc=ModbusCh1->Refresh();
  else
    sc=5;
  if (sc!=p_status_ch1) {
    p_status_ch1=sc;
    Frame->DisplayStatus(1,sc);
  }

  if (ch2_enabled)
    sc=ModbusCh2->Refresh();
  else
    sc=5;
  if (sc!=p_status_ch2) {
    p_status_ch2=sc;
    Frame->DisplayStatus(2,sc);
  }

   if (ch3_enabled)
    sc=ModbusCh3->Refresh();
  else
    sc=5;
  if (sc!=p_status_ch3) {
    p_status_ch3=sc;
    Frame->DisplayStatus(3,sc);
  }

  if (st1_enabled)
    sc=Deltac->Refresh();
  else
    sc=5;
  if (sc!=p_status_st1) {
    p_status_st1=sc;
    Frame->DisplayStatus(0,sc);
  }

}
