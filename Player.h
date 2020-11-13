#ifndef PLAYER_H
#define PLAYER_H
#include "MoveableObject.h"
class Player: public MoveableObject
{
    private:
    protected:
        int direction;
    public:
        Player();
        Player(int a, int b);
        void draw();
        void move();
        void setDirection(int s);
        ~Player();
};
#endif