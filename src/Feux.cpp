#include "Feux.h"
#include <Arduino.h>

#define TEMP_CLIGNOTE_VERT 3000

Feux::Feux(){};

Feux::Feux(int LED_vert, int LED_jaune, int LED_rouge) {
    // TODO Hardcoded pour le moment
    this->temp_clignote_vert = TEMP_CLIGNOTE_VERT;
    this->temp_jaune         = 2000;
    this->temp_vert          = 5000;
    this->temp_rouge         = 5000;

    this->LED_vert  = LED_vert;
    this->LED_jaune = LED_jaune;
    this->LED_rouge = LED_rouge;

    pinMode(LED_vert, OUTPUT);
    pinMode(LED_jaune, OUTPUT);
    pinMode(LED_rouge, OUTPUT);

    etat_actuel          = ROUGE;
    this->etat_souhaiter = VERT;
    this->tm.startTimer(temp_rouge);
    rouge();
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
            blinkVert();
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
            rouge();
            if (this->tm.isTimerReady()) {
                etat_actuel = CLIGNOTE_VERT;
                this->tm.startTimer(temp_clignote_vert);
            }
        break;

        case CLIGNOTE_VERT:
            blinkVert();
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

void Feux::goToRouge() {
    switch (etat_actuel) {
        case VERT:
            etat_actuel = CLIGNOTE_VERT;
            this->tm.startTimer(temp_clignote_vert);
            break;
        case CLIGNOTE_VERT:
            blinkVert();
            if (this->tm.isTimerReady()) {
                etat_souhaiter = VERT;
            }
        break;
        case JAUNE:
            jaune();
            if (this->tm.isTimerReady()) {
                etat_actuel = ROUGE;
                this->tm.startTimer(temp_rouge);
            }
        break;
        case ROUGE:
            rouge();
            if (this->tm.isTimerReady()) {
                etat_actuel = CLIGNOTE_VERT;
                this->tm.startTimer(temp_clignote_vert);
            }
        break;
    }
}

void Feux::blinkVert() {
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