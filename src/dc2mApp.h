/***************************************************************
 * Name:      dc2mApp.h
 * Purpose:   Defines Application Class
 * Author:    Andrea Fabbri ()
 * Created:   2025-09-27
 * Copyright: Andrea Fabbri ()
 * License:
 **************************************************************/

#ifndef DC2MAPP_H
#define DC2MAPP_H

#include <wx/app.h>
#define wxUSE_WXHTML_HELP 1
#include <wx/help.h>
#include <wx/fs_zip.h>
#include "mDriver.h"
#include "cDriver.h"

class dc2mApp : public wxApp
{
  public:
    virtual bool OnInit();
    void Refresh();
    void ToLog(uint16_t mode,wxString msg);

    cDriver* Deltac;
    mDriver* ModbusCh1;
    mDriver* ModbusCh2;
    mDriver* ModbusCh3;


  private:
    wxLocale* m_locale;
    int32_t p_status_st1;
    int32_t p_status_ch1;
    int32_t p_status_ch2;
    int32_t p_status_ch3;

    bool st1_enabled=false;
    bool ch1_enabled=false;
    bool ch2_enabled=false;
    bool ch3_enabled=false;

    dc2mFrame* Frame;
};

#endif // DC2MAPP_H
