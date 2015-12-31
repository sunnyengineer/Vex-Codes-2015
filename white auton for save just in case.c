
task main()
{

int kp = 2.6;
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
		while(SensorValue[lif] > height){
			motor[RRL] = 127;
			motor[RLL] = 127;
			motor[LLL] = 127;
			motor[LRL] = 127;}
	}
	if(direction == "down"){
		while(SensorValue[lif] < height){
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
	stp();
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
void skygrip(){//puts claws inwards to grab a skyrise
	setServo(LeftClaw, -70);
	setServo(RightClaw,70);}

void fold(){
	setServo(LeftClaw, -120);
	setServo(RightClaw, 120);}

string lef = "lef", rit = "rit", R = "R", L = "L", lfi = "lif", U = "up", Do = "down";
void auto(){
	aut = true;
if(x == 2 && y == 1){
		fold();
		reset(lef);
		movebac(-180);
		feed();
		reset(lef);
		move(1, 260);
		close();
		reset(lef);
		movebac(-40);
		lift(U, 2405);
		reset(lef);
		turn(R, 105);
		reset(lef);
		movebac(-30);
		lift(Do, 3000);
		feed();
		reset(lef);
		movebac(-100);
	}
if(x == 1 && y == 2){
		fold();
		reset(lef);
		movebac(-180);
		feed();
		reset(lef);
		move(1, 290);
		close();
		reset(lef);
		movebac(-90);
		lift(U, 2405);
		reset(lef);
		turn(L, -195);
		reset(lef);
		movebac(-50);
		lift(Do, 3000);
		feed();
		reset(lef);
		movebac(-100);}
if(x == 2 && y == 2){
		reset(lef);
		feed();
		move(1, 250);
		close();
		reset(lef);
		turn(R, 750);
		reset(lef);
		move(1, 100);
		feed();
		reset(lef);
		movebac(-100);}
if(x == 1 && y == 1){
	reset(lef);
		feed();
		move(1, 250);
		close();
		reset(lef);
		turn(L, -650);
		feed();
		reset(lef);
		movebac(-100);}

}
task autonomous(){
	auto();
	aut = false;
}

}
