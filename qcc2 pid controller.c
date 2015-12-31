#ifndef PIDController_h
#define PIDController_h

typedef struct Controller{
	float timer, dT;
	float kP, kI, kD, epsilon, slewRate;
	int error, lastError;
	float errorSum;
	float output, lastOutput;
}PID;
void pidInit(PID &pid, float kP, float kI, float kD, float epsilon, float slewRate)
{
	pid.timer = nPgmTime;
	pid.kP = kP;
	pid.kI = kI;
	pid.kD = kD;
	pid.epsilon = epsilon;
	pid.slewRate = slewRate;
	pid.error = 0;
	pid.output = 0;
}
 float pidFilteredOutput(PID &pid)
 {
   float filteredOut = 0;
   if(pid.dT != 0 && pid.output != 0)
   {
     if(abs(pid.output - pid.lastOutput)/pid.dT > pid.slewRate)
       			filteredOut = pid.lastOutput + pid.slewRate*pid.dT * (pid.output/abs(pid.output));
     else
       			filteredOut = pid.output;
 	 }
 	 if(abs(filteredOut) > 127)
 	   			 filteredOut = 127 * filteredOut/abs(filteredOut);

 	 return filteredOut;
}

float pidExecute(PID &pid, float error)
{
	      pid.lastError = pid.error;
	      pid.error = error;

	      pid.dT = (nPgmTime - pid.timer)/1000;
	      pid.timer = nPgmTime;
	      delay(10);

	      float rate;
	      if(abs(pid.dT) > 0)
	      				rate = (pid.error - pid.lastError)/pid.dT;
	      else
	      	      rate = 0;

	      if(abs(error) > pid.epsilon)
	      				pid.errorSum +=error*pid.dT;

	      pid.lastOutput = pid.output;
	      pid.output = error * pid.kP + pid.errorSum * pid.kI + rate * pid.kD;

	      return pidFilteredOutput(pid);
}

void pidReset(PID &pid)
{
			  pid.errorSum = 0;
			  pid.dT = 0;
			  pid.lastOutput = 0;
			  pid.lastError = 0;
}
#endif
