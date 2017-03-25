#include "bno055.h"

BNO055::BNO055():
    deviceAddress_(DEFAULT_ADDRESS),
    currentMode_(CONFIGMODE)
{
}

BNO055::~BNO055()
{
}

uint8_t BNO055::init(mode_t mode, address_t device_address)
{
    uint8_t status_byte = 0;
    deviceAddress_ = device_address;
/// Delay for the Power-On-Reset Time.
    delay(POWER_ON_RESET_TIME_MS);
    status_byte = setGyroUnits(RADIANS_PER_SECOND);
    if (status_byte) {return status_byte;}
    status_byte = setAccelUnits(METERS_PER_SQUARE_SECOND);
    if (status_byte) {return status_byte;}
    status_byte = setEulerAngleUnits(RADIANS);
    if (status_byte) {return status_byte;}
    status_byte = setTemperatureUnits(CELSIUS);
    if (status_byte) {return status_byte;}
/// Default power-up mode is CONFIGMODE; change here.
    status_byte = setMode(mode);
    return status_byte;
}

uint8_t BNO055::readRawData(uint8_t * const arrayPtr)
{
    return i2cRead(deviceAddress_, ACC_DATA_X_LSB, RAW_DATA_NUM_BYTES,
                   arrayPtr);
}

uint8_t BNO055::readCalibData(uint8_t * const arrayPtr)
{
    return i2cRead(deviceAddress_, ACC_OFFSET_X_LSB, CALIB_DATA_NUM_BYTES,
                   arrayPtr);
}

uint8_t BNO055::writeCalibData(uint8_t * const arrayPtr)
{
    return i2cWrite(deviceAddress_, ACC_OFFSET_X_LSB, CALIB_DATA_NUM_BYTES,
                    arrayPtr);
}

uint8_t BNO055::readCalibrationStatus(void)
{
    uint8_t value;
    i2cReadByte(deviceAddress_, CALIB_STAT, value);
    return value;
}

bool BNO055::isDeviceCalibrated(void)
{
    const uint8_t FULLY_CALIBRATED = 3;
    const uint8_t SYS_MASK = 0xC0;
    uint8_t calibrationStatus = (readCalibrationStatus() & SYS_MASK) >> 6;
    return (calibrationStatus == FULLY_CALIBRATED);
}

bool BNO055::isSensorCalibrated(sensor_t sensor)
{
    const uint8_t FULLY_CALIBRATED = 3;

    const uint8_t MAG_CALIB_STATUS_MASK = 0x03;
    const uint8_t MAG_CALIB_STATUS_BIT_OFFSET = 0;
    const uint8_t ACCEL_CALIB_STATUS_MASK = 0x0C;
    const uint8_t ACCEL_CALIB_STATUS_BIT_OFFSET = 2;
    const uint8_t GYRO_CALIB_STATUS_MASK = 0x30;
    const uint8_t GYRO_CALIB_STATUS_BIT_OFFSET = 4;

    uint8_t mask = 0;
    uint8_t bitOffset = 0;
    if (sensor == ACCELEROMETER)
    {
        mask = ACCEL_CALIB_STATUS_MASK;
        bitOffset = ACCEL_CALIB_STATUS_BIT_OFFSET;
    }
    if (sensor == MAGNETOMETER)
    {
        mask = MAG_CALIB_STATUS_MASK;
        bitOffset = MAG_CALIB_STATUS_BIT_OFFSET;
    }
    if (sensor == GYROSCOPE)
    {
        mask = GYRO_CALIB_STATUS_MASK;
        bitOffset = GYRO_CALIB_STATUS_BIT_OFFSET;
    }
    return (((readCalibrationStatus() & mask) >> bitOffset) == FULLY_CALIBRATED);
}

uint16_t BNO055::read16(uint8_t starting_address)
{
    const uint8_t num_bytes = 2;
    uint8_t temp_array[num_bytes];
    i2cRead(deviceAddress_, starting_address, num_bytes, temp_array);
    return (int16_t(temp_array[1]) << 8) | int16_t(temp_array[0]);
}

uint16_t BNO055::readRawAccel(axis_t axis)
{
    uint8_t baseAddress = ACC_DATA_X_LSB;
    // Register addresses follow the pattern X_LSB, X_MSB, ... Z_LSB, Z_MSB,
    // so incrementing by 2 will access the next axis
    return read16(baseAddress + (2 * axis));
}

uint16_t BNO055::readRawMag(axis_t axis)
{
    uint8_t baseAddress = MAG_DATA_X_LSB;
    // Register addresses follow the pattern X_LSB, X_MSB, ... Z_LSB, Z_MSB,
    // so incrementing by 2 will access the next axis
    return read16(baseAddress + (2 * axis));
}

