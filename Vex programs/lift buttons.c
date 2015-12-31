
task main()
{
if(vexRT(Btn7D) == 1){ //code for anti-sleep
	motor[leftlift] = (127*.1);
	motor[rightlift] = (127*.1);
	waitInMilliseconds(10);
	stopMotor(leftlift);
	stopMotor(rightlift);}

if(vexRT(Btn8D) == 1){ //front hook//
	motor[hook] = 127;
	waitInMilliseconds(2000);
	stopMotor(hook);}



}
