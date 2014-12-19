#ifndef HARBOR_H
#define HARBOR_H
#include "coord.h"
class Ship;

class Harbor	// Singleton
{
	public:
		static Harbor* getInstance();
		static void destroyInstance();
		//Fonction qui donne les positions d'entrées possibles sur la matrice
		coord* getInitialPosition();
		// Fonction alloue ship a coord
		void addShip(Ship* Boat);
		//Fonction trouve les coordonnées d'un bateau
		coord* findShip(Ship* Boat);
		bool isThereAShip(coord* coord);
		//Fonction déplace bateau
		void moveBoat(Ship* Boat, int x, int y);
		void moveBoatsToQuais();
		//Enleve un bateau
		void deleteShip(Ship* Boat);
		void deleteShipByCoord(coord coordBoat);
		//Complete les quais
		void addQuais();
		//retourner les coordonnées d'un quais en fct de son id
		coord findQuais(int id);
		//Affichage des quais de la carte
		void afficheQuais();
		//Créé une reservation
		void addReservation(int id, Ship* Boat);
		int findFreeReservation();
		// Retourne l'id de la reservation d'un bateau
		int findReservation(Ship* Boat);
		//Affiche les bateaux et leur coordonnées ainsi que les quais
		void afficheMatrix();
		void dessineMatrix();
		//Methode de collision
		void collision(Ship* Boat1,Ship* Boat2);

	protected:
	private:
		//Constructeur
		Harbor();
		//Destructeur
		~Harbor();
		//Variable statique singleton
		static Harbor* uniqueHarbor;
		//Dimensions de la map
		int _N;
		int _M;
		//Map qui a en clé un objet coordonnées
		std::map<coord, Ship*> _matrix;
		//Iterateur pour parcourir la map
		std::map<coord, Ship*>::iterator _it;
		// map des quais
		std::map<coord, int> _quais;
		std::map<coord, int>::iterator _it_quais;
		// map des reservation de quais
		std::map<int, Ship*> _reservation;
		std::map<int, Ship*>::iterator _it_reservation;
};

#endif // HARBOR_H
