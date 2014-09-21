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
 
#ifndef _OPEN_MENU_
#define _OPEN_MENU_

#if ARDUINO >= 100
 #include "Arduino.h"
 #include "Print.h"
#else
 #include "WProgram.h"
#endif

#include <LiquidCrystal.h>
 
class Menu {
  
  public:
              Menu             (String _name);                            // constructor
    String    getName          (void);                                    // return menu name
    void      addCallback      (void (*_menuCallback)(void));             // add menu callback
    void      select           (void);                                    // select menu
    void      unselect         (void);                                    // unselect menu
    bool      isSelected       (void);                                    // returns true if menu is selected, false else
    void      invokeCallback   (void);                                    // invoke menu callback function
    bool      callbackIsSupported   (void);                               // returns true it menu supports callback function, false else
  private:
    String    menuName;
    void      (*menuCallback) (void);                                     // menu callback must look like "void callMe (void)"
    bool      selected;                                                   // true if selected, false else
    bool      callbackSupported;                                          // true if menu supports callback function, false else
};

class MenuSystem   {
    
public:
             MenuSystem        (String _name);                            // constructor 
    int      addMenu           (Menu *m, void (*_menuCallback)(void));    // add menu to menu system with callback function
    int      addMenu           (Menu *m);                                 // add menu to menu system without callback function
    void     printMenuSystem   (void);                                    // print the whole menu system for debbuging
    String   getName           (void);                                    // return menu system name
    void     next              (void);                                    // choose next menu
    void     prev              (void);                                    // choose previous menu  
    void     call              (void);                                    // invoke menu callback
    String   getMenuName       (uint8_t index);                           // return menu name by index
    bool     menuIsSelected    (uint8_t index);                           // true if menu by index is selected, else false  
    uint8_t  getSelectCounter  (void);                                    // retruns selection counter
    uint8_t  getMenuQuantity   (void);                                    // returns menu quantity added to menu system
    uint8_t  scroll            (uint8_t l);                          
    
    
private:  
    String   menuSystemName;                                              // name of menu system
    int      selectCounter;                                               // selection counter
    Menu   **listMenu ;                                                   // stores pointer to menu objects 
    uint8_t  menuQuantity;                                                // quantity of menus
    
};




#endif
