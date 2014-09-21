/* The MIT License (MIT)
 *
 * Copyright (c) 2014 to nils minor (contact nilsminor@web.de)
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */
#include "openMenu.h"

Menu::Menu (String _name) {
 menuName          = _name;    // set name
 selected          = false;    // is not seledted on start
 callbackSupported = false;    // No Callback at Beginning
}
String Menu::getName            (void) {
  return menuName;
}

void Menu::addCallback          (void (*_menuCallback)(void)) {
  menuCallback = _menuCallback;
  callbackSupported = true;
}
void Menu::select               (void) {
  selected = true;
}
void Menu::unselect             (void) {
  selected = false;
}
bool Menu::isSelected           (void) {
  return selected;
}
void Menu::invokeCallback       (void) {
  if (callbackSupported)
    menuCallback ( );
}
bool Menu::callbackIsSupported  (void) {
  return callbackSupported;
}
