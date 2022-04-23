// test input IR sensor, output buzzer

#define buzzer 13     // pin buzzer
#define ir_analog 32  // pin IR 
const int ch = 0;     // channel
const int bpm = 120;
const int quarter_note_delay = (60 * 1000) / bpm;

void setup() {
  Serial.begin(115200);
  //set timer
  ledcSetup(ch, 0, 8); 
  ledcAttachPin(buzzer, ch);
}

void loop() {
  int val_ir = analogRead(ir_analog);
  ledcWrite(ch,25);  // set volume duty cycle = 25%
  Serial.println(val_ir);
  // IR detect 
  if(val_ir > 0){
    ledcWrite(ch,0);
  }
  else{
    ledcWriteNote(ch, NOTE_C, 4);
    delay(quarter_note_delay);
  }
  delay(100);
}
