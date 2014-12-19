#include "StrongHull.h"

StrongHull::StrongHull()
{
    //ctor
}

StrongHull::~StrongHull()
{
    //dtor
}

bool StrongHull::operator < (const Hull& a) const
{
    if (this->getSolidity() < a.getSolidity())
        return true;
    else
        return false;
}
