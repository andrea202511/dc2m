#ifndef CSETTINGS_H
#define CSETTINGS_H

#include <wx/string.h>
#include <wx/textctrl.h>


#include <wx/valtext.h>
#include <wx/valgen.h>
#include <wx/config.h>
#include <wx/valnum.h>
#include <stdint.h>

class dc2mFrame;

struct channel_set {
  wxString name;
  bool enable;
  int32_t ipp1;
  int32_t ipp2;
  int32_t ipp3;
  int32_t ipp4;
  int32_t port;
  int32_t starttx;
  int32_t startrx;
  int32_t lengthtx;
  int32_t lengthrx;
  int32_t trefresh;
  int32_t byteord;
  int32_t charord;
};

class C_Settings
{
  public:
    C_Settings();
    virtual ~C_Settings();

    int LogLevel;

   // bool reinit;
    void LoadValue();
    void SaveValue();
    int lastCh;

    void Chx2Chn(int n);
    void Chn2Chx(int n);

    wxString chat_server;
    wxString station_name;
    wxString station_loc;

    channel_set chx;
    channel_set ch1;
    channel_set ch2;
    channel_set ch3;

  protected:
    wxConfig* dconfig;

    wxTextCtrl* MainTextArea;
  private:
};


#endif // CSETTINGS_H
