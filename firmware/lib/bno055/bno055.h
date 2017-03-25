#ifndef BNO055_H_
#define BNO055_H_
#include <stdint.h>
#include <i2c_wrapper.h>
#include <Arduino.h>

/**
 * \brief a lightweight BNO055 driver
 * \details this driver may be generalized to another
 *          microcontroller by simply rewriting the i2c wrapper
 *          implementation and implementing a delay function.
 */
class BNO055
{
    public:
    enum address_t
    {
        DEFAULT_ADDRESS = 0x29, /// Device address if COM3 pin is Logic-1
        ALTERNATE_ADDRESS = 0x28 /// Device address if COM3 pin is Logic-0
    };

    enum sensor_t
    {
        ACCELEROMETER = 0,
        GYROSCOPE = 1,
        MAGNETOMETER = 2
    };

    enum gyro_units_t
    {
        DEGREES_PER_SECOND = 0,
        RADIANS_PER_SECOND = 1
    };

    enum accel_units_t
    {
        METERS_PER_SQUARE_SECOND = 0,
        MILLI_GS = 1
    };

    enum temperature_units_t
    {
        CELSIUS = 0,
        FAHRENHEIT= 1
    };

    enum euler_angle_units_t {
        DEGREES = 0,
        RADIANS = 1
    };

    enum mode_t
    {
            CONFIGMODE   = 0x00,
            ACCONLY      = 0x01,
            MAGONLY      = 0x02,
            GYROONLY     = 0x03,
            ACCMAG       = 0x04, /// Accelerometer and magnetometer turned on
            ACCGYRO      = 0x05, /// Accelerometer and Gyro turned on
            MAGGYRO      = 0x06, /// Magnetometer and Gyro turned on
            AMG          = 0x07, /// All 3 sensors turned on
            IMU          = 0x08, /// Fusion mode w/ Acc and Gyro
            COMPASS      = 0x09, /// Fusion mode w/ Heading data only
            M4G          = 0x0A, /// Fusion mode w/ Magnet-for-gyroscope
            NDOF_FMC_OFF = 0x0B, /// Fusion mode w/o magnetometer auto-calibration
            NDOF         = 0x0C  /// Fusion mode w/ magnetometer auto-calibration
    };

    enum axis_t
    {
        X_AXIS = 0,
        Y_AXIS = 1,
        Z_AXIS = 2
    };

    BNO055();
    ~BNO055();

/**
 * \brief initialize the bno055 device so that communication can begin with
 *        the sensor.
 * \param device_address i2c address
 * \return a status byte, where 0 indicates success and 1 indicates failure
 */
    uint8_t init(mode_t mode = NDOF, address_t device_address = DEFAULT_ADDRESS);

/**
 * \brief perform a data dump of registers 0x08 through 0x35
 *        into the specified array starting at the index location.
 * \param arrayPtr the name of the array where data will be written
 */
    uint8_t readRawData(uint8_t * const arrayPtr);

/**
 * \brief perform a data dump of registers 0x55 through 0x6A
 *        into the specified array starting at the index location.
 * \param arrayPtr the name of the array where data will be written
 */
    uint8_t readCalibData(uint8_t * const arrayPtr);

/**
 * \brief write back calibration data to the calibration registers
 * \param arrayPtr the name of the array containing data to be written
 */
    uint8_t writeCalibData(uint8_t * const arrayPtr);

/**
 * \brief read the register for calibration status
 */
    uint8_t readCalibrationStatus(void);

/**
 * \brief return the device calibration status
 */
    uint8_t readDeviceCalibration(void);

/**
 * \brief quickly check if the BNO055 is calibrated
 */
    bool isDeviceCalibrated(void);

/**
 * \brief check if the sensor in question is calibrated
 */
    bool isSensorCalibrated(sensor_t sensor);

/**
 * \brief grab the raw accelerometer data for a given axis
 * \param axis the axis_t enumeration corresponding to the desired axis
 */
    uint16_t readRawAccel(axis_t axis);

/**
 * \brief grab the raw magnetometer data for a given axis
 * \param axis the axis_t enumeration corresponding to the desired axis
 */
    uint16_t readRawMag(axis_t axis);

/**
 * \brief grab the raw gyroscope data for a given axis
 * \param axis the axis_t enumeration corresponding to the desired axis
 */
    uint16_t readRawGyro(axis_t axis);

/**
 * \brief read the Euler heading from the sensor fusion algorithm
 */
    uint16_t readEulHead(void);

/**
 * \brief read the linear acceleration data for a given axis (sensor fusion)
 * \param axis the axis_t enumeration corresponding to the desired axis
 */
    uint16_t readLinearAccel(axis_t axis);

/**
 * \brief read the gravitational vector data for a given axis (sensor fusion)
 * \param axis the axis_t enumeration corresponding to the desired axis
 */
    uint16_t readGravityVector(axis_t axis);

/**
 * \brief Get the unscaled quaternion data. Return i2c status byte,
          where nonzero indicates failure.
 */
    uint8_t readQuaternion(int16_t& w, int16_t& x, int16_t& y, int16_t& z);

/**
 * \brief get the mode from one of the various available modes.
 */
    mode_t getMode();
/**
 * \brief set the mode from one of the various available modes.
 */
    uint8_t setMode(mode_t m);

/**
 * \brief set the units to radians and radians-per-second.
 */
    uint8_t setGyroUnits(gyro_units_t units);

/**
 * \brief set accel units to either mg or m/(s^2)
 */
    uint8_t setAccelUnits(accel_units_t units);

/**
 * \brief set euler angle units to either mg or m/(s^2)
 */
    uint8_t setEulerAngleUnits(euler_angle_units_t units);

/**
 * \brief set the units of the temperature
 */
    uint8_t setTemperatureUnits(temperature_units_t units);

/**
 * \brief remap axis to account for alternate mounting orientation.
 * \details new orientation is relative to the default initial orientation.
 *          On-chip mode is switched to CONNFIGMODE and then restored before
            function returns.
 * \param new_sign_x +/- value to determine new sign of the new x axis
 * \param new_x axis specifying the new x-axis
 * \param new_sign_y +/- value to determine new sign of the new y axis
 * \param new_y axis specifying the new y-axis
 * \param new_sign_z +/- value to determine new sign of the new z axis
 * \param new_z axis specifying the new z-axis
 */
    uint8_t axisRemap(int8_t new_sign_x, axis_t new_x,
                      int8_t new_sign_y, axis_t new_y,
                      int8_t new_sign_z,  axis_t new_z);

