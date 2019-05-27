void setup() {
  Serial.begin(9600);
  pinMode(A1, OUTPUT);
  pinMode(A2, OUTPUT);
  pinMode(A3, OUTPUT);
}

void loop() {
  
  for (byte i = 0; i < 8; i++){
    digitalWrite(A1, LOW);
    digitalWrite(A2, LOW);
    digitalWrite(A3, LOW);
    if (B001 & i) digitalWrite(A1, HIGH);
    if (B010 & i) digitalWrite(A2, HIGH);
    if (B100 & i) digitalWrite(A3, HIGH);
    int v = analogRead(A0);
    Serial.print(v);
    Serial.print("\t");
    if (i == 7) Serial.println(".");
    delay(100);
  }
   
}
