#pragma config(Motor,  port2,            ,             tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,            ,             tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,            ,             tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,            ,             tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,            ,             tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,            ,             tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,            ,             tmotorVex393_MC29, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

//#include "vex_competition_include.c"

void open(){
	setMotor(port8, 127);
	forward(127);
	stopMotor(port8);
}
void close(){
	setMotor(port8, -127);
	forward(127);
	stopMotor(port8);
}

void lift(int speed){
	setMotor(port2, -1*speed);
	setMotor(port3, -1*speed);
	forward(speed);
	forward(speed);
	stopMotor(port2);
	stopMotor(port3);
}
void notlift(int speed){
	setMotor(port2, speed);
	setMotor(port3, speed);
	forward(speed);
	forward(speed);
	stopMotor(port2);
	stopMotor(port3);
}

void freeze(){
	stopMotor(port4);
	stopMotor(port7);
}

void stopElevator(){
	stopMotor(port2);
	stopMotor(port3);
}


void moveForward(int speed){
	setMotor(port4, speed);
	setMotor(port7, speed);
	forward(speed);
	forward(speed);
	stopMotor(port4);
	stopMotor(port7);
}

void moveBackward(int speed){
	setMotor(port4, speed);
	setMotor(port7, speed);
	forward(-1 * speed);
	forward(-1 * speed);
	stopMotor(port4);
	stopMotor(port7);
}

void right(int speed){
	setMotor(port7, -1 * speed);
	forward(speed);
	stopMotor(port7);
}

void left(int speed){
	setMotor(port4, -1 * speed);
	forward(-1 * speed);
	stopMotor(port4);

}

task drive(){
	int isForward = 1;
	int speed = 60;
	while(1==1){
		if(vexRT[Btn8U] == 1){
			moveForward(speed);
			if(speed <= 127){speed += 1;}
		}
  	if(vexRT[Btn7D] == 1){
			stopAllMotors();
			speed = 10;
		}
		if(vexRT[Btn8D] == 1){
			moveBackward(-1 * speed);
			if(speed <= 127){speed += 1;}
		}
		if(vexRT[Btn8L] == 1){left(-127);}
		if(vexRT[Btn8R] == 1){right(-127);}

	}
}

/*
task claw(){
	int speed = 60;
	open();
	close();
	while(1==1){
		if(vexRT[Btn5U] == 1){lift(127);}
		if(vexRT[Btn5D] == 1){notlift(127);}
		if(vexRT[Btn6U] == 1){open();}
		if(vexRT[Btn6D] == 1){close();}

	}
}
*/

task main()
{
	//startTask(claw);
	startTask(drive);
	while(true){
		wait()
		}

}
