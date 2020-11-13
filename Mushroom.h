#ifndef MUSHROOM_H
#define MUSHROOM_H
#include "GameObject.h"
#include<stdlib.h>
class Mushroom: public GameObject
{
    private:
    protected:
        int life;
        bool active;
    public:
      
        Mushroom();
        bool isActive() const;
        void giveLife();
        void decreaseLife();
        int lifeStatus() const;
        void dead();
        void draw();
        ~Mushroom();
};
#endif