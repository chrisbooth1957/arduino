/*
 * This is a reorganized version of https://github.com/kriswiner/MPU9250
 */

#ifndef __MPU9250_H_
#define __MPU9250_H_

#define MPU9250_CALIBRATE_MAG  false 

#define MPU9250_ADDRESS 0x68      // MPU9250 address when ADO = 1
#define AK8963_ADDRESS  0x0C      // Address of AK8963 (MPU9250) magnetometer
#define BMP280_ADDRESS  0x76      // Address of BMP280 altimeter

// MPU9250 registers
#define MPU9250_SELF_TEST_X_GYRO  0x00
#define MPU9250_SELF_TEST_Y_GYRO  0x01
#define MPU9250_SELF_TEST_Z_GYRO  0x02
#define MPU9250_SELF_TEST_X_ACCEL 0x0D
#define MPU9250_SELF_TEST_Y_ACCEL 0x0E
#define MPU9250_SELF_TEST_Z_ACCEL 0x0F
#define MPU9250_SELF_TEST_A       0x10

#define MPU9250_XG_OFFSET_H       0x13  // User-defined trim values for gyroscope
#define MPU9250_XG_OFFSET_L       0x14
#define MPU9250_YG_OFFSET_H       0x15
#define MPU9250_YG_OFFSET_L       0x16
#define MPU9250_ZG_OFFSET_H       0x17
#define MPU9250_ZG_OFFSET_L       0x18
#define MPU9250_SMPLRT_DIV        0x19
#define MPU9250_CONFIG            0x1A
#define MPU9250_GYRO_CONFIG       0x1B
#define MPU9250_ACCEL_CONFIG      0x1C
#define MPU9250_ACCEL_CONFIG2     0x1D
#define MPU9250_LP_ACCEL_ODR      0x1E
#define MPU9250_WOM_THR           0x1F

#define MPU9250_MOT_DUR           0x20  // Duration counter threshold for motion interrupt generation, 1 kHz rate, LSB = 1 ms
#define MPU9250_ZMOT_THR          0x21  // Zero-motion detection threshold bits [7:0]
#define MPU9250_ZRMOT_DUR         0x22  // Duration counter threshold for zero motion interrupt generation, 16 Hz rate, LSB = 64 ms 

#define MPU9250_FIFO_EN          0x23
#define MPU9250_I2C_MST_CTRL     0x24
#define MPU9250_I2C_SLV0_ADDR    0x25
#define MPU9250_I2C_SLV0_REG     0x26
#define MPU9250_I2C_SLV0_CTRL    0x27
#define MPU9250_I2C_SLV1_ADDR    0x28
#define MPU9250_I2C_SLV1_REG     0x29
#define MPU9250_I2C_SLV1_CTRL    0x2A
#define MPU9250_I2C_SLV2_ADDR    0x2B
#define MPU9250_I2C_SLV2_REG     0x2C
#define MPU9250_I2C_SLV2_CTRL    0x2D
#define MPU9250_I2C_SLV3_ADDR    0x2E
#define MPU9250_I2C_SLV3_REG     0x2F
#define MPU9250_I2C_SLV3_CTRL    0x30
#define MPU9250_I2C_SLV4_ADDR    0x31
#define MPU9250_I2C_SLV4_REG     0x32
#define MPU9250_I2C_SLV4_DO      0x33
#define MPU9250_I2C_SLV4_CTRL    0x34
#define MPU9250_I2C_SLV4_DI      0x35
#define MPU9250_I2C_MST_STATUS   0x36
#define MPU9250_INT_PIN_CFG      0x37
#define MPU9250_INT_ENABLE       0x38
#define MPU9250_DMP_INT_STATUS   0x39  // Check DMP interrupt
#define MPU9250_INT_STATUS       0x3A
#define MPU9250_ACCEL_XOUT_H     0x3B
#define MPU9250_ACCEL_XOUT_L     0x3C
#define MPU9250_ACCEL_YOUT_H     0x3D
#define MPU9250_ACCEL_YOUT_L     0x3E
#define MPU9250_ACCEL_ZOUT_H     0x3F
#define MPU9250_ACCEL_ZOUT_L     0x40
#define MPU9250_TEMP_OUT_H       0x41
#define MPU9250_TEMP_OUT_L       0x42
#define MPU9250_GYRO_XOUT_H      0x43
#define MPU9250_GYRO_XOUT_L      0x44
#define MPU9250_GYRO_YOUT_H      0x45
#define MPU9250_GYRO_YOUT_L      0x46
#define MPU9250_GYRO_ZOUT_H      0x47
#define MPU9250_GYRO_ZOUT_L      0x48

