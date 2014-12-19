#ifndef SHIP_H
#define SHIP_H
#include <string>
class Factory;
class Engine;
class Hull;

class Ship
{
    public:
    	//Constructeur
        Ship();
        Ship(std::string Name, Factory* f);
        Ship(std::string Name);
        Ship(const Ship& other);
        //Destructeur
        virtual ~Ship();
        //Accesseurs
        std::string getName() const;
        void setName(std::string newName);
        int getSpeed();
        int getSolidity();
        virtual float failureProbability() = 0; //Donne la proba de s'arreter durant un deplacement
        virtual bool accept(int dockId) = 0; //Renvoie true si le dock auxquel est affecté le bateau est accpete
        virtual int getPriority() = 0;//Donne la priorité selon le type du bateau

    protected:
        std::string _name;
        Engine* _ShipEngine;
        Hull* _ShipHull;
    private:

};

#endif // SHIP_H
