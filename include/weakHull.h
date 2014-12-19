#ifndef WEAKHULL_H
#define WEAKHULL_H
#include "Hull.h"

class WeakHull : public Hull
{
    public:
        WeakHull();
        ~WeakHull();
        bool operator < (const Hull& a) const;
    protected:
    private:
};

#endif // WEAKHULL_H
