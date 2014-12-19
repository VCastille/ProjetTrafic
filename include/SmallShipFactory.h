#ifndef SMALLSHIPFACTORY_H
#define SMALLSHIPFACTORY_H
#include "Factory.h"


class SmallShipFactory : public Factory
{
    public:
        SmallShipFactory();
        ~SmallShipFactory();
        Engine* createEngine();
        Hull* createHull();
    protected:
    private:
};

#endif // SMALLSHIPFACTORY_H
