#pragma config(I2C_Usage, I2C1, i2cSensors)
#pragma config(Sensor, in1,    Gyroscope,      sensorGyro)
#pragma config(Sensor, dgtl1,  enc,            sensorQuadEncoder)
#pragma config(Sensor, dgtl3,  pnu_lift1,      sensorDigitalOut)
#pragma config(Sensor, dgtl4,  pnu_lift2,      sensorDigitalOut)
#pragma config(Sensor, dgtl6,  pnu_bar2,       sensorDigitalOut)
#pragma config(Sensor, dgtl7,  pnu_plat1,      sensorDigitalOut)
#pragma config(Sensor, dgtl8,  pnu_plat2,      sensorDigitalOut)
#pragma config(Sensor, I2C_1,  DriveEncoderLeft, sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Sensor, I2C_2,  DriveEncoder,   sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Motor,  port1,           CollectionB,   tmotorVex393TurboSpeed_HBridge, openLoop, reversed)
#pragma config(Motor,  port2,           LT,            tmotorVex393HighSpeed_MC29, openLoop, reversed)
#pragma config(Motor,  port3,           LPT,           tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port4,           DriveFrontRight, tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           DriveFrontLeft, tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           DriveRearLeft, tmotorVex393_MC29, openLoop, encoderPort, I2C_2)
#pragma config(Motor,  port7,           DriveRearRight, tmotorVex393_MC29, openLoop, encoderPort, I2C_1)
#pragma config(Motor,  port8,           LPB,           tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port9,           LB,            tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port10,          CollectionA,   tmotorVex393HighSpeed_HBridge, openLoop, reversed)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

// TO CHANGE LCD THING, GO TO LCD FILE LINE: 272
// LINE 58 COMP.H
#define NoLiftLimits
#define OneLiftEncoder
#define HasGyro
#define NoPowerExpander
//#define MultiDriveEncoders
#if defined(_DEBUG)
const string FILE = __FILE__;
#endif

int motorSpeed;
#include "core/v1/pid/b.h"
#include "core/v1/core.h"
#include "core/DriverProfiles/2105B.h"

#include "core/auton/B/Red_Front.h"
#include "core/auton/B/Red_Back.h"
#include "core/auton/B/Blue_Front.h"
#include "core/auton/B/Blue_Back.h"
#include "core/auton/B/Stay.h"
#include "core/auton/B/Progskills.h"

#include "core/misc/2105A-autonmanager.h"

void ResetDriveEncoders() {
	nMotorEncoder[DriveEncoder] = 0;
	nMotorEncoder[DriveEncoderLeft] = 0;
	SensorValue[DriveEncoder] = 0;
	SensorValue[DriveEncoderLeft] = 0;
}

void init() {
	ResetDriveEncoders();
	SensorValue[enc] = 0;
	SensorValue[Gyroscope] = 0;
	PID_Drive.Sensor = DriveEncoder;
	PID_Drive.IntegralLimit = 100;
	PID_Drive.Kp = 0.1;
	PID_Drive.Ki = 0;
	PID_Drive.Kd = 0;
	PID_Drive_TurnTo.Sensor = Gyroscope;
	PID_Drive_TurnTo.IntegralLimit = 200;
	PID_Drive_TurnTo.Kp = 0.18;
	PID_Drive_TurnTo.Ki = 0.0001;
	PID_Drive_TurnTo.Kd = 0.001;
}
