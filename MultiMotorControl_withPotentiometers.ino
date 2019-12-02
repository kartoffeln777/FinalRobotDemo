//L293D
//Motor 1
const int motor1Pin1  = 49;  
const int motor1Pin2  = 48; 
const int en1         = 6; 
//Motor 2
const int motor2Pin1  = 32; 
const int motor2Pin2  = 33;  
const int en2         = 9; //Used to be 7 
//Motor 3
const int motor3Pin1  = 44;  
const int motor3Pin2  = 45; 
const int en3         = 5;  
//Motor 4
const int motor4Pin1  = 41; 
const int motor4Pin2  = 40;  
const int en4         = 10; //Used to be 4
//Motor 5
const int motor5Pin1  = 36; 
const int motor5Pin2  = 37;  
const int en5         = 3; 

const int analogInM5Pin = A0;  // Analog input pin that the potentiometer is attached to
const int analogInM4Pin = A1;  // Analog input pin that the potentiometer is attached to
const int analogInM3Pin = A2;  // Analog input pin that the potentiometer is attached to
const int analogInM2Pin = A3;  // Analog input pin that the potentiometer is attached to
const int analogInM1Pin = A4;  // Analog input pin that the potentiometer is attached to

int gripperSensorValue = 0;        // value read from the pot
int M4SensorValue = 0;        // value read from the pot
int M3SensorValue = 0;        // value read from the pot
int M2SensorValue = 0;        // value read from the pot
int M1SensorValue = 0;        // value read from the pot
int gripperOutputValue = 0;   // value output to the PWM (analog out)
int M4OutputValue = 0;        // value output to the PWM (analog out)
int M3OutputValue = 0;        // value output to the PWM (analog out)
int M2OutputValue = 0;        // value output to the PWM (analog out)
int M1OutputValue = 0;        // value output to the PWM (analog out)

const int pot_neutral_value = 125;

int getMotorPin1(int motorNum) {
  if (motorNum == 1){
    return motor1Pin1;
    }
  else if (motorNum == 2){
    return motor2Pin1;
  }
  else if (motorNum == 3){
    return motor3Pin1;
  }
  else if (motorNum == 4){
    return motor4Pin1;
  }
  else{
    return motor5Pin1;  
  }
}

int getMotorPin2(int motorNum) {
  if (motorNum == 1){
    return motor1Pin2;
    }
  else if (motorNum == 2){
    return motor2Pin2;
  }
  else if (motorNum == 3){
    return motor3Pin2;
  }
  else if (motorNum == 4){
    return motor4Pin2;
  }
  else{
    return motor5Pin2;  
  }
}

int getMotorEn(int motorNum) {
  if (motorNum == 1){
    return en1;
    }
  else if (motorNum == 2){
    return en2;
  }
  else if (motorNum == 3){
    return en3;
  }
  else if (motorNum == 4){
    return en4;
  }
  else{
    return en5;  
  }
}

void moveToPickup(){
  pinMode(getMotorPin1(1), OUTPUT);  
  pinMode(getMotorPin2(1), OUTPUT);
  pinMode(getMotorEn(1), OUTPUT);
  pinMode(getMotorPin1(2), OUTPUT);  
  pinMode(getMotorPin2(2), OUTPUT);
  pinMode(getMotorEn(2), OUTPUT);
  pinMode(getMotorPin1(3), OUTPUT);  
  pinMode(getMotorPin2(3), OUTPUT);
  pinMode(getMotorEn(3), OUTPUT);
  pinMode(getMotorPin1(4), OUTPUT);  
  pinMode(getMotorPin2(4), OUTPUT);
  pinMode(getMotorEn(4), OUTPUT);
  pinMode(getMotorPin1(5), OUTPUT);  
  pinMode(getMotorPin2(5), OUTPUT);
  pinMode(getMotorEn(5), OUTPUT);

  driveMotor(5, 0.6, 0.0);
  driveMotor(4, 0.0, 1.0);
  driveMotor(3, 0.0, 1.0);
  driveMotor(2, 0.0, 1.0);
  driveMotor(1, 3.5, 0.0);
  driveMotor(2, 1.0, 0.0);
  driveMotor(3, 1.0, 0.0);
  driveMotor(4, 1.0, 0.0);
  driveMotor(5, 0.0, 0.4);


}

void moveToHome(){
  pinMode(getMotorPin1(1), OUTPUT);  
  pinMode(getMotorPin2(1), OUTPUT);
  pinMode(getMotorEn(1), OUTPUT);
  pinMode(getMotorPin1(2), OUTPUT);  
  pinMode(getMotorPin2(2), OUTPUT);
  pinMode(getMotorEn(2), OUTPUT);
  pinMode(getMotorPin1(3), OUTPUT);  
  pinMode(getMotorPin2(3), OUTPUT);
  pinMode(getMotorEn(3), OUTPUT);
  pinMode(getMotorPin1(4), OUTPUT);  
  pinMode(getMotorPin2(4), OUTPUT);
  pinMode(getMotorEn(4), OUTPUT);
  pinMode(getMotorPin1(5), OUTPUT);  
  pinMode(getMotorPin2(5), OUTPUT);
  pinMode(getMotorEn(5), OUTPUT);

  driveMotor(5, 0.6, 0.0);
  driveMotor(4, 0.0, 1.0);
  driveMotor(3, 0.0, 1.0);
  driveMotor(2, 0.0, 1.0);
  driveMotor(1, 0.0, 3.5);
  driveMotor(2, 1.0, 0.0);
  driveMotor(3, 1.0, 0.0);
  driveMotor(4, 1.0, 0.0);
  driveMotor(5, 0.0, 0.4);
  
}

