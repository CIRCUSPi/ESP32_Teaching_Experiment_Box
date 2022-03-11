#define M1A 12
#define M1B 13

void setup() {
  pinMode(M1A, OUTPUT);
  pinMode(M1B, OUTPUT);
  ledcSetup(0, 5000, 8);
  ledcAttachPin(M1A, 0);
  ledcSetup(1, 5000, 8);
  ledcAttachPin(M1B, 1);
}

void loop() {
  ledcWrite(0, 255);
  ledcWrite(1, 0);
  delay(2000);
  ledcWrite(0, 0);
  ledcWrite(1, 0);
  delay(1000);
  ledcWrite(0, 0);
  ledcWrite(1, 255);
  delay(2000);
  ledcWrite(0, 0);
  ledcWrite(1, 0);
  delay(1000);
}
