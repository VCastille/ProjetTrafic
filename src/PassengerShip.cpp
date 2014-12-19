#include "PassengerShip.h"

PassengerShip::PassengerShip()
{
    //ctor
}
float PassengerShip::failureProbability(){
	return 20;
}
bool PassengerShip::accept(int dockId){
	if(dockId <= 10)
		{return true;}
	else 
	{return false;}
}
int PassengerShip::getPriority(){
	return 7;
}