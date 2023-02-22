#include "Intersection.h"
#include <Arduino.h>

Intersection::Intersection(){}

Intersection::Intersection(Feux principal, Feux secondaire)
{
    // Variables
    this->active           = true; // Indicates quel feux est actif, true = principal actif false secondaie actif
    this->tempDeChangement = 2500; // Temp d'attente entre les changements d'etat des LED
    this->tempDattente     = 5000; // Le temps d'attente pour que la transition commence 
    
    this->principal = principal;
    this->secondaire = secondaire;

    // Etiendre tout les feux
    this->principal.off();
    this->secondaire.off();

    // Initialisation feux principal alumer, secondaire etient
    this->principal.vert();
    this->secondaire.rouge();
}

void Intersection::toggleLights(){
    // Basculer l'etat des feux
    if(active){
        routeSecondaire();
        active = false;
    }
    else{
        routePrincipal();
        active = true;
    }
}

void Intersection::routePrincipal(){
    delay(tempDattente);
    secondaire.jaune();
    delay(tempDeChangement);
    secondaire.rouge();
    delay(tempDeChangement);
    principal.vert();
    delay(tempDeChangement);
}

void Intersection::routeSecondaire(){
    delay(tempDattente);
    principal.jaune();
    secondaire.rouge();
    delay(tempDeChangement);
    principal.rouge();
    secondaire.vert();
    delay(tempDeChangement);
}