#pragma config(Sensor, in1,    dial,           sensorPotentiometer)
#pragma config(Sensor, dgtl1,  Gre,            sensorLEDtoVCC)
#pragma config(Sensor, dgtl2,  Yel,            sensorLEDtoVCC)
#pragma config(Sensor, dgtl3,  Red,            sensorLEDtoVCC)
#pragma config(Sensor, dgtl11, Res,            sensorTouch)
#pragma config(Sensor, dgtl12, H,              sensorTouch)
#pragma config(Motor,  port1,           L,             tmotorVex393_HBridge, openLoop, reversed)
#pragma config(Motor,  port2,           Claw,          tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port10,          R,             tmotorVex393_HBridge, openLoop)
int y = 0;
int out(int y){
    while(true){
        turnLEDOn(Red);
        turnLEDOff(Gre);
        turnLEDOff(Yel);
        stopMotor(L);
        stopMotor(R);
        if(SensorValue[Res] == 1){
            y = 0;
            return(y);
        }
    }
}

int hit(int x){
    stopMotor(L);
    stopMotor(R);
    turnLEDOff(Red);
    turnLEDOff(Gre);
    turnLEDOn(Yel);
    wait(2);
    x = x + 1;
    return(x);
}

task main(){
 while(true){
        turnLEDOn(Gre);
        turnLEDOff(Red);
        turnLEDOff(Yel);
        startMotor(L, vexRT(Ch3));
        startMotor(R, vexRT(Ch2));
        waitInMilliseconds(10);
        stopMotor(L);
        stopMotor(R);
        if(SensorValue[H] == 1){
            y = hit(y);}
        if(y == 3){
            y = out(y);
        }
    }

}
