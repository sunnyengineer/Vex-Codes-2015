#pragma config(Sensor, dgtl1,  lft,            sensorQuadEncoder)
#pragma config(Sensor, dgtl3,  lif,            sensorQuadEncoder)
#pragma config(Sensor, dgtl5,  rig,            sensorQuadEncoder)
#pragma config(Motor,  port1,           LRL,           tmotorVex393_HBridge, openLoop)
#pragma config(Motor,  port2,           LLL,           tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port3,           FRD,           tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port4,           BRD,           tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port5,           RF,            tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port6,           LF,            tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           BLD,           tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           FLD,           tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port9,           RRL,           tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port10,          RLL,           tmotorVex393_HBridge, openLoop, reversed)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#pragma platform(VEX)

//Competition Control and Duration Settings
#pragma competitionControl(Competition)
#pragma autonomousDuration(20)
#pragma userControlDuration(120)

#include "Vex_Competition_Includes.c"   //Main competition background code...do not modify!

/////////////////////////////////////////////////////////////////////////////////////////
//
//                          Pre-Autonomous Functions
//
// You may want to perform some actions before the competition starts. Do them in the
// following function.
//
/////////////////////////////////////////////////////////////////////////////////////////
int x;
int y;
int Userinput(){
	while(true){
		if(nLCDButtons == 1){
			return 1;
			}if(nLCDButtons == 4){
			return 2;
		}
	}
}
void LED(){
	displayLCDCenteredString(0, "Side?");
	displayLCDString(0, 0, "Red         Blue");
	x = Userinput();
	displayLCDCenteredString(0, "Position?");
	displayLCDString(0, 0, "Left     Right");
	waitInMilliseconds(500);
	y = Userinput();
	if(x == 1 && y == 1){
		displayLCDCenteredString(0, "Red, left");
		}if(x == 2 && y == 1){
		displayLCDCenteredString(0, "Blue, left");
		}if(x == 1 && y == 2){
		displayLCDCenteredString(0, "Red, Right");
		}if(x == 2 && y == 2){
		displayLCDCenteredString(0, "Blue, Right");
	}
}


void pre_auton(){
	if(!bIfiRobotDisabled){ //Allows robot to return to driver mode if cortex experiences a power glitch
		return;
	}
	LED();
	bStopTasksBetweenModes = false;
}

/////////////////////////////////////////////////////////////////////////////////////////
//
//                                 Autonomous Task
//
// This task is used to control your robot during the autonomous phase of a VEX Competition.
// You must modify the code to add your own robot specific commands here.
//
/////////////////////////////////////////////////////////////////////////////////////////
int error;
int integral(int in){
	while(true){
		in = in + error;
		return in;
	}
}
int derivative(int err){
	while(true){
		err = error;
		int der = error - err;
		return der;
	}
}

void stp(){
	motor[FLD] = 0;
	motor[FRD] = 0;
	motor[BLD] = 0;
	motor[BRD] = 0;}
void reset(string encode){
	if(encode == "lef"){
		SensorValue(lft) = 0;}
	if(encode == "rit"){
		SensorValue(rig) = 0;}
	if(encode == "lif"){
		SensorValue(lif) = 0;}
}
void move(int direction, int target){
	if(direction == 1){
		while(SensorValue[lft] < target){
			int error = target - SensorValue[lft];
			int inte = integral(0);
			if (error == 0){
				inte = 0;}
			if ( abs(error) > 40){
				inte = 0;}
			int deri = derivative(error);
			int speed = error + inte + deri;
			if(speed > 127){
				int speed = 127;}
			motor[FLD] = speed;
			motor[FRD] = speed;
			motor[BLD] = speed;
			motor[BRD] = speed;}
		if(direction == 0){
			while(SensorValue[rig] < target){
				int error = target - SensorValue[lft];
				int inte = integral(0);
				if (error == 0){
					inte = 0;}
				if (abs(error) > 40){
					inte = 0;}
				int deri = derivative(error);
				int speed = error + inte + deri;
				if(speed > 127){
					int speed = 127;}
				motor[FLD] = -speed;
				motor[FRD] = -speed;
				motor[BLD] = -speed;
				motor[BRD] = -speed;}
		}
		stp();}
}
void turn(string direction, int angle){
	if(direction == "R"){
		while(SensorValue[lft] < angle){
			int error = angle - SensorValue[lft];
			int inte = integral(0);
			if (error == 0){
				inte = 0;}
			if ( abs(error) > 40){
				inte = 0;}
			int deri = derivative(error);
			int speed = error + inte + deri;
			if(speed > 127){
				int speed = 127;}
			motor[FLD] = speed;
			motor[FRD] = -speed;
			motor[BLD] = speed;
			motor[BRD] = -speed;}
	}
	if(direction == "L"){
		while(SensorValue[lft] > angle){
			int error = -angle + SensorValue[lft];
			int inte = integral(0);
			if (error == 0){
				inte = 0;}
			if ( abs(error) > 40){
				inte = 0;}
			int deri = derivative(error);
			int speed = error + inte + deri;
			if(speed > 127){
				int speed = 127;}
			motor[FLD] = -speed;
			motor[FRD] = speed;
			motor[BLD] = -speed;
			motor[BRD] = speed;}
	}
}
void swingtrn(int dir, int angle){
	if(dir == 1){
		while(SensorValue[rig] < angle){
			int error = angle - SensorValue[lft];
			int inte = integral(0);
			if (error == 0){
				inte = 0;}
			if ( abs(error) > 40){
				inte = 0;}
			int deri = derivative(error);
			int speed = error + inte + deri;
			if(speed > 127){
				int speed = 127;}
			motor[FLD] = speed;
			motor[FRD] = 0;
			motor[BLD] = speed;
			motor[BRD] = 0;}
	}
	if(dir == 0){
		while(SensorValue[rig] > angle){
			int error = -angle + SensorValue[lft];
			int inte = integral(0);
			if (error == 0){
				inte = 0;}
			if ( abs(error) > 40){
				inte = 0;}
			int deri = derivative(error);
			int speed = error + inte + deri;
			if(speed > 127){
				int speed = 127;}
			motor[FLD] = 0;
			motor[FRD] = speed;
			motor[BLD] = 0;
			motor[BRD] = speed;}
	}
}
void lift(int height){
	while(SensorValue[lif] < height){
		motor[RRL] = 127;
		motor[RLL] = 127;
		motor[LLL] = 127;
		motor[LRL] = 127;}
	motor[RRL] = 0;
	motor[RLL] = 0;
	motor[LLL] = 0;
	motor[LRL] = 0;}
