#include <Servo.h>
#include <multiMotor.h>
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
const int forwardDriveMultiplier = 255;
const int reverseDriveMultiplier = 190;


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

  driveMotor.driveDual(100, 12);
/*

 



  //Forward and Reverse Movement
  ch3Pulse = pulseIn(ch3Rpin, HIGH); //records new pulse width for channel 3
  //Serial.print("Variable_1:");



  if (ch3Pulse > 1300 && ch3Pulse < 1500)
  { //checks if left joystick is inbetween third and fourth dash and if so sets speed to zero
    driveMotor.driveDual(0, 0);


  }

  else if (ch3Pulse > 1500)
  { //checks if left joystick is moving forward


    //1000 - 2000 -> -255 - 255
    // pwr - 1500 / 2
    eightBitPwr =( ch3Pulse - 1500 / 2);
    PwrPercent = (eightBitPwr/255) * 100;
    driveMotor.driveDual(100, 10);
    

  } 
  else if (ch3Pulse < 1300)
  { //checks if left joystick is moving in reverse

    //1000 - 2000 -> -255 - 255
    // pwr - 1500 / 2
    eightBitPwr =( ch3Pulse - 1500 / 2);
    PwrPercent = (eightBitPwr/255) * 100;
    driveMotor.driveDual(-100, 10);
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
  
  */
}
