#pragma config(Sensor, dgtl1,  lft,            sensorQuadEncoder)
#pragma config(Motor,  port1,           FR,            tmotorVex269_HBridge, openLoop)
#pragma config(Motor,  port7,           BL,            tmotorServoContinuousRotation, openLoop, driveLeft, encoderPort, dgtl1)
#pragma config(Motor,  port8,           BR,            tmotorVex269_MC29, openLoop, reversed)
#pragma config(Motor,  port10,          FL,            tmotorVex269_HBridge, openLoop)

#include <FlashLib.h>
task main()
{

		int i = 0;
    unsigned char *data;
    int datalength;

    if(RCFS_GetFile("rerun write", &data, &datalength ) == RCFS_SUCCESS )
    {
      while(i < datalength){
        motor[FL] = *(data+i);
        motor[BL] = *(data+i);
        motor[FR] = *(data+(i+1));
        motor[BR] = *(data+(i+1));
        i+=6;
        wait1Msec(6);
    	}
    }
}
