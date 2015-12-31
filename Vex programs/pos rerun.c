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
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#define spinJoy Ch1
#define fwdJoy Ch3

//forewarning, I can't spell for my life, also all line numbers referenced are subject to change, but should get you in the right area.

task main()
{
	const int maxPower = 127; //max power of vex motors
	float powerPercent = 1; //var to set power to the bot
	float power = 0; //power to write to motors

	//A bunch of vars for the program, should be self explainitory
	int armMotor;
	int spinVal;
	int forwardVal;

	bool fwd = false;
	bool bwd = false;

	char encoderVal[15];
	char powerVal[15];

	bool fwdJoyTog = false;

	bool spinJoyTog = false;
	bool leftSpin = false;
	bool rightSpin = false;

	bool crabJoyTog = false;
	bool crabLeft = false;
	bool crabRight = false;

	bool armTog = false;
	bool upArm = false;
	bool downArm = false;
	bool close = false;
	bool intakeTog = false;
	bool intakeIn = false;
	bool intakeOut = false;
	bool intakeOff = false;
	bool intakePrintTog = false;

	bool fwdNotCrab = true;

	int intakeVal;
	int intakeVal1;

	clearDebugStream();

	while (true)
	{
		//A bunch of buttons on the VEX partner remote allow for the remapping of power
	  //I had difficulties using the joystick on the main remote to change the power like most people do in Driver Control
	  //So to fix this the power is fixed and the Joysticks just determine direction. You can change the power of the motors
		//Using these buttons on the partner remote
		if (vexRT[Btn7UXmtr2] == 1)
		{
			powerPercent = 0.1;
		}
		if (vexRT[Btn7LXmtr2] == 1)
		{
			powerPercent = 0.2;
		}
		if (vexRT[Btn7DXmtr2] == 1)
		{
			powerPercent = 0.3;
		}
		if (vexRT[Btn7RXmtr2] == 1)
		{
			powerPercent = 0.4;
		}
		if (vexRT[Btn8UXmtr2] == 1)
		{
			powerPercent = 0.5;
		}
		if (vexRT[Btn8LXmtr2] == 1)
		{
			powerPercent = 0.6;
		}
		if (vexRT[Btn8DXmtr2] == 1)
		{
			powerPercent = 0.7;
		}
		if (vexRT[Btn8RXmtr2] == 1)
		{
			powerPercent = 0.8;
		}
		if (vexRT[Btn5UXmtr2] == 1)
		{
			powerPercent = 0.9;
		}
		if (vexRT[Btn6UXmtr2] == 1)
		{
			powerPercent = 1.0;
		}
		//How I calculate the power since max power for vex is 127, not 100, so 50% power is 63.5 power
		power = powerPercent*maxPower;

		//Super useful button to clear the debug stream, basically for when you mess up with your route and want to restart the recording
		if (vexRT[Btn7U] == 1)
		{
			clearDebugStream();
		}

		//I had huge issues with crabbing, so at the end of the day I had to make it a toggle. What this means is that the
		//left joystick controls forward, backwards, and crabbing, fwd/bwd being on the y axis while crab is on the x axis of
		//the joystick. However, it is locked to on fwd/bwd movement when the program is started up. By pressing BTN 8R, this
		//allows for only crab movements to be made and recorded. So you bassically have to use this button to toggle between
		//either forward/backward movement, or crabbing on the left joystick. The reason this even is needed is because while
		//going forward, its common to sway a little bit into the x axis, causing the program to think you want to crab. And
		//since there is no variable power in Auto Auto, it would cause the bot to crab for like 1 degree at full power,
		//causing issues with the debug stream print out and the actual possiton of the bot. There is probably a way to fix
		//this, but wasnt worth the time to figure out during the season.
		if (vexRT[Btn8U] == 1)
		{
			fwdNotCrab = true;
		}

		//Two button toggle because I'm lazy, but ended up being more helpful. You know when you press 8U the bot will be in
		//fwd/bwd movement, and vise versa with 8R, instead of guessing which state the toggle is in and accidentally messing up
		//the recording in the debug stream.

		if (vexRT[Btn8R] == 1)
		{
			fwdNotCrab = false;
		}

		//controls

		//A warning, this is were things get confusing, even for me. I'm commenting this code months after i wrote this section,
		//which took a good month to figure out. So bare with me here, I'll do my best to explain this messy code.

		//first conditinal checks that the bot is in fwd/bwd mode and not crab mode.
		if (fwdNotCrab == true){
		if (vexRT[fwdJoy] >= 10)//Adds a thershhold of +10 to set values
		{
			//so if someone is pushing the fwdJoy in the possitive y direction, turn all of these vars to these states
			fwdJoyTog = true;
			fwd = true;

			//this is setting the fwd power car to the global power var, which was dicussed earlier in the code
			forwardVal = power; //sets + joy values to varibles
		}
		//seeing if the joy is being pushed in the negative y direction, meaning the bot should go backwards
		else if (vexRT[fwdJoy] <= -10)//Adds a thershhold of -10 to set values
		{
			fwdJoyTog = true;
			bwd = true;
			forwardVal = -power; //sets - joy values to varibles
		}
		//If the fwdJoy is not being touched, then check all this:
		else
		{
			if (fwdJoyTog == false)//if there is no input to the fwdJoy,
			{
			if (crabJoyTog == false)//if there is no input to the crabJoy,
			{
				if(spinJoyTog == false)//if there is no input to the spinJoy,
				{
					SensorValue[lft] = 0; //clear the encoder on the front wheel(which is used for all encoder values)
					//when the bot isnt moving, basically  resetting the bot for the next move.
					//The reason for this is to make sure that while youre trying to spin the bot, the code isnt clearing the encoder
					//because its all like "Oh hey, no one is trying to move forward so I better clear the encoder" which is the same
					//encoder the spin is using to record its turn. Which would result in 0 being pritned out over and over again.
					//*Skip this next explination unless you have a good grasp on what is going on, it's not critical*
					//(If you really get into the code you'll realise that the spin is done with a gyro instead of a encoder, but
					//it used to be done with the same encoder, and could be swiched back to one if your team does not own a gyro
					//(which i would really recomend you get one, they are amazing). So yeah it is possible to do without a gyro.)
				}}
			}else{//This is an else statment to the first if statement above: 	if (fwdJoyTog == false)
			//so if fwdJoyTog is true, which got changed to true if the fwdjoy was moving in the positive or negative
			//Y direction, see above (line ~167 & 176).

			//so an important note here is that the only way the code will get to the above else statement, is if the if on line 164
			//and the else if on line 174 evalutate to be false. So basically while the fwdJoy is being pushed forward, the code stays in
			//the if on line 164 and writes the power to the bot (bottom of the code) so that it moves forward.
			//So then when you return the fwdJoy to 0, the code goes to the else on line 181, but the if on line 183 evaluates to be
			//false, since fwdJoyTog is still true from the if on line 164, bringing us here to this else. So this code will
			//only activate once per movement, since fwdJoyTog gets reset to false at the end of this code. So this is the code
			//that prints the last movement to the debugstream. And the next loop through the code goes to line 189, resetting the
			//encoder for the next move. Thus, the next time you move fwdJoy the bot will move, causing the encoder to count,
			//and that value will get printed out using the code below. And the cycle continues indefinatly.


					//this if detecs if the bot was going forward (fwdJoy was positive Y) or backwards (fwdJoy negative Y) which will be
					//delt with below
					if (fwd == true)// meaning the bot went forward
					{
						//so we conver our current encoder value and power values from ints to strings and store them in our
						//char arrays that we declared at the top of the code.
						sprintf(encoderVal, "%d", abs(SensorValue[lft]));

						//then we start to write to the debug stream all of our data, in the exact format that our functions use.
						//You can edit this to mimic your own functions, or use my included functions: MechWheelFunctions.
						//In MechWheelFunctions, the function for forward looks like "forwardFour(pwr, degs);" where pwr and degs
						//are arguments for power and degrees, respectivly. So, we print out EXACTLY what we want the code to look
						//like, right down to the simi colon to finish of the statement. This way we can copy and paste the code
						//directly from the debug stream to an autnomous section in a comp code. As you can see we print out the
						//start of the function, followed by the power, then a comma, then the encoder value, the end it with a close
						//parenthase and a simicolon.
						//An important distinction to remeber is that this is literally text, the program does not "realize" it is
						//printing code. I could make it print the word "apple" whenever the bot moves forward, but instead I'm
						//telling it to print letters that correspong directly to my fucntions code, so that when they are pasted
						//into another file with correct pragmas, etc. It'll execute the move you just drove it to do perfectly.
						writeDebugStream("move(1,");
						writeDebugStream(encoderVal);
						writeDebugStreamLine(");");

						//resetting the vars so that this doesnt get stuck in an endless loop :P Also ensures that the information is only printed
						//once then the encoder is reset.
						fwd = false;
						fwdJoyTog = false;
					}else{

						//if fwd = false, then it must be going backwards. So here is the same code, just using backwardFour instead of ForwardFour
						sprintf(encoderVal, "%d", abs(SensorValue[lft]));
						sprintf(powerVal, "%d", power);
						writeDebugStream("movebac(-");
						writeDebugStream(encoderVal);
						writeDebugStreamLine(");");
						bwd = false;
						fwdJoyTog = false;
				}
			}
			//this is if fwd is not moving, then neither should the bot, so this sets forwardVal (the var that is written to the motors at the
			//bottom of the code) to 0, thus stopping the bot.
			forwardVal = 0;
		}
	}

	//the rest of the code is the same except coded for crabbing and spinning. Ill add comments were necisary but for the most part is the same
	//concept.


		//Setting variables for Spin
		if (vexRT[spinJoy] >= 10)
		{
			spinJoyTog = true;
			rightSpin = true;
			spinVal = power; //sets + joy values to varibles
		}
		else if(vexRT[spinJoy] <= -10)
		{
			spinJoyTog = true;
			leftSpin = true;
			spinVal = -power;
		}
		else
		{
			if (spinJoyTog == false)
			{
			if (crabJoyTog == false)//pretty sure you don't need this if and the next one here, since
															//spinning uses a gyro and not the same encoder as crab and fwd, but
															//I left it here in case you dont have a gyro, this should all work
															//with an encoder with a little tweaking to this section and to the
															//spin function in MechWheelFunctions.c
			{
				if(fwdJoyTog == false)
				{
					SensorValue[lft] = 0;
				}}
			}else{
					if (rightSpin == true)// meaning the bot went right
					{
						sprintf(encoderVal, "%d", abs(SensorValue[lft]));
						writeDebugStream("turn(R,");
						writeDebugStream(encoderVal);
						writeDebugStreamLine(");");
						rightSpin = false;
						spinJoyTog = false;
					}else{
						sprintf(encoderVal, "%d", abs(SensorValue[lft]));
						sprintf(powerVal, "%d", power);
						writeDebugStream("turn(L, -");
						writeDebugStream(encoderVal);
						writeDebugStreamLine(");");
						leftSpin = false;
						spinJoyTog = false;
				}
			}
			spinVal = 0;
		}


		//Setting variables for arms up
		if (vexRT[Btn6U]== 1 && vexRT[Btn6D]== 0 )//Checks for single button press
		{
			armTog = true;
			upArm = true;
			armMotor = power;
		}
		else if (vexRT[Btn6U]== 0 && vexRT[Btn6D]== 1  )//Checks for single button press
		{
			armTog = true;
			downArm = true;
			armMotor = -power;
		}else{
			if(armTog == false)
			{
				//SensorValue[armRightE] = 0;
				//this is incase you have an encoder on your arm system instead of a potentionmeter like we used.
				//so with a little tweaking to this section and to the armUp and armDown functions in MechWheelFunctions.c
				//you could get this to work with an encoder instead of a pot.
			}else{
				if(upArm == true)
				{
						sprintf(encoderVal, "%d", abs(SensorValue[ritlif]));
						writeDebugStream("lift(U,");
						writeDebugStream(encoderVal);
						writeDebugStreamLine(");");
						upArm = false;
						armTog = false;
					}else{
						sprintf(encoderVal, "%d", abs(SensorValue[ritlif]));
						sprintf(powerVal, "%d", power);
						writeDebugStream("lift(Do,");
						writeDebugStream(encoderVal);
						writeDebugStreamLine(");");
						downArm = false;
						armTog = false;
				}
			}
			armMotor = 0;
		}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


		//this next code is for an intake, which is different from the other sections of the code. Instead of using an encoder on the intake,
		//we discovered that you usually want to leave the intake on for a little while of the program. So this section makes the intake act
		//like a toggle, so you push button 5U and the intake intakes inward. So you keep holding the intake in button while you do your
		//movements, and then let go. Instead of using a function for this, we literally just turn the intake on and off by writting a
		//power varable directly to the intake motor. So the debug stream will print out "motor[intake]=127" or whatever power you were
		//on. When you let go it'll print out "motor[intake]=0" so when you copy and paste the intake will turn on and off for the right duration.

		if (vexRT[Btn5U]== 1 && vexRT[Btn5D]== 0 )//Checks for single button press
		{
			intakeTog = true;
			intakeIn = true;
			setServo(LeftClaw,120);
			setServo(RightClaw,-120);
			if(intakePrintTog == false)
			{
				writeDebugStreamLine("feed();");
				intakePrintTog = true;
			}
		}
		else if (vexRT[Btn5U]== 0 && vexRT[Btn5D]== 1  )//Checks for single button press
		{
			close = true;
			intakeTog = true;
			intakeOut = true;
			setServo(RightClaw, -10);
			setServo(LeftClaw, -10);
			if(intakePrintTog == false)
			{
				writeDebugStreamLine("close();");
				intakePrintTog = true;
			}}
			else{

			if(intakeTog == false)
			{
				if(intakeOff == true)
				{
					intakeOff = false;
				}
			}else{
				if(intakeIn == true)
				{
						intakeIn = false;
						intakeTog = false;
						intakeOff = true;
						intakePrintTog = false;

					}else{
						intakeOut = false;
						intakeTog = false;
						intakeOff = true;
						intakePrintTog = false;
				}
			}
			intakeVal = 0;
		}



/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		//Values to write values from each side, in order to make setting varibales above easier
		//NOTE: Do NOT change these to negative values if the bot its running in reverse, reverse the motor
		//in the pragma.

		//This is were we write the vars that we assigned throughout the code so that the bot actually moves. Pretty simple stuff here.

		motor[FRD] = forwardVal - spinVal;
		motor[BRD] = forwardVal - spinVal;
		motor[FLD] = forwardVal + spinVal;
		motor[BLD] = forwardVal + spinVal;
		motor[RRL] = armMotor + 20 ;
		motor[LLL] = armMotor + 20 ;
		motor[RLL] = armMotor + 20 ;
		motor[LRL] = armMotor + 20 ;


		//These next few lines are in case you wanted to have an arm limit in auto auto. I wouldnt worry so much about what memoryPot is,
		//just add an arm limit here if you desire (so your bot doesnt flip while running auto auto ;P

		/*	if(SensorValue[armLeftE] < SensorValue[memoryPot])
		{
			motor[armRight] = armMotor - 30 ;
			motor[armLeft] = armMotor - 30;
		}*/


		//That's it! Feel free to contact me on the fourms on email me at mover333@gmail.com

		//You are free to make any edits and this code is public, but please give any credit for the original code to me, Mitchell Overfield.

		//Thanks for anyone and everyone who makes VEX possible, it has changed my life and I am forever grateful for these oppertunities.

}


}
