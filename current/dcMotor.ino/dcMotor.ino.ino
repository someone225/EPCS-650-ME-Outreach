#include <multiMotor.h>

#define in1 9
#define in2 7
#define enA 11

#define in3 12
#define in4 13
#define enB 10



multiMotor testMotor(12); //initializes a multiMotor class named testMotor
//you can think of a multiMotor class as representing an L293n motor driver
void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  testMotor.initDual(in1, in2, in3, in4, enA, enB, 12);


}

void loop() {

  //running a single-channel motor
  
  testMotor.driveDual(0, 0);
  
  

  
}
