#ifndef CRAPENGINE_H
#define CRAPENGINE_H
#include "Engine.h"


class CrapEngine : public Engine
{
    public:
        CrapEngine();
        virtual ~CrapEngine();
        int getSpeed();

    protected:

    private:
        int speed;
};

#endif // CRAPENGINE_H
