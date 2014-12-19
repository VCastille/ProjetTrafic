#include "PleasureCraft.h"

PleasureCraft::PleasureCraft()
{
    //ctor
}
float PleasureCraft::failureProbability(){
	return 5;
}
bool PleasureCraft::accept(int dockId){
	return true;
}
int PleasureCraft::getPriority(){
	return 2;
}