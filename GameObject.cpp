#include "GameObject.h"

GameObject::GameObject():p(0,0)
{

}

GameObject::GameObject(int a, int b):p(a,b)
{

}

Position GameObject::getPosition()
{
    return this->p;
}

void GameObject::setPosition(int a, int b)
{
    p.setX( a );
    p.setY( b );
}

GameObject::~GameObject()
{
}