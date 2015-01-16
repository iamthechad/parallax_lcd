/* 
	NOTE: you must: #include <SoftwareSerial.h>
	BEFORE including the class header file
	
	For Parallax LCD's (27976, 27977, 27979)
	For more information contact http://www.parallax.com	
	
	Updated to Arduino 1.0 by Chad Johnston (cjohnston@megatome.com)
	July 11, 2012
	      
	Original Work done by:
    Douglas Farrell	
    cyberblob59@yahoo.com
			  
    Used/Modified with permission from allen joslin
    --Based on SparkFunSerLCD.h from--
	allen joslin
	payson productions
	allen@joslin.net
	
	Updated 8/1/2012 Martin C. Stoufer mcstoufer@speakeasy.net
	# Added interface functions to play music and define/print custom characters.
*/
/*
The MIT License (MIT)

Copyright (c) 2012-2013 Megatome Technologies, LLC

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
*/

#ifndef ParallaxLCD_h
#define ParallaxLCD_h

#include <Arduino.h>

/******************************************************************************************************/
/* ParallaxLCD -- manages the Parallax LCD's, based on NewSoftSerial to aid pinning and printing      */
/*                                                                                                    */
/*	   Stable Serial Speeds 2400, 9600, 19200                                                         */
/*                                                                                                    */
/*     posBase: cursor positioning                                                                    */
/*                                                                                                    */
/*     on/off: display of characters                                                                  */
/*                                                                                                    */
/*     bright: backlight control, on or off                                                           */
/*                                                                                                    */
/*     LF: Line Feed control                                                                          */
/*                                                                                                    */
/*     CR: Carrage Return control                                                                     */
/*                                                                                                    */
/*     Cursor: Cursor Control                                                                         */
/*                                                                                                    */
/*     Music: Generate tones for Piezo speaker                                                        */
/*                                                                                                    */
/*     Custom Characters: Store and display custom characters                                         */
/*                                                                                                    */
/******************************************************************************************************/

class ParallaxLCD : public SoftwareSerial {
public:
   ParallaxLCD ( int pin, int numRows, int numCols );
   void setup ( boolean startEmpty=true ); 

   void on ();
   void off ();
   void lf ();
   void cr ();
   void empty ();

   void scrollLeft ();
   void scrollRight ();

   void backLightOn (); //Backlight only available with model numbers 27977, 27979
   void backLightOff (); //Backlight only available with model numbers 27977, 27979
   
   void pos ( int row, int col );

   void cursorUnderline();
   void cursorBlock();
   void cursorOnChrBlink();
   void cursorOff ();

   // Make music
   void playTone ( int duration, int scale, int note );
   
   // Custom characters
   void setCustomCharacter(int charIndex, unsigned char bytes[]);
   void printCustomCharacter(int charIndex);
   
	// shortcuts for printing at particular positions
   void at ( int row, int col, char );
   void at ( int row, int col, const char[] );
   void at ( int row, int col, String );
   void at ( int row, int col, uint8_t );
   void at ( int row, int col, int );
   void at ( int row, int col, unsigned int );
   void at ( int row, int col, long );
   void at ( int row, int col, unsigned long );
   void at ( int row, int col, long, int );

private:
	int _bv[9];
};


#endif
