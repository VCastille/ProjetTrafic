#include "JetEngine.h"
#include "Engine.h"

JetEngine::JetEngine()
{
    //ctor
    speed = 3;
}

JetEngine::~JetEngine()
{
    //dtor
}

int JetEngine::getSpeed()
{
    return speed;
}
