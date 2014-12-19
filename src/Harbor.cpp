#include <iostream>
#include <map>
#include <ctime>
#include <cstdlib>
#include "Ship.h"
#include "Harbor.h"
using namespace std;
Harbor* Harbor::uniqueHarbor=NULL; // Obligatoire de le placer pour l'objet Harbor Singleton
///////////////////////Harbor
Harbor::Harbor(){		//constructeur
	_N=20;
	_M=20;
}
Harbor::~Harbor(){		//Destructeur
	_matrix.clear();
	_quais.clear();
}
Harbor* Harbor::getInstance(){
	if (uniqueHarbor==NULL)
	{uniqueHarbor = new Harbor();}
	return uniqueHarbor;
}

void Harbor::destroyInstance()
{
	delete uniqueHarbor;
}
coord* Harbor::getInitialPosition()
{
	int x,y;
	x=0;
	y=_M/2;
	coord* initialPosition = new coord(x,y);
	return initialPosition;
}
void Harbor::addShip(Ship* Boat){	//Ajoute un bateau a la map
	coord* coordBoat = getInitialPosition(); // On recupere les points d'entrée de la map
	if(_matrix[*coordBoat]==NULL)
	{_matrix[*coordBoat]=Boat;}
	else{cout<<"place init deja prise"<<endl;}
	delete coordBoat;
}
coord* Harbor::findShip(Ship * Boat){	//Trouve un bateau et retourne ses coordonnées
	coord* memoryCoord= new coord();
	_it = _matrix.begin();
	while (_it != _matrix.end())
	{
		if(Boat == _it->second) //est-ce que mon bateau est deja dans ma map
		{
			*memoryCoord=_it->first;	// Si oui, je mémorise ses coordonnées
		}
		_it++;
	}
	return memoryCoord;
}
bool Harbor::isThereAShip(coord* coord)	// Renvoie true si il y a un bateau sur les coord
{
	bool presence = false;
	_it = _matrix.begin();
	while (_it != _matrix.end())
	{
		if(coord->x == _it->first.x && coord->y == _it->first.y) //est-ce que mon bateau est deja dans ma map
		{
			presence=true;
		}
		_it++;
	}
	return presence;
}
void Harbor::moveBoat(Ship* Boat,int x, int y){//Deplace un bateau
	coord* Arrivee= new coord(x,y);
	_it = _matrix.begin();
	bool placePrise=false;
	placePrise = isThereAShip(Arrivee);
	if(x>_N && y>_M)// On regarde qu'on soit dans les dimensions
	{cout<<"Impossible de bouger le bateau "<<Boat->getName()<<" vers "<< Arrivee->x <<","<< Arrivee->y<<": hors dimensions" <<endl;}
	if(placePrise==true)// Si la place est prise, message d'erreur
		{collision(Boat,_matrix[*Arrivee]);}
	else	// Sinon on le bouge
	{
		deleteShip(Boat);
		_matrix[*Arrivee]=Boat;
		//cout<<Boat->getName()<<" deplace vers "<< Arrivee->x <<","<< Arrivee->y <<endl;
	}
}
void Harbor::moveBoatsToQuais()
{
	coord* BoatPosition;
	coord QuaiPosition;
	_it_reservation = _reservation.begin();
	while(_it_reservation != _reservation.end())
	{
		BoatPosition=findShip(_it_reservation->second);
		QuaiPosition=findQuais(_it_reservation->first);
        if(BoatPosition->x > QuaiPosition.x )// Si le bateau est au dessus du quai
			{moveBoat(_it_reservation->second,BoatPosition->x-1,BoatPosition->y);}//Je le fais avancer d'une case vers le bas
        else if(BoatPosition->x < QuaiPosition.x )// Si le bateau est en dessous du quai
			{moveBoat(_it_reservation->second,BoatPosition->x+1,BoatPosition->y);}//Je le fais avancer d'une case vers le haut
		else if(BoatPosition->y > QuaiPosition.y )//si le bateau est à droite du quai
			{moveBoat(_it_reservation->second,BoatPosition->x,BoatPosition->y-1);}//Je le deplace d'une case vers la gauche
		else if(BoatPosition->y < QuaiPosition.y )//si le bateau est à gauche du quai
			{moveBoat(_it_reservation->second,BoatPosition->x,BoatPosition->y+1);}//Je le deplace d'une case vers la droite
		else if(BoatPosition->x == QuaiPosition.x && BoatPosition->y == QuaiPosition.y)
			{cout<<"Bateau arrive"<<endl;}
		_it_reservation++;
	}
}
void Harbor::deleteShip(Ship* Boat){ //Enleve un bateau via l'adresse du bateau
	coord* coordBoat=findShip(Boat); // on recupere les coordonnées du bateau
	deleteShipByCoord(*coordBoat);	// on l'enleve
}
void Harbor::deleteShipByCoord(coord coordBoat){	//Enleve un bateau par ses coordonnées
	_matrix.erase(coordBoat);
}
void Harbor::addQuais()	// Ajoute les quais a la carte
{
	int i=0;
	int j=0;
	//Generation aleatoire des id des quais
	int listeRandom[2*_N];	// On créé un tableau qui stockera les random des id des quais
	int nombreRandom;
	bool test=false;
	for(i=0;i<2*_N;i++)//Pour chaque case du tableau
	{
		while(test==false)	// Tant que le test est faux
		{
			test=true;
			nombreRandom=rand()%(2*_N);//Je lance le rand
			for(j=0;j<i;j++)// Je compare le rand à ce qui est dans mon tableau
			{
				if(nombreRandom==listeRandom[j])	// Si la valeur a déjà été tirée
				{
					test=false;	// Je remet ma valeur a faux, pour relancer un rand
				}
			}
		}
		test=false;// Sinon je repasse la valeur a faux apres coup, pour la prochaine case
		listeRandom[i]=nombreRandom;//Je stocke le random dans mon tableau
	}
	j=0;
	//Placement des id des quais
	for (i=0;i<_N;i++)	// Pour la colonne de gauche (j=0)
	{
			coord coordQuai(i,j);
			_quais[coordQuai]=listeRandom[i];	// Je place mes id en reprenant l'ordre du tableau

	}
	j=_N-1;
	for (i=0;i<_N;i++)	// Pour la colonne de droite (j=_M-1)
	{
		coord coordQuai(i,j);
		_quais[coordQuai]=listeRandom[i+j];	// Je place mes id en continuant les valeurs du tableau
	}
}
coord Harbor::findQuais(int id)
{
	coord* memoryCoord= new coord();
	_it_quais = _quais.begin();
	while (_it_quais != _quais.end())
	{
		if(id == _it_quais->second) //est-ce que mon bateau est deja dans ma map
		{
			*memoryCoord=_it_quais->first;	// Si oui, je mémorise ses coordonnées
		}
		_it_quais++;
	}
	return *memoryCoord;
}
void Harbor::afficheQuais()
{
	_it_quais = _quais.begin();
	cout<<"Affichage des quais "<<_N<<","<<_M<<endl;
	while (_it_quais != _quais.end())
	{
		cout<<"("<<_it_quais->first.x<<","<<_it_quais->first.y<<") name:"<<_it_quais->second<<endl;
		_it_quais++;
	}
}
void Harbor::addReservation(int id, Ship* Boat)
{
	if(_reservation[id]!=NULL)
	{cout<<"Quai deja reservé"<<endl;}
	else
	{_reservation[id]=Boat;}
}
int Harbor::findFreeReservation()
{
	int i=0;
	_it_quais = _quais.begin();
	if(_reservation.find(0) == _reservation.end()){ return 0;} // Si la premiere clef est aussi la derniere (ie pas de reservation)
	else
    {
        while(_it_quais != _quais.end()) // Tant que je n'ai pas tout testé
        {
            if (_reservation.find(i) != _reservation.end()) // Si la place n'est pas prise
            {
            	i++;
                _it_quais++;
            } //retourne valeur.
            else// Sinon je passe à l'id suivant
            { return i;}
        }
        return -1; //Il n'y a plus de reservation libres
    }
}
int Harbor::findReservation(Ship* Boat)
{
	int idReserve=-1;
	_it_reservation = _reservation.begin();
	while (_it_reservation != _reservation.end())
	{
		if(Boat == _it_reservation->second) //est-ce que mon bateau est deja dans les reservations
		{
			idReserve=_it_reservation->first;	// Si oui, je mémorise l'id de la reservation
		}
		_it_reservation++;
	}
	return idReserve;
}
void Harbor::afficheMatrix(){
	_it = _matrix.begin();

	cout<<"Affichage des bateaux "<<_N<<","<<_M<<endl;
	while (_it != _matrix.end())
	{
		cout<<"("<<_it->first.x<<","<<_it->first.y<<") name:"<<_it->second->getName()<<endl;
		_it++;
	}
}

