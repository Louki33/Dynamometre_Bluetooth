/**
 * @file communication.h
 * @brief 
 * @author Durin
 * @version 1.0
 * @date 04/06/2021
 */
#ifndef COMMUNICATION_H
#define COMMUNICATION_H
#include "BluetoothSerial.h"

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif


class Communication
{
  public:
    Communication();
    void init();
    String attendreInstruction();
    void envoyerforce(float Force);
    
   private:
   BluetoothSerial SerialBT;
   String message = "";
   char caractere;
   
};
#endif COMMUNICATION_H
