#include <SPI.h>
#include "mcp_can.h"


// Pins: 
//D2: INT
//D10(Configurable): CS
//D11: MOSI
//D12: MISO
//D13: SCK

//PWR: 5v
//GND: GND


MCP_CAN CAN(10);

INT32U canId = 0x000;

unsigned char len = 0;
unsigned char buf[8];
char str[20];


void setup()
{
    Serial.begin(38400);

START_INIT:

    if(CAN_OK == CAN.begin(CAN_125KBPS))
    {
        Serial.println("Initialized successfully");
    }
    else
    {
        Serial.println("Initializing is failed");
        Serial.println("Reloading...");
        delay(100);
        goto START_INIT;
    }
}


void loop()
{
    if(CAN_MSGAVAIL == CAN.checkReceive()) 
    {
        CAN.readMsgBuf(&len, buf);
        canId = CAN.getCanId();
        
//        Serial.print((String)buf);
//        Serial.print("<");Serial.print(canId);Serial.print(",");
        for(int i = 0; i<len; i++)
        {
            Serial.print((char)buf[i]);
        }
//        Serial.print(">");
        Serial.println();
    }
}
