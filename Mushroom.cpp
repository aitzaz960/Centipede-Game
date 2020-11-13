#include "Mushroom.h"
Mushroom::Mushroom():GameObject( rand()%51, rand()%34+5 ){
    
    active = 1;
    life = 2;
    p.setX( rand()%51 );
    p.setY( rand()%34+5 );
    //cout << p.getX() << " "<<p.getY() << endl;
}


bool Mushroom::isActive() const{
    if(active == 1)
        return 1;
    else
        return 0;
}

void Mushroom::giveLife()
{
    life = 2;
}

void Mushroom::decreaseLife(){
    life--;
    dead();
}

int Mushroom::lifeStatus() const
{
    return life;
}

void Mushroom::dead()
{
    if(life < 1)
        active = 0;
}

void Mushroom::draw(){
    DrawSquare( p.getX()*20 , p.getY()*20 ,19,colors[GREEN]); 
}

Mushroom::~Mushroom(){

}