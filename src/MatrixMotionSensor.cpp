#include "MatrixMotionSensor.h"


bool MatrixMotion::begin(){
	Wire.begin();

	i2cMUXSelect();
	delay(50);
	if(i2cReadData(Device_ID) == 0x44){
		i2cWriteData(Device_CONFIG, 0x08); // reset
		delay(500);
		i2cWriteData(Device_CONFIG, 0x04); // enable
		return true;
	}
	else{
		return false;
	}
}

uint8_t MatrixMotion::i2cReadData(MotionRegType reg){
	Wire.beginTransmission(MatrixMotion_ADDR);
	Wire.write(reg);
	Wire.endTransmission(1);

	delay(1);
	Wire.requestFrom(MatrixMotion_ADDR, 1);
	delay(1);

	return Wire.read();
}

void MatrixMotion::i2cMUXSelect(){
	switch (_ver)
	{
	case 2:
		Wire.beginTransmission(ADDR_PCA954X);
		Wire.write(_ch + 4);
		Wire.endTransmission(1);

		delay(10);
		break;
	case 3:
		Wire.beginTransmission(ADDR_PCA954X);
		Wire.write((1 << _ch));
		Wire.endTransmission(1);
		
		delay(10);
		break;
	default:
		break;
	}
}

void MatrixMotion::i2cWriteData(MotionRegType reg, uint8_t data){

	Wire.beginTransmission(MatrixMotion_ADDR);

	Wire.write(reg);
	Wire.write(data);

	Wire.endTransmission(1);
}

void MatrixMotion::setFilter(FilterType filter){
	i2cWriteData(Device_CONFIG, filter + 0x04);
}

int MatrixMotion::getRoll(){
	i2cMUXSelect();
	int data = (uint16_t)(i2cReadData(ROLL_H) << 8 | i2cReadData(ROLL_L));
	if(data>32767){
		data -= 65536;
	}
	return data;

}

int MatrixMotion::getYaw(){
	i2cMUXSelect();
	int data = (uint16_t)(i2cReadData(YAW_H) << 8 | i2cReadData(YAW_L));
	if(data>32767){
		data -= 65536;
	}
	return data;
}

int MatrixMotion::getPitch(){
	i2cMUXSelect();
	int data = (uint8_t)(i2cReadData(PITCH_L));
	return data-90;
}

int MatrixMotion::getGyro(AxisType axis){
	i2cMUXSelect();
	int data;
	switch(axis){
		case x:
			data = (uint16_t)(i2cReadData(GYRO_X_H) << 8 | i2cReadData(GYRO_X_L));
			break;
		case y:
			data = (uint16_t)(i2cReadData(GYRO_Y_H) << 8 | i2cReadData(GYRO_Y_L));
			break;
		case z:
			data = (uint16_t)(i2cReadData(GYRO_Z_H) << 8 | i2cReadData(GYRO_Z_L));
			break;
		default:
			break;
	}
	if(data>32767){
		data -= 65536;
	}
	return data;
}

int MatrixMotion::getAccel(AxisType axis){
	i2cMUXSelect();
	int data;
	switch(axis){
		case x:
			data = (uint16_t)(i2cReadData(ACCEL_X_H) << 8 | i2cReadData(ACCEL_X_L));
			break;
		case y:
			data = (uint16_t)(i2cReadData(ACCEL_Y_H) << 8 | i2cReadData(ACCEL_Y_L));
			break;
		case z:
			data = (uint16_t)(i2cReadData(ACCEL_Z_H) << 8 | i2cReadData(ACCEL_Z_L));
			break;
		default:
			break;
	}
	if(data>32767){
		data -= 65536;
	}
	return data;
}


float MatrixMotion::getTemperature(){
	i2cMUXSelect();
	return i2cReadData(Temp);
}