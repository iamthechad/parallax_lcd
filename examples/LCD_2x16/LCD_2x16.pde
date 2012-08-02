/* 
 	NOTE: you must: #include <SoftwareSerial.h>
 	BEFORE including the ParallaxLCD.h header
 */

#include <SoftwareSerial.h>
#include <ParallaxLCD.h>

#define ROWS 2
#define COLS 16

ParallaxLCD lcd(2,2,16); // desired pin, rows, cols

/**
 * Initialize the 2-dimensional custom character byte array.
 * Even though each 'byte' is 0-255, only the lowest 5 bytes are used. So only
 *  0-31 are valid values.
 */
byte customCharacters[8][8] = {0, 4, 14, 31, 14, 4, 0, 0,   // Diamond
                               0, 10, 14, 31, 31, 14, 4, 0, // Heart
                               0, 4, 14, 31, 14, 4, 14, 0,  // Spade
                               4, 14, 4, 10, 31, 10, 4, 14, // Club (sorta...)
                               4, 14, 21, 4, 4, 4, 4, 4,    // Up
                               4, 4, 4, 4, 4, 21, 14, 4,    // Down
                               27, 22, 13, 27, 22, 13, 27, 22, // Stipple pattern #1
                               29, 14, 23, 27, 29, 14, 23, 27  // Stipple pattern #2
                             };
void setup () {

  lcd.setup();
  delay(1000);
  lcd.backLightOn();
  lcd.at(1,4,"Milliseconds\0");
  delay(1000);
  lcd.off();
  delay(1000);
  lcd.on();
  lcd.pos(0,1);
  lcd.at(0,1,"m:\0");
  for (int b=0; b<101; b+=5) {
    lcd.at(0,3,millis());
    delay(500);
  }
  lcd.empty();
  lcd.print("Line Feed\0");
  for (int b=0; b<51; b+=5) {
    lcd.lf();
    delay(500);
  }
  lcd.empty();
  lcd.print("Chr Return\0");
  delay(1000);
  for (int b=0; b<51; b+=5) {
    lcd.pos(0,11);
    delay(500);
    lcd.cr();
    delay(500);
  }

  lcd.cursorBlock();
  lcd.empty();
  lcd.print("Block Cursor\0");
  for (int x=1; x<16; x++) {
    lcd.pos(1,x);
    delay(500);
  }
  lcd.empty();
  lcd.print("Underline Cursor\0");
  lcd.cursorUnderline();
  for (int x=1; x<16; x++) {

    lcd.pos(1,x);
    delay(500);
  }
  lcd.backLightOff();
  lcd.cursorOff();
  
  // Clear the screen and enjoy a brief interlude.
  lcd.empty();
  lcd.print("Music Maestro!\0");
  lcd.playTone(213, 216, 223);
  lcd.playTone(213, 216, 223);
  lcd.playTone(214, 216, 227);
  lcd.playTone(210, 217, 220);
  lcd.playTone(210, 217, 222);
  lcd.playTone(210, 217, 224);
  lcd.playTone(210, 217, 226);
  delay(3000);
  
  /**
   * Initialize the custom character slots on the LCD with the predefined values.
   */
  int i;
  for(i=0; i < 8; i++) {
    lcd.setCustomCharacter(i, customCharacters[i]);
  }
  lcd.empty();
  lcd.backLightOn();
  // Now display them for 2 seconds each.
  for(i=0; i < 8; i++) {
    lcd.at((i%ROWS),1, "Custom Char \0");
    lcd.at((i%ROWS),13, i);
    lcd.printCustomCharacter(i);
    lcd.cr();
    delay(2000);
  }
}

void loop () {
  lcd.at(2,9,millis());
}


