#pragma config(Sensor, dgtl1,  lft,            sensorQuadEncoder)
#pragma config(Sensor, dgtl3,  lif,            sensorQuadEncoder)
#pragma config(Sensor, dgtl11, rig,            sensorQuadEncoder)
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
void lift(int height, string direction){
	if(direction == "up"){
		while(SensorValue[lif] < height){
			motor[RRL] = 127;
			motor[RLL] = 127;
			motor[LLL] = 127;
			motor[LRL] = 127;}
	}
	if(direction == "down"){
		while(SensorValue[lif] > height){
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
		SensorValue(lft) = 0;}
	if(encode == "rit"){
		SensorValue(rig) = 0;}
	if(encode == "lif"){
		SensorValue(lif) = 0;}
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
			int speed = error + inte + deri;
			if(speed > 127){
				int speed = 127;}
			motor[FLD] = speed;
			motor[FRD] = speed;
			motor[BLD] = speed;
			motor[BRD] = speed;}
	if(direction == 0){
		while(SensorValue[lft] > target){
			int error = -target + SensorValue[lft];
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
string lef = "lef", rit = "rit", R = "R", L = "L", lfi = "lif", U = "up", Do = "down";
task main()
{		reset(rit);
		reset(lef);
		move(1, 500);
		waitInMilliseconds(200);
		feed(900, 1);
		reset(lef);
		reset(rit);
		waitInMilliseconds(200);
		turn(L, -560);
		reset(lef);
		reset(rit);
		waitInMilliseconds(200);
		move(1, 50);
		reset(lef);
		reset(rit);
		waitInMilliseconds(200);
		feed(900, 0);
		moveback(200);
		feed(900, 0);
		moveback(200);}
