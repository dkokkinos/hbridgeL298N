# Full-Bridge Motor Driver Dual - L298N

A simple C++ driver for the L298N chip. An Arduino example is also included. 
The L298N chip is a high voltage, high current dual full – bridge motor driver. PWM signals can pass through it with a board such as Arduino. 

The driver provides independent control of the speed and direction of the two supported motors. 
The library consists of two files, the header and the cpp file. The header contains the following interface
| Function        | Parameters           | Description  |
| :------------- |:-------------|:-----|
| **SetSpeed**  | const int | the speed of the motors, a number between 0-255 |
| **MotorA_Front**  | none | will drive one motor in one direction |
| **MotorA_Back** | none| will drive the same motor in different direction |
| **MotorA_Stop** | none | this function will stop the motor A |
| **MotorB_Front** | none  |  will drive the other motor in one direction |
| **MotorB_Back** | none  | will drive the same motor in different direction |
| **MotorB_Stop** | none | this function will stop the motor B |
The constructor initialization will initialize the driver for one motor or two, depending on the number of arguments.
```cpp
HBridgeL298N(int motorA_InputPin1, int motorA_InputPin2, int motorA_EnablePin,
		int motorB_InputPin1, int motorB_InputPin2, int motorB_EnablePin);
HBridgeL298N(int motorA_InputPin1, int motorA_InputPin2, int motorA_EnablePin);
```
* Keep in mind that the driver is supposed to control motors of the same speed (for example in a vehicle). So the next function will set the speed to both motors.
```cpp
void SetSpeed(const int _speed)
```
To steer a differential robot you will call MotorA_Front() for one motor and MotorB_Back() for the other.

# Install the library
Download this repository as a .zip file and from the Arduino IDE go to Sketch -> Include library -> Add .ZIP Library
# Usage example in Arduino
Lastly, to initialize the library you must provide three pins for one motor and three pins for the other. For example:
```cpp
int motorPinPlus = 2;  
int motorPinMinus = 3;     
int motorPinEnable = 9; 

int motor2PinPlus = 4;      
int motor2PinMinus = 5;      
int motor2PinEnable = 10;
```
The numbers are compatible with an Arduino UNO board.

An initialization example of the library would be the following:
```cpp
HBridgeL298N * HBridge;
void setup() {
    Serial.begin(9600);
    HBridge = new HBridgeL298N(motorPinPlus, motorPinMinus, motorPinEnable,
                               motor2PinPlus, motor2PinMinus, motor2PinEnable);
}
```
After the initialization you can control the motors calling functions such as:
```cpp
HBridge->SetSpeed(speed);
HBridge->MotorA_Front();
HBridge->MotorB_Back();
```

Finally, complete example is the following:
```processing
#include <HBridgeL298N.h>

int motorPinPlus = 2;  
int motorPinMinus = 3;     
int motorPinEnable = 9; 

int motor2PinPlus = 4;      
int motor2PinMinus = 5;      
int motor2PinEnable = 10;

HBridgeL298N* HBridge;

void setup() {
  Serial.begin(9600);
  HBridge = new HBridgeL298N(motorPinPlus, motorPinMinus, motorPinEnable,
  motor2PinPlus, motor2PinMinus,motor2PinEnable );
}

void loop() {
  if (Serial.available()) {
    byte x = Serial.read();
    int speed = 110;
    HBridge->SetSpeed(speed); 
    if (x == 'f') {
      HBridge->MotorA_Front();
    } else if (x == 'b') {
      HBridge->MotorA_Back();
    }  else if (x == 'c') {
      HBridge->MotorB_Front();
    }  else if (x == 'd') {
      HBridge->MotorB_Back();
    } else if (x == 'q') {
      HBridge->MotorA_Stop();
    }else if (x == 's') {
      HBridge->MotorB_Stop();
    }
  }
}
```

# Schematic
Here is a schematic of an external power, an arduino UNO and the L298N chip
![alt text](https://raw.githubusercontent.com/codedayafternoon/hbridgeL298N/master/image%20example%20with%20one%20motor.jpg)



