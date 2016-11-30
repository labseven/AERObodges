#include <mcp_can.h>
#include <mcp_can_dfs.h>

#include <SPI.h>
#include "mcp_can.h"

INT32U canId = 0x000;

unsigned char len = 0;
unsigned char buf[8];
char str[20];

MCP_CAN CAN(10);

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
    canId = CAN.getCanId();
    unsigned char* buf = "test";
    CAN.sendMsgBuf(canId,0,5,buf);
    if(CAN.checkError())
    {
      
    }
}
