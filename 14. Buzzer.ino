#define BuzzerPin 17
const int pwmChannel = 0;
const int resolution = 10;

void setup() {
  pinMode(BuzzerPin, OUTPUT);
  ledcAttachPin(BuzzerPin, pwmChannel);
  ledcSetup(pwmChannel, 1000, resolution);
}

void loop() {
  for (int i=0; i<4; i++) {
    ledcWrite(pwmChannel, 512);
    delay(100);
    ledcWrite(pwmChannel, 0);
    delay(100);
  }
	delay(3000);
}
