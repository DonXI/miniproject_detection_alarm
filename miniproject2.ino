#include <TridentTD_LineNotify.h>
#include <WiFi.h>

#define buzzer 13
#define ir_analog 32
#define button 16
#define usb 25

const int ch = 0; // channel buzzer

// wifi and line token 
#define ssid "wifi"
#define password "password"
#define linetoken "line_token_key"

void setup() {
  Serial.begin(115200);
  
  /* input */ 
  pinMode(button, INPUT_PULLUP);
  
  /* output */
  // set Line notify
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED){
    Serial.println(".");
  }
  LINE.setToken(linetoken);
  // set USB light
  pinMode(usb, OUTPUT);
  //set buzzer
  ledcSetup(ch, 0, 8); 
  ledcAttachPin(buzzer, ch); 
}

void loop() {
  int val_ir = analogRead(ir_analog);
  //int sw = digitalRead(button);
  ledcWrite(ch, 25);
  Serial.println(val_ir);
  
  // IR detect 
  if(val_ir > 0){
    ledcWrite(ch,0);
    digitalWrite(usb, HIGH);
  }
  else{
    // send notify
    while(digitalRead(button) == HIGH){
      ledcWriteNote(ch, NOTE_C, 4);
      LINE.notify("ระวังมีผู้บุรุก");
      digitalWrite(usb, LOW);   
    }
    // button push => reset output
    LINE.notify("ปลอดภัยแล้ว");
  }
  delay(100);
}
