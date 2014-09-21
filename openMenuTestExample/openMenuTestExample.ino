/* The MIT License (MIT)
 *
 * Copyright (c) 2014 to nils minor (contact nilsminor@web.de)
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */
#include <openRotary.h>
#include <LiquidCrystal.h>
#include "openMenu.h"

/***************************************************************************************************************************************/
/**  LCD *******************************************************************************************************************************/
/***************************************************************************************************************************************/
/*      Pin  Arduino Micro      4004A LCD -> http://www.powertipusa.com/pdf/pc4004a.pdf */  
#define RS           12         // 11
#define RW           11         // 10
#define E1           10         //  9
#define E2           9          // 15
#define D4           5          //  4
#define D5           4          //  3
#define D6           3          //  2
#define D7           2          //  1

#define LCD_COLS     40
#define LCD_LINES    4
#define CURSOR       "-> "
// LCD function:  RS,RW,EN1,EN2,D4,D5,D6,D7
// PC4004-A pins: 11,10,  9, 15, 4, 3, 2, 1
LiquidCrystal lcd (12,11,10, 9, 5, 4, 3, 2);
/***************************************************************************************************************************************/

/***************************************************************************************************************************************/
/** menu *******************************************************************************************************************************/
/***************************************************************************************************************************************/
MenuSystem ms ("main-menu");
Menu       m1 ("sub-menu 1"); 
void m1_callback (void) { 
  Serial.println("m1_callback");
}
Menu       m2 ("sub-menu 2");
Menu       m3 ("sub-menu 3");
Menu       m4 ("sub-menu 4");
Menu       m5 ("sub-menu 5");

/***************************************************************************************************************************************/

/***************************************************************************************************************************************/
/** Rotary *****************************************************************************************************************************/
/***************************************************************************************************************************************/
// Arduino micro input-pins to connect to CESI-32/LX
#define ROTARY_STATE_PIN         A3
#define ROTARY_DIRECTION_PIN     A5
#define ROTARY_BUTTON_PIN        A4
#define ROTARY_BUTTON_DEBOUNCE   50

OpenRotary rotary = OpenRotary (ROTARY_STATE_PIN, ROTARY_DIRECTION_PIN, ROTARY_BUTTON_PIN, 0);    // make the rotary encoder object 

void callbackRotaryButtonPressed (void) {  // handler which will be called if the rotary button is pressed
  ms.call ( );
  printMenu ( );
}
void callbackRotaryTurnRight (void) {      // handler which will be called if the rotary encoder is turned right
  ms.next ( );
  printMenu ( );
}
void callbackRotaryTurnLeft (void)  {      // handler which will be called if the rotary encoder is turned right
  ms.prev ( );
  printMenu ( );
}
/***************************************************************************************************************************************/

void setup ( ) {
  Serial.begin (115200);
   
  rotary.setRotaryCountBoundaries (-10,10);                            // set rotary counter boundaries 
  rotary.setRotaryButtonCallback  (&callbackRotaryButtonPressed);      // set callback for button press
  rotary.setRotaryRotationCallback(&callbackRotaryTurnRight,           // set callback for rotation
                                   &callbackRotaryTurnLeft);
  m1.select   ( );    // select first one                                 
  ms.addMenu  (&m1, &m1_callback);
  ms.addMenu  (&m2);
  ms.addMenu  (&m3);
  ms.addMenu  (&m4);
  ms.addMenu  (&m5);  
 
  lcd.begin     (LCD_COLS, LCD_LINES);
  
}
void loop() {
  rotary.check ( );    // in loop just check the rotary  

  
}

uint8_t middle (String str) {                // calculate middle
  return ( (LCD_COLS/2) - (str.length()/2) );
}


void printMenu (void) {
  lcd.clear ( );
  // print main menu line
  lcd.setCursor (middle(ms.getName ()),0); 
  lcd.print (ms.getName ());
 
  lcd.setCursor (37,0); 
  lcd.print (ms.getSelectCounter()+1); lcd.print ("/");lcd.print (ms.getMenuQuantity ( )); 
  
  
  int scroll = ms.scroll (LCD_LINES);
  for (int i = 1; i < LCD_LINES;i++) {
    lcd.setCursor (0,i);  // line
    if (ms.menuIsSelected (scroll)) lcd.print (CURSOR);
    lcd.print (ms.getMenuName (scroll));
    scroll++;
  }
   ms.printMenuSystem ( );
}
