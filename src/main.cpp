/*
  Titre      : TP Feux rouge
  Auteur     : Yahya Madrani
  Date       : 02/12/2021
  Description: Proposition de solution en Classe
  Version    : 0.0.1
*/

#include <Arduino.h>
#include "Timer.h"
#include "Feux.h"

int PIN_VERT  = 7;
int PIN_JAUNE = 8;
int PIN_ROUGE = 9;

Feux feux(PIN_VERT, PIN_JAUNE, PIN_ROUGE);

void setup() {
	
}

void loop() {
  feux.BoucleUnFeux();
}