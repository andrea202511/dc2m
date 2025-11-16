#include "QrcodeDialog.h"

//(*InternalHeaders(QrcodeDialog)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(QrcodeDialog)
const wxWindowID QrcodeDialog::ID_PANEL1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(QrcodeDialog,wxDialog)
  //(*EventTable(QrcodeDialog)
  //*)
END_EVENT_TABLE()

QrcodeDialog::QrcodeDialog(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
  //(*Initialize(QrcodeDialog)
  wxBoxSizer* BoxSizer1;

  Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE|wxBORDER_STATIC, _T("id"));
  SetClientSize(wxSize(200,200));
  Move(wxDefaultPosition);
  SetMinSize(wxSize(200,200));
  SetMaxSize(wxSize(400,400));
  BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
  QRpanel = new wxPanel(this, ID_PANEL1, wxDefaultPosition, wxSize(200,200), wxTAB_TRAVERSAL, _T("ID_PANEL1"));
  BoxSizer1->Add(QRpanel, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxSHAPED, 5);
  SetSizer(BoxSizer1);
  Layout();

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
