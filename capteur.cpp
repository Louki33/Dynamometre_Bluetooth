/**
 * @file capteur.cpp
 * @brief 
 * @author Durin
 * @version 1.0
 * @date 04/06/2021
 */
#include "capteur.h"
/**
 * @fn Capteur()
 * @brief Constructeur
 * @return void
 */
Capteur::Capteur()
{
  Serial.println("Un nouveau capteur !");
}
/**
 * @fn init()
 * @brief Initialisation bus I2C
 * @return void
 */
void Capteur::init(){
  Wire.begin(115200);
}
/**
 * @fn readcapteur()
 * @brief Lecture données du capteur 
 * @brief Décoder et convertir ces données 
 * @return Force
 */
float Capteur::readcapteur()
{
  Wire.beginTransmission(FX29_ADDRESS);
  Wire.write(FX29_ADDRESS); 
  Wire.endTransmission(false);
  Wire.requestFrom(FX29_ADDRESS, 2); // demande à recevoir 2 octets du périphérique d'adresse 0x28
  forceMSB = Wire.read() & 0x7F;  // Lecture Octet de poids fort
  forceLSB = Wire.read();  // Lecture Octet de poids faible
  Decode = (forceMSB << 8) | forceLSB; // Concaténation MSB LSB
  Force = (Decode - 1000) * (LOAD_RANGE / 14000); //Convertion en Livre-force des 2 octets
  Force = Force*FORCE_DECANEWTON; //Convertion des Livre-force en DecaNewton
  return Force;
}
