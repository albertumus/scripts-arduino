#define RED 13
void setup() {
 pinMode(RED, OUTPUT);
}
 
void loop() {
  delay(1000);
  digitalWrite(RED,HIGH);
  delay(3000);
  digitalWrite(RED,LOW);
}
