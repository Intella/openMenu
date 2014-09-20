#include "openMenu.h"

Menu::Menu (String _name)
{
 menuName = _name; 
}

String Menu::getName         (void) 
{
  return menuName;
}
void Menu::addCallback    (void (*_menuCallback)(void))
{
  menuCallback = _menuCallback;
}
