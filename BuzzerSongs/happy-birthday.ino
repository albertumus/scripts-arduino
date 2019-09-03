//Alberto - Happy Birthday
//2019.08.28

#include "pitches.h"
 
// notes in the melody:
int melody[] = {
  NOTE_C5, NOTE_D5, NOTE_E5, NOTE_F5, NOTE_G5, NOTE_A5, NOTE_B5, NOTE_C6};
int duration = 500;  // 500 miliseconds
 
void setup() {
 
}
 
void loop() {  
  // Primera Parte
  tone(8, melody[0], duration);
  delay(500);
   
  tone(8, melody[0], duration);
  delay(500);

  tone(8, melody[1], duration);
  delay(500);

  tone(8, melody[0], duration);
  delay(500);

  tone(8, melody[3], duration);
  delay(500);

  tone(8, melody[2], duration+200);
  delay(500);

  delay(1000);
  // Segunda Parte
  tone(8, melody[0], duration);
  delay(500);
    
  tone(8, melody[0], duration);
  delay(500);

  tone(8, melody[1], duration);
  delay(500);

  tone(8, melody[0], duration);
  delay(500);

  tone(8, melody[4], duration);
  delay(500);

  tone(8, melody[3], duration+200);
  delay(500);

  delay(1000);

  // Tercera Parte
  tone(8, melody[0], duration);
  delay(500);
    
  tone(8, melody[0], duration);
  delay(500);

  tone(8, melody[7], duration);
  delay(500);
    
  tone(8, melody[5], duration);
  delay(500);

  tone(8, melody[3], duration);
  delay(500);

   tone(8, melody[2], duration);
   delay(500);

   tone(8, melody[1], duration);
   delay(500);

   tone(8, melody[6], duration);
   delay(500);

   tone(8, melody[6], duration);
   delay(500);

   tone(8, melody[5], duration);
   delay(500);

   tone(8, melody[3], duration);
   delay(500);

   tone(8, melody[4], duration);
   delay(500);

   tone(8, melody[3], duration+300);
   delay(500);

  
  // restart after two seconds 
  delay(7000);
}
