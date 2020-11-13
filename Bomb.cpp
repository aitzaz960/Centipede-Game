#include "Bomb.h"

Bomb::Bomb():MoveableObject(0,0)
{
    active = 0;
}

Bomb::Bomb(int a, int b):MoveableObject(a,b)
{
    active = 1;
}

void Bomb::move()
{
    draw();
    p.setY( p.getY() + 1 );
    //draw();
}

void Bomb::draw()
{
    DrawSquare( p.getX() * 20 , p.getY() * 20 ,19,colors[WHITE]);
}

void Bomb::setActive()
{
    if(active==1)
        active = 0;
    else
        active = 1;
}
bool Bomb::isActive()
{
    return active;
}

Bomb::~Bomb()
{
    
} 