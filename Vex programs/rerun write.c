#pragma config(Sensor, dgtl1,  lft,            sensorQuadEncoder)
#pragma config(Motor,  port1,           FR,            tmotorVex269_HBridge, openLoop)
#pragma config(Motor,  port7,           BL,            tmotorServoContinuousRotation, openLoop, driveLeft, encoderPort, dgtl1)
#pragma config(Motor,  port8,           BR,            tmotorVex269_MC29, openLoop, reversed)
#pragma config(Motor,  port10,          FL,            tmotorVex269_HBridge, openLoop)
#include <FlashLib.h>

static char robotData[14988];

task rerun()
{
		int i;
    for(i=0;i<14988;i+= 6){
        robotData[i] = vexRT[Ch3];
        robotData[i+1] = vexRT[Ch2];

        wait1Msec(6);
    }

    RCFS_AddFile(robotData, 14988);
}

task main(){
	while(true){
	startTask(rerun);
	motor[FL] = vexRT(Ch3);
	motor[BL] = vexRT(Ch3);
	motor[FR] = vexRT(Ch2);
	motor[BR] = vexRT(Ch2);}
}
