#pragma config(Sensor, dgtl1,  LED,            sensorLEDtoVCC)
#pragma config(Motor,  port2,           left_top,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           left_mid,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           left_bot,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           right_top,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           right_mid,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           right_bot,     tmotorVex393_MC29, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task Blink;

task main()
{
	startTask(Blink);
	while(true){
		motor[left_top] = vexRT[Ch3];
		motor[left_mid] = vexRT[Ch3];
		motor[left_bot] = vexRT[Ch3];
		motor[right_top] = vexRT[Ch3];
		motor[right_mid] = vexRT[Ch3];
		motor[right_bot] = vexRT[Ch3];
	}
}

task Blink {
	while(true) {
		SensorValue[LED] = 0;
		sleep(100);
		SensorValue[LED] = 1;
		sleep(300);
	}
}
