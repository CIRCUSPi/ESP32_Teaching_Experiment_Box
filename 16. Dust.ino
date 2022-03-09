#define ledPower 25
#define dustPin 33

int samplingTime = 280;
int deltaTime = 40;
int sleepTime = 9680;

int readValue = 0;
float dustValue = 0;

void setup(){
  Serial.begin(9600);
  pinMode(ledPower,OUTPUT);
}

void loop(){
  digitalWrite(ledPower,LOW); // power on the LED
  delayMicroseconds(samplingTime);

  readValue = analogRead(dustPin); // read the dust value

  delayMicroseconds(deltaTime);
  digitalWrite(ledPower,HIGH); // turn the LED off
  delayMicroseconds(sleepTime);

  dustValue = map(readValue, 670, 2531, 70, 430);
  Serial.print(dustValue);
  Serial.println(" ug/m^3");
  delay(1000);
}