#define MPU9250_EXT_SENS_DATA_00   0x49
#define MPU9250_EXT_SENS_DATA_01   0x4A
#define MPU9250_EXT_SENS_DATA_02   0x4B
#define MPU9250_EXT_SENS_DATA_03   0x4C
#define MPU9250_EXT_SENS_DATA_04   0x4D
#define MPU9250_EXT_SENS_DATA_05   0x4E
#define MPU9250_EXT_SENS_DATA_06   0x4F
#define MPU9250_EXT_SENS_DATA_07   0x50
#define MPU9250_EXT_SENS_DATA_08   0x51
#define MPU9250_EXT_SENS_DATA_09   0x52
#define MPU9250_EXT_SENS_DATA_10   0x53
#define MPU9250_EXT_SENS_DATA_11   0x54
#define MPU9250_EXT_SENS_DATA_12   0x55
#define MPU9250_EXT_SENS_DATA_13   0x56
#define MPU9250_EXT_SENS_DATA_14   0x57
#define MPU9250_EXT_SENS_DATA_15   0x58
#define MPU9250_EXT_SENS_DATA_16   0x59
#define MPU9250_EXT_SENS_DATA_17   0x5A
#define MPU9250_EXT_SENS_DATA_18   0x5B
#define MPU9250_EXT_SENS_DATA_19   0x5C
#define MPU9250_EXT_SENS_DATA_20   0x5D
#define MPU9250_EXT_SENS_DATA_21   0x5E
#define MPU9250_EXT_SENS_DATA_22   0x5F
#define MPU9250_EXT_SENS_DATA_23   0x60
#define MPU9250_MOT_DETECT_STATUS  0x61
#define MPU9250_I2C_SLV0_DO        0x63
#define MPU9250_I2C_SLV1_DO        0x64
#define MPU9250_I2C_SLV2_DO        0x65
#define MPU9250_I2C_SLV3_DO        0x66
#define MPU9250_I2C_MST_DELAY_CTRL 0x67
#define MPU9250_SIGNAL_PATH_RESET  0x68
#define MPU9250_MOT_DETECT_CTRL    0x69
#define MPU9250_USER_CTRL          0x6A // Bit 7 enable DMP, bit 3 reset DMP
#define MPU9250_PWR_MGMT_1         0x6B // Device defaults to the SLEEP mode
#define MPU9250_PWR_MGMT_2         0x6C
#define MPU9250_DMP_BANK           0x6D // Activates a specific bank in the DMP
#define MPU9250_DMP_RW_PNT         0x6E // Set read/write pointer to a specific start address in specified DMP bank
#define MPU9250_DMP_REG            0x6F // Register in DMP from which to read or to which to write
#define MPU9250_DMP_REG_1          0x70
#define MPU9250_DMP_REG_2          0x71
#define MPU9250_FIFO_COUNTH        0x72
#define MPU9250_FIFO_COUNTL        0x73
#define MPU9250_FIFO_R_W           0x74
#define MPU9250_WHO_AM_I           0x75 // Should return 0x71
#define MPU9250_XA_OFFSET_H        0x77
#define MPU9250_XA_OFFSET_L        0x78
#define MPU9250_YA_OFFSET_H        0x7A
#define MPU9250_YA_OFFSET_L        0x7B
#define MPU9250_ZA_OFFSET_H        0x7D
#define MPU9250_ZA_OFFSET_L        0x7E

//Magnetometer Registers, see https://www.akm.com/akm/en/file/datasheet/AK8963C.pdf
#define AK8963_ADDRESS      0x0C
#define AK8963_WHO_AM_I     0x00  // should return 0x48
#define AK8963_INFO         0x01
#define AK8963_ST1          0x02  // data ready status bit 0
#define AK8963_XOUT_L       0x03  // data
#define AK8963_XOUT_H       0x04
#define AK8963_YOUT_L       0x05
#define AK8963_YOUT_H       0x06
#define AK8963_ZOUT_L       0x07
#define AK8963_ZOUT_H       0x08
#define AK8963_ST2          0x09  // Data overflow bit 3 and data read error status bit 2
#define AK8963_CNTL         0x0A  // Power down (0000), single-measurement (0001), self-test (1000) and Fuse ROM (1111) modes on bits 3:0
#define AK8963_ASTC         0x0C  // Self test control
#define AK8963_I2CDIS       0x0F  // I2C disable
#define AK8963_ASAX         0x10  // Fuse ROM x-axis sensitivity adjustment value
#define AK8963_ASAY         0x11  // Fuse ROM y-axis sensitivity adjustment value
#define AK8963_ASAZ         0x12  // Fuse ROM z-axis sensitivity adjustment value