void Harbor::dessineMatrix()
{
     //Affichage graphique du port
    int i,j;
    for(i=0; i<_M; i++)
    {
        for(j=0; j<_N; j++)
        {
            coord c (i,j); //coordonnees courantes

            if(isThereAShip(&c) == true && (j==0 || j==19)) //si bateau sur quais
            {
                if(j == 19)
                    std::cout << "B";
                if(_quais[c] < 10)
                    std::cout << " " << _quais[c] << "  " ;
                else
                    std::cout << " " <<  _quais[c] << " ";
                if(j == 0)
                    std::cout << "B";
            }
            else if (isThereAShip(&c) == true) // si il y a un bateau
                std::cout << "B";
            else if(j==0 || j==19) // si on est sur un quais libre
            {
                if(j == 19)
                    std::cout << "Q";
                if(_quais[c] < 10)
                    std::cout << " " << _quais[c] << "  " ;
                else
                    std::cout << " " <<  _quais[c] << " ";
                if(j == 0)
                    std::cout << "Q";
            }
            else //sinon remplissage
                std::cout << "-";
        }
        std::cout << std::endl;
    }
}

void Harbor::collision(Ship* Boat1,Ship* Boat2){
	coord* coordBoat1=findShip(Boat1);
	coord* coordBoat2=findShip(Boat2);
	//On verifie que les 2 bateaux soient sur la meme case
	cout<<"Collision"<<endl;
	if(Boat1->getSolidity() > Boat2->getSolidity())
	{
		deleteShip(Boat2);
	}
	else
	{
		coordBoat1->x++;
		if(isThereAShip(coordBoat1)==true)
			{moveBoat(Boat1,coordBoat1->x,coordBoat1->y);}
		else{
			coordBoat1->x--;
			coordBoat1->y++;
			if(isThereAShip(coordBoat1)==true)
				{moveBoat(Boat1,coordBoat1->x,coordBoat1->y);}
			else{
			coordBoat1->y--;
			coordBoat1->x--;
			if(isThereAShip(coordBoat1)==true)
				{moveBoat(Boat1,coordBoat1->x,coordBoat1->y);}
			}
		}
	}
}
