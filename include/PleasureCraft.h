#ifndef PLEASURECRAFT_H
#define PLEASURECRAFT_H
#include "Ship.h"

class PleasureCraft: public Ship
{
    public:
        PleasureCraft();
        float failureProbability(); //Donne la proba de s'arreter durant un deplacement
        bool accept(int dockId); //Renvoie true si le dock auxquel est affecté le bateau est accpete
        int getPriority();//Donne la priorité selon le type du bateau
    protected:
    private:
};

#endif // PLEASURECRAFT_H
