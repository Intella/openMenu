#include "openMenu.h"

Menu::Menu (String _name)
{
 menuName  = _name; 
 selected  = false;
}
String Menu::getName         (void) 
{
  return menuName;
}

void Menu::addCallback       (void (*_menuCallback)(void))
{
  menuCallback = _menuCallback;
}
void Menu::select         (void) {
  selected = true;
}
void Menu::unselect       (void) {
  selected = false;
}
