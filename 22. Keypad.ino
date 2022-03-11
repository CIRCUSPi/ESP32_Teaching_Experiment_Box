#define ROWS 4
#define COLS 4

char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte rowPins[ROWS] = {32, 17, 5, 4};
byte colPins[COLS] = {25, 27, 26, 22};

byte scanCode[ROWS][COLS] = {
  {0, 1, 1, 1},
  {1, 0, 1, 1},
  {1, 1, 0, 1},
  {1, 1, 1, 0}
};

char key;

char keyScan() {
  for (int i=0; i<4; i++) {
    for (int j=0; j<4; j++) {
      digitalWrite(rowPins[j], scanCode[i][j]);
    }
    for (int k=0; k<4; k++) {
      if (digitalRead(colPins[k]) == 0) {
        delay(10);
        if (digitalRead(colPins[k]) == 0) {
          while(digitalRead(colPins[k]) == 0);
          return hexaKeys[i][k];
        }
      }
    }
  }
  return 'X';
}

void setup(){
  Serial.begin(9600);
  for (int i=0; i<4; i++) {
    pinMode(rowPins[i], OUTPUT);
    pinMode(colPins[i], INPUT_PULLUP);
  }
}

void loop(){
  key = keyScan();

  if (key != 'X'){
    Serial.println(key);
  }
}