// BMP280 registers
#define BMP280_TEMP_XLSB  0xFC
#define BMP280_TEMP_LSB   0xFB
#define BMP280_TEMP_MSB   0xFA
#define BMP280_PRESS_XLSB 0xF9
#define BMP280_PRESS_LSB  0xF8
#define BMP280_PRESS_MSB  0xF7
#define BMP280_CONFIG     0xF5
#define BMP280_CTRL_MEAS  0xF4
#define BMP280_STATUS     0xF3
#define BMP280_RESET      0xE0
#define BMP280_ID         0xD0  // should be 0x58
#define BMP280_CALIB00    0x88

// Set initial input parameters
enum MPU9250accelScale {
  AFS_2G = 0,
  AFS_4G,
  AFS_8G,
  AFS_16G
};

enum MPU9250gyroScale {
  GFS_250DPS = 0,
  GFS_500DPS,
  GFS_1000DPS,
  GFS_2000DPS
};

enum MPU9250magScale {
  MFS_14BITS = 0, // 0.6 mG per LSB
  MFS_16BITS      // 0.15 mG per LSB
};

enum BMP280Posr {
  P_OSR_00 = 0,  // no op
  P_OSR_01,
  P_OSR_02,
  P_OSR_04,
  P_OSR_08,
  P_OSR_16
};

enum BMP280Tosr {
  T_OSR_00 = 0,  // no op
  T_OSR_01,
  T_OSR_02,
  T_OSR_04,
  T_OSR_08,
  T_OSR_16
};

enum BMP280IIRFilter {
  full = 0,  // bandwidth at full sample rate
  BW0_223ODR,
  BW0_092ODR,
  BW0_042ODR,
  BW0_021ODR // bandwidth at 0.021 x sample rate
};

enum BMP280Mode {
  Sleep = 0,
  forced,
  forced2,
  normal
};

enum BMP280SBy {
  t_00_5ms = 0,
  t_62_5ms,
  t_125ms,
  t_250ms,
  t_500ms,
  t_1000ms,
  t_2000ms,
  t_4000ms,
};

class mpu9250 {
  public:
    mpu9250();
    ~mpu9250();
    void begin(void);
    bool newData(void);
    void readAccelData(float*, float*, float*);
    void readGyroData(float*, float*, float*);
    byte readMagData(float*, float*, float*);
    void readTempData(float*);

  private:
    void selfTest(void);
    void getAccelRes(void);
    void getGyroRes(void);
    void getMagRes(void);
    void initAccelGyro(void);
    void calibrateAccelGyro(void);
    void initMag(void);
    void calibrateMag(void);
    byte readMagData(int16_t*);
    
    uint8_t gyroScale   = GFS_250DPS;
    uint8_t accelScale  = AFS_2G;
    uint8_t magScale    = MFS_16BITS;   // Choose either 14-bit or 16-bit magnetometer resolution
    uint8_t magMode     = 0x06;         // 2 for 8 Hz, 6 for 100 Hz continuous magnetometer data read
    float accelRes, gyroRes, magRes;    // scale resolutions per LSB for the sensors

    float magCalibration[3] = {0, 0, 0};  // Factory mag calibration and mag bias
    float gyroBias[3] = {0, 0, 0}, accelBias[3] = {0, 0, 0}, magBias[3] = {0, 0, 0};      // Bias corrections for gyro and accelerometer
    float temperature;                          // Stores the MPU9250 gyro internal chip temperature in degrees Celsius
    float SelfTest[6];                          // Holds results of gyro and accelerometer self test

    // global constants for 9 DoF fusion and AHRS (Attitude and Heading Reference System)
    float GyroMeasError = PI * (40.0f / 180.0f);   // gyroscope measurement error in rads/s (start at 40 deg/s)
    float GyroMeasDrift = PI * (0.0f  / 180.0f);   // gyroscope measurement drift in rad/s/s (start at 0.0 deg/s/s)

    float ax, ay, az, gx, gy, gz, mx, my, mz; // variables to hold latest MPU9250 sensor data values

}; // class


void readBytes(uint8_t address, uint8_t subAddress, uint8_t count, uint8_t * dest);
uint8_t readByte(uint8_t address, uint8_t subAddress);
void writeByte(uint8_t address, uint8_t subAddress, uint8_t data);
void I2Cscan();

#endif
