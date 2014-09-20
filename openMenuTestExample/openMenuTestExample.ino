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

// LCD function:  RS,RW,EN1,EN2,D4,D5,D6,D7
// PC4004-A pins: 11,10,  9, 15, 4, 3, 2, 1
LiquidCrystal lcd (12,11, 10,  9, 5, 4, 3, 2);
/***************************************************************************************************************************************/

/***************************************************************************************************************************************/
/** menu *******************************************************************************************************************************/
/***************************************************************************************************************************************/
MenuSystem ms ("main-menu");
Menu       m1 ("sub-menu 1");
Menu       m2 ("sub-menu 2");
Menu       m3 ("sub-menu 3");


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

void callbackRotaryButtonPressed (void)            // handler which will be called if the rotary button is pressed
{
  
 ms.printMenuSystem ( );
}
void callbackRotaryTurnRight (void)                // handler which will be called if the rotary encoder is turned right
{
  Serial.print("callbackRotaryTurnRight");
  Serial.print("  rotaryCount: ");
  Serial.println(rotary.getRotaryCount ( ));
}
void callbackRotaryTurnLeft (void)                 // handler which will be called if the rotary encoder is turned right
{
  Serial.print("callbackRotaryTurnLeft");
  Serial.print("   rotaryCount: ");
  Serial.println(rotary.getRotaryCount ( ));
}
/***************************************************************************************************************************************/

void setup ( ) {
  Serial.begin (115200);
  rotary.setRotaryCountBoundaries (-10,10);                            // set rotary counter boundaries 
  rotary.setRotaryButtonCallback  (&callbackRotaryButtonPressed);      // set callback for button press
  rotary.setRotaryRotationCallback(&callbackRotaryTurnRight,           // set callback for rotation
                                   &callbackRotaryTurnLeft);
                                   
  ms.addMenu(&m1);
  ms.addMenu(&m2);
  ms.addMenu(&m3);
  
 /*
  lcd.begin (LCD_COLS, LCD_LINES);
  lcd.setCursor (0,0);
  lcd.print ("TEST");
  */
  
}
void loop() {
  rotary.check ( );    // in loop just check the rotary (maybe i will change it in futre to support intterupts but not needed in the moment)

  
}
