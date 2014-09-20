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
    
private:  
    String   menuSystemName;                                              // name of menu system
    int      selectCounter;                                               // selection counter
    Menu   **listMenu ;                                                   // stores pointer to menu objects 
    uint8_t  menuQuantity;                                                // quantity of menus
    
};




#endif
