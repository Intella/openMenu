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

MenuSystem::MenuSystem       (String _name) {
   menuSystemName = _name;
   menuQuantity   = 0;
   selectCounter  = 0;
   scrollActive   = false;
   scrollCounter  = 0;
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
int MenuSystem::addMenu          (Menu *m) {
  
  listMenu = (Menu**) realloc (listMenu, 
                              (menuQuantity+1) * sizeof(Menu*)); // reallocate listMenu array,
  if (listMenu!=NULL) {
    listMenu [menuQuantity++]   = m;
    return menuQuantity;
   }
   else {
     Serial.println ("Error (re)allocating memory");
     return NULL;
   }
}
void MenuSystem::printMenuSystem (void) {
  Serial.println("**********************************");
  Serial.print ("menuQuantity:    "); Serial.println(menuQuantity);
  Serial.print   ("selectCounter:   "); Serial.println(selectCounter);
  Serial.print   ("scrollCounter:   "); Serial.print(scrollCounter);
  Serial.print   ("   scrollActive:   ");
  if (scrollActive) Serial.println("active");
  else              Serial.println("idle");
  Serial.println ("");
  
  Serial.print ("--> "); Serial.println(menuSystemName);    
  
  for (int i = 0; i != menuQuantity; i++) {
    
    Serial.print("----> "); 
    if (listMenu [i]->isSelected ( )) Serial.print ("(s) ");
    else                              Serial.print ("    ");
    Serial.print (listMenu[i]->getName ( ));
    Serial.print ("  callback: ");
    if (listMenu [i]->callbackIsSupported ( )) Serial.print ("YES");
    else                                       Serial.print ("NO");
    Serial.println ("");
  }
  Serial.println("**********************************");
}
String MenuSystem::getName (void) {
  return menuSystemName;
}
void MenuSystem::next       (void) {
  if (selectCounter < menuQuantity-1) {
    listMenu [selectCounter]->unselect ( );    // unselect previous
    listMenu [++selectCounter]->select ( );    // select next
    if (scrollActive) scrollCounter++; 
  }
  
}
void MenuSystem::prev       (void) {
  if (selectCounter > 0) {
    listMenu [selectCounter]->unselect ( );    // unselect previous 
    listMenu [--selectCounter]->select ( );    // select next 
    if (scrollActive && scrollCounter !=0 ) scrollCounter--;
  }
}  
void MenuSystem::call       (void) {
    listMenu [selectCounter]->invokeCallback ( );  // call Callback 
}  
String MenuSystem::getMenuName       (uint8_t index) {
  if (index >= 0 && index < menuQuantity)
    return listMenu[index]->getName ( );
  else return "error";
} 
bool MenuSystem::menuIsSelected    (uint8_t index) {
  if (index >= 0 && index < menuQuantity)
    return listMenu[index]->isSelected ( );
  else return false;
}
uint8_t MenuSystem::scroll (uint8_t l) {
  uint8_t calculated = 0;  //selectCounter, l,i,menuQuantity
  if      (selectCounter < l-2) {  // no scrolling needed
    calculated = 0;
    scrollActive = false;
  }
  else {
    scrollActive = true;
    calculated = scrollCounter;
  }
  
  
  return calculated;
}
uint8_t MenuSystem::getSelectCounter  (void) {
  return selectCounter;
}
uint8_t MenuSystem::getMenuQuantity   (void) {
  return menuQuantity;
}


