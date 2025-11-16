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
#include "mDriver.h"
#include "dc2.h"

class dc2mApp : public wxApp
{
  public:
    virtual bool OnInit();
    void Refresh();

    C_Chat* deltac;
    mDriver* ModbusCh1;
    mDriver* ModbusCh2;
    mDriver* ModbusCh3;

  private:
    int32_t p_status_ch1;
    int32_t p_status_ch2;
    int32_t p_status_ch3;

    dc2mFrame* Frame;

};

#endif // DC2MAPP_H
