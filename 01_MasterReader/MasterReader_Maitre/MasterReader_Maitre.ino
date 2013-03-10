// Librairie Wire - Master Reader (Maitre Lit)
// *** Programme pour le Maître - Le maître Lit ***
//
// par Nicholas Zambetti <http://www.zambetti.com>
// Traduction par MCHobby.be <http://www.mchobby.be>
// Montage & tutoriel détaillé disponibles sur 
//    http://mchobby.be/wiki/index.php?title=Arduino_I2C_Intro-Montage
// 
// Démontre l'usage de la librairie Wire.
// Lectures de données depuis un périphérique I2C/TWI esclave.
//
// A utiliser avec le programme esclave de cet exemple.
//
// Crée le 29 mars 2006
// Traduit le 9 mars 2013 (MCHobby)
//
// This example code is in the public domain.
// Ce code d'exemple fait partie du domaine public.

#include <Wire.h>

void setup()
{
  Wire.begin();        // joindre le bus i2c (adresse est optionnelle pour un maître)
  Serial.begin(9600);  // démarré une communication série
}

void loop()
{
  Wire.requestFrom(2, 6);    // lecture de 6 octets (bytes) depuis l'esclave #2

  while(Wire.available())    // l'esclave pourrait envoyer moins de données qu'attendu
  {
    char c = Wire.read();    // Reception de l'octet (byte) comme caractère
    Serial.print(c);         // Affichage du caractère.
  }

  delay(500); // Attendre une demi seconde.
}
