#ifndef INSTANCE_H
#define INSTANCE_H
#include <queue>
class Ship;


class instance
{
    public:
        instance();
        virtual ~instance();
        Ship* createShip();         //Créé une instance de Ship sans nom
        void addToWaitList(Ship* Boat);
        void cycle();				//Gere le cycle d'ajout de bateaux
    protected:
    private:
    	std::queue <Ship*>_waitList; // File de bateaux
};

#endif // INSTANCE_H
