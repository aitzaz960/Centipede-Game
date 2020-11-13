#ifndef MOVEABLEOBJECT_H
#define MOVEABLEOBJECT_H
#include "GameObject.h"
class MoveableObject: public GameObject
{
    private:
    protected:
    public:
        MoveableObject();
        MoveableObject(int a, int b);
        virtual void move() = 0;
        ~MoveableObject();
};
#endif