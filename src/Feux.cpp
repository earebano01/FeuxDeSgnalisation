#include "Feux.h"
#include <Arduino.h>

#define TEMP_CLIGNOTE_VERT 3000
#define TEMP_VERT  3000
#define TEMP_JAUNE 2000
#define TEMP_ROUGE 8000

Feux::Feux(){};

Feux::Feux(int LED_vert, int LED_jaune, int LED_rouge) {
    // TODO Hardcoded pour le moment
    this->temp_clignote_vert = TEMP_CLIGNOTE_VERT;
    this->temp_jaune         = TEMP_JAUNE;
    this->temp_vert          = TEMP_VERT;
    this->temp_rouge         = TEMP_ROUGE;

    this->LED_vert  = LED_vert;
    this->LED_jaune = LED_jaune;
    this->LED_rouge = LED_rouge;

    pinMode(this->LED_vert, OUTPUT);
    pinMode(this->LED_jaune, OUTPUT);
    pinMode(this->LED_rouge, OUTPUT);

    this->etat_actuel    = VERT;
    this->etat_souhaiter = ROUGE;
    this->tm.startTimer(temp_rouge);
    vert();
}

void Feux::go() {
    this->etat_souhaiter = VERT;
}

void Feux::stop() {
    this->etat_souhaiter = ROUGE;
}

void Feux::loopLights() {
    if (etat_souhaiter == VERT) {
        goToVert();
    } else {
        goToRouge();
    }
}

void Feux::BoucleUnFeux(){
    switch (etat_actuel) {
        case ROUGE:
            rouge();
            if (this->tm.isTimerReady()) {
                etat_actuel = CLIGNOTE_VERT;
                this->tm.startTimer(temp_clignote_vert);
            }
        break;

        case CLIGNOTE_VERT:
            clignoteVert();
            if (this->tm.isTimerReady()) {
                etat_actuel = VERT;
                this->tm.startTimer(temp_vert);
            }
            
        break;

        case VERT:
            vert();
            if (this->tm.isTimerReady()) {
                etat_actuel = JAUNE;
                this->tm.startTimer(temp_jaune);
            }
        break;

        case JAUNE:
            jaune();
            if (this->tm.isTimerReady()) {
                etat_actuel = ROUGE;
                this->tm.startTimer(temp_rouge);
            }
        break;
    }
}

void Feux::goToVert() {
    switch (etat_actuel) {
        case ROUGE:
          etat_actuel = JAUNE;
          tm.startTimer(temp_jaune);
          break;
        case JAUNE:
          jaune();
          if (tm.isTimerReady()) {
            etat_actuel = VERT;
          }
          break;
        case CLIGNOTE_VERT:
          etat_actuel = VERT;
          break;
        case VERT:
          vert();
          break;
      }
}

void Feux::goToRouge() {
    switch (etat_actuel) {
        case VERT:
          etat_actuel = CLIGNOTE_VERT;
          tm.startTimer(temp_clignote_vert);
          break;
        case CLIGNOTE_VERT:
          clignoteVert();
          if (tm.isTimerReady()) {
            etat_actuel = JAUNE;
            tm.startTimer(temp_jaune);
          }
          break;
        case JAUNE:
          jaune();
          if (tm.isTimerReady()) {
            etat_actuel = ROUGE;
          }
          break;
        case ROUGE:
          rouge();
          break;
      }
}

void Feux::clignoteVert() {
    // TODO hardcoded
    if (millis() % 1000 > 500) {
        vert();
    } else {
        off();
    }
}

void Feux::vert() {
    digitalWrite(LED_vert, HIGH);
    digitalWrite(LED_jaune, LOW);
    digitalWrite(LED_rouge, LOW);
}

void Feux::jaune() {
    digitalWrite(LED_vert, LOW);
    digitalWrite(LED_jaune, HIGH);
    digitalWrite(LED_rouge, LOW);
}

void Feux::rouge() {
    digitalWrite(LED_vert, LOW);
    digitalWrite(LED_jaune, LOW);
    digitalWrite(LED_rouge, HIGH);
}

void Feux::off() {
    digitalWrite(LED_vert, LOW);
    digitalWrite(LED_jaune, LOW);
    digitalWrite(LED_rouge, LOW);
}