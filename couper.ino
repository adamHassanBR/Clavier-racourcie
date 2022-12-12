
#include "Keyboard.h"

const int copyPin = 5;          
int previousButtonState = HIGH;   
              

void setup() 
{

  pinMode(copyPin, INPUT_PULLUP);

  Keyboard.begin();
}

void loop() 
{

  int copyState = digitalRead(copyPin);
 
  if ((copyState != previousButtonState) && (copyState == HIGH)) 
  {
    Keyboard.press(KEY_LEFT_GUI); // apuyer sur cmd
    Keyboard.press('x'); // apuyer sur c
    delay(100);
    Keyboard.releaseAll(); // relacher toute les touches

    
  }

  previousButtonState = copyState;
}
