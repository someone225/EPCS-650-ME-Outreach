
#include <multiMotor.h>

#define enA 9
#define enB 0
#define in1 12
#define in2 7
#define in3 0
#define in4 0

multiMotor testMotor(in1, in2, in3, in4, enA, enB);
void setup() {
  // put your setup code here, to run once:
  testMotor.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  //digitalWrite(enA, HIGH);
  testMotor.initSingle(0, 0, 1, 0);
  
}
