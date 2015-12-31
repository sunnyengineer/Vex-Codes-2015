#pragma config(Sensor, in1,    lif,            sensorPotentiometer)
#pragma config(Sensor, in2,    ritlif,         sensorPotentiometer)
#pragma config(Sensor, in3,    leftLF,         sensorLineFollower)
#pragma config(Sensor, in4,    midLF,          sensorLineFollower)
#pragma config(Sensor, in5,    gyro,           sensorGyro)
#pragma config(Sensor, in6,    rightLF,        sensorLineFollower)
#pragma config(Sensor, in7,    accel,          sensorAccelerometer)
#pragma config(Sensor, dgtl3,  sky,            sensorDigitalOut)
#pragma config(Sensor, dgtl4,  rig,            sensorQuadEncoder)
#pragma config(Sensor, dgtl6,  lft,            sensorQuadEncoder)
#pragma config(Motor,  port1,           FLD,           tmotorVex393_HBridge, openLoop, reversed)
#pragma config(Motor,  port2,           RLL,           tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           BRD,           tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port4,           RRL,           tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port5,           LLL,           tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port6,           RightClaw,     tmotorServoStandard, openLoop)
#pragma config(Motor,  port7,           LRL,           tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           LeftClaw,      tmotorServoStandard, openLoop)
#pragma config(Motor,  port9,           FRD,           tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port10,          BLD,           tmotorVex393_HBridge, openLoop)
#pragma platform(VEX)

//Competition Control and Duration Settings
#pragma competitionControl(Competition)
#pragma autonomousDuration(0)
#pragma userControlDuration(60)

#include "Vex_Competition_Includes.c"   //Main competition background code...do not modify!

/////////////////////////////////////////////////////////////////////////////////////////
//
//                         Driver Skills Template
//
// This is a template for the driver skills competition. It is identical in structure to
// the standard competition template except that the two "#pragma' statements above (and
// copied below) adjust the time limits for the competition.
//				#pragma autonomousDuration(0)
//				#pragma userControlDuration(60)
// The autonomous duration for "Driver Skills" is zero; i.e. there is no autonomous phase.
// The user control duration is 60 seconds
//
// NOTE: The above two pragmas only impact the Crystal implementation. For systems using
//       VEXNET, the VEXNET system ignores these statements as it has the durations
//       for the competition built-in.
//
// Whenever this user program is run, the duration is automatically sent to the VEX master
// processor. The master CPU will only accept these commands once per power=on cycle. So, it's
// best to power cycle your VEX to ensure that they get recognized in case you were
// previously running a standard competition program with different durations.
//
// Testing Via Crystals:
// ====================
//
// The procedure to test a Driver Skills program using the crystals is as follows:
//
// 1. Turn off power to the Crystal transmitter/joysticks.
//
// 2. Turn on your VEX so that the Driver Skills program is running.
//
// 3. Driver skills program segment of your program will start running. At the end of 60
//    seconds the VEX Master CPU will turn off the motors.
//
// 4. Repeat the above sequence
//
//
// Testing Via VEXNET Using VEXNET Competition Switch
// ==================================================
//
// The procedure to test a Driver Skills program using VEXNET Competition Switch is as follows:
//
// 1. Set the two switches on the Competition switch to "DISABLE" and "USER CONTROL"
//
// 2. Start the Driver skills program
//
// 3. Set Switch to ENABLE from DISABLE
//
// 4. You need to manually time the 60 second duration.
//
// 5. Set Switch to DISABLE
//
// 6. Repeat from step (3) to run subsequent test runs. There's no need to reset the VEX or
//    restart your user program.
//
//
// Testing Via VEXNET Using ROBOTC IDE
// ==================================================
//
// It is not necessary to own a VEXNET switch. ROBOTC has a test window that allows the same functionality.
// The test window has three buttons for "DISABLE", "AUTONOMOUS", "USER CONTROL".
//
// 1. Open the ROBOTC Debugger. Then open the "Competition Control" Debugger window.
//
// 2. Start your Driver Skills program running.
//
// 3. Click the "DISABLED" button on the "Competition Control" window.
//
// 4. Click the "USER CONTROL" button on the "Competition Control" window.
//
// 5. You need to manually time the 60 second duration.
//
// 6. Click the "DISABLED" button on the "Competition Control" window.
//
// 7. Repeat from step (4) to run subsequent test runs. There's no need to reset the VEX or
//    restart your user program.
//
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
//
//                          Pre-Autonomous Functions
//
// You may want to perform some actions before the competition starts. Do them in the
// following function.
//
/////////////////////////////////////////////////////////////////////////////////////////

void pre_auton()
{
  // Set bStopTasksBetweenModes to false if you want to keep user created tasks running between
  // Autonomous and Tele-Op modes. You will need to manage all user created tasks if set to false.
  bStopTasksBetweenModes = true;

	// All activities that occur before the competition starts
	// Example: clearing encoders, setting servo positions, ...
}

