/* 
  NOTE: you must: #include <SoftwareSerial.h>
  BEFORE including the ParallaxLCD.h header
 */

#include <SoftwareSerial.h>
#include <ParallaxLCD.h>

// Change these values if you're using the 4x20 LCD
#define ROWS 2
#define COLS 16

ParallaxLCD lcd(2,ROWS,COLS); // desired pin, rows, cols

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
  lcd.empty();

  // Count some milliseconds
  lcd.at(1,4,"Milliseconds\0");
  delay(1000);
  lcd.off();
  delay(1000);
  lcd.on();
  lcd.at(0,0,"m:\0");
  for (int b=0; b<=100; b+=5) {
    lcd.at(0,2,millis());
    delay(500);
  }

  // Line feeds
  lcd.empty();
  lcd.print("Line Feed\0");
  for (int b=0; b<=50; b+=5) {
    lcd.lf();
    delay(500);
  }

  // Carriage Returns
  lcd.empty();
  lcd.print("Chr Return\0");
  delay(1000);
  for (int b=0; b<=30; b+=5) {
    lcd.pos(0,10);
    delay(500);
    lcd.cr();
    delay(500);
  }

  // Different cursors
  lcd.empty();
  lcd.cursorBlock();
  lcd.print("Block Cursor\0");
  for (int x=0; x<COLS; x++) {
    lcd.pos(1,x);
    delay(500);
  }
  lcd.empty();
  lcd.cursorUnderline();
  lcd.print("Underline Cursor\0");
  for (int x=0; x<COLS; x++) {
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
    lcd.at((i%ROWS),0, "Custom Char \0");
    lcd.at((i%ROWS),13, i);
    lcd.printCustomCharacter(i);
    lcd.cr();
    delay(2000);
  }
}

void loop () {
  lcd.at(ROWS,9,millis());
}
