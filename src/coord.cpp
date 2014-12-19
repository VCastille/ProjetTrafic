#include "coord.h"
using namespace std;
///////////////////////coord
coord::coord(){				//Constructeur � 0
	x=y=0;
}
coord::coord(int newx, int newy){	//Constructeur avec arguments
	x = newx;
	y = newy;
}
coord::~coord(){		//Destructeur
}
bool coord::operator < (const coord& c) const{ //Definition de l'op�rateur <
	if(x < c.x)	// Priorit� donn�e aux x
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
