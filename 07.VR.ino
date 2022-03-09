#define VRPin 25

void setup() {
  Serial.begin(9600);
  pinMode(VRPin, INPUT);

}

void loop() {
  int VRvalue = analogRead(VRPin);
  Serial.print("VR: ");
  Serial.println(VRvalue);
  delay(100);
}
