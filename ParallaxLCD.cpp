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
*/
#include <Arduino.h>

#include <SoftwareSerial.h>
#include "ParallaxLCD.h"

#define PINOUT      0
#define POSBASE     1
#define BOUNCE      2
#define NUMROWS     3
#define NUMCOLS     4

ParallaxLCD::ParallaxLCD ( int pin, int numRows, int numCols, int posBase) : SoftwareSerial(pin,pin) {
	_bv[PINOUT]=pin;
	_bv[POSBASE]=posBase;
	_bv[BOUNCE]=10;
	_bv[NUMROWS]=numRows;
	_bv[NUMCOLS]=numCols;
	_ro[0]=0;
	_ro[1]=64;
	_ro[2]=numCols;
	_ro[3]=_ro[1]+numCols;
}

void ParallaxLCD::setup(boolean startEmpty ) {
	pinMode(_bv[PINOUT], OUTPUT);
	delay(_bv[BOUNCE]);
	begin(19200);
	delay(_bv[BOUNCE]);
	if (startEmpty) {
		empty(); 
	}
	cursorOff();
}

void ParallaxLCD::on () { 
	write(24); delay(_bv[BOUNCE]); 
}

void ParallaxLCD::off () { 
	write(21); delay(_bv[BOUNCE]); 
}

void ParallaxLCD::scrollLeft () { 
	print(8); delay(_bv[BOUNCE]); 
}

void ParallaxLCD::scrollRight () { 
	write(9); delay(_bv[BOUNCE]); 
}

void ParallaxLCD::empty () { 
	write(12); delay(_bv[BOUNCE]*10);
}

void ParallaxLCD::cursorUnderline () { 
	write(24); delay(_bv[BOUNCE]); 
}

void ParallaxLCD::cursorBlock () { 
	write(23); delay(_bv[BOUNCE]); 
}

void ParallaxLCD::cursorOff () { 
	write(22); delay(_bv[BOUNCE]); 
}

void ParallaxLCD::cursorOnChrBlink () { 
	write(25); delay(_bv[BOUNCE]); 
}

void ParallaxLCD::cr () { 
	write(13); delay(_bv[BOUNCE]); 
}

void ParallaxLCD::lf () { 
	write(10); delay(_bv[BOUNCE]); 
}

void ParallaxLCD::backLightOn () {
	write(17); delay(_bv[BOUNCE]);
}

void ParallaxLCD::backLightOff () {
	write(18); delay(_bv[BOUNCE]);
}

void ParallaxLCD::pos ( int row, int col ) 
{ 
	if (row == 0)
		{
			write(128 + _ro[(row - _bv[POSBASE])] + (col - _bv[POSBASE])); delay(_bv[BOUNCE]);
		}
	else if (row == 1)
		{
			write(148 + _ro[(row - _bv[POSBASE])] + (col - _bv[POSBASE])); delay(_bv[BOUNCE]);
		}
	else if (row == 2)
		{
			write(168 + _ro[(row - _bv[POSBASE])] + (col - _bv[POSBASE])); delay(_bv[BOUNCE]);			
		}
	else if (row == 3)
		{
			write(188 + _ro[(row - _bv[POSBASE])] + (col - _bv[POSBASE])); delay(_bv[BOUNCE]);			
		}
}

// shortcuts

void ParallaxLCD::at ( int row, int col, char v )				{ pos(row,col); print(v); }
void ParallaxLCD::at ( int row, int col, const char v[] )	{ pos(row,col); print(v); }
void ParallaxLCD::at ( int row, int col, String v )             { pos(row,col); print(v); }
void ParallaxLCD::at ( int row, int col, uint8_t v )			{ pos(row,col); print(v); }
void ParallaxLCD::at ( int row, int col, int v )				{ pos(row,col); print(v); }
void ParallaxLCD::at ( int row, int col, unsigned int v )	{ pos(row,col); print(v); }
void ParallaxLCD::at ( int row, int col, long v )				{ pos(row,col); print(v); }
void ParallaxLCD::at ( int row, int col, unsigned long v )	{ pos(row,col); print(v); }
void ParallaxLCD::at ( int row, int col, long v, int t )		{ pos(row,col); print(v,t); }