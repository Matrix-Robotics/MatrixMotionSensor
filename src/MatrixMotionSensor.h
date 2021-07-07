#ifndef _MatrixMotionSensor_H_
#define _MatrixMotionSensor_H_

#include <Arduino.h>
#include <Wire.h>

#ifndef ADDR_PCA954X
#define ADDR_PCA954X 0x70
#endif

#define MatrixMotion_ADDR 0x23

typedef enum __AxisType
{
	x = 0,
	y,
	z
} AxisType;

typedef enum __FilterType
{
	NONE = 0, 
	GYRO, // Gyro angle data
	CPLTY, // Complimentary_filter
	KALMAN // Kalman Filter
} FilterType;


class MatrixMotion{
private:
	typedef enum __MotionRegType
	{
		Device_ID = 1,
		Device_CONFIG,
		ROLL_H,
		ROLL_L,
		YAW_H,
		YAW_L,
		PITCH_L,
		GYRO_X_H,
		GYRO_X_L,
		GYRO_Y_H,
		GYRO_Y_L,
		GYRO_Z_H,
		GYRO_Z_L,
		ACCEL_X_H,
		ACCEL_X_L,
		ACCEL_Y_H,
		ACCEL_Y_L,
		ACCEL_Z_H,
		ACCEL_Z_L,
		Temp
	} MotionRegType;

	uint8_t _ch=0, _ver=1;
	uint8_t i2cReadData(MotionRegType reg);
	void i2cMUXSelect();
	void i2cWriteData(MotionRegType reg, uint8_t data);
public:
	friend class MiniI2C;
	bool begin();
	void setFilter(FilterType filter);

	int getRoll();
	int getYaw();
	int getPitch();
	int getGyro(AxisType axis);
	int getAccel(AxisType axis);
	float getTemperature();

};

#endif
