#include "MilitaryShip.h"

MilitaryShip::MilitaryShip()
{
    //ctor
}
float MilitaryShip::failureProbability(){
	return 50;
}
bool MilitaryShip::accept(int dockId){
	if(dockId >= 20)
		{return true;}
	else 
	{return false;}
}
int MilitaryShip::getPriority(){
	return 10;
}