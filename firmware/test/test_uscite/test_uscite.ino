
//DS - DATA
#define REG_DS 8

//STCP - LATCH
#define REG_STCP 10

//SHCP - CLOCK
#define REG_SHCP 9

void setup() {
  pinMode(REG_DS, OUTPUT);
  pinMode(REG_STCP, OUTPUT);
  pinMode(REG_SHCP, OUTPUT);
}

void loop() {
  digitalWrite(REG_STCP, LOW);
  // shift out the bits:
  shiftOut(REG_DS, REG_SHCP, MSBFIRST, 0xFF);
  shiftOut(REG_DS, REG_SHCP, MSBFIRST, 0xFF);
  //take the latch pin high so the LEDs will light up:
  digitalWrite(REG_STCP, HIGH);

  delay(1000);
  //azzero:
  digitalWrite(REG_STCP, LOW);
  // shift out the bits:
  shiftOut(REG_DS, REG_SHCP, MSBFIRST, 0x00);
  shiftOut(REG_DS, REG_SHCP, MSBFIRST, 0x00);
  //take the latch pin high so the LEDs will light up:
  digitalWrite(REG_STCP, HIGH);
  
  delay(1000);
}
