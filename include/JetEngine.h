#ifndef JETENGINE_H
#define JETENGINE_H
#include "Engine.h"


class JetEngine : public Engine
{
    public:
        JetEngine();
        virtual ~JetEngine();
        int getSpeed();

    protected:
        int speed;

    private:
};

#endif // JETENGINE_H
