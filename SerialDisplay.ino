/*
  LiquidCrystal Library - Serial Input

 Demonstrates the use a 16x2 LCD display.  The LiquidCrystal
 library works with all LCD displays that are compatible with the
 Hitachi HD44780 driver. There are many of them out there, and you
 can usually tell them by the 16-pin interface.

 This sketch displays text sent over the serial port
 (e.g. from the Serial Monitor) on an attached LCD.

 The circuit:
 * LCD RS pin to digital pin 12
 * LCD RW pin to digital pin 11
 * LCD Enable pin to digital pin 10
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)

 Library originally added 18 Apr 2008
 by David A. Mellis
 library modified 5 Jul 2009
 by Limor Fried (http://www.ladyada.net)
 example added 9 Jul 2009
 by Tom Igoe
 modified 22 Nov 2010
 by Tom Igoe
 modified 7 Nov 2016
 by Arturo Guadalupi

 This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/LiquidCrystalSerialDisplay

*/

// include the library code:
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, rw = 11, en = 10, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, rw, en, d4, d5, d6, d7);
uint8_t incomingByte,lcdByte;

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  lcd.home();
  // initialize the serial communications:
  Serial.begin(9600);
}

void loop() {
  if (Serial.available()) {
    incomingByte = Serial.read();
    if ((incomingByte >=32) && (incomingByte <= 126)) lcd.write(incomingByte);
    if (incomingByte == 0x01) lcd.begin(20, 2);
    if (incomingByte == 0x02) lcd.setCursor(0, 0);  //GOTOLNE0
    if (incomingByte == 0x03) lcd.setCursor(0, 1);  //GOTOLNE1
    if (incomingByte == 0x04) lcd.clear();
  }
}