    static const uint8_t RAW_DATA_NUM_BYTES = 46;
    static const uint8_t CALIB_DATA_NUM_BYTES = 22;

private:

/**
 * \brief read two subsequent bytes by the address of the least significant byte
 *        and return their combined value as a 16-bit integer
 * \param starting_addresss the starting address to read from.
          In the BNO055 register mapping, it is the least significant byte.
 */
 uint16_t read16(uint8_t starting_address);

/// The current device address according to the wiring.
    address_t deviceAddress_;
    mode_t currentMode_;

/// Constants
    static const uint8_t ACC_DATA_X_LSB = 0x08;
    static const uint8_t ACC_DATA_X_MSB = 0x09;
    static const uint8_t ACC_DATA_Y_LSB = 0x0A;
    static const uint8_t ACC_DATA_Y_MSB = 0x0B;
    static const uint8_t ACC_DATA_Z_LSB = 0x0C;
    static const uint8_t ACC_DATA_Z_MSB = 0x0D;

    static const uint8_t MAG_DATA_X_LSB = 0x0E;
    static const uint8_t MAG_DATA_X_MSB = 0x0F;
    static const uint8_t MAG_DATA_Y_LSB = 0x10;
    static const uint8_t MAG_DATA_Y_MSB = 0x11;
    static const uint8_t MAG_DATA_Z_LSB = 0x12;
    static const uint8_t MAG_DATA_Z_MSB = 0x13;

    static const uint8_t GYR_DATA_X_LSB = 0x14;
    static const uint8_t GYR_DATA_X_MSB = 0x15;
    static const uint8_t GYR_DATA_Y_LSB = 0x16;
    static const uint8_t GYR_DATA_Y_MSB = 0x17;
    static const uint8_t GYR_DATA_Z_LSB = 0x18;
    static const uint8_t GYR_DATA_Z_MSB = 0x19;

    static const uint8_t EUL_HEADING_LSB = 0x1A;
    static const uint8_t EUL_HEADING_MSB = 0x1B;
    static const uint8_t EUL_ROLL_LSB = 0x1C;
    static const uint8_t EUL_ROLL_MSB = 0x1D;
    static const uint8_t EUL_PITCH_LSB = 0x1E;
    static const uint8_t EUL_PITCH_MSB = 0x1F;

    static const uint8_t QUA_DATA_W_LSB = 0x20;
    static const uint8_t QUA_DATA_W_MSB = 0x21;
    static const uint8_t QUA_DATA_X_LSB = 0x22;
    static const uint8_t QUA_DATA_X_MSB = 0x23;
    static const uint8_t QUA_DATA_Y_LSB = 0x24;
    static const uint8_t QUA_DATA_Y_MSB = 0x25;
    static const uint8_t QUA_DATA_Z_LSB = 0x26;
    static const uint8_t QUA_DATA_Z_MSB = 0x27;

