/**
 * @file capteur.h
 * @brief 
 * @author Durin
 * @version 1.0
 * @date 04/06/2021
 */
 
#ifndef CAPTEUR_H
#define CAPTEUR_H
#include <Wire.h>
#include "Arduino.h"

#define FX29_ADDRESS    0x28
#define LOAD_RANGE    100.0
#define FORCE_DECANEWTON    0.4448

class Capteur
{
  public:
    Capteur();
    void init(); 
    float readcapteur();
    
  private:
    byte forceMSB;
    byte forceLSB;
    float Decode;
    float Force = 0.00;

};
#endif CAPTEUR_H
