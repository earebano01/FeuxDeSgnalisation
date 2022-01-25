#ifndef FEUX_H
    #define FEUX_H

#include "Timer.h"

class Feux{
    private:
        int LED_vert, LED_jaune, LED_rouge;

        long temp_clignote_vert;
        long temp_jaune;
        long temp_vert;
        long temp_rouge;

        enum Etat {
            VERT,
            CLIGNOTE_VERT,
            JAUNE,
            ROUGE
        }; 

        Etat etat_actuel;
        Etat etat_souhaiter;

        Timer tm;
    
    public:
        Feux();
        Feux(int LED_vert, int LED_jaune, int LED_rouge);
        void go();
        void stop();
        void loopLights();
        void BoucleUnFeux();
        void goToVert();
        void goToRouge();
        void blinkVert();
        void vert();
        void jaune();
        void rouge();
        void off();
};
#endif  // FEUX_H