#include "cSettings.h"


C_Settings settings;


C_Settings::C_Settings()
{
  //ctor

}

void C_Settings::LoadValue() {
  dconfig=new wxConfig("dc2m","AndreaF");

  dconfig->Read(wxT("/StationName"),&station_name);
  dconfig->Read(wxT("/StationLoc"),&station_loc);
	dconfig->Read(wxT("/CH1_alias"),&ch1.name);
	dconfig->Read(wxT("/CH1_enabled"),&ch1.enable);
	dconfig->Read(wxT("/CH1_address_p1"),&ch1.ipp1);
	dconfig->Read(wxT("/CH1_address_p2"),&ch1.ipp2);
	dconfig->Read(wxT("/CH1_address_p3"),&ch1.ipp3);
	dconfig->Read(wxT("/CH1_address_p4"),&ch1.ipp4);
	dconfig->Read(wxT("/CH1_port"),&ch1.port);
	dconfig->Read(wxT("/CH1_starttx"),&ch1.starttx);
	dconfig->Read(wxT("/CH1_startrx"),&ch1.startrx);
	dconfig->Read(wxT("/CH1_lengthtx"),&ch1.lengthtx);
	dconfig->Read(wxT("/CH1_lengthrx"),&ch1.lengthrx);
	dconfig->Read(wxT("/CH1_trefresh"),&ch1.trefresh);
	dconfig->Read(wxT("/CH1_byteord"),&ch1.byteord);
	dconfig->Read(wxT("/CH1_charord"),&ch1.charord);


	dconfig->Read(wxT("/CH2_alias"),&ch2.name);
	dconfig->Read(wxT("/CH2_enabled"),&ch2.enable);
	dconfig->Read(wxT("/CH2_address_p1"),&ch2.ipp1);
	dconfig->Read(wxT("/CH2_address_p2"),&ch2.ipp2);
	dconfig->Read(wxT("/CH2_address_p3"),&ch2.ipp3);
	dconfig->Read(wxT("/CH2_address_p4"),&ch2.ipp4);
	dconfig->Read(wxT("/CH2_port"),&ch2.port);
	dconfig->Read(wxT("/CH2_starttx"),&ch2.starttx);
	dconfig->Read(wxT("/CH2_startrx"),&ch2.startrx);
	dconfig->Read(wxT("/CH2_lengthtx"),&ch2.lengthtx);
	dconfig->Read(wxT("/CH2_lengthrx"),&ch2.lengthrx);
	dconfig->Read(wxT("/CH2_trefresh"),&ch2.trefresh);
	dconfig->Read(wxT("/CH2_byteord"),&ch2.byteord);
	dconfig->Read(wxT("/CH2_charord"),&ch2.charord);

	dconfig->Read(wxT("/CH3_alias"),&ch3.name);
	dconfig->Read(wxT("/CH3_enabled"),&ch3.enable);
	dconfig->Read(wxT("/CH3_address_p1"),&ch3.ipp1);
	dconfig->Read(wxT("/CH3_address_p2"),&ch3.ipp2);
	dconfig->Read(wxT("/CH3_address_p3"),&ch3.ipp3);
	dconfig->Read(wxT("/CH3_address_p4"),&ch3.ipp4);
	dconfig->Read(wxT("/CH3_port"),&ch3.port);
	dconfig->Read(wxT("/CH3_starttx"),&ch3.starttx);
	dconfig->Read(wxT("/CH3_startrx"),&ch3.startrx);
	dconfig->Read(wxT("/CH3_lengthtx"),&ch3.lengthtx);
	dconfig->Read(wxT("/CH3_lengthrx"),&ch3.lengthrx);
	dconfig->Read(wxT("/CH3_trefresh"),&ch3.trefresh);
	dconfig->Read(wxT("/CH3_byteord"),&ch3.byteord);
	dconfig->Read(wxT("/CH3_charord"),&ch3.charord);
  LogLevel=3;
  MainTextArea=NULL;
}

C_Settings::~C_Settings()
{


}

void C_Settings::SaveValue() {

  dconfig->Write(wxT("/StationName"),station_name);
  dconfig->Write(wxT("/StationLoc"),station_loc);

	dconfig->Write(wxT("/CH1_alias"),ch1.name);
	dconfig->Write(wxT("/CH1_enabled"),ch1.enable);
	dconfig->Write(wxT("/CH1_address_p1"),ch1.ipp1);
	dconfig->Write(wxT("/CH1_address_p2"),ch1.ipp2);
	dconfig->Write(wxT("/CH1_address_p3"),ch1.ipp3);
	dconfig->Write(wxT("/CH1_address_p4"),ch1.ipp4);
	dconfig->Write(wxT("/CH1_port"),ch1.port);
	dconfig->Write(wxT("/CH1_starttx"),ch1.starttx);
	dconfig->Write(wxT("/CH1_startrx"),ch1.startrx);
	dconfig->Write(wxT("/CH1_lengthtx"),ch1.lengthtx);
	dconfig->Write(wxT("/CH1_lengthrx"),ch1.lengthrx);
	dconfig->Write(wxT("/CH1_trefresh"),ch1.trefresh);
	dconfig->Write(wxT("/CH1_byteord"),ch1.byteord);
	dconfig->Write(wxT("/CH1_charord"),ch1.charord);

	dconfig->Write(wxT("/CH2_alias"),ch2.name);
	dconfig->Write(wxT("/CH2_enabled"),ch2.enable);
	dconfig->Write(wxT("/CH2_address_p1"),ch2.ipp1);
	dconfig->Write(wxT("/CH2_address_p2"),ch2.ipp2);
	dconfig->Write(wxT("/CH2_address_p3"),ch2.ipp3);
	dconfig->Write(wxT("/CH2_address_p4"),ch2.ipp4);
	dconfig->Write(wxT("/CH2_port"),ch2.port);
	dconfig->Write(wxT("/CH2_starttx"),ch2.starttx);
	dconfig->Write(wxT("/CH2_startrx"),ch2.startrx);
	dconfig->Write(wxT("/CH2_lengthtx"),ch2.lengthtx);
	dconfig->Write(wxT("/CH2_lengthrx"),ch2.lengthrx);
	dconfig->Write(wxT("/CH2_trefresh"),ch2.trefresh);
	dconfig->Write(wxT("/CH2_byteord"),ch2.byteord);
	dconfig->Write(wxT("/CH2_charord"),ch2.charord);

	dconfig->Write(wxT("/CH3_alias"),ch3.name);
	dconfig->Write(wxT("/CH3_enabled"),ch3.enable);
	dconfig->Write(wxT("/CH3_address_p1"),ch3.ipp1);
	dconfig->Write(wxT("/CH3_address_p2"),ch3.ipp2);
	dconfig->Write(wxT("/CH3_address_p3"),ch3.ipp3);
	dconfig->Write(wxT("/CH3_address_p4"),ch3.ipp4);
	dconfig->Write(wxT("/CH3_port"),ch3.port);
	dconfig->Write(wxT("/CH3_starttx"),ch3.starttx);
	dconfig->Write(wxT("/CH3_startrx"),ch3.startrx);
	dconfig->Write(wxT("/CH3_lengthtx"),ch3.lengthtx);
	dconfig->Write(wxT("/CH3_lengthrx"),ch3.lengthrx);
	dconfig->Write(wxT("/CH3_trefresh"),ch3.trefresh);
	dconfig->Write(wxT("/CH3_byteord"),ch3.byteord);
	dconfig->Write(wxT("/CH3_charord"),ch3.charord);
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


