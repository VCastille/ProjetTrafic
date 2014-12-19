#include <iostream>
#include <map>
#include <ctime>
#include <cstdlib>
#include "Ship.h"
#include "coord.h"
#include "Harbor.h"
#include "instance.h"

using namespace std;




///////////////////////Main
/*void TestShipHarbor()
{
	Harbor* Pearl = Harbor::getInstance();
	Pearl->addQuais();

	//Tests des quais

	//test fonction findQuais
	//coord c = Pearl->findQuais(2);
	//cout<<"Quai numero 2 : "<<c.x<<","<<c.y<<endl;
	//Test de l'affichage de tous les quais
	//Pearl->afficheQuais();

	//Test des bateaux
	Ship* Bateau1 = new Ship("Bateau1");
	Ship* Bateau2 = new Ship("Bateau2");
	Ship* Bateau3 = new Ship("Bateau3");
	//Test de l'ajout de bateaux
	Pearl->addShip(Bateau1);
	Pearl->addShip(Bateau2);
	Pearl->moveBoat(Bateau1,5, 5);
	Pearl->addShip(Bateau3);
	//Affichage de la map des ship
	Pearl->afficheMatrix();
	//Test des affectations de quais
	Pearl->addReservation(1,Bateau1);
	cout<<"Le bateau"<<Bateau1->getName()<<" a reserve le quai" << Pearl->findReservation(Bateau1)<<endl;
}*/
void testCycle()
{
	instance* cycleTest = new instance();
	cycleTest->cycle();
}
int main()
{
   // TestShipHarbor();
    testCycle();
    return 0;
}
