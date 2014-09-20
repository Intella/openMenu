#include "openMenu.h"
#include "openMenuSystem.h"


Menu::Menu (String _name)
{
 menuName = _name; 
}

String Menu::getName         (void) 
{
  return menuName;
}
