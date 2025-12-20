#ifndef QRCODEDIALOG_H
#define QRCODEDIALOG_H

//(*Headers(QrcodeDialog)
#include <wx/dialog.h>
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
    //*)

  protected:

    //(*Identifiers(QrcodeDialog)
    //*)

  private:

    //(*Handlers(QrcodeDialog)
    void OnPaint(wxPaintEvent& event);
    void OnQRpanelPaint(wxPaintEvent& event);
    //*)
    wxBitmapBundle* bm;

    DECLARE_EVENT_TABLE()
};

#endif
