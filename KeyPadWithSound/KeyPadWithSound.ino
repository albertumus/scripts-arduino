#include "pitches.h"
#include <Keypad.h>

int melody[] = {
  NOTE_C5, NOTE_D5, NOTE_E5, NOTE_F5, NOTE_G5, NOTE_A5, NOTE_B5, NOTE_C6};
int duration = 500;

const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
//define the cymbols on the buttons of the keypads
char hexaKeys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = {9, 8, 7, 6}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {5, 4, 3, 2}; //connect to the column pinouts of the keypad

//initialize an instance of class NewKeypad
Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  String secretKey = "123";
  String userKey = "";
  bool i = true;  

  while (i) {
    char customKey = customKeypad.getKey();
    if (customKey) {
      userKey = userKey + customKey;
      Serial.println(userKey);
    }
    if ( userKey.length() == 3) {
      if (userKey == secretKey) {
        Serial.println("Has acertado la clave secreta");
        Sonar();
      } else {
        Serial.println("No has acertado la clave secreta");
        Alarma();
      }
      i = false;
    }
     
  }
  
}


void Sonar() {
  for (int i=0; i<3;i++) {
    tone(12, melody[0], duration);
    delay(1000);
  }
}

void Alarma() {
  for (int i=0; i<3;i++) {
    tone(12, melody[1], duration);
    delay(1000);
  }
}
