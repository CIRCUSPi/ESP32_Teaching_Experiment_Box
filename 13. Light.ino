#define LightPin 25

void setup() {
  Serial.begin(9600);
  pinMode(LightPin, INPUT);

}

void loop() {
  int LightValue = analogRead(LightPin);
  Serial.print("Light Value: ");
  Serial.println(LightValue);
  delay(100);
}
