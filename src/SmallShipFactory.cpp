#include "SmallShipFactory.h"
#include "CrapEngine.h"
#include "WeakHull.h"

SmallShipFactory::SmallShipFactory()
{
    //ctor
}

SmallShipFactory::~SmallShipFactory()
{
    //dtor
}

Engine* SmallShipFactory::createEngine()
{
    return new CrapEngine();
}

Hull* SmallShipFactory::createHull()
{
    return new WeakHull();
}
