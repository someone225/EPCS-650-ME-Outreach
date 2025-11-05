#define enA 9
#define in1 12
#define in2 7

void setup() {
  // put your setup code here, to run once:
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);

  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  //digitalWrite(enA, HIGH);
  analogWrite(enA, 0);

}

struct dcMotor
{
  int in1 = 0
  int in2 = 0
  int in3 = 0
  int in4 = 0
  int enA = 0
  int enB = 0

  void initSingle(ctr1, ctr2, id, en, dir)
  {
    switch id
    {
      case 1:
        this.in1 = ctr1;
        this.in2 = ctr2;
        this.enA = en;

        pinMode(this.in1, OUTPUT);
        pinMode(this.in2, OUTPUT);
        pinMode(this.enA, OUTPUT);

        if(dir == "FORWARD")
        {
          digitalWrite(this.in1, HIGH);
          digitalWrite(this.in2, LOW);
        }
        else if(dir == "REVERSE")
        {
          digitalWrite(this.in1, LOW);
          digitalWrite(this.in2, HIGH);
        }
        
        break;
        
      case 2:
        this.in3 = ctr1;
        this.in4 = ctr2;
        this.enB = en;

        pinMode(this.in3, OUTPUT);
        pinMode(this.in4, OUTPUT);
        pinMode(this.enB, OUTPUT);
        
        break;
    }




    
      
  }
  
}