uint16_t BNO055::readRawGyro(axis_t axis)
{
    uint8_t baseAddress = GYR_DATA_X_LSB;
    // Register addresses follow the pattern X_LSB, X_MSB, ... Z_LSB, Z_MSB,
    // so incrementing by 2 will access the next axis
    return read16(baseAddress + (2 * axis));
}

uint16_t BNO055::readEulHead(void)
{
    return read16(EUL_HEADING_LSB);
}

uint16_t BNO055::readLinearAccel(axis_t axis)
{
    uint8_t baseAddress = LIA_DATA_X_LSB;
    // Register addresses follow the pattern X_LSB, X_MSB, ... Z_LSB, Z_MSB,
    // so incrementing by 2 will access the next axis
    return read16(baseAddress + (2 * axis));
}

uint16_t BNO055::readGravityVector(axis_t axis)
{
    uint8_t baseAddress = GRV_DATA_X_LSB;
    // Register addresses follow the pattern X_LSB, X_MSB, ... Z_LSB, Z_MSB,
    // so incrementing by 2 will access the next axis
    return read16(baseAddress + (2 * axis));
}

uint8_t BNO055::readRawQuaternion(int16_t& w, int16_t& x, int16_t& y, int16_t& z)
{
    uint8_t quaternionNumBytes = 8;
    uint8_t quaternionData[quaternionNumBytes];
    uint8_t failure = i2cRead(deviceAddress_, QUA_DATA_W_LSB, quaternionNumBytes,
                              quaternionData);
    if (failure)
        return failure;
    w = (((int16_t)quaternionData[1]) << 8) | quaternionData[0];
    x = (((int16_t)quaternionData[3]) << 8) | quaternionData[2];
    y = (((int16_t)quaternionData[5]) << 8) | quaternionData[4];
    z = (((int16_t)quaternionData[7]) << 8) | quaternionData[6];
    return 0;
}

BNO055::mode_t BNO055::getMode()
{
    return currentMode_;
}

uint8_t BNO055::setMode(mode_t mode)
{
/// status_byte will be 0 iff all transactions succeed.
    uint8_t status_byte = 0;
    mode_t previous_mode = getMode();
/// Read
    uint8_t opr_mode_bits;
    status_byte = i2cReadByte(deviceAddress_, OPR_MODE, opr_mode_bits);
    if (status_byte) {return status_byte;}
/// Modify. (Clear bits 6:4)
    opr_mode_bits &= ~(OPR_MODE_MASK);
/// Set new mode bits
    opr_mode_bits |= (mode << OPR_MODE_OFFSET);
// Write back.
    status_byte = i2cWriteByte(deviceAddress_, OPR_MODE, opr_mode_bits);
    if (status_byte) {return status_byte;}

/// Remember mode for other operations that need it.
    currentMode_ = mode;

/// Delay time depends on the previous mode.
/// Magic values from pg 21 of the datasheet.
    if (previous_mode == CONFIGMODE)
        delay(7);
    else
        delay(19);

/// TODO: add readback to ensure that setMode worked.
    return 0;
}

uint8_t BNO055::setGyroUnits(gyro_units_t units)
{
/// status_byte will be 0 iff all transactions succeed.
    uint8_t status_byte = 0;
    mode_t previous_mode = getMode();
    status_byte = setMode(CONFIGMODE);
    if (status_byte) {return status_byte;}
/// Read.
    uint8_t unit_sel_bits;
    status_byte = i2cReadByte(deviceAddress_, UNIT_SEL, unit_sel_bits);
    if (status_byte) {return status_byte;}
/// Modify. (clear units and then set the desired units)
    unit_sel_bits &= ~(1 << GYR_UNIT);
    unit_sel_bits |= (units << GYR_UNIT);
// Write back.
    status_byte = i2cWriteByte(deviceAddress_, UNIT_SEL, unit_sel_bits);
    if (status_byte) {return status_byte;}
    status_byte = setMode(previous_mode);
    if (status_byte) {return status_byte;}

/// TODO: add readback to ensure that setMode worked.
    return 0;
}

uint8_t BNO055::setAccelUnits(accel_units_t units)
{
/// status_byte will be 0 iff all transactions succeeded.
    uint8_t status_byte = 0;
    mode_t previous_mode = getMode();
    status_byte = setMode(CONFIGMODE);
    if (status_byte) {return status_byte;}
/// Read.
    uint8_t unit_sel_bits;
    status_byte = i2cReadByte(deviceAddress_, UNIT_SEL, unit_sel_bits);
    if (status_byte) {return status_byte;}
/// Modify. (Clear ACC_UNIT bit.)
    unit_sel_bits &= ~(1 << ACC_UNIT);
/// Set new unit
    unit_sel_bits |= (units << ACC_UNIT);
// Write back.
    status_byte = i2cWriteByte(deviceAddress_, UNIT_SEL, unit_sel_bits);
    if (status_byte) {return status_byte;}

    status_byte = setMode(previous_mode);
    if (status_byte) {return status_byte;}

/// TODO: add readback to ensure that setMode worked.
    return 0;
}

