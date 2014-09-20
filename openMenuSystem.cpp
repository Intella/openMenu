#include "openMenu.h"
#include "openMenuSystem.h"

MenuSystem::MenuSystem       (String _name)
{
   menuSystemName = _name;
   menuQuantity   = 0;
}

int MenuSystem::addMenu          (Menu m){
  listMenu [menuQuantity++] = m;
  return menuQuantity;
}
MenuSystem::printMenuSystem (void){
  Serial.print ("->");
  Serial.println(menuSystemName);
  for (int i = 0; i!= menuQuantity; i++) {
    
    Serial.print("-->"); Serial.println(listMenu [i].getName ( ));
  }
}

String MenuSystem::getName         (void) 
{
  return menuSystemName;
}
