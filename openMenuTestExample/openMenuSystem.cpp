#include "openMenu.h"

MenuSystem::MenuSystem       (String _name)
{
   menuSystemName = _name;
   menuQuantity   = 0;
}

int MenuSystem::addMenu          (Menu m){
  listMenu [menuQuantity++] = m;
  return menuQuantity;
}
void MenuSystem::printMenuSystem (void){
  Serial.print ("menuQuantity: ");
  Serial.println(menuQuantity);
  Serial.print ("-->");
  Serial.println(menuSystemName);
  /*
  for (int i = 0; i != menuQuantity; i++) {
    
    Serial.print("-->"); Serial.println(listMenu[i].getName ( ));
  }
  */
  for ( it = list.begin(); it != list.end(); ++it ) {
      // For each friend, print out their info

      it->printFriendInfo();

   }

}
String MenuSystem::getName (void) {
  return menuSystemName;
}
