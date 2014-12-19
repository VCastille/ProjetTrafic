#ifndef HULL_H
#define HULL_H


class Hull
{
    public:
        Hull();
        ~Hull();
        int getSolidity() const;
        virtual bool operator < (const Hull& a) const = 0;
    protected:
        int m_solidity;
    private:
};

#endif // HULL_H
