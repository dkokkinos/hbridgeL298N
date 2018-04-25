/*
 * HBridgeL298N.cpp
 *
 *  Created on: 28 Dec 2017
 *      Author: jim
 */

#include "HBridgeL298N.h"

HBridgeL298N::HBridgeL298N(int motorA_InputPin1, int motorA_InputPin2,
		int motorA_EnablePin, int motorB_InputPin1, int motorB_InputPin2,
		int motorB_EnablePin) {
	this->motorA_Input1Pin = motorA_InputPin1;
	this->motorA_Input2Pin = motorA_InputPin2;
	this->motorA_EnablePin = motorA_EnablePin;

	this->motorB_Input1Pin = motorB_InputPin1;
	this->motorB_Input2Pin = motorB_InputPin2;
	this->motorB_EnablePin = motorB_EnablePin;

	pinMode(this->motorA_Input1Pin, OUTPUT);
	pinMode(this->motorA_Input2Pin, OUTPUT);
	pinMode(this->motorA_EnablePin, OUTPUT);

	pinMode(this->motorB_Input1Pin, OUTPUT);
	pinMode(this->motorB_Input2Pin, OUTPUT);
	pinMode(this->motorB_EnablePin, OUTPUT);

	this->speed = 255;
}
HBridgeL298N::HBridgeL298N(int motorA_InputPin1, int motorA_InputPin2,
		int motorA_EnablePin) {
	this->motorA_Input1Pin = motorA_InputPin1;
	this->motorA_Input2Pin = motorA_InputPin2;
	this->motorA_EnablePin = motorA_EnablePin;

	pinMode(this->motorA_Input1Pin, OUTPUT);
	pinMode(this->motorA_Input2Pin, OUTPUT);
	pinMode(this->motorA_EnablePin, OUTPUT);

	this->speed = 255;
}
HBridgeL298N::~HBridgeL298N() {

}
void HBridgeL298N::SetSpeed(const int _speed) {
	this->speed = _speed;
}
void HBridgeL298N::MotorA_Front() {
	analogWrite(this->motorA_EnablePin, this->speed);
	digitalWrite(this->motorA_Input1Pin, HIGH);
	digitalWrite(this->motorA_Input2Pin, LOW);
}
void HBridgeL298N::MotorA_Back() {
	analogWrite(this->motorA_EnablePin, this->speed);
	digitalWrite(this->motorA_Input1Pin, LOW);
	digitalWrite(this->motorA_Input2Pin, HIGH);
}
void HBridgeL298N::MotorB_Front() {
	analogWrite(this->motorB_EnablePin, this->speed);
	digitalWrite(this->motorB_Input1Pin, HIGH);
	digitalWrite(this->motorB_Input2Pin, LOW);
}
void HBridgeL298N::MotorB_Back() {
	analogWrite(this->motorB_EnablePin, this->speed);
	digitalWrite(this->motorB_Input1Pin, LOW);
	digitalWrite(this->motorB_Input2Pin, HIGH);
}
void HBridgeL298N::MotorA_Stop() {
	analogWrite(this->motorA_EnablePin, 0);
	digitalWrite(this->motorA_Input1Pin, LOW);
	digitalWrite(this->motorA_Input2Pin, HIGH);
}
void HBridgeL298N::MotorB_Stop() {
	analogWrite(this->motorB_EnablePin, 0);
	digitalWrite(this->motorB_Input1Pin, LOW);
	digitalWrite(this->motorB_Input2Pin, HIGH);
}
