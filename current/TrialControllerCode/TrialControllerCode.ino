#include <Servo.h>
#include <multiMotor.h>
#include <math.h>
Servo myservo; //create servo object to control a servo

const int pos = 0; //variable to store the servo position

const int ch1Rpin = 6; //this connects to channel 1 on rc receiver
const int ch3Rpin = 5; //this connects to channel 3 on rc receiver

const int ENA = 11;
const int IN1 = 13;
const int IN2 = 12;
const int IN3 = 9;
const int IN4 = 8;
const int ENB = 10;
const int MaxOverclockWattage = 12;

const int deg = 90;


multiMotor driveMotor(12); 

void setup() 
{
  //controler pins
  pinMode(ch1Rpin, INPUT);
  pinMode(ch3Rpin, INPUT);
  //motor pins
  //attaches the servo on pin 7
  Serial.begin(9600);
  myservo.attach(4);

  


}

void loop() 
{
  driveMotor.initDual(IN1, IN2, IN3, IN4, ENA, ENB, MaxOverclockWattage);
  float eightBitPwr;
  float PwrPercent;
  unsigned long ch1Pulse; //this is the length of the pulse that controller sends from channel 1
  unsigned long ch3Pulse; //this is the lenth of the pulse that controller sends from channel 3
  int ch1PpD; //ch1 Pulse per degree
  int ch3PpS; //ch3 Pulse per speed




  //driveMotor.driveDual(0, 12);


 



  //Forward and Reverse Movement
  ch3Pulse = pulseIn(ch3Rpin, HIGH);
  //driveMotor.driveDual(PwrPercent, 12);
  PwrPercent = convertPower(ch3Pulse);

  


  Serial.print("Variable_1:");
  Serial.print(PwrPercent);
  Serial.print(",");
  Serial.print("Variable_2:");
  Serial.println(0);

  driveMotor.driveDual(PwrPercent, 12);
  


  //Turning Movement
  ch1Pulse = pulseIn(ch1Rpin, HIGH); //records new pulse width for channel 1
  if(ch1Pulse >= 1300 && ch1Pulse <= 1400)
  { //checks if joystick is still
    myservo.write(deg); //sets wheels straight
  } 
  else if(ch1Pulse < 1300)
  { //checks if right joystick is moving left  
    ch1PpD = 376/deg;
    myservo.write(((ch1Pulse-1370)/ch1PpD)+deg); //tells the servo how many degrees to turn to the left
  } 
  else if(ch1Pulse > 1400)
  { //checks if right joystick is moving right
    ch1PpD = 502/deg;
    myservo.write(((ch1Pulse-1385)/ch1PpD)+deg); //tells the servo how many degrees to turn to the right
  }
  
  
}


float convertPower(float pulse)
{
  //1000 -> -100
  // 1300 - 1600 -> 0
  //1950 -> 100

  int output = 0;
  
  if(pulse > 1600)
  {
    output = (pulse - 1450)  / 5;
  }
  else if(pulse < 1300)
  {
    //0 , -300 -> 0, -100
    output = ( pulse - 1300 ) / 3;
  }
  else
  {
    output = 0;
  }


  if(output > 100)
  {
    output = 100;
  }
  if(output < -100)
  {
    output = -100;
  }

  


  return output;

}
