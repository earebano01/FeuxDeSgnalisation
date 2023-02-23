/*
  Titre      : TP Feux rouge
  Auteur     : Yahya Madrani
  Date       : 02/12/2021
  Description: Proposition de solution en Classe
  Version    : 0.0.2
*/

#include <Arduino.h>
#include "Timer.h"
#include "Feux.h"
#include "Intersection.h"

// Configuration des broches
// Route principal
int PrincipalVert  = 3;
int PincipalJaune  = 4;
int PrincipalRouge = 5;

// Route secondaire
int SecondaireVert  = 8;
int SecondaireJaune = 7;
int SecondaireRouge = 6;

// Creation des objets
Feux feuxPrincipal(PrincipalVert, PincipalJaune, PrincipalRouge);
Feux feuxSecondaire(SecondaireVert, SecondaireJaune, SecondaireRouge);
Intersection intersection(feuxPrincipal, feuxSecondaire);


void sideRoadTL();
void mainRoadTL();

void setup() {  
  feuxPrincipal.off();
  feuxSecondaire.off();
  feuxPrincipal.vert();
  feuxSecondaire.rouge();
}

void loop() {
  intersection.toggleLights();
  //feuxPrincipal.BoucleUnFeux();
}

