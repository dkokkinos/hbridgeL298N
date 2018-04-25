/*
 * HBridgeL2N.h
 *
 *  Created on: 28 Dec 2017
 *      Author: jim
 */

#ifndef HBRIDGEL2N_H_
#define HBRIDGEL2N_H_

#include "Arduino.h"

class HBridgeL298N{
public:
	HBridgeL298N(int motorA_InputPin1, int motorA_InputPin2, int motorA_EnablePin,
			int motorB_InputPin1, int motorB_InputPin2, int motorB_EnablePin);
	HBridgeL298N(int motorA_InputPin1, int motorA_InputPin2, int motorA_EnablePin);
	~HBridgeL298N();
	void SetSpeed(const int _speed);
	void MotorA_Front();
	void MotorA_Back();
	void MotorB_Front();
	void MotorB_Back();
	void MotorA_Stop();
	void MotorB_Stop();
private:
	int speed;

	int motorA_Input1Pin;
	int motorA_Input2Pin;
	int motorA_EnablePin;

	int motorB_Input1Pin;
	int motorB_Input2Pin;
	int motorB_EnablePin;
};

#endif /* HBRIDGEL2N_H_ */











