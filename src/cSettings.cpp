#include "cSettings.h"


C_Settings settings;


C_Settings::C_Settings()
{
  //ctor

}

void C_Settings::LoadValue() {
  dconfig=new wxConfig("dc2m","Andrea202511");

  dconfig->Read(wxT("/language"),&Language);
  dconfig->Read(wxT("/ST1/enabled"),&station_enable);
  dconfig->Read(wxT("/ST1/alias"),&station_name);
  dconfig->Read(wxT("/ST1/location"),&station_loc);
  dconfig->Read(wxT("/ST1/StLogLevel"),&StLogLevel);
  dconfig->Read(wxT("/ST1/ChLogLevel"),&ChLogLevel);


	dconfig->Read(wxT("/CH1/enabled"),&ch1.enable);
  dconfig->Read(wxT("/CH1/alias"),&ch1.name);
	dconfig->Read(wxT("/CH1/run"),&ch1.run);
	dconfig->Read(wxT("/CH1/address_p1"),&ch1.ipp1);
	dconfig->Read(wxT("/CH1/address_p2"),&ch1.ipp2);
	dconfig->Read(wxT("/CH1/address_p3"),&ch1.ipp3);
	dconfig->Read(wxT("/CH1/address_p4"),&ch1.ipp4);
	dconfig->Read(wxT("/CH1/port"),&ch1.port);
	dconfig->Read(wxT("/CH1/starttx"),&ch1.starttx);
	dconfig->Read(wxT("/CH1/startrx"),&ch1.startrx);
	dconfig->Read(wxT("/CH1/lengthtx"),&ch1.lengthtx);
	dconfig->Read(wxT("/CH1/lengthrx"),&ch1.lengthrx);
	dconfig->Read(wxT("/CH1/filemsg"),&ch1.filemsg);
	dconfig->Read(wxT("/CH1/trefresh"),&ch1.trefresh);
	dconfig->Read(wxT("/CH1/byteord"),&ch1.byteord);
	dconfig->Read(wxT("/CH1/charord"),&ch1.charord);


	dconfig->Read(wxT("/CH2/enabled"),&ch2.enable);
	dconfig->Read(wxT("/CH2/alias"),&ch2.name);
	dconfig->Read(wxT("/CH2/run"),&ch2.run);
	dconfig->Read(wxT("/CH2/address_p1"),&ch2.ipp1);
	dconfig->Read(wxT("/CH2/address_p2"),&ch2.ipp2);
	dconfig->Read(wxT("/CH2/address_p3"),&ch2.ipp3);
	dconfig->Read(wxT("/CH2/address_p4"),&ch2.ipp4);
	dconfig->Read(wxT("/CH2/port"),&ch2.port);
	dconfig->Read(wxT("/CH2/starttx"),&ch2.starttx);
	dconfig->Read(wxT("/CH2/startrx"),&ch2.startrx);
	dconfig->Read(wxT("/CH2/lengthtx"),&ch2.lengthtx);
	dconfig->Read(wxT("/CH2/lengthrx"),&ch2.lengthrx);
	dconfig->Read(wxT("/CH2/filemsg"),&ch2.filemsg);
	dconfig->Read(wxT("/CH2/trefresh"),&ch2.trefresh);
	dconfig->Read(wxT("/CH2/byteord"),&ch2.byteord);
	dconfig->Read(wxT("/CH2/charord"),&ch2.charord);

	dconfig->Read(wxT("/CH3/enabled"),&ch3.enable);
	dconfig->Read(wxT("/CH3/alias"),&ch3.name);
	dconfig->Read(wxT("/CH3/run"),&ch3.run);
	dconfig->Read(wxT("/CH3/address_p1"),&ch3.ipp1);
	dconfig->Read(wxT("/CH3/address_p2"),&ch3.ipp2);
	dconfig->Read(wxT("/CH3/address_p3"),&ch3.ipp3);
	dconfig->Read(wxT("/CH3/address_p4"),&ch3.ipp4);
	dconfig->Read(wxT("/CH3/port"),&ch3.port);
	dconfig->Read(wxT("/CH3/starttx"),&ch3.starttx);
	dconfig->Read(wxT("/CH3/startrx"),&ch3.startrx);
	dconfig->Read(wxT("/CH3/lengthtx"),&ch3.lengthtx);
	dconfig->Read(wxT("/CH3/lengthrx"),&ch3.lengthrx);
	dconfig->Read(wxT("/CH3/filemsg"),&ch3.filemsg);
	dconfig->Read(wxT("/CH3/trefresh"),&ch3.trefresh);
	dconfig->Read(wxT("/CH3/byteord"),&ch3.byteord);
	dconfig->Read(wxT("/CH3/charord"),&ch3.charord);

  MainTextArea=NULL;
}

C_Settings::~C_Settings()
{


}

