#ifndef MDRIVER_H
#define MDRIVER_H

#include <wx/string.h>

#include "cDriver.h"
#include "modbus.h"
#include "cSettings.h"

extern C_Settings settings;

enum {STATE_OFF=0, STATE_OFFLINE, STATE_ONLINE};
enum {NO_ERROR=0, CONNECT_ERROR=-1, READ_ERROR=-2, WRITE_ERROR=-3 };

class mDriver
{
    public:
        mDriver(int32_t ch);
        virtual ~mDriver();

        void Connect(void);
        void Disconnect(void);
        int32_t Refresh(void);
        void WriteRegisters(uint16_t reg,uint16_t num, uint16_t* val);
        void ReadRegisters(uint16_t reg, uint16_t num, uint16_t* val);

        int err;
        int GetStatus();

        wxString sendmsg;
        uint32_t sendest;
        uint16_t sendcod;

        wxString recvmsg;
        uint32_t recvrec;
        uint16_t recvcod;
        bool to_dc();
        bool init;
     //   bool rx_free(){return buffer_rx[0]==0;}
        bool from_dc(wxString msg, int chat_id);

    protected:

    private:
        modbus* comm=NULL;
        int32_t channel;
        channel_set cs;
        int32_t error=0;
        bool connected=false;
        int32_t restart=0;

        int32_t tick;
        uint16_t last_cod_tx;
        uint16_t last_cod_rx;


        uint16_t* buffer_tx;  //from dc2m to device
        uint16_t* buffer_rx;  //from device to dc2m

        int32_t msg_par[10];

};

/*
#1 codice parametro parametro parametro
or
ABCDEF generic message


RX

0001 Sender ID
0002 Code 16 bit unsigned 0=message
0003 AB or first parameter
0004 CD or second parameter
0005 EF ...
0006 GH ...
...

TX
0001 Recipient ID
0002 Code 16 bit unsigned
0003 AB
0004 CD
0005 EF
0006 GH
...
*/

#endif // MDRIVER_H
