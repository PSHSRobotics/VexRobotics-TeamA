/*---------------------------------------------------------------------------*/
/*                                                                           */
/*        Description: Competition template for VEX EDR                      */
/*                                                                           */
/*---------------------------------------------------------------------------*/

// This code is for the VEX cortex platform
#pragma platform(VEX2)
#pragma config(Motor,  port2,            ,             tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,            ,             tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,            ,             tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,            ,             tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,            ,             tmotorVex393_MC29, openLoop)

// Select Download method as "competition"
#pragma competitionControl(Competition)

//Main competition background code...do not modify!
#include "Vex_Competition_Includes.c"

void moveForward(int speed){
	setMotor(port2, -1 * speed);
	setMotor(port3, speed);
	forward(speed);
	stopMotor(port2);
	stopMotor(port3);
}

void moveBackward(int speed){
	setMotor(port2, -1 * speed);
	setMotor(port3, speed);
	forward(-1 * speed);
	stopMotor(port2);
	stopMotor(port3);
}
void right(int speed){
	//port 2 is right motor
	setMotor(port2, speed);
	forward(speed);
	stopMotor(port2);
}

//----NOT USED----
void spinLeft(int speed)
{
	//port 3 is left motor
	//turn left
	setMotor(port3, -1*speed);
	forward(-1*speed);
	stopMotor(port3);

	//port 2 is right motor
	//turn right
	setMotor(port2, -1*speed);
	forward(-1*speed);

	stopMotor(port2);
}

void left(int speed){
	//port 3 is left motor
	setMotor(port3, -1 * speed);
	forward(-1 * speed);
	stopMotor(port3);
}

void lift(int speed){
	setMotor(port4, speed);
	forward(speed);
	stopMotor(port4);
}

// open claw
void open(){
	/*setMotor(port6, 127);
	wait(1.5);
	stopMotor(port6);*/
	setMotor(port6, 127);
	forward(127);
	stopMotor(port6);
}

// close claw
void close(){
	/*
	setMotor(port6, -127);
	wait(1.5);
	stopMotor(port6);\
	*/
	setMotor(port6, -127);
	forward(-127);
	stopMotor(port6);
}


/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the cortex has been powered on and    */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton()
{
  // Set bStopTasksBetweenModes to false if you want to keep user created tasks
  // running between Autonomous and Driver controlled modes. You will need to
  // manage all user created tasks if set to false.
  bStopTasksBetweenModes = true;

	// Set bDisplayCompetitionStatusOnLcd to false if you don't want the LCD
	// used by the competition include file, for example, you might want
	// to display your team name on the LCD in this function.
	// bDisplayCompetitionStatusOnLcd = false;

  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

task autonomous()
{
  // ..........................................................................
  // Insert user code here.
  // ..........................................................................

  // Remove this function call once you have "real" code.
  //AutonomousCodePlaceholderForTesting();

	//--------------DONT USE AUTONOMOUS--------------
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


task claw()
{
	while(1==1){
		if(vexRT[Btn5U] == 1)
		{
			lift(-66);
		}
		if(vexRT[Btn5D] == 1){
			lift(66);
		}
		if(vexRT[Btn7U] == 1){
			open();
		}
		if(vexRT[Btn7D] == 1){
			close();
		}
	}
}

task drive()
{
	int isForward = 1;
	int speed = 10;
	while(1==1){
		if(vexRT[Btn8U] == 1){
			moveForward(speed);
			if(speed <= 127){
				speed += 2;}
			}

  	if(vexRT[Btn6D] == 1){
			stopAllMotors();
			speed = 10;
			}

		if(vexRT[Btn8D] == 1){
			moveBackward(-1 * speed);
			if(speed <= 127){
				speed += 2;
			}
		}
		if(vexRT[Btn8L] == 1){
			left(-63);
		}
		if(vexRT[Btn8R] == 1){
			right(-63);
		}

	}
}


task usercontrol()
{
  // User control code here, inside the loop

	// port2 and port3 are for the motors
	// port4 is to lift the claw
	// port5 is to open and close the claw

	startTask(claw)
	startTask(drive)
	while(true){
		wait()
	}

	//---------RUNNING SEPERATE TASKS SO CLAW AND MOTOR CAN RUN IN PARALLEL---------------
  //while (true)
  //{
    // This is the main execution loop for the user control program.
    // Each time through the loop your program should update motor + servo
    // values based on feedback from the joysticks.

    // ........................................................................
    // Insert user code here. This is where you use the joystick values to
    // update your motors, etc.
    // ........................................................................

    // Remove this function call once you have "real" code.
    //UserControlCodePlaceholderForTesting();
  //}
}
