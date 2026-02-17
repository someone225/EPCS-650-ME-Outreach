const int receiverpin = 10; //this connects to channel on rc receiver
unsigned long pulseDuration; //this is the length of the pulse that controller sends

void setup() {
  //pinMode(13,OUTPUT);
  pinMode(receiverpin, INPUT);
  Serial.begin(9600);

}

void loop() {
  pulseDuration = pulseIn(receiverpin, HIGH); //records new pulse width
  Serial.println(pulseDuration); 


}
