/*
  Analog input, analog output, serial output

  Reads an analog input pin, maps the result to a range from 0 to 255 and uses
  the result to set the pulse width modulation (PWM) of an output pin.
  Also prints the results to the Serial Monitor.

  The circuit:
  - potentiometer connected to analog pin 0.
    Center pin of the potentiometer goes to the analog pin.
    side pins of the potentiometer go to +5V and ground
  - LED connected from digital pin 9 to ground

  created 29 Dec. 2008
  modified 9 Apr 2012
  by Tom Igoe

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/AnalogInOutSerial
*/

// These constants won't change. They're used to give names to the pins used:
const int analogInM5Pin = A0;  // Analog input pin that the potentiometer is attached to
const int analogInM4Pin = A1;  // Analog input pin that the potentiometer is attached to
const int analogInM3Pin = A2;  // Analog input pin that the potentiometer is attached to
const int analogInM2Pin = A3;  // Analog input pin that the potentiometer is attached to
const int analogInM1Pin = A4;  // Analog input pin that the potentiometer is attached to
//const int analogOutPin = 9; // Analog output pin that the LED is attached to

int M5SensorValue = 0;        // value read from the pot
int M4SensorValue = 0;        // value read from the pot
int M3SensorValue = 0;        // value read from the pot
int M2SensorValue = 0;        // value read from the pot
int M1SensorValue = 0;        // value read from the pot
int M5OutputValue = 0;        // value output to the PWM (analog out)
int M4OutputValue = 0;        // value output to the PWM (analog out)
int M3OutputValue = 0;        // value output to the PWM (analog out)
int M2OutputValue = 0;        // value output to the PWM (analog out)
int M1OutputValue = 0;        // value output to the PWM (analog out)

void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);
}

void loop() { 
  // read the analog in value:
  M5SensorValue = analogRead(analogInM5Pin);
  M4SensorValue = analogRead(analogInM4Pin);
  M3SensorValue = analogRead(analogInM3Pin);
  M2SensorValue = analogRead(analogInM2Pin);
  M1SensorValue = analogRead(analogInM1Pin);
  // map it to the range of the analog out:
  M5OutputValue = map(M5SensorValue, 0, 1023, 0, 255);
  M4OutputValue = map(M4SensorValue, 0, 1023, 0, 255);
  M3OutputValue = map(M3SensorValue, 0, 1023, 0, 255);
  M2OutputValue = map(M2SensorValue, 0, 1023, 0, 255);
  M1OutputValue = map(M1SensorValue, 0, 1023, 0, 255);
  // change the analog out value:
  //analogWrite(analogOutPin, outputValue);

  // print the results to the Serial Monitor:
  Serial.print("gripper = ");
  Serial.print(M5SensorValue);
  Serial.print("\t gripper output = ");
  Serial.println(M5OutputValue);
  Serial.print("M4 motor pot= ");
  Serial.print(M4SensorValue);
  Serial.print("\t M4 motor output = ");
  Serial.println(M4OutputValue);
  Serial.print("M3 motor pot= ");
  Serial.print(M3SensorValue);
  Serial.print("\t M3 motor output = ");
  Serial.println(M3OutputValue);
  Serial.print("M2 motor pot= ");
  Serial.print(M2SensorValue);
  Serial.print("\t M2 motor output = ");
  Serial.println(M2OutputValue);
  Serial.print("M1 motor pot= ");
  Serial.print(M1SensorValue);
  Serial.print("\t M1 motor output = ");
  Serial.println(M1OutputValue);  

  // wait 2 milliseconds before the next loop for the analog-to-digital
  // converter to settle after the last reading:
  delay(2);
}
