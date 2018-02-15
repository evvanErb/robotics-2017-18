#pragma config(UART_Usage, UART1, uartVEXLCD, baudRate19200, IOPins, None, None)
#pragma config(I2C_Usage, I2C1, i2cSensors)
#pragma config(Sensor, dgtl3,  led,            sensorLEDtoVCC)
#pragma config(Sensor, I2C_1,  right,          sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Sensor, I2C_2,  left,           sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Motor,  port1,           pusher,        tmotorVex393HighSpeed_HBridge, openLoop)
#pragma config(Motor,  port2,           grabber,       tmotorServoContinuousRotation, openLoop, reversed)
#pragma config(Motor,  port3,           rightWheel,    tmotorVex393_MC29, openLoop, reversed, encoderPort, I2C_1)
#pragma config(Motor,  port4,           rightWheelTwo, tmotorServoContinuousRotation, openLoop, reversed)
#pragma config(Motor,  port5,           leftWheel,     tmotorVex393_MC29, openLoop, encoderPort, I2C_2)
#pragma config(Motor,  port6,           raise,         tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port7,           leftWheelTwo,  tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port8,           liftOne,       tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port9,           liftTwo,       tmotorServoContinuousRotation, openLoop, reversed)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*        Description: Competition template for VEX EDR                      */
/*                                                                           */
/*---------------------------------------------------------------------------*/

// This code is for the VEX cortex platform
#pragma platform(VEX2)

// Select Download method as "competition"
#pragma competitionControl(Competition)

//Main competition background code...do not modify!
#include "Vex_Competition_Includes.c"

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the cortex has been powered on and    */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/
bool autonSide = true;
void pre_auton()
{
  // Set bStopTasksBetweenModes to false if you want to keep user created tasks
  // running between Autonomous and Driver controlled modes. You will need to
  // manage all user created tasks if set to false.
  bStopTasksBetweenModes = true;

  //activate LCD
  bDisplayCompetitionStatusOnLcd = true;
  bLCDBacklight = true;
  /*
  int volts =  nImmediateBatteryLevel;
  string voltage = sprintf("", "%d", volts);
  displayLCDCenteredString(0, "LEFT");
  displayLCDCenteredString(1, voltage);
  while(nLCDButtons != 2){ //While center not pressed
    if(nLCDButtons == 0) //No button pressed
      wait1Msec(10); //Do nothing
    else{ //Some button was pressed
      if(nLCDButtons == 1){
        autonSide = true; //Decrement if left press
      }
      else if(nLCDButtons == 4){
        autonSide = false; //Increment if right press
      }
      //Update display
      clearLCDLine(0);
      if(autonSide){
      	displayLCDCenteredString(0, "LEFT");
    	}else{
    		displayLCDCenteredString(0, "RIGHT");
    	}

      while(nLCDButtons != 0){//Wait for release
        wait1Msec(10); //Wait for multitasking.
      }
  	}
  }
  */
}


	// Set bDisplayCompetitionStatusOnLcd to false if you don't want the LCD
	// used by the competition include file, for example, you might want
	// to display your team name on the LCD in this function.
	// bDisplayCompetitionStatusOnLcd = false;

  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

