#include "BigShipFactory.h"
#include "JetEngine.h"
#include "StrongHull.h"

BigShipFactory::BigShipFactory()
{
    //ctor
}

BigShipFactory::~BigShipFactory()
{
    //dtor
}

Engine* BigShipFactory::createEngine()
{
    return new JetEngine();
}

Hull* BigShipFactory::createHull()
{
    return new StrongHull();
}