/////////////////////////////////////////////////////////////////////////////////////////
//
//                                 Autonomous Task
//
// The "Driver Skills" competition has no autonomous phase. Simply leave the following
// placeholder.
//
/////////////////////////////////////////////////////////////////////////////////////////

int kp = 3.2;  // kill switches and constants for PID, do not mess with these
int ki = 1;
bool aut = false;
bool kill = false;
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
void lift(string direction, int rheight, int lheight){// decently self explanatory, it either goes up or down according to the
	//right potentiometer height and left potentiometer height, with left being negative
	if(direction == "up"){
		while(SensorValue[ritlif] < rheight){
			motor[RRL] = 127;
			motor[RLL] = 127;}

		while(SensorValue[lif] > lheight){
			motor[LLL] = 127;
			motor[LRL] = 127;}
}
	if(direction == "down"){
		while(SensorValue[ritlif] > rheight){
			motor[RRL] = -127;
			motor[RLL] = -127;}
		while(SensorValue[lif] < lheight){
			motor[LLL] = -127;
			motor[LRL] = -127;}
	}
	motor[RRL] = 0;
	motor[RLL] = 0;
	motor[LLL] = 0;
	motor[LRL] = 0;
}

void stp(){//kills drive motors
	motor[FLD] = 0;
	motor[FRD] = 0;
	motor[BLD] = 0;
	motor[BRD] = 0;}

void reset(string encode){//resets encoders and gyro based upon what is put in parenthesis
	if(encode == "lef"){
		SensorValue[lft] = 0;}
	if(encode == "rit"){
		SensorValue[rig] = 0;}
	if(encode == "lif"){
		SensorValue[lif] = 0;}
	if(encode == "giro"){
		SensorValue[gyro] = 1;}
}
//error, inte, deri, and speed are all part of PID
void move(int direction, int target){//standard forward movement
	if(direction == 1){
		while(SensorValue[lft] < target){
			int error = target - SensorValue[lft];
			int inte = integral(0);
			if (error == 0){
				inte = 0;}
			if ( abs(error) > 40){
				inte = 0;}
			int deri = derivative(error);
			int speed = (error * kp) + (inte * ki) + deri;
			if(speed > 127){
				int speed = 127;}
			motor[FLD] = speed;
			motor[FRD] = speed;
			motor[BLD] = speed;
			motor[BRD] = speed;}
		stp();}
}
void movebac(int target){//standard movement back, target int is distance travelled, positive
	while(SensorValue[lft] > target){
		int error = -target + SensorValue[lft];
		int inte = integral(0);
		if (error == 0){
			inte = 0;}
		if (abs(error) > 40){
			inte = 0;}
		int deri = derivative(error);
		int speed = ( error * kp) + (inte * ki) + deri;
		if(speed > 127){
			int speed = 127;}
		motor[FLD] = -speed;
		motor[FRD] = -speed;
		motor[BLD] = -speed;
		motor[BRD] = -speed;}
	stp();
}
//don't worry about the music

