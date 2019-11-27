//www.elegoo.com
//2016.12.9
#include "IRremote.h"

int ledPin = 13;  // LED on Pin 13 of Arduino
int pirPin = 7; // Input for HC-S501
int buzzer = 12;
int receiver = 11;

int pirValue; // Place to store read PIR Value

IRrecv irrecv(receiver);   
decode_results results;

// describing Remote IR codes 
String translateIR()
{
  String result = "None";
  switch(results.value)

  {
  case 0xFFA25D: Serial.println("POWER"); result = "POWER"; break;
  case 0xFFE21D: Serial.println("FUNC/STOP"); break;
  case 0xFF629D: Serial.println("VOL+"); break;
  case 0xFF22DD: Serial.println("FAST BACK");    break;
  case 0xFF02FD: Serial.println("PAUSE");    break;
  case 0xFFC23D: Serial.println("FAST FORWARD");   break;
  case 0xFFE01F: Serial.println("DOWN");    break;
  case 0xFFA857: Serial.println("VOL-");    break;
  case 0xFF906F: Serial.println("UP");    break;
  case 0xFF9867: Serial.println("EQ");    break;
  case 0xFFB04F: Serial.println("ST/REPT");    break;
  case 0xFF6897: Serial.println("0");    break;
  case 0xFF30CF: Serial.println("1");    break;
  case 0xFF18E7: Serial.println("2");    break;
  case 0xFF7A85: Serial.println("3");    break;
  case 0xFF10EF: Serial.println("4");    break;
  case 0xFF38C7: Serial.println("5");    break;
  case 0xFF5AA5: Serial.println("6");    break;
  case 0xFF42BD: Serial.println("7");    break;
  case 0xFF4AB5: Serial.println("8");    break;
  case 0xFF52AD: Serial.println("9");    break;
  case 0xFFFFFFFF: Serial.println(" REPEAT");break;  

  default: 
    Serial.println(" other button   ");

  }// End Case

  delay(500); // Do not get immediate repeat
  return result;

} //END translateIR

void setup() {
  Serial.begin(9600);
  Serial.println("IR Receiver Button Decode"); 
  pinMode(buzzer,OUTPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(pirPin, INPUT);

  irrecv.enableIRIn();

  digitalWrite(buzzer,LOW);
  digitalWrite(ledPin, LOW);
  
  
  
}

void loop() {
  pirValue = digitalRead(pirPin);
  if (pirValue == 1) {
    digitalWrite(ledPin, HIGH);
    digitalWrite(buzzer, HIGH);
    if (irrecv.decode(&results)) // have we received an IR signal?
    {
      String result = translateIR(); 
      if (result == "POWER") {
        digitalWrite(buzzer, LOW);
        digitalWrite(ledPin, LOW);
        delay(20000);
      }
      irrecv.resume(); // receive the next value
    }  
  } else {
    digitalWrite(ledPin, LOW);
    digitalWrite(buzzer, LOW);
  }
  
  

}
