#ifndef FACTORY_H
#define FACTORY_H
#include "Engine.h"
#include "Hull.h"

class Factory
{
    public:
        Factory();
        ~Factory();
        virtual Engine* createEngine() = 0;
        virtual Hull* createHull() = 0;
    protected:
    private:
};

#endif // FACTORY_H
