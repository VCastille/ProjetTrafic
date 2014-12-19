#ifndef MILITARYSHIP_H
#define MILITARYSHIP_H
#include "Ship.h"

class MilitaryShip: public Ship
{
    public:
        MilitaryShip();
        float failureProbability(); //Donne la proba de s'arreter durant un deplacement
        bool accept(int dockId); //Renvoie true si le dock auxquel est affecté le bateau est accpete
        int getPriority();//Donne la priorité selon le type du bateau
    protected:
    private:
};

#endif // MILITARYSHIP_H
