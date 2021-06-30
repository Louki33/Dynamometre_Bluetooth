/**
 * @file communication.cpp
 * @brief 
 * @author Durin
 * @version 1.0
 * @date 04/06/2021
 */
#include "capteur.h"
#include "communication.h"
/**
 * @fn Capteur()
 * @brief Constructeur
 * @return void
 */
Communication::Communication()
{
  Serial.println("Une nouvelle communication !");
}
/**
 * @fn init()
 * @brief Initialisation le la liaison bluetooth
 * @return void
 */
void Communication::init()
{
  SerialBT.begin("Dynamometre");
}
/**
 * @fn attendreInstruction()
 * @brief Patiente afin de recevoir la bonne instruction
 * @return message
 */
String Communication::attendreInstruction()
{
  if (SerialBT.available()) {
    caractere = SerialBT.read();
  if (caractere != '\n') {
    message += String(caractere);
    } else {
      message = "";
    }
      Serial.write(caractere);
 }
return message;
}
/**
 * @fn envoyerforce()
 * @brief Permet de transmettre la force via le bluetooth
 * @param float Force
 * @return void
 */
void Communication::envoyerforce(float Force)
{
  SerialBT.println(Force);
}
