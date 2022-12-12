#include <HID-Project.h>                    
#include <HID-Settings.h>

                    

#define pinPot A0
int valPot = 0;
int previousval = 0;
int valPot2 = 0;

void setup() 
{
  Consumer.begin();                         
  delay(1000);                              
  for(int a = 0; a < 22; a++) 
  {
    Consumer.write(MEDIA_VOLUME_DOWN);      //set the volume to 0
    delay(2);
  } 

  
}

void loop() 
{
  valPot = analogRead(pinPot);                      //read potentiometer value
  valPot = map(valPot, 0, 1023, 0, 101);          //map it to 102 steps

  if(abs(valPot - previousval) > 1) 
  {          //check if potentiometer value has changed
    previousval = valPot;
    valPot /= 5,95;                               //divide it by 2 to get 51 steps
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
  }
  delay(301);                               //wait at least 300ms between changing volume levels
}                                           //if it will change faster Windows can sometimes 
                                            //increase or decrease volume by 10 steps at once
