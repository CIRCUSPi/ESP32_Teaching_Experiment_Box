#define MoisturePin 14

void setup() {
  Serial.begin(9600);
  pinMode(MoisturePin, INPUT);

}

void loop() {
  int Moisture = analogRead(MoisturePin);
  Serial.print("Moisture: ");
  Serial.println(Moisture);
  delay(1000);
}
