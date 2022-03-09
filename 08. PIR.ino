#define PIRPin 25

void setup() {
  Serial.begin(9600);
  pinMode(PIRPin, INPUT);

}

void loop() {
  int PIRvalue = digitalRead(PIRPin);
  if (PIRvalue == 0) {
    Serial.println("Someone passed by.");
  }
  else {
    Serial.println("None");
  }

  delay(100);
}
