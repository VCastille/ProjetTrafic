#include "CrapEngine.h"
#include "Engine.h"

CrapEngine::CrapEngine()
{
    //ctor
    speed = 1;
}

CrapEngine::~CrapEngine()
{
    //dtor
}

int CrapEngine::getSpeed()
{
    return speed;
}
