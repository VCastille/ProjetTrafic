#ifndef STRONGHULL_H
#define STRONGHULL_H
#include "Hull.h"

class StrongHull : public Hull
{
    public:
        StrongHull();
        ~StrongHull();
        bool operator < (const Hull& a) const;
    protected:
    private:
};

#endif // STRONGHULL_H
