#include "openMenu.h"

Menu::Menu (String _name)
{
 menuName          = _name; 
 selected          = false;
 callbackSupported = false;    // No Callback at Beginning
}
String Menu::getName         (void) 
{
  return menuName;
}

void Menu::addCallback       (void (*_menuCallback)(void))
{
  menuCallback = _menuCallback;
  callbackSupported = true;
}
void Menu::select         (void) {
  selected = true;
}
void Menu::unselect       (void) {
  selected = false;
}
bool Menu::isSelected     (void) {
  return selected;
}
void Menu::invokeCallback (void) {
  if (callbackSupported)
    menuCallback ( );
}
