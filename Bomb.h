#ifndef BOMB_H
#define BOMB_H
#include "MoveableObject.h"
class Bomb : public MoveableObject
{
    private:
        bool active;
    protected:
    public:
        Bomb();
        Bomb(int a, int b);
        void move();
        void draw();
        void setActive();
        bool isActive();
        ~Bomb();
};
#endif