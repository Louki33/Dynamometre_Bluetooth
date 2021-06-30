# Protocole du Dynamomètre

## **Bibliothèque utilisées**

**Standard Libraries :**
```c++
#include <Wire.h>
```

**ESP32 Libraries :**

```c++
#include "BluetoothSerial.h"
```


## Transmission de donnée requête/réponse en bluetooth

### Fonctions 

**AVAILABLE: Obtenez le nombre d'octets disponibles pour la lecture à partir du port série.** 

```c++
Serial.available();
```
**READ: Lit les données série entrantes.** 

```c++
Serial.read();
```
**WRITE: Écrit des données binaires sur le port série.** 

```c++
Serial.write();
```
### Fonctionnement du système client/serveur

Le serveur attend une demande d'envoi du caractère *"F"* et si le client lui envoie il reçoit les données attendues.  
De plus tant que le serveur ne reçoit pas le bon caractère il envoie aucunne donnée.

### Description détaillée

 Exemple d'utilisation pour une donnée aléatoire

```c++
  #include "BluetoothSerial.h"

  #if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
  #error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
  #endif

  BluetoothSerial SerialBT;

  // Gérer les messages reçus et envoyés
  String message = "";
  char c;
  float Value = random(10000000) / 10000.0; 
  //nombre aléatoire entre 0.00 et 1000.00

  void setup()
{
  SerialBT.begin("Dynamometre");
  // initialisation de la liaison bluetooth
  Serial.begin(115200);
  // initialisation de la liaison série vers la console
}

void loop()
{
if (SerialBT.available()) {
    char c = SerialBT.read();
    if (c != '\n') {
      message += String(c);
    }
    else {
      message = "";
    }
    Serial.write(c);
  }
  if (message == "F") {
    SerialBT.println(Value);
  }
  delay(20);
}
```
