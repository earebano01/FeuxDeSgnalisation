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

// L'autre route principal
int PrincipalVert2  = 0;
int PincipalJaune2  = 1;
int PrincipalRouge2 = 2;

// L'autre Route secondaire
int SecondaireVert2  = 11;
int SecondaireJaune2 = 10;
int SecondaireRouge2 = 9;

// Creation des objets
Feux feuxPrincipal(PrincipalVert, PincipalJaune, PrincipalRouge);
Feux feuxSecondaire(SecondaireVert, SecondaireJaune, SecondaireRouge);
Intersection intersection(feuxPrincipal, feuxSecondaire);

Feux feuxPrincipalDeux(PrincipalVert2, PincipalJaune2, PrincipalRouge2);
Feux feuxSecondaireDeux(SecondaireVert2, SecondaireJaune2, SecondaireRouge2);
Intersection intersectionDeux(feuxPrincipalDeux, feuxSecondaireDeux);


void sideRoadTL();
void mainRoadTL();

void setup() {  
  feuxPrincipal.off();
  feuxSecondaire.off();
  feuxPrincipal.vert();
  feuxSecondaire.rouge();

  feuxPrincipalDeux.off();
  feuxSecondaireDeux.off();
  feuxPrincipalDeux.vert();
  feuxSecondaireDeux.rouge();
}

void loop() {
  intersection.toggleLights();
  intersectionDeux.toggleLights();
  // feuxPrincipal.BoucleUnFeux();
}

