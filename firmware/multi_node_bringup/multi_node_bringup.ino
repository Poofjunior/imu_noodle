/*
 * \project single_board_bringup.ino
 * \author Joshua Vasquez
 */

#include "pinouts.h"
#include <bno055.h>
#include <i2c_wrapper.h>

const uint8_t NUM_BNOS = 3;
BNO055 bno_array[NUM_BNOS];
uint8_t addresses[NUM_BNOS] = {BNO055::ALTERNATE_ADDRESS, 0x2E, 0x2F};

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
    for (uint8_t index = 0; index < NUM_BNOS; ++index)
    {
        if(!bno_array[index].init(BNO055::NDOF, (BNO055::address_t)addresses[index]))
        {
            Serial.print("BNO055 ");
            Serial.print(index);
            Serial.println(" init succeeded.");
        }
        else
        {
            Serial.print("BNO055 ");
            Serial.print(index);
            Serial.println(" init succeeded.");
        }
    }
    delay(2000);
}

void loop(void)
{
    float heading;
    for (uint8_t index = 0; index < NUM_BNOS; ++index)
    {
        heading = bno_array[index].readEulHead()/900.0;
        Serial.print(index);
        Serial.print(": ");
        Serial.println(heading);
    }
    Serial.println();
    delay(50);
}