void drop(int height){
	while(SensorValue[lif] < height){
		motor[RRL] = -127;
		motor[RLL] = -127;
		motor[LLL] = -127;
		motor[LRL] = -127;}
	motor[RRL] = 0;
	motor[RLL] = 0;
	motor[LLL] = 0;
	motor[LRL] = 0;}

void feed(int time, int direction){
	if(direction == 1){
		motor[RF] = 127;
		motor[LF] = 127;
		waitInMilliseconds(time);
		motor[RF] = 0;
		motor[LF] = 0;}
	if(direction == 0){
		motor[RF] = -127;
		motor[LF] = -127;
		waitInMilliseconds(time);
		motor[RF] = 0;
		motor[LF] = 0;}
}

string lef = "lef", rit = "rit", R = "R", L = "L", lfi = "lif";
task autonomous(){
	if(x == 2 && y == 1){
		reset(rit);
		reset(lef);
		move(1, 500);
		waitInMilliseconds(200);
		feed(900, 1);
		reset(lef);
		reset(rit);
		waitInMilliseconds(200);
		turn(L, -260);
		reset(lef);
		reset(rit);
		waitInMilliseconds(200);
		move(1, 690);
		reset(lef);
		reset(rit);
		waitInMilliseconds(200);
		turn(L, -143);
	if(x == 1 && y == 1){
		reset(lfi);
		lift(150);}


	}
}

/////////////////////////////////////////////////////////////////////////////////////////
//
//                                 User Control Task
//
// This task is used to control your robot during the user control phase of a VEX Competition.
// You must modify the code to add your own robot specific commands here.
//
/////////////////////////////////////////////////////////////////////////////////////////
void stahp(){
	motor[RRL] = 0;
	motor[RLL] = 0;
	motor[LLL] = 0;
	motor[LRL] = 0;}

void stahpfeed(){
	motor[RF] = 0;
	motor[LF] = 0;}

task usercontrol(){
	while (true)
	{
		motor[FRD] = vexRT(Ch2);
		motor[FLD] = vexRT(Ch3);
		motor[BRD] = vexRT(Ch2);
		motor[BLD] = vexRT(Ch3);
		waitInMilliseconds(10);
		motor[FRD] = 0;
		motor[FLD] = 0;
		motor[BRD] = 0;
		motor[BLD] = 0;

		if(vexRT(Btn6U) == 1){
			motor[RRL] = 127;
			motor[RLL] = 127;
			motor[LLL] = 127;
			motor[LRL] = 127;
		}
		else if(vexRT(Btn6D) == 1){
			motor[RRL] = -127;
			motor[RLL] = -127;
			motor[LLL] = -127;
			motor[LRL] = -127;
		}
		else{
			stahp();}


		if(vexRT(Btn5U) == 1){
			motor[RF] = 127;
			motor[LF] = 127;
		}
		else if(vexRT(Btn5D) == 1){
			motor[LF] = -127;
			motor[RF] = -127;
		}
		else{
			stahpfeed();}




	}
}
