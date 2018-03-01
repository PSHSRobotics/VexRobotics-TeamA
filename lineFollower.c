#pragma config(Sensor, in1,    lineFollowerRIGHT,   sensorLineFollower)
#pragma config(Sensor, in2,    lineFollowerCENTER,  sensorLineFollower)
#pragma config(Sensor, in3,    lineFollowerLEFT,    sensorLineFollower)
#pragma config(Motor,  port2,           rightMotor,    tmotorNormal, openLoop, reversed)
#pragma config(Motor,  port3,           leftMotor,     tmotorNormal, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*----------------------------------------------------------------------------------------------------*\
|*                             	    - Triple Sensor Line Tracking -                                   *|
|*                                      ROBOTC on VEX 2.0 CORTEX                                      *|
|*                                                                                                    *|
|*  This program uses 3 VEX Line Follower Sensors to track a black line on a light(er) surface.       *|
|*  There is a two second pause at the beginning of the program.                                      *|
|*                                                                                                    *|
|*                                        ROBOT CONFIGURATION                                         *|
|*    NOTES:                                                                                          *|
|*    1)  Reversing 'rightMotor' (port 2) in the "Motors and Sensors Setup" is needed with the        *|
|*        "Squarebot" mode, but may not be needed for all robot configurations.                       *|
|*    2)  Lighting conditions, line darkness, and surface lightness change from place to place,       *|
|*        so the value of 'threshold' may need to be changed to better suit your environment.         *|
|*                                                                                                    *|
|*    MOTORS & SENSORS:                                                                               *|
|*    [I/O Port]          [Name]              [Type]                [Description]                     *|
|*    Motor  - Port 2     rightMotor          VEX 3-wire module     Right side motor                  *|
|*    Motor  - Port 3     leftMotor           VEX 3-wire module     Left side motor                   *|
|*    Analog - Port 1     lineFollowerRIGHT   VEX Light Sensor      Front-right, facing down          *|
|*    Analog - Port 2     lineFollowerCENTER  VEX Light Sensor      Front-center, facing down         *|
|*    Analog - Port 3     lineFollowerLEFT    VEX Light Sensor      Front-left, facing down           *|
\*-----------------------------------------------------------------------------------------------4246-*/



task lineFollowing()
{
	 wait1Msec(200);          // The program waits for 2000 milliseconds before continuing.

  int threshold = 505;      /* found by taking a reading on both DARK and LIGHT    */
                            /* surfaces, adding them together, then dividing by 2. */
  while(true)
  {
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -+
   /* displayLCDCenteredString(0, "LEFT  CNTR  RGHT");        //  Display   |
    displayLCDPos(1,0);                                     //  Sensor    |
    displayNextLCDNumber(SensorValue(lineFollowerLEFT));    //  Readings  |
    displayLCDPos(1,6);                                     //  to LCD.   |
    displayNextLCDNumber(SensorValue(lineFollowerCENTER));  //            |
    displayLCDPos(1,12);                                    //  L  C  R   |
    displayNextLCDNumber(SensorValue(lineFollowerRIGHT));   //  x  x  x   |
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -+
		*/
		// White is around ~0 and dark is ~4000
    // If one of the sensors see white:
    if(SensorValue(lineFollowerRIGHT) > threshold || SensorValue(lineFollowerCENTER) > threshold || SensorValue(lineFollowerLEFT) > threshold)
    {
    	//Sees dark then move
      motor[leftMotor]  = 50;
      motor[rightMotor] = 50;
    }
    else if(SensorValue(lineFollowerLEFT) < threshold || SensorValue(lineFollowerRIGHT) > threshold || SensorValue(lineFollowerCENTER) > threshold)
    {
    	// if white is seen by left sesor then left will move normal speed and the left motor will move at a slightly higher speed:)
    	motor[leftMotor] = 50;
    	motor[rightMotor] = 55;
    }
    else if(SensorValue(lineFollowerLEFT) > threshold || SensorValue(lineFollowerRIGHT) < threshold || SensorValue(lineFollowerCENTER) < threshold)
  	{
  		// If black is seen by left sensor and white is seen by the right sensor the move right motor move higher speed
  		motor[leftMotor] = 60;
  		motor[rightMotor] = 50;
  	}
    else if(SensorValue(lineFollowerLEFT) > threshold || SensorValue(lineFollowerRIGHT) < threshold || SensorValue(lineFollowerCENTER) < threshold)
  	{
  		// If black is seen by left sensor and white is seen by the right sensor the move right motor move higher speed
  		motor[leftMotor] = 60;
  		motor[rightMotor] = 50;
  	}
  	else if(SensorValue(lineFollowerLEFT) < threshold || SensorValue(lineFollowerRIGHT) > threshold || SensorValue(lineFollowerCENTER) < threshold)
 	 {
 			motor[leftMotor] = 50;
  		motor[rightMotor] = 55;
  	}
    else
    	// Sees white then stop:
    {
      // go straight
      motor[leftMotor]  = 0;
      motor[rightMotor] = 0;
    }
  }
}
task userControl()
{
	while(true)
	{
		if(vexRT[Btn7L] == 1) //left button -- start line following
		{
			startTask(lineFollowing);//start line following


		}
		if(vexRT[Btn7R] == 1) //right -- off line following
		{
			//off line following
			stopAllMotors();
			motor[leftMotor] = 0;
			motor[rightMotor] = 0;
		}
	}

}
//+++++++++++++++++++++++++++++++++++++++++++++| MAIN |+++++++++++++++++++++++++++++++++++++++++++++++
task main()
{
 	startTask(userControl);
 	while(true)
 	{
 		wait();
 	}
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//Got EM COACH LLLLLOOOOOLLLLLLLL LMAO