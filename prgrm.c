#pragma config(Sensor, in1,    lif,            sensorPotentiometer)
#pragma config(Sensor, in2,    ritlif,         sensorPotentiometer)
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
	int kp = 2;
bool aut = false;
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
void lift(string direction, int height){
	if(direction == "up"){
		while(SensorValue[ritlif] < height){
			motor[RRL] = 127;
			motor[RLL] = 127;
			motor[LLL] = 127;
			motor[LRL] = 127;}
	}
	if(direction == "down"){
		while(SensorValue[ritlif] > height){
			motor[RRL] = -127;
			motor[RLL] = -127;
			motor[LLL] = -127;
			motor[LRL] = -127;}
	}
	motor[RRL] = 0;
	motor[RLL] = 0;
	motor[LLL] = 0;
	motor[LRL] = 0;
}

void stp(){
	motor[FLD] = 0;
	motor[FRD] = 0;
	motor[BLD] = 0;
	motor[BRD] = 0;}

void reset(string encode){
	if(encode == "lef"){
		SensorValue[lft] = 0;}
	if(encode == "rit"){
		SensorValue[rig] = 0;}
	if(encode == "lif"){
		SensorValue[lif] = 0;}
}

void moveback(int time){
	motor[FLD] = -127;
	motor[FRD] = -127;
	motor[BRD] = -127;
	motor[BLD] = -127;
	waitInMilliseconds(time);
	stp();}
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
			int speed = (error * kp) + inte + deri;
			if(speed > 127){
				int speed = 127;}
			motor[FLD] = speed;
			motor[FRD] = speed;
			motor[BLD] = speed;
			motor[BRD] = speed;}
		stp();}
	}
void movebac(int target){
		while(SensorValue[lft] > target){
			int error = -target + SensorValue[lft];
			int inte = integral(0);
			if (error == 0){
				inte = 0;}
			if (abs(error) > 40){
				inte = 0;}
			int deri = derivative(error);
			int speed = ( error * kp) + inte + deri;
			if(speed > 127){
				int speed = 127;}
			motor[FLD] = -speed;
			motor[FRD] = -speed;
			motor[BLD] = -speed;
			motor[BRD] = -speed;}
	stp();}


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
			int speed = (error * kp) + inte + deri;
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
			int speed = (error * kp) + inte + deri;
			if(speed > 127){
				int speed = 127;}
			motor[FLD] = -speed;
			motor[FRD] = speed;
			motor[BLD] = -speed;
			motor[BRD] = speed;}
	}
}
void feed(){
		setServo(LeftClaw,120);
		setServo(RightClaw,-120);
}
void close(){
		setServo(RightClaw, -10);
		setServo(LeftClaw, -10);
	}
string lef = "lef", rit = "rit", R = "R", L = "L", lfi = "lif", U = "up", Do = "down";
task main()
{
		reset(lef);
		feed();
		waitInMilliseconds(100);
		move(1, 225);
		close();
		reset(lef);
		movebac(-210);
		reset(lef);
		turn(L, -376);
		reset(lef);
		movebac(-80);
		lift(U, 725);
		reset(lef);
		move(1, 52);
		waitInMilliseconds(500);
		feed();
		waitInMilliseconds(500);
		reset(lef);
		movebac(-75);
		lift(Do, 282);
		reset(lef);
		move(1, 275);
		waitInMilliseconds(250);
		close();
		reset(lef);
		move(1, 180);
		reset(lef);
		lift(U, 350);
		turn(R, 435);
		reset(lef);
		move(1, 1115);
		reset(lef);
		turn(R, 372);
		lift(U, 2230);
		reset(lef);
		move(1, 700);
		reset(lef);
		lift(U, 2230);
		reset(lef);
		lift(Do, 1950);
		movebac(-75);
		reset(lef);
		feed();
		movebac(-100);


}
