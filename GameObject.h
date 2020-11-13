#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include "util.h"
#include "Position.h"
class GameObject
{
    private:
    protected:
        Position p;
    public:
        GameObject();
        GameObject(int a, int b);
        virtual void draw() = 0;
        Position getPosition();
        void setPosition(int a, int b);
        ~GameObject();
};
#endif