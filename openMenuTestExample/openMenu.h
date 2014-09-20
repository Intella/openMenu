#ifndef _OPEN_MENU_
#define _OPEN_MENU_

#if ARDUINO >= 100
 #include "Arduino.h"
 #include "Print.h"
#else
 #include "WProgram.h"
#endif

class Menu {
  
  public:
              Menu           (String _name);
    String    getName        (void);
  private:
    String    menuName;
};

class MenuSystem    {
    
public:
             MenuSystem      (String _name);
    int      addMenu         (Menu *m);
    void     printMenuSystem (void);
    String   getName         (void);
    
private:
    String   menuSystemName;
    Menu  * *listMenu ;       // stores pointer to menu objects 
    uint8_t  menuQuantity;
    
};



#endif
