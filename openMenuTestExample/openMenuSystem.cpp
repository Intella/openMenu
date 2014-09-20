#include "openMenu.h"

MenuSystem::MenuSystem       (String _name)
{
   menuSystemName = _name;
   menuQuantity   = 0;
   selectCounter  = 0;

}
int MenuSystem::addMenu          (Menu *m, void (*_menuCallback)(void)) {
  
  listMenu = (Menu**) realloc (listMenu, 
                              (menuQuantity+1) * sizeof(Menu*)); // reallocate listMenu array,
  if (listMenu!=NULL) {
    listMenu [menuQuantity++]   = m;
    m->addCallback (_menuCallback);
    return menuQuantity;
   }
   else {
     Serial.println ("Error (re)allocating memory");
     return NULL;
   }
}
void MenuSystem::printMenuSystem (void){
  Serial.print ("menuQuantity: "); Serial.println(menuQuantity);
  
  Serial.print ("--> "); Serial.println(menuSystemName);
  
  for (int i = 0; i != menuQuantity; i++) {
    Serial.print("----> "); Serial.print (listMenu[i]->getName ( ));
    Serial.print ("  Callback: ");
    
  }


}
String MenuSystem::getName (void) {
  return menuSystemName;
}
