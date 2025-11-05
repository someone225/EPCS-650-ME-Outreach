#include <Servo.h>
Servo myservo; //create servo object to control a servo

const int pos = 0; //variable to store the servo position

const int ch1Rpin = 6; //this connects to channel 1 on rc receiver
const int ch3Rpin = 5; //this connects to channel 3 on rc receiver
const int ENA = 9;
const int IN1 = 12;
const int IN2 = 7;
const int deg = 90;

void setup() 
{
  //controler pins
  pinMode(ch1Rpin, INPUT);
  pinMode(ch3Rpin, INPUT);
  //motor pins
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  //attaches the servo on pin 7
  Serial.begin(9600);
  myservo.attach(4);
}

void loop() 
{
  unsigned long ch1Pulse; //this is the length of the pulse that controller sends from channel 1
  unsigned long ch3Pulse; //this is the lenth of the pulse that controller sends from channel 3
  int ch1PpD; //ch1 Pulse per degree
  int ch3PpS; //ch3 Pulse per speed

  //Forward and Reverse Movement
  ch3Pulse = pulseIn(ch3Rpin, HIGH); //records new pulse width for channel 3
  if (ch3Pulse > 1455)
  { //checks if left joystick is moving forward
    ch3PpS = 518/255;
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    analogWrite(ENA, (ch3Pulse-1455)/ch3PpS); // Speed = 1 to 255 forward
  } 
  else if (ch3Pulse < 1240)
  { //checks if left joystick is moving in reverse
    ch3PpS = 246/190;
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    analogWrite(ENA, (1240-ch3Pulse)/ch3PpS); //Speed = 1 to 190 in reverse
  }
  else if (ch3Pulse >= 1240 && ch3Pulse <= 1455)
  { //checks if left joystick is inbetween third and fourth dash and if so sets speed to zero
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    analogWrite(ENA, 0); //Speed = 0
  }

  //Turning Movement
  ch1Pulse = pulseIn(ch1Rpin, HIGH); //records new pulse width for channel 1
  if(ch1Pulse >= 1370 && ch1Pulse <= 1385)
  { //checks if joystick is still
    myservo.write(deg); //sets wheels straight
  } 
  else if(ch1Pulse < 1370)
  { //checks if right joystick is moving left  
    ch1PpD = 376/deg;
    myservo.write(((ch1Pulse-1370)/ch1PpD)+deg); //tells the servo how many degrees to turn to the left
  } 
  else if(ch1Pulse > 1385)
  { //checks if right joystick is moving right
    ch1PpD = 502/deg;
    myservo.write(((ch1Pulse-1385)/ch1PpD)+deg); //tells the servo how many degrees to turn to the right
  }
}