uint8_t BNO055::setEulerAngleUnits(euler_angle_units_t units)
{
/// Status byte will be 0 iff all transactions succeed.
    uint8_t status_byte = 0;
    mode_t previous_mode = getMode();
    status_byte = setMode(CONFIGMODE);
    if (status_byte) {return status_byte;}
/// Read.
    uint8_t unit_sel_bits;
    status_byte = i2cReadByte(deviceAddress_, UNIT_SEL, unit_sel_bits);
    if (status_byte) {return status_byte;}
/// Modify. (Clear EUL_UNIT bit.)
    unit_sel_bits &= ~(1 << EUL_UNIT);
/// Set new unit
    unit_sel_bits |= (units << EUL_UNIT);
// Write back.
    status_byte = i2cWriteByte(deviceAddress_, UNIT_SEL, unit_sel_bits);
    if (status_byte) {return status_byte;}

    status_byte = setMode(previous_mode);
    if (status_byte) {return status_byte;}

/// TODO: add readback to ensure that setMode worked.
    return 0;
}

uint8_t BNO055::setTemperatureUnits(temperature_units_t units)
{
/// Status byte will be 0 iff all transactions succeed.
    uint8_t status_byte = 0;
    mode_t previous_mode = getMode();
    status_byte = setMode(CONFIGMODE);
    if (status_byte) {return status_byte;}
/// Read.
    uint8_t unit_sel_bits;
    status_byte = i2cReadByte(deviceAddress_, UNIT_SEL, unit_sel_bits);
    if (status_byte) {return status_byte;}
/// Modify. (Clear TEMP_UNIT bit.)
    unit_sel_bits &= ~(1 << TEMP_UNIT);
/// Set new unit
    unit_sel_bits |= (units << TEMP_UNIT);
// Write back.
    status_byte = i2cWriteByte(deviceAddress_, UNIT_SEL, unit_sel_bits);
    if (status_byte) {return status_byte;}

    status_byte = setMode(previous_mode);
    if (status_byte) {return status_byte;}

/// TODO: add readback to ensure that setMode worked.
    return 0;
}

uint8_t BNO055::axisRemap(int8_t new_sign_x, axis_t new_x,
                          int8_t new_sign_y, axis_t new_y,
                          int8_t new_sign_z, axis_t new_z)
{
/// Status byte will be 0 iff all transactions succeed.
    uint8_t status_byte = 0;
/// Save the previous mode.
    mode_t previous_mode = getMode();
    status_byte = setMode(CONFIGMODE);
    if (status_byte) {return status_byte;}

/// Get old value.
    uint8_t axis_bits;
    status_byte = i2cReadByte(deviceAddress_, AXIS_MAP_CONFIG, axis_bits);
    if (status_byte) {return status_byte;}
/// Remove old values (two bits each) and apply changes.
    axis_bits &= ~( (AXIS_MASK << REMAPPED_X_OFFSET)
                  | (AXIS_MASK << REMAPPED_Y_OFFSET)
                  | (AXIS_MASK << REMAPPED_Z_OFFSET));
/// Add new values:
    axis_bits |= (new_x << REMAPPED_X_OFFSET)
               | (new_y << REMAPPED_Y_OFFSET)
               | (new_z << REMAPPED_Z_OFFSET);
/// Write back new settings.
    status_byte = i2cWriteByte(deviceAddress_, AXIS_MAP_CONFIG, axis_bits);
    if (status_byte) {return status_byte;}

/// Get old value.
    uint8_t axis_sign_bits;
    status_byte = i2cReadByte(deviceAddress_, AXIS_MAP_SIGN, axis_sign_bits);
    if (status_byte) {return status_byte;}
/// Remove old values and apply changes.
    axis_sign_bits &= ~( (1 << REMAPPED_X_SIGN_OFFSET)
                       | (1 << REMAPPED_Y_SIGN_OFFSET)
                       | (1 << REMAPPED_Z_SIGN_OFFSET));
/// Add new values:
    uint8_t sign_x = (new_sign_x < 0) ? 1 : 0;
    uint8_t sign_y = (new_sign_y < 0) ? 1 : 0;
    uint8_t sign_z = (new_sign_z < 0) ? 1 : 0;

    axis_sign_bits |= (sign_x << REMAPPED_X_SIGN_OFFSET)
                    | (sign_y << REMAPPED_Y_SIGN_OFFSET)
                    | (sign_z << REMAPPED_Z_SIGN_OFFSET);

/// Write back new settings.
    status_byte = i2cWriteByte(deviceAddress_, AXIS_MAP_SIGN, axis_sign_bits);
    if (status_byte) {return status_byte;}

/// Put back the previous mode.
    status_byte = setMode(previous_mode);
    if (status_byte) {return status_byte;}
    return 0;
}

