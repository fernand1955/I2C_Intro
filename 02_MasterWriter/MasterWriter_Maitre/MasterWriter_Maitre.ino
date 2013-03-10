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
  Wire.begin(); // joindre le bus i2c (adresse est optionnelle pour un maître)
}

byte x = 0;

void loop()
{
  Wire.beginTransmission(4); // Commencer transmission vers l'esclave  #4
  Wire.write("x is ");       // Envoi de 5 octets (5 bytes)
  Wire.write(x);             // envoi d'un byte/octet (valeur numérique)  
  Wire.endTransmission();    // fin transmission

  x++;
  delay(500); // delay de 500 ms
}
