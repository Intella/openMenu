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
              Menu             (String _name);
    String    getName          (void);
    void      addCallback      (void (*_menuCallback)(void));
    void      select           (void);
    void      unselect         (void);
    bool      isSelected       (void);
    void      invokeCallback   (void);
  private:
    String    menuName;
    void      (*menuCallback)  (void);
    bool      selected;
    bool      callbackSupported;
};

class MenuSystem   {
    
public:
             MenuSystem        (String _name);
    int      addMenu           (Menu *m, void (*_menuCallback)(void));
    int      addMenu           (Menu *m);
    void     printMenuSystem   (void);
    String   getName           (void);
    void     next              (void);
    void     prev              (void);
    void     call              (void);
    
private:  
    String   menuSystemName;  // name of menu system
    int      selectCounter;   // 
    Menu  * *listMenu ;       // stores pointer to menu objects 
    uint8_t  menuQuantity;    // quantity of menus
    
};



#endif
