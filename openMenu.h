#ifndef _OPEN_MENU_
#define _OPEN_MENU_

#if ARDUINO >= 100
 #include "Arduino.h"
 #include "Print.h"
#else
 #include "WProgram.h"
#endif

#include "openMenu.h"
#include "openMenuSystem.h"

class MenuSystem :public Menu {
    
public:
    MenuSystem (String _name);
    int      addMenu (Menu m);
    void     printMenuSystem (void);
    String   getName (void);
    
private:
    String   menuSystemName;
    Menu     listMenu [ ];
    uint8_t  menuQuantity;
    
};

class Menu {
  
  public:
    Menu (String _name);
    String getName (void);
  private:
    String menuName;
  
  
};

#endif
