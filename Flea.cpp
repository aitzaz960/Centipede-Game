#include "Flea.h"

Flea::Flea():MoveableObject(rand()%40, 40)
{
    dis = 0;
}

void Flea::move(){
    p.setY( p.getY()-3);
    if( p.getY() < 0)
    {
        dis = 0;
    }


}

void Flea::draw(){
    DrawSquare( p.getX()*10, p.getY()*10, 20, colors[BLUE]);
}

void Flea::removeFromScreen(){
    dis = 0;
}

void Flea::showOnScren(){
    dis = 1;
    p.setX(rand()%120);
    p.setY(40);
}

bool Flea::getDis() const{
    return dis;
}

Flea::~Flea(){

}