int driveMotor(int motorNum, float time1, float time2){
  
  int pin1 = getMotorPin1(motorNum);
  int pin2 = getMotorPin2(motorNum);
  int en = getMotorEn(motorNum);  
  
  pinMode(en, OUTPUT);  
  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);
  // this function will run the motors in both directions at a fixed speed
  // turn on motor 2
  digitalWrite(pin1, HIGH);
  digitalWrite(pin2, LOW);
  // set speed to 200 out of possible range 0~255
  analogWrite(en, 200);   
  delay(1000 * time1);

  // now change motor directions
  digitalWrite(pin1, LOW);
  digitalWrite(pin2, HIGH);  
  delay(1000 * time2);
  // now turn off motors
  digitalWrite(pin1, LOW);
  digitalWrite(pin2, LOW);

  return 0;
}

int driveMotorToPotValue(int motorNum, int potValue){
  Serial.begin(9600);
  Serial.print("Test\n");
  int pin1 = getMotorPin1(motorNum);
  int pin2 = getMotorPin2(motorNum);
  int en = getMotorEn(motorNum);  
  int sensorValue = 0;
  int outputValue = 0;
  int analogInPin = 0;

  if (motorNum == 1) {
    analogInPin = analogInM1Pin;
    Serial.print("Selected Motor 1");    
  }
  else if (motorNum == 2) {
    analogInPin = analogInM2Pin;
    Serial.print("Selected Motor 2");    
  }
  else if (motorNum == 3) {
    analogInPin = analogInM3Pin;
    Serial.print("Selected Motor 3");    
  }
  else if (motorNum == 4) {
    analogInPin = analogInM4Pin;
    Serial.print("Selected Motor 4");    
  }
  else {
    analogInPin = analogInM5Pin;
    Serial.print("Selected Motor 5");    
  }

  sensorValue = analogRead(analogInPin);
  outputValue = map(sensorValue, 0, 1023, 0, 255);
  pinMode(en, OUTPUT);  
  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);
  
  while (abs(outputValue-potValue) >= 4){
    if (motorNum == 1){
      if (outputValue > potValue) {
        driveMotor(1, 0.5, 0);
        }
      else {
        driveMotor(1, 0, 0.5);
        }
    }
    else if (motorNum == 5){
      if (outputValue > potValue) {
        driveMotor(5, 0, 0.2);
        }
      else {
        driveMotor(5, 0.2, 0);
        }
    }
    else {
      if (outputValue > potValue) {
        driveMotor(motorNum, 0, 0.3);
        }
      else {
        driveMotor(motorNum, 0.3, 0);
        }
    }
    sensorValue = analogRead(analogInPin);
    outputValue = map(sensorValue, 0, 1023, 0, 255);
    Serial.print("M");
    Serial.print(motorNum);
    Serial.print("motor pot = ");
    Serial.print(outputValue);
    Serial.print("\n");
  }

  return 0;
}

int driveToPosition(int pos1, int pos2, int pos3, int pos4, int pos5){
  driveMotorToPotValue(1, pos1);
  driveMotorToPotValue(2, pos2);
  driveMotorToPotValue(3, pos3);
  driveMotorToPotValue(4, pos4);
  driveMotorToPotValue(5, pos5);
  return 0;
}

int openGrippers(){
    driveMotor(5, 0.0, 0.7);
    return 0;
}

int closeGrippers(){
    driveMotor(5, 0.7, 0.0);
    return 0;
}

void setup() {
  // put your setup code here, to run once
  //moveToPickup();
  //moveToHome();
  //driveMotorToPotValue(2, 166);
  //driveMotorToPotValue(2, 173);
  //driveMotorToPotValue(2, 159);
  
  //From box to hover posn #1
  //driveMotorToPotValue(2, 158);
  //driveMotorToPotValue(3, 164);

  //From hover posn #1 to hover posn #2
  //driveMotorToPotValue(1, 172);

  //From hover posn #2 to putdown posn
  //driveMotorToPotValue(2, 195);
  //driveMotorToPotValue(3, 162);  

  //From putdown posn to hover posn #2
  //driveMotorToPotValue(2, 158);
  //driveMotorToPotValue(3, 164);

  //From hover posn #2 to hover posn #1
  //driveMotorToPotValue(1, 142);

  //From hover posn #1 to box posn
  //driveMotorToPotValue(2, 172);
  //driveMotorToPotValue(3, 178);

  //driveToPosition(172, 158, 164, 124, 75);
  //openGrippers();
  //closeGrippers();

  //Final Robot Demo
  //Drive to home position
  //driveMotorToPotValue(2, 158);
  //driveMotorToPotValue(3, 193);
  //driveMotorToPotValue(1, 135);
  driveMotor(1, 0.0, 0.9);  
  //driveMotor(1, 0.0, 0.2);  
  //driveMotor(3, 0.0, 0.4);
  //FORWARDS
  //driveMotor(2, 0.3, 0.0);  
  //driveMotor(3, 0.0, 0.9);
  //BACKWARDS
  //driveMotor(2, 0.0, 1.9);
  //driveMotor(3, 1.5, 0.0);
  
  //driveMotor(5, 1.5, 0.0);
}

void loop() {
  // put your main code here, to run repeatedly:
  


}
