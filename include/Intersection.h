#ifndef INTERSECTION_H
    #define INTERSECTION_H

#include "Feux.h"

class Intersection
{
    private:
        Feux principal, secondaire;
        bool active;
        int tempDeChangement;
        int tempDattente;
        
        void routePrincipal();
        void routeSecondaire();

    public:
        Intersection();
        Intersection(Feux principal, Feux secondaire);
        void toggleLights();
};

#endif // INTERSECTION_H