task autonomous(){
	//motor encoder 1000 = 51"
	nMotorEncoder[rightWheel] = 0;
	nMotorEncoder[leftWheel] = 0;
	if(autonSide){
		//pick up
		motor[grabber] = -127;
		motor[pusher] = -127;
		delay(400);
		motor[grabber] = 0;
		motor[pusher] = 0;
		//lift
		motor[liftOne] = 127;
		motor[liftTwo] = 127;
		motor[raise] = -127;
		delay(1500);
		motor[liftOne] = 0;
		motor[liftTwo] = 0;
		motor[raise] = 0;
		//move forward
		//while one of the wheels less than goal
		while(nMotorEncoder[rightWheel] < 1350){
			motor[rightWheel] = 127;
			motor[rightWheelTwo] = 127;
			motor[leftWheel] = 127;
			motor[leftWheelTwo] = 127;
	}
		motor[rightWheel] = 0;
		motor[leftWheel] = 0;
		motor[rightWheelTwo] = 0;
		motor[leftWheelTwo] = 0;

		//lower XLIFT
		motor[liftOne] = -127;
		motor[liftTwo] = -127;
		delay(800);
		motor[liftOne] = 0;
		motor[liftTwo] = 0;
		//drop cone
		motor[grabber] = 127;
		delay(300);
		motor[grabber] = 0;
		//raise XLIFT
		motor[liftOne] = 127;
		motor[liftTwo] = 127;
		delay(500);
		motor[liftOne] = 0;
		motor[liftTwo] = 0;
		//pick mobile goal
		motor[raise] = 127;
		delay(1000);
		motor[raise] = 0;
		//reverse
		nMotorEncoder[rightWheel] = 0;
		nMotorEncoder[leftWheel] = 0;
		while(nMotorEncoder[rightWheel] > -900){
			motor[rightWheel] = -127;
			motor[leftWheel] = -127;
			motor[rightWheelTwo] = -127;
			motor[leftWheelTwo] = -127;
		}
		motor[rightWheel] = 0;
		motor[leftWheel] = 0;
		motor[rightWheelTwo] = 0;
		motor[leftWheelTwo] = 0;
		//turn right 90
		nMotorEncoder[rightWheel] = 0;
		nMotorEncoder[leftWheel] = 0;
		while(nMotorEncoder[rightWheel] > -850){
			motor[rightWheel] = -60;
			motor[rightWheelTwo] = -60;
			motor[leftWheel] = 60;
			motor[leftWheelTwo] = 60;
		}
		motor[rightWheel] = 0;
		motor[rightWheelTwo] = 0;
		motor[leftWheel] = 0;
		motor[leftWheelTwo] = 0;
		//forward
		nMotorEncoder[rightWheel] = 0;
		nMotorEncoder[leftWheel] = 0;
		while(nMotorEncoder[rightWheel] < 1000){
			motor[rightWheel] = 127;
			motor[leftWheel] = 127;
			motor[rightWheelTwo] = 127;
			motor[leftWheelTwo] = 127;
		}
		motor[rightWheel] = 0;
		motor[leftWheel] = 0;
		motor[rightWheelTwo] = 0;
		motor[leftWheelTwo] = 0;
		//drop
		motor[raise] = -127;
		motor[pusher] = 127;
		delay(1000);
		motor[raise] = 0;
		motor[pusher] = 0;
		//backup
		nMotorEncoder[rightWheel] = 0;
		nMotorEncoder[leftWheel] = 0;
		while(nMotorEncoder[rightWheel] > -1000){
			motor[rightWheel] = -127;
			motor[leftWheel] = -127;
			motor[rightWheelTwo] = -127;
			motor[leftWheelTwo] = -127;
			motor[pusher] = -127;
		}
		motor[pusher] = 0;
		motor[rightWheel] = 0;
		motor[leftWheel] = 0;
		motor[rightWheelTwo] = 0;
		motor[leftWheelTwo] = 0;
	}
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/


//DEADBAND
int deadBand(int val){
	if(fabs(val) <= 10){
		return(0);
	}else{
		return(val);
	}
}

task usercontrol()
{
  // User control code here, inside the loop

  while (true)
  {
  	//LCD
  /*
	  bDisplayCompetitionStatusOnLcd = true;
	  bLCDBacklight = true;
	  int volts =  nImmediateBatteryLevel;
	  string voltage = sprintf("", "%d", volts);
	  displayLCDCenteredString(0, "LEFT");
	  displayLCDCenteredString(1, voltage);
	  */

		//MOVE with joysticks
		motor[rightWheel] = deadBand(vexRT[Ch2]) - deadBand(vexRT[Ch1]) - deadBand(vexRT[Ch4]);
		motor[rightWheelTwo] = deadBand(vexRT[Ch2]) - deadBand(vexRT[Ch1]) - deadBand(vexRT[Ch4]);
		motor[leftWheel] = deadBand(vexRT[Ch2]) + deadBand(vexRT[Ch1]) + deadBand(vexRT[Ch4]);
		motor[leftWheelTwo] = deadBand(vexRT[Ch2]) + deadBand(vexRT[Ch1]) + deadBand(vexRT[Ch4]);

		if(vexRT[Btn8U] == 1){
			motor[rightWheel] = 127;
			motor[rightWheelTwo] = 127;
			motor[leftWheel] = 127;
			motor[leftWheelTwo] = 127;
		}
		else if(vexRT[Btn8D] == 1){
			motor[rightWheel] = -127;
			motor[rightWheelTwo] = -127;
			motor[leftWheel] = -127;
			motor[leftWheelTwo] = -127;
		}
		else if(vexRT[Btn8R] == 1){
			motor[rightWheel] = -127;
			motor[rightWheelTwo] = -127;
			motor[leftWheel] = 127;
			motor[leftWheelTwo] = 127;
		}
		else if(vexRT[Btn8L] == 1){
			motor[rightWheel] = 127;
			motor[rightWheelTwo] = 127;
			motor[leftWheel] = -127;
			motor[leftWheelTwo] = -127;
		}

		//raise and lower lift MOBILE GOAL
		if(vexRT[Btn5U] == 1){
			motor[raise] = 127;
		}
		else if(vexRT[Btn5D] == 1){
			motor[raise] = -127;
		}
		else{
			motor[raise] = 0;
		}

		//raise and lift X-LIFT in unison
		if(vexRT[Btn7U]==1){
			motor[liftOne] = 127;
			motor[liftTwo] = 127;
		}
		else if(vexRT[Btn7D]==1){
			motor[liftOne] = -127;
			motor[liftTwo] = -127;
		}
		//one side x-lift at a time
		else if(vexRT[Btn8LXmtr2]==1){
			motor[liftOne] = 127;
		}
		else if(vexRT[Btn8RXmtr2]==1){
			motor[liftTwo] = 127;
		}
		else if(vexRT[Btn7LXmtr2]==1){
			motor[liftOne] = -127;
		}
		else if(vexRT[Btn7RXmtr2]==1){
			motor[liftTwo] = -127;
		}

		//x-lift joy stick
		else{
			motor[liftOne] = deadBand(vexRT[Ch2Xmtr2]);
			motor[liftTwo] = deadBand(vexRT[Ch2Xmtr2]);
	 	}

	 	//activate pusher
		if(vexRT[Btn7UXmtr2]==1){
			motor[pusher] = 127;
		}
		//retract pusher
		else if(vexRT[Btn7DXmtr2]==1){
			motor[pusher] = -127;
		}
		else{
			motor[pusher] = 0;
		}

		//GRAB with x-lift RUBBERS joystick
		motor[grabber] = deadBand(vexRT[Ch4Xmtr2]);
  }
}
