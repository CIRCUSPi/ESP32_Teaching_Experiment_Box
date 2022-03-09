/*
 * 共陽極
 * #define D1 33
 * #define D2 16
 * #define D3 12
 * #define D4 32
 * #define A 17
 * #define B 5
 * #define C 4
 * #define D 25
 * #define E 27
 * #define F 26
 * #define G 22
 * #define DP 21
 */
const byte pointPin[4] = {32, 33, 16, 12};
const byte numberPin[8] = {21, 22, 26, 27, 25, 4, 5, 17};
const byte numberCode[10] = {0xc0, 0xf9, 0xa4, 0xb0, 0x99, 0x92, 0x82, 0xf8, 0x80, 0x90};

String printCode[5] = {"0", "0", "0", "0", "0"};

void setup() {
  Serial.begin(9600);
  for (int i=0; i<4; i++) {
    pinMode(pointPin[i], OUTPUT);
    digitalWrite(pointPin[i], HIGH);
  }
  for (int i=0; i<8; i++) {
    pinMode(numberPin[i], OUTPUT);
  }

}

void loop() {
  numberPrint(0.325);
}

void numberPrint(float _value) {
  String value = String(float(_value),3);
  byte Position = 0;
  byte point = 0;
  for (int i=0; i<5; i++) {
    if (value[i] == '.') {
      point = i;
    }
    else {
      printCode[Position] = value[i];
      Position += 1;
    }
  }

  for (int i=0; i<4; i++) {
    digitalWrite(pointPin[i], LOW);
    delay(5);
    int cnt = printCode[i].toInt();
    //Serial.println(cnt);

    if ((point-1) == i) {
      byte count = numberCode[cnt]^0x80;
      for (int pin=0; pin<8; pin++) {
        digitalWrite(numberPin[7-pin], (count >> pin)& 0x01);
      }
    }
    else {
      for (int pin=0; pin<8; pin++) {
        digitalWrite(numberPin[7-pin], (numberCode[cnt] >> pin)& 0x01);
      }
    }

    digitalWrite(pointPin[i], HIGH);
  }
}
