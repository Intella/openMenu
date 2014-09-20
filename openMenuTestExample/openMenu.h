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
              Menu           (void);
              Menu           (String _name);
    String    getName        (void);
    void      addCallback    (void (*_menuCallback)(void));
    void      select         (void);
    void      unselect       (void);
  private:
    String    menuName;
    void      (*menuCallback)    (void);
    bool      selected;
};

class MenuSystem   {
    
public:
             MenuSystem      (String _name);
    int      addMenu         (Menu *m, void (*_menuCallback)(void));
    void     printMenuSystem (void);
    String   getName         (void);
    
private:
    String   menuSystemName;
    int      selectCounter;
    Menu  * *listMenu ;       // stores pointer to menu objects 
    uint8_t  menuQuantity;
    
};



#endif
