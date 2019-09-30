// runs Conway's game of life on the LED Matrix

const int rows = 8;
const int columns = 16;
int LEDColumns[columns] = {22, 24, 26, 28, 30, 32, 34, 36, 39, 41, 43, 45, 47, 49, 51, 53};
int LEDRows[rows]= {14, 15, 16, 17, 18, 19};
int life[rows][columns];

void setup() {
  for(int i = 0; i < rows; i++) {
    for(int j = 0; j < columns; j++) {
      life[i][j] = random(0,2);
    }
  }
  
  // rows
  for(int i = 0; i < rows; i++)
    pinMode(LEDRows[i], OUTPUT);
  // columns
  for(int j = 0; j < columns; j++)
    pinMode(LEDColumns[j], OUTPUT);

  for(int i = 0; i < rows; i++)
    digitalWrite(LEDRows[i],LOW);
  // columns
  for(int j = 0; j < columns; j++)
    digitalWrite(LEDColumns[j], LOW);
}

void updateLife() {
  for(int i = 0; i < rows; i++) {
    for(int j = 0; j < columns; j++) {
      life[i][j] = random(0,2);
    }
  }
}

void loop() {
  updateLife();
  for(int i = 0; i < rows; i++) {
    digitalWrite(LEDRows[i], LOW);
    for(int j = 0; j < columns; j++) {
      digitalWrite(LEDColumns[j], random(0,2));
    }
    delay(1000);
    for(int j = 0; j < columns; j++) {
        digitalWrite(LEDColumns[j], LOW);
    }
    digitalWrite(LEDRows[i], HIGH);
  }
}
