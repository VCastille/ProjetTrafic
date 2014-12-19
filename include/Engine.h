#ifndef ENGINE_H
#define ENGINE_H


class Engine
{
    public:
        Engine();
        virtual ~Engine();
        virtual int getSpeed()= 0 ;
    protected:
    private:
};

#endif // ENGINE_H
