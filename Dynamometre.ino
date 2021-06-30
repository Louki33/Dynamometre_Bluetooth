/**
 * @file Dynamometre.ino
 * @brief 
 * @author Durin
 * @version 1.0
 * @date 04/06/2021
 */
#include "capteur.h"
#include "communication.h"

Capteur CapteurFX;
Communication BT;

void setup()
{
  //Initialisation des objets BT et CapteurFX
  CapteurFX.init();
  BT.init();
  Serial.begin(115200);
}
/**
 * @fn loop()
 * @brief si l'instruction demander est égal à "Force"
 * @brief alors ce dispositif transmet la force en decanewton
 * @return void
 */
void loop()
{
  if (BT.attendreInstruction() == "Force"){
    BT.envoyerforce(CapteurFX.readcapteur());
  }
}
