const int ENA = 9;
const int IN1 = 10;
const int IN2 = 8;

void setup() {
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
}

void loop() {
  // Forward at 50% speed
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, 128); // Speed = 0 to 255
  delay(2000);

  // Stop
  analogWrite(ENA, 0);
  delay(1000);

  // Reverse at full speed
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  analogWrite(ENA, 255);
  delay(2000);

  // Stop again
  analogWrite(ENA, 0);
  delay(1000);
}
