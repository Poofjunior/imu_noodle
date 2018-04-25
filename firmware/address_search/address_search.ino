/*
 * \project single_board_bringup.ino
 * \author Joshua Vasquez
 */

#include "pinouts.h"
#include <bno055.h>
#include <i2c_wrapper.h>

BNO055 bno055;

void setup(){
    Serial.begin(9600);// baud rate irrelevant for usb serial.
    delay(3000);
    Serial.print("Git hash: ");
    Serial.println(GIT_HASH);
    Serial.print("Git branch: ");
    Serial.println(GIT_BRANCH);
    Serial.print("Upload Date: ");
    Serial.println(UPLOAD_DATE);
    i2cInit();
    delay(1000);
    for (uint8_t address = 0x1F; address < 120; ++address)
    {
        if(!bno055.init(BNO055::NDOF, (BNO055::address_t)address))
        {
            Serial.print("BNO055 at ");
            Serial.print("0x");
            Serial.print(address, HEX);
            Serial.println(" init succeeded.");
            break;
        }
        else
        {
            Serial.print("BNO055 at ");
            Serial.print("0x");
            Serial.print(address, HEX);
            Serial.println(" init failed.");
        }
    }
}

void loop(void)
{
}