void turn(string direction, int angle){// turn function, L is left turn with a positive desired turn and R is right and
	//negative
	if(direction == "L"){
		while(SensorValue[gyro] < angle){
			int error = angle - SensorValue[lft];
			int inte = integral(0);
			while (error < 0){
				error = -error;}
			if (error == 0){
				inte = 0;}
			if ( abs(error) > 40){
				inte = 0;}
			int deri = derivative(error);
			int speed = (error * kp) + (inte * ki) + deri;
			if(speed > 127){
				int speed = 127;}
			motor[FLD] = -(speed);
			motor[FRD] = (speed);
			motor[BLD] = -(speed);
			motor[BRD] = (speed);}
	}
	if(direction == "R"){
		while(SensorValue[gyro] > angle){
			int error = -angle + SensorValue[lft];
			int inte = integral(0);
			while (error < 0){
				error = -error;}
			if (error == 0){
				inte = 0;}
			if ( abs(error) > 40){
				inte = 0;}
			int deri = derivative(error);
			int speed = (error * kp) + (inte * ki) + deri;
			if(speed > 127){
				int speed = 127;}
			motor[FLD] = (speed*1.35);//up the 1.35 if the robot fails it's right turns any
			motor[FRD] = -(speed*1.35);
			motor[BLD] = (speed*1.35);
			motor[BRD] = -(speed*1.35);}
	}
stp();
}
void swinturn(string direction, int angle, int forw){// turn function, L is left turn with a positive desired turn and R is right and
	//negative
	if(direction == "L" && forw == 0){
		while(SensorValue[gyro] < angle){
			int error = angle - SensorValue[lft];
			int inte = integral(0);
			while (error < 0){
				error = -error;}
			if (error == 0){
				inte = 0;}
			if ( abs(error) > 40){
				inte = 0;}
			int deri = derivative(error);
			int speed = (error * kp) + (inte * ki) + deri;
			if(speed > 127){
				int speed = 127;}
			motor[FLD] = -(speed);
			motor[BLD] = -(speed);
			}
	}
		if(direction == "L" && forw == 1){
		while(SensorValue[gyro] < angle){
			int error = angle - SensorValue[lft];
			int inte = integral(0);
			while (error < 0){
				error = -error;}
			if (error == 0){
				inte = 0;}
			if ( abs(error) > 40){
				inte = 0;}
			int deri = derivative(error);
			int speed = (error * kp) + (inte * ki) + deri;
			if(speed > 127){
				int speed = 127;}
			motor[FRD] = (speed);
			motor[BRD] = (speed);
			}
	}
	if(direction == "R" && forw == 0){
		while(SensorValue[gyro] > angle){
			int error = -angle + SensorValue[lft];
			int inte = integral(0);
			while (error < 0){
				error = -error;}
			if (error == 0){
				inte = 0;}
			if ( abs(error) > 40){
				inte = 0;}
			int deri = derivative(error);
			int speed = (error * kp) + (inte * ki) + deri;
			if(speed > 127){
				int speed = 127;}
//up the 1.35 if the robot fails it's right turns any
			motor[FRD] = -(speed*1.35);
			motor[BRD] = -(speed*1.35);}
	}
	if(direction == "R" && forw == 1){
		while(SensorValue[gyro] > angle){
			int error = -angle + SensorValue[lft];
			int inte = integral(0);
			while (error < 0){
				error = -error;}
			if (error == 0){
				inte = 0;}
			if ( abs(error) > 40){
				inte = 0;}
			int deri = derivative(error);
			int speed = (error * kp) + (inte * ki) + deri;
			if(speed > 127){
				int speed = 127;}
//up the 1.35 if the robot fails it's right turns any
			motor[FLD] = (speed*1.35);
			motor[BLD] = (speed*1.35);}
	}
stp();
}
void feed(){//opens claws
	setServo(LeftClaw,120);
	setServo(RightClaw,-120);
}
void close(){//puts claws in starting postion
	setServo(RightClaw, -10);
	setServo(LeftClaw, -10);
}
void skygrip(){//puts claws inwards to grab a skyrise
	setServo(LeftClaw, -70);
	setServo(RightClaw,70);}

void fold(){
	setServo(LeftClaw, -120);
	setServo(RightClaw, 120);}

string lef = "lef", rit = "rit", R = "R", L = "L", lfi = "lif", U = "up", Do = "down", giro = "giro";
void programskills(){
		fold();
		reset(lef);
		movebac(-180);
		close();
		reset(giro);
		turn(R, -203);
		lift(U, 660, 3230);
		feed();
		reset(lef);
		move(1, 73);
		waitInMilliseconds(200);
		skygrip();
		lift(U, 910, 2890);
		reset(lef);
		movebac(-360);//high bat 290, low bat 310
		reset(giro);
		turn(R, -205);//low bat 205, high bat 180
		reset(lef);
		movebac(-40);//low bat -40, high bat -60
		lift(Do, 810, 2990);
		lift(U, 740, 3050);
		reset(lef);
		move(1, 50);
		reset(lef);
		movebac(-50);//low bat 110, high bat 60
		feed();
		lift(Do, 290,3715);
		reset(lef);
		movebac(-20);
		reset(giro);
		swinturn(L, 710, 0);
		feed();
		reset(lef);
		move(1, 250);
		close();
		reset(lef);
		movebac(-100);
		lift(U, 310, 3695);
		reset(giro);
		turn(R, -680);//low bat 740, high bat 700
		lift(U, 975, 3030);
		reset(lef);
		move(1, 290);
		lift(Do, 800, 3205);
		feed();
		reset(lef);
		movebac(-100);
		fold();
		lift(Do, 290,3715);
		reset(giro);
		turn(L, 200);
		stp();
		waitInMilliseconds(5000);
		reset(lef);
		movebac(-180);
		close();
		reset(giro);
		turn(R, -203);
		lift(U, 660, 3230);
		feed();
		reset(lef);
		move(1, 73);
		waitInMilliseconds(200);
		skygrip();
		lift(U, 1300, 2500);
		reset(lef);
		movebac(-360);//high bat 290, low bat 310
		reset(giro);
		turn(R, -260);//low bat 205, high bat 180
		reset(lef);
		movebac(-40);
		lift(Do, 900, 3000);
		reset(lef);
		move(1, 50);
		feed();}

task autonomous()
{
		SensorType[in5] = sensorNone;
 		waitInMilliseconds(1000);
 		//Reconfigure Analog Port 8 as a Gyro sensor and allow time for ROBOTC to calibrate it
 		SensorType[in5] = sensorGyro;
 		waitInMilliseconds(2000);
		programskills();
}

/////////////////////////////////////////////////////////////////////////////////////////
//
//                                 User Control Task
//
// This task is used to control your robot during the user control phase of a VEX Competition.
// You must modify the code to add your own robot specific commands here.
//
/////////////////////////////////////////////////////////////////////////////////////////

task usercontrol()
{

	while (true)
	{

	}
}