    static const uint8_t LIA_DATA_X_LSB = 0x28;
    static const uint8_t LIA_DATA_X_MSB = 0x29;
    static const uint8_t LIA_DATA_Y_LSB = 0x2A;
    static const uint8_t LIA_DATA_Y_MSB = 0x2B;
    static const uint8_t LIA_DATA_Z_LSB = 0x2C;
    static const uint8_t LIA_DATA_Z_MSB = 0x2D;

    static const uint8_t GRV_DATA_X_LSB = 0x2E;
    static const uint8_t GRV_DATA_X_MSB = 0x2F;
    static const uint8_t GRV_DATA_Y_LSB = 0x30;
    static const uint8_t GRV_DATA_Y_MSB = 0x31;
    static const uint8_t GRV_DATA_Z_LSB = 0x32;
    static const uint8_t GRV_DATA_Z_MSB = 0x33;

    static const uint8_t TEMP = 0x34;
    static const uint8_t CALIB_STAT = 0x35;

    static const uint8_t UNIT_SEL = 0x3B;
    /// Bitfield offsets for UNIT_SEL
        static const uint8_t ACC_UNIT= 0;
        static const uint8_t GYR_UNIT = 1;
        static const uint8_t EUL_UNIT = 2;
        static const uint8_t TEMP_UNIT = 3;

    static const uint8_t OPR_MODE = 0x3D;
    /// Bitfield offsets for OPR_MODE
        static const uint8_t OPR_MODE_OFFSET = 0; /// bits <3:0>
    /// Bitmasks for OPR_MODE
        static const uint8_t OPR_MODE_MASK =  0x0F;  /// 0b00001111

    static const uint8_t AXIS_MAP_CONFIG = 0x41;
    /// Bitfield offsets for AXIS_MAP_CONFIG
        static const uint8_t REMAPPED_X_OFFSET = 0;
        static const uint8_t REMAPPED_Y_OFFSET = 2;
        static const uint8_t REMAPPED_Z_OFFSET = 4;
    /// Bitmasks for AXIS_MAP_CONFIG
        static const uint8_t AXIS_MASK = 0x03;

    static const uint8_t AXIS_MAP_SIGN = 0x42;
    /// Bitfield offsets for AXIS_MAP_SIGN
        static const uint8_t REMAPPED_X_SIGN_OFFSET = 2;
        static const uint8_t REMAPPED_Y_SIGN_OFFSET = 1;
        static const uint8_t REMAPPED_Z_SIGN_OFFSET = 0;

    static const uint8_t ACC_OFFSET_X_LSB = 0x55;
    static const uint8_t ACC_OFFSET_X_MSB = 0x56;
    static const uint8_t ACC_OFFSET_Y_LSB = 0x57;
    static const uint8_t ACC_OFFSET_Y_MSB = 0x58;
    static const uint8_t ACC_OFFSET_Z_LSB = 0x59;
    static const uint8_t ACC_OFFSET_Z_MSB = 0x5A;

    static const uint8_t MAG_OFFSET_X_LSB = 0x5B;
    static const uint8_t MAG_OFFSET_X_MSB = 0x5C;
    static const uint8_t MAG_OFFSET_Y_LSB = 0x5D;
    static const uint8_t MAG_OFFSET_Y_MSB = 0x5E;
    static const uint8_t MAG_OFFSET_Z_LSB = 0x5F;
    static const uint8_t MAG_OFFSET_Z_MSB = 0x60;

    static const uint8_t GYR_OFFSET_X_LSB = 0x61;
    static const uint8_t GYR_OFFSET_X_MSB = 0x62;
    static const uint8_t GYR_OFFSET_Y_LSB = 0x63;
    static const uint8_t GYR_OFFSET_Y_MSB = 0x64;
    static const uint8_t GYR_OFFSET_Z_LSB = 0x65;
    static const uint8_t GYR_OFFSET_Z_MSB = 0x66;

    static const uint8_t ACC_RADIUS_LSB = 0x67;
    static const uint8_t ACC_RADIUS_MSB = 0x68;
    static const uint8_t MAG_RADIUS_LSB = 0x69;
    static const uint8_t MAG_RADIUS_MSB = 0x6A;

    static const uint32_t POWER_ON_RESET_TIME_MS = 650;
};
#endif //BNO055_H_

