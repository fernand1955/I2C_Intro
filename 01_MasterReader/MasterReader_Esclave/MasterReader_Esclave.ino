// Librairie Wire - Master Reader (Maitre Lit)
// *** Programme pour l' Esclave - L'esclave écrit ***
//
// par Nicholas Zambetti <http://www.zambetti.com>
// Traduction par MCHobby.be <http://www.mchobby.be>
// Montage & tutoriel détaillé disponibles sur 
//    http://mchobby.be/wiki/index.php?title=Arduino_I2C_Intro-Montage
// 
// Démontre l'usage de la librairie Wire.
// Envoi des données sur le bus i2c en tant qu'esclave.
//
// A utiliser avec le programme Maître de cet exemple.
//
// Crée le 29 mars 2006
// Traduit le 9 mars 2013 (MCHobby)
//
// This example code is in the public domain.
// Ce code d'exemple fait partie du domaine public.


#include <Wire.h>

void setup()
{
  Wire.begin(2);                // Joindre le bus i2c avec l'adresse #2
  Wire.onRequest(requestEvent); // enregistrer l'événement (lorsqu'une demande arrive)
}

void loop()
{
  delay(100); // Attendre 100ms
}

// Fonction qui est exécutée lorsque des données sont envoyées par le Maître.
// Cette fonction est enregistrée comme une événement ("event" en anglais), voir la fonction setup()
void requestEvent()
{
  Wire.write("hello "); // Répondre avec un message de 6 octets (bytes)
                        // comme attendu par le maître.
}
