#define MQ3Pin 27

void setup() {
  Serial.begin(9600);
  pinMode(MQ3Pin, INPUT);

}

void loop() {
  int MQ3Value = analogRead(MQ3Pin);
  Serial.print("MQ3Value: ");
  Serial.println(MQ3Value);
  delay(1000);
}
