#include <TridentTD_LineNotify.h>
#include <WiFi.h>

#define buzzer 13
#define ir_analog 32
const int ch = 0; // channel
const int bpm = 120;
const int quarter_note_delay = (60 * 1000) / bpm;

// wifi and line token 
#define ssid "xi_xxviii"
#define password "khanoon_chompoo"
#define linetoken "qkYVxT6JeQtj2gj9qTqpvjt17Ze5p7Z1FzPiaBP5N9X"

void setup() {
  Serial.begin(115200);
  //set timer
  ledcSetup(ch, 0, 8); 
  ledcAttachPin(buzzer, ch);

  // connect WIFI
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED){
    Serial.println(".");
  }
  
  // set Line notify
  LINE.setToken(linetoken);
  
}

void loop() {
  int val_ir = analogRead(ir_analog);
  ledcWrite(ch, 80);  // set volume duty cycle = 25%
  Serial.println(val_ir);
  
  if(val_ir > 0){
    ledcWrite(ch,0);
  }
  else{
    ledcWriteNote(ch, NOTE_C, 4);
    delay(quarter_note_delay);
    LINE.notify("มีผู้บุกรุก");
    
  }
  delay(100);
}
