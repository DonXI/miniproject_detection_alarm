#define button 16

void setup() {
  Serial.begin(115200);
  pinMode(button, INPUT_PULLUP);
}

void loop() {
  int sw = digitalRead(button);
  Serial.println(sw);
  if(sw == LOW){
    Serial.print(sw); //กด reset
  }
  else{
    Serial.print(sw);
  }
  delay(500);
}
