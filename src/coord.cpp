#include "coord.h"
using namespace std;
///////////////////////coord
coord::coord(){				//Constructeur à 0
	x=y=0;
}
coord::coord(int newx, int newy){	//Constructeur avec arguments
	x = newx;
	y = newy;
}
coord::~coord(){		//Destructeur
}
bool coord::operator < (const coord& c) const{ //Definition de l'opérateur <
	if(x < c.x)	// Priorité donnée aux x
	{ return true; }
	if(x == c.x && y<c.y)
	{return true;}
	else
	{return false;}	//Retourne vrai si <, false sinon
}
bool coord::operator == (const coord& c) const
{
    if(x == c.x && y == c.y)
        return true;
    else return false;
}
