
#include <multiMotor.h>

#define enA 9
#define enB 0
#define in1 12
#define in2 7
#define in3 0
#define in4 0

multiMotor testMotor();
void setup() {
  // put your setup code here, to run once:
}

void loop() {
  // put your main code here, to run repeatedly:
  //digitalWrite(enA, HIGH);
  initSingle(0, 0, 1, 0);
  
}
