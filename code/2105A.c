#pragma config(UART_Usage, UART1, uartVEXLCD, baudRate19200, IOPins, None, None)
#pragma config(UART_Usage, UART2, uartNotUsed, baudRate4800, IOPins, None, None)
#pragma config(Sensor, in1,    PowerExpander,  sensorNone)
#pragma config(Sensor, dgtl1,  Brake1,         sensorDigitalOut)
#pragma config(Sensor, dgtl2,  Brake2,         sensorDigitalOut)
#pragma config(Motor,  port1,           CollectB,      tmotorVex393_HBridge, openLoop, reversed)
#pragma config(Motor,  port2,           LeftB,         tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port3,           RightB,        tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           LeftA,         tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port5,           RightA,        tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           DriveRearLeft, tmotorVex393HighSpeed_MC29, openLoop, reversed)
#pragma config(Motor,  port7,           DriveRearRight, tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port8,           DriveFrontLeft, tmotorVex393HighSpeed_MC29, openLoop, reversed)
#pragma config(Motor,  port9,           DriveFrontRight, tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port10,          CollectA,      tmotorVex393_HBridge, openLoop, reversed)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//


// TO CHANGE LCD THING, GO TO LCD FILE LINE: 272
#define NoLiftLimits
//#define NoPowerExpander
//#define MultiDriveEncoders.
#if defined(_DEBUG)
const string FILE = __FILE__;
#endif

#include "core/v1/core.h"
#include "core/DriverProfiles/2105A.h"
//#include "core/misc/2105A-autonmanager.h"

void ResetDriveEncoders() {
	//SensorValue[DriveEncoder] = 0;
	//SensorValue[DriveEncoderLeft] = 0;
}

void init() {

}
