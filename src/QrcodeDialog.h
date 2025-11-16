#ifndef QRCODEDIALOG_H
#define QRCODEDIALOG_H

//(*Headers(QrcodeDialog)
#include <wx/dialog.h>
#include <wx/panel.h>
#include <wx/sizer.h>
//*)

#include <wx/bmpbndl.h>
#include <wx/dcclient.h>



class QrcodeDialog: public wxDialog
{
  public:

    QrcodeDialog(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
    virtual ~QrcodeDialog();
    void SetBitmap(wxBitmapBundle* bmp) {
      bm=bmp;
    }

    //(*Declarations(QrcodeDialog)
    wxPanel* QRpanel;
    //*)

  protected:

    //(*Identifiers(QrcodeDialog)
    static const wxWindowID ID_PANEL1;
    //*)

  private:

    //(*Handlers(QrcodeDialog)
    void OnPaint(wxPaintEvent& event);
    //*)
    wxBitmapBundle* bm;

    DECLARE_EVENT_TABLE()
};

#endif
