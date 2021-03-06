task usercontrol {
	char court;
	int dval = 0;
	int deadband = 10;
	int buttonToggleState = 0;
	int buttonPressed = 0;
	while(1){
		//----------------------
		//			Drive
		//----------------------

		/*
		dval = (vexRT[Ch2] + (vexRT[Ch1] * drivemultiplier) + (vexRT[Ch3]*0.5) - (vexRT[Ch4]*0.5) * drivemultiplier) * drivemultiplier;
		motor[DriveRight]  = dval < deadband && dval > -deadband ? 0 : dval;
		dval = (-vexRT[Ch2] + (vexRT[Ch1] * drivemultiplier) - (vexRT[Ch3]*0.5) - (vexRT[Ch4]*0.5) * drivemultiplier) * drivemultiplier;
		motor[DriveLeft]  = dval < deadband && dval > -deadband ? 0 : dval;
		*/

		dval = (-vexRT[Ch2] + vexRT[Ch1]);
		motor[DriveFrontRight]  = dval < deadband && dval > -deadband ? 0 : dval;
		dval = (vexRT[Ch2] + vexRT[Ch1]);
		motor[DriveFrontLeft]  = dval < deadband && dval > -deadband ? 0 : dval;
		dval = (-vexRT[Ch2] + vexRT[Ch1]);
		motor[DriveRearRight]  = dval < deadband && dval > -deadband ? 0 : dval;
		dval = (vexRT[Ch2] + vexRT[Ch1]);
		motor[DriveRearLeft]  = dval < deadband && dval > -deadband ? 0 : dval;

		//----------------------
		//			Launcher
		//----------------------

		if(vexRT[Btn7D] == 1){
			FwSetGain(0.05);
			FwMaxPower(127);
			motorSpeed = 1;
			FwVelocitySet(&flywheel, 2400, 1);
			court = 'F';
			}else if(vexRT[Btn7R] == 1){
			motorSpeed = 0;
			FwVelocitySet( &flywheel, 0, motorSpeed);
			}else if(vexRT[Btn7L] == 1){
			FwSetGain(0.005);
			FwMaxPower(84);
			motorSpeed = 0.9;
			FwVelocitySet( &flywheel, 1800, motorSpeed);
			court = 'M';
			}else if(vexRT[Btn7U] == 1){
			FwSetGain(0.05);
			FwMaxPower(110);
			motorSpeed = 0.236;
			FwVelocitySet( &flywheel, 1580, motorSpeed);
			court = 'C';
			}else if(vexRT[Btn8U] == 1) {
			FwSetGain(0.005);
			FwMaxPower(118);
			motorSpeed = 0.6;
			FwVelocitySet( &flywheel, 1890, motorSpeed);
			court = 'S';
		}

		if(vexRT[Btn8R] == 1){
			if( ! buttonPressed ){
				buttonToggleState = 1 - buttonToggleState;
				buttonPressed = 1;
			}
			}else{
			buttonPressed = 0;
		}

		if(buttonToggleState){
			motor[LPT] = 127;
			motor[LPB] = 127;
			}else{
			motor[LPT] = 0;
			motor[LPB] = 0;
		}

		/* ---------- CAT LAUNCHER -----------
		if(vexRT[Btn8L] == 1){
		motor[CatA] = 127;
		motor[CatB] = 127;
		} else {
		motor[CatA] = 0;
		motor[CatB] = 0;
		}
		//*/

		//----------------------
		//			Auto Drive thing
		//----------------------

		//----------------------
		//			Collection
		//----------------------
		if(vexRT[Btn6U] == 1){

			switch(court){
			case 'S':
				motor[CollectionA] = 127;
				motor[CollectionB] = 127;
				break;
			default:
				motor[CollectionA] = 127;
				motor[CollectionB] = 127;
			}

			}else if(vexRT[Btn6D] == 1){
			motor[CollectionA] = -127;
			motor[CollectionB] = -127;
			}else{
			if(vexRT[Btn5U] == 1){
				motor[CollectionA] =  127;
				}else if(vexRT[Btn5D] == 1){
				motor[CollectionA] =  -127;
				} else {
				motor[CollectionA] = 0;
			}
			motor[CollectionB] = 0;
		}


		//----------------------
		//				Lift
		//----------------------
		if(vexRT[Btn8D] == 1){
			SensorValue[pnu_plat1] = 1;
			SensorValue[pnu_plat2] = 1;
			} else {
			SensorValue[pnu_plat1] = 0;
			SensorValue[pnu_plat2] = 0;
		}

		if(vexRT[Btn8L] == 1){
			SensorValue[pnu_bar2] = 1;
			SensorValue[pnu_lift1] = 1;
			SensorValue[pnu_lift2] = 1;
			} else {
			SensorValue[pnu_bar2] = 0;
			SensorValue[pnu_lift1] = 0;
			SensorValue[pnu_lift2] = 0;
		}

	}
}
