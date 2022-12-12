/***************Copy*****************/
/*
GND : GND 
VCC : 2
*/
/************************************/

/***************Coller*****************/
/*
GND : GND 
VCC : 3
*/
/************************************/

/***************Save*****************/
/*
GND : GND 
VCC : 4
*/
/************************************/

/***************Cut*****************/
/*
GND : GND 
VCC : 5
*/
/************************************/

/***************Volume potentiometre*****************/
/*
GND : GND 
VCC : VCC
DATA : A0
*/
/****************************************************/




#include "Keyboard.h"

const int copyPin = 3;   
int previousCopyState = HIGH;   

const int collerPin = 4;         
int previousCollerState = HIGH;

const int savePin = 5;         
int previousSaveState = HIGH;

const int cutPin = 2;         
int previousCutState = HIGH;

/*
#include <HID-Project.h>                    
#include <HID-Settings.h>

#define pinPot A0
int valPot = 0;
int previousval = 0;
int valPot2 = 0;*/

void setup() 
{

  pinMode(copyPin, INPUT_PULLUP);
  pinMode(collerPin, INPUT_PULLUP);
  pinMode(savePin, INPUT_PULLUP);
  pinMode(cutPin, INPUT_PULLUP);


  Keyboard.begin();
  //Consumer.begin();  
  delay(1000);  
         /*                     
  for(int a = 0; a < 22; a++) 
  {
    Consumer.write(MEDIA_VOLUME_DOWN);      //set the volume to 0
    delay(2);
  } */
}

void loop() 
{

  int copyState = digitalRead(copyPin);
  int collerState = digitalRead(collerPin);
  int saveState = digitalRead(savePin);
  int cutState = digitalRead(cutPin);



 
  if ((copyState != previousCopyState) && (copyState == HIGH)) 
  {
    TXLED0;
    Keyboard.press(KEY_LEFT_GUI); // apuyer sur cmd
    TXLED0;
    Keyboard.press('c'); // apuyer sur c
    TXLED0;
    delay(100);
    TXLED0;
    Keyboard.releaseAll(); // relacher toute les touches
    TXLED0;
  }
  previousCopyState = copyState; 
  
  
  if ((collerState != previousCollerState) && (collerState == HIGH)) 
  {
    TXLED0;
    Keyboard.press(KEY_LEFT_GUI); // apuyer sur cmd
    TXLED0;
    Keyboard.press('v'); // apuyer sur v
    TXLED0;
    delay(100);
    TXLED0;
    Keyboard.releaseAll(); // relacher toute les touches
    TXLED0;
  }
  previousCollerState = collerState;
  


  if ((saveState != previousSaveState) && (saveState == HIGH)) 
  {
    TXLED0;
    Keyboard.press(KEY_LEFT_GUI); // apuyer sur cmd
    TXLED0;
    Keyboard.press('s'); // apuyer sur s
    TXLED0;
    delay(100);
    TXLED0;
    Keyboard.releaseAll(); // relacher toute les touches
    TXLED0;
  }
  previousSaveState = saveState;
  
  if ((cutState != previousCutState) && (cutState == HIGH)) 
  {
    TXLED0;
    Keyboard.press(KEY_LEFT_GUI); // apuyer sur cmd
    TXLED0;
    Keyboard.press('x'); // apuyer sur x
    TXLED0;
    delay(100);
    TXLED0;
    Keyboard.releaseAll(); // relacher toute les touches
    TXLED0;
  }
  previousCutState = cutState;



 
  
  
  


/*

  valPot = analogRead(pinPot);                      //read potentiometer value
  valPot = map(valPot, 0, 1023, 0, 101);          //map it to 102 steps

  if(abs(valPot - previousval) > 1) 
  {          //check if potentiometer value has changed
    previousval = valPot;
    valPot /= 5,95;                               //divide it by 5,95 to get 16 steps
    while(valPot2 < valPot) 
    {
      Consumer.write(MEDIA_VOLUME_UP);      //turn volume up to appropiate level
      valPot2++;
      delay(2);
    }
    while(valPot2 > valPot) 
    {
      Consumer.write(MEDIA_VOLUME_DOWN);    //turn volume down to appropiate level
      valPot2--;
      delay(2);
    }
    delay(301);
  }*/
}
