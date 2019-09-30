// runs Conway's game of life on the LED Matrix
int _LEDColumns[6] = {14, 15, 16, 17, 18, 19};
int _LEDRows[6][3]=
{{36, 8, 43},
 {34, 9, 45},
 {32, 10, 47},
 {30, 11, 49},
 {28, 12, 51},
 {26, 13, 53}};

const int rows = 8;
int row_offset = 14;
const int columns = 18; // actually 16
int column_offset = 23;
int life[rows][columns];

void setup() {
  for(int i = 0; i < rows; i++) {
    for(int j = 0; j < columns; j++) {
      life[i][j] = 0;
    }
  }
  
  // rows
  for(int i = row_offset; i < row_offset+rows; i++)
    pinMode(i, OUTPUT);
  // columns
  for(int j = column_offset; j < column_offset+columns; j++)
    pinMode(j, OUTPUT);

  for(int i = row_offset; i < row_offset+rows; i++)
    digitalWrite(i,HIGH);
  // columns
  for(int j = column_offset; j < column_offset+columns; j++)
    digitalWrite(j, HIGH);
}

void updateLife() {
  for(int i = 0; i < rows; i++) {
    for(int j = 0; j < columns; j++) {
      life[i][j] = 0;
    }
  }
}

void loop() {
  updateLife();
  // write to LEDs (multiplex)
  /*
  for(int i = 0; i < rows; i++) {
    digitalWrite(i+row_offset, HIGH);
    for(int j = 0; j < columns; j++) {
      if(life[i][j] == 1)
        digitalWrite(2*j+column_offset,LOW);
    }
    // short delay for POV (Persistence of Vision)
    delayMicroseconds(100);
    for(int j = 0; j < columns; j++) {
      digitalWrite(2*j+column_offset,LOW);
    }
    digitalWrite(i+row_offset, LOW);
  }
  */
}
