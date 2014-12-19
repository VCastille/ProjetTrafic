#include <iostream>
#include <map>
#include "Ship.h"
#include "Engine.h"
#include "Hull.h"
#include "Factory.h"
#include "SmallShipFactory.h"
#include "BigShipFactory.h"

using namespace std;

/////////////////////Classe Ship
Ship::Ship(){		//Constructeur
	_name= "No Name";
}

Ship::Ship(string Name, Factory* f) //constructeur avec type de bateau (=> factory)
{
    _name = Name;
    _ShipEngine = f->createEngine();
    _ShipHull = f->createHull();
}

Ship::Ship(string Name){	//Constructeur
	_name= Name;
}
Ship::Ship(const Ship& other){		// Constructeur par copie
	_name = other.getName();
}
Ship::~Ship(){						//Destructeur
}
void Ship::setName(string newName){		//Modifie le nom
	_name = newName;
}
string Ship::getName() const{			// Donne le nom
	return _name;
}
int Ship::getSpeed(){				//Appelle la methode getSpeed du moteur du bateau
	return _ShipEngine->getSpeed();
}
int Ship::getSolidity(){
	return _ShipHull->getSolidity();
}
