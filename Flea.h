#ifndef FLEA_H
#define FLEA_H
#include<stdlib.h>
#include "MoveableObject.h"
class Flea: public MoveableObject
{
    private:
    protected:
        bool dis;
    public:
        Flea();
        void move();
        void draw();
        void removeFromScreen();
        void showOnScren();
        bool getDis() const;
        ~Flea();
};
#endif