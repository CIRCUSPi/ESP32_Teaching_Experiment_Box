#define Trig 13
#define Echo 15
void setup(){
  Serial.begin(9600);
  pinMode(Trig, OUTPUT);
  pinMode(Echo, INPUT);
}
void loop() {
  digitalWrite(Trig, LOW);
  delayMicroseconds(5);
  digitalWrite(Trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(Trig, LOW);
  float EchoTime = pulseIn(Echo, HIGH);
  float distance = EchoTime * 34 / 1000 / 2;
  Serial.println(distance);
  delay(50);
}
