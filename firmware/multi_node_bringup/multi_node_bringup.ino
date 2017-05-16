/*
 * \project multi_board_bringup.ino
 * \author Joshua Vasquez
 */

#include "pinouts.h"
#include <bno055.h>
#include <i2c_wrapper.h>

const uint8_t NUM_BNOS = 5;
BNO055 bno_array[NUM_BNOS];
uint8_t addresses[NUM_BNOS] = {0x2F, 0x2D, 0x2E, 0x2C, BNO055::ALTERNATE_ADDRESS};

void setup(){
    Serial.begin(9600);// baud rate irrelevant for usb serial.
    delay(3000);
    Serial.print("Git Hash: ");
    Serial.println(GIT_HASH);
    Serial.print("Git Branch: ");
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
    int16_t w, x, y, z;
    float QUAT_BITS_TO_FLOAT = 16384.0;
    for (uint8_t index = 0; index < NUM_BNOS; ++index)
    {
        heading = bno_array[index].readRawQuaternion(w, x, y, z);
        Serial.print(index);
        Serial.print(": ");
        Serial.print("w: ");
        Serial.print(w/QUAT_BITS_TO_FLOAT);
        Serial.print(" x: ");
        Serial.print(x/QUAT_BITS_TO_FLOAT);
        Serial.print(" y: ");
        Serial.print(y/QUAT_BITS_TO_FLOAT);
        Serial.print(" z: ");
        Serial.println(z/QUAT_BITS_TO_FLOAT);
    }
    Serial.println();
    delay(50);
}
