#pragma config(Motor,  port1,           m2,            tmotorVex393_HBridge, openLoop)
#pragma config(Motor,  port10,          m3,            tmotorVex393_HBridge, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task main(){
	while(true){
		if(vexRT(Btn8D) == 1){
			motor[m2] = 127;
			motor[m3] = 127;
		}
		else{
			motor[m2] = 0;
			motor[m3] = 0;}
	}
}