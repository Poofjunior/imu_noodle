/*
 * \project single_board_bringup.ino
 * \author Joshua Vasquez
 */

#include "pinouts.h"
#include <bno055.h>
#include <i2c_wrapper.h>

BNO055 bno055;
BNO055::address_t address = (BNO055::address_t)0x22;

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
    if(!bno055.init(BNO055::NDOF, address))
        Serial.println("BNO055 init succeeded.");
    else
    {
        Serial.print("BNO055 at ");
        Serial.print("0x");
        Serial.print(address, HEX);
        Serial.println(" init failed.");
    }
}

void loop(void)
{
    float heading = bno055.readEulHead()/900.0;
    Serial.println(heading);
    delay(50);
}
