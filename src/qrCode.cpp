#include "qrCode.h"

//(*InternalHeaders(QrcodeDialog)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(QrcodeDialog)
//*)

BEGIN_EVENT_TABLE(QrcodeDialog,wxDialog)
  //(*EventTable(QrcodeDialog)
  //*)
END_EVENT_TABLE()

QrcodeDialog::QrcodeDialog(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
  //(*Initialize(QrcodeDialog)
  Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE|wxBORDER_STATIC, _T("id"));
  SetClientSize(wxSize(210,210));
  Move(wxDefaultPosition);
  SetMinSize(wxSize(210,210));
  SetMaxSize(wxSize(210,210));

  Connect(wxEVT_PAINT, (wxObjectEventFunction)&QrcodeDialog::OnPaint);
  //*)
}

QrcodeDialog::~QrcodeDialog()
{
  //(*Destroy(QrcodeDialog)
  //*)
}


void QrcodeDialog::OnPaint(wxPaintEvent& event)
{

  wxPaintDC dc(this);
  dc.DrawBitmap(bm->GetBitmapFor(this),1,1,false);

}

void QrcodeDialog::OnQRpanelPaint(wxPaintEvent& event)
{
}
