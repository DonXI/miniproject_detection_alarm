#define usb 25

void setup() {
  Serial.begin(115200);
  pinMode(usb, OUTPUT);

}

void loop() {
  digitalWrite(usb, LOW); // เปิดไฟ
  delay(500);
  digitalWrite(usb, HIGH);
  delay(500);
  digitalWrite(usb, LOW);
  delay(500);
  digitalWrite(usb, HIGH);
  delay(10000);
}
