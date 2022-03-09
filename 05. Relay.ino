#define RelayPin 25

void setup() {
  Serial.begin(9600);
  pinMode(RelayPin, OUTPUT);

}

void loop() {
  Serial.println("Relay: ON");
  digitalWrite(RelayPin, HIGH);
  delay(3000);
  Serial.println("Relay: OFF");
  digitalWrite(RelayPin, LOW);
  delay(1000);
}
