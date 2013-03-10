// Librairie Wire - Master Writer (Maitre ecrit)
// par Nicholas Zambetti <http://www.zambetti.com>
// Traduction par MCHobby.be <http://www.mchobby.be>
// Montage & tutoriel détaillé disponibles sur 
//    http://mchobby.be/wiki/index.php?title=Arduino_I2C_Intro-Montage
// 
// Démontre l'usage de la librairie Wire.
// Ecrit des données vers un périphérique esclave I2C/TWI
//
// A utiliser avec le programme esclave de cet exemple.
//
// Crée le 29 mars 2006
// Traduit le 9 mars 2013 (MCHobby)
//
// This example code is in the public domain.
// Ce code d'exemple fait partie du domaine public.
//
#include <Wire.h>

void setup()
{
  Wire.begin(4);                // Joindre le Bus I2C avec adresse #4
  Wire.onReceive(receiveEvent); // enregistrer l'événement (lorsqu'une demande arrive)
  Serial.begin(9600);           // Démarrer une communication série
}

void loop()
{
  delay(100);
}

// Fonction qui est exécutée lorsque des données sont envoyées par le Maître.
// Cette fonction est enregistrée comme une événement ("event" en anglais), voir la fonction setup()
void receiveEvent(int howMany)
{
  while(1 < Wire.available()) // Lire tous les octets sauf le dernier
  {
    char c = Wire.read();     // lecture de l'octet/byte comme caractère
    Serial.print(c);          // afficher le caractère
  }
  int x = Wire.read();        // lecture de l'octet/byte ignoré comme un entier
  Serial.println(x);          // Afficher la valeur numérique 
}

