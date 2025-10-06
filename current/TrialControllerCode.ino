#include <Servo.h>
Servo myservo; //create servo object to control a servo

const int pos = 0; //variable to store the servo position

const int ch1Rpin = 11; //this connects to channel 1 on rc receiver
const int ch3Rpin = 5; //this connects to channel 3 on rc receiver
const int ENA = 9;
const int IN1 = 10;
const int IN2 = 8;

const int ch3PpS = 1.929411765; //ch3 Pulse per speed aka 492/255 (difference in resting pulse to max pulse/max speed)
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
  myservo.attach(7);
  Serial.begin(9600);
}

void loop() 
{
  unsigned long ch1Pulse; //this is the length of the pulse that controller sends from channel 1
  unsigned long ch3Pulse; //this is the lenth of the pulse that controller sends from channel 3
  int ch1PpD; //ch1 Pulse per degree

  //Forward and Reverse Movement
  ch3Pulse = pulseIn(ch3Rpin, HIGH); //records new pulse width for channel 3
  if (ch3Pulse <= 1499)
  { //checks if left joystick is moving forward
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    analogWrite(ENA, (1499-ch3Pulse)/ch3PpS); // Speed = 0 to 255 forward
  } else if (ch3Pulse > 1499)
  { //checks if left joystick is moving in reverse
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    analogWrite(ENA, (ch3Pulse-1499)/ch3PpS); //Speed = 0 to 255 in reverse
  }

  //Turning Movement
  ch1Pulse = pulseIn(ch1Rpin, HIGH); //records new pulse width for channel 1
  if(ch1Pulse = 1520)
  { //checks if joystick is still
    myservo.write(90); //sets wheels straight
  } else if(ch1Pulse<1520)
  { //checks if right joystick is moving left
    ch1PpD = 496/deg;
    myservo.write(((ch1Pulse-1520)/ch1PpD)+deg); //tells the servo how many degrees to turn to the left
  } else if(ch1Pulse>1520)
  { //checks if right joystick is moving right
    ch1PpD = 470/deg;
    myservo.write(((ch1Pulse-1520)/ch1PpD)+deg); //tells the servo how many degrees to turn to the right
  }
}