void C_Settings::SaveValue() {

  dconfig->Write(wxT("/language"),Language);
  dconfig->Write(wxT("/ST1/enabled"),station_enable);
  dconfig->Write(wxT("/ST1/alias"),station_name);
  dconfig->Write(wxT("/ST1/location"),station_loc);
  dconfig->Write(wxT("/ST1/StLogLevel"),StLogLevel);
  dconfig->Write(wxT("/ST1/ChLogLevel"),ChLogLevel);

	dconfig->Write(wxT("/CH1/enabled"),ch1.enable);
	dconfig->Write(wxT("/CH1/alias"),ch1.name);
	dconfig->Write(wxT("/CH1/run"),ch1.run);
	dconfig->Write(wxT("/CH1/address_p1"),ch1.ipp1);
	dconfig->Write(wxT("/CH1/address_p2"),ch1.ipp2);
	dconfig->Write(wxT("/CH1/address_p3"),ch1.ipp3);
	dconfig->Write(wxT("/CH1/address_p4"),ch1.ipp4);
	dconfig->Write(wxT("/CH1/port"),ch1.port);
	dconfig->Write(wxT("/CH1/starttx"),ch1.starttx);
	dconfig->Write(wxT("/CH1/startrx"),ch1.startrx);
	dconfig->Write(wxT("/CH1/lengthtx"),ch1.lengthtx);
	dconfig->Write(wxT("/CH1/lengthrx"),ch1.lengthrx);
	dconfig->Write(wxT("/CH1/filemsg"),ch1.filemsg);
	dconfig->Write(wxT("/CH1/trefresh"),ch1.trefresh);
	dconfig->Write(wxT("/CH1/byteord"),ch1.byteord);
	dconfig->Write(wxT("/CH1/charord"),ch1.charord);

	dconfig->Write(wxT("/CH2/enabled"),ch2.enable);
	dconfig->Write(wxT("/CH2/alias"),ch2.name);
	dconfig->Write(wxT("/CH2/run"),ch2.run);
	dconfig->Write(wxT("/CH2/address_p1"),ch2.ipp1);
	dconfig->Write(wxT("/CH2/address_p2"),ch2.ipp2);
	dconfig->Write(wxT("/CH2/address_p3"),ch2.ipp3);
	dconfig->Write(wxT("/CH2/address_p4"),ch2.ipp4);
	dconfig->Write(wxT("/CH2/port"),ch2.port);
	dconfig->Write(wxT("/CH2/starttx"),ch2.starttx);
	dconfig->Write(wxT("/CH2/startrx"),ch2.startrx);
	dconfig->Write(wxT("/CH2/lengthtx"),ch2.lengthtx);
	dconfig->Write(wxT("/CH2/lengthrx"),ch2.lengthrx);
	dconfig->Write(wxT("/CH2/filemsg"),ch2.filemsg);
	dconfig->Write(wxT("/CH2/trefresh"),ch2.trefresh);
	dconfig->Write(wxT("/CH2/byteord"),ch2.byteord);
	dconfig->Write(wxT("/CH2/charord"),ch2.charord);

	dconfig->Write(wxT("/CH3/enabled"),ch3.enable);
	dconfig->Write(wxT("/CH3/alias"),ch3.name);
	dconfig->Write(wxT("/CH3/run"),ch3.run);
	dconfig->Write(wxT("/CH3/address_p1"),ch3.ipp1);
	dconfig->Write(wxT("/CH3/address_p2"),ch3.ipp2);
	dconfig->Write(wxT("/CH3/address_p3"),ch3.ipp3);
	dconfig->Write(wxT("/CH3/address_p4"),ch3.ipp4);
	dconfig->Write(wxT("/CH3/port"),ch3.port);
	dconfig->Write(wxT("/CH3/starttx"),ch3.starttx);
	dconfig->Write(wxT("/CH3/startrx"),ch3.startrx);
	dconfig->Write(wxT("/CH3/lengthtx"),ch3.lengthtx);
	dconfig->Write(wxT("/CH3/lengthrx"),ch3.lengthrx);
	dconfig->Write(wxT("/CH3/filemsg"),ch3.filemsg);
	dconfig->Write(wxT("/CH3/trefresh"),ch3.trefresh);
	dconfig->Write(wxT("/CH3/byteord"),ch3.byteord);
	dconfig->Write(wxT("/CH3/charord"),ch3.charord);
	dconfig->Flush();

}

void C_Settings::Chx2Chn(int n)
{
  if (n==1) {
    ch1=chx;
  }
  if (n==2) {
    ch2=chx;
  }
  if (n==3) {
    ch3=chx;
  }
  SaveValue();
}
void C_Settings::Chn2Chx(int n)
{
  if (n==1) {
    chx=ch1;
  }
  if (n==2) {
    chx=ch2;
  }
  if (n==3) {
    chx=ch3;
  }
}
void C_Settings::Chn2Chw(int n)
{
  if (n==1) {
    chw=ch1;
  }
  if (n==2) {
    chw=ch2;
  }
  if (n==3) {
    chw=ch3;
  }
}


