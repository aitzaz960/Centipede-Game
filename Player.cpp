#include "Player.h"

Player::Player():MoveableObject(0,0)
{
    direction = 1;
};

Player::Player(int a, int b):MoveableObject(a,b)
{
    direction = 1;
}

void Player::draw()
{
    DrawSquare( p.getX() * 20,   p.getY() *20,   19,   colors[GOLD]);
  //  DrawRectangle(    (p.getX() * 20) + 20,     (p.getY() * 20),    20,    10,    colors[GRAY] );
    //DrawSquare(   (p.getX() * 20) + 20 + 20 ,     p.getY() * 20,    19,    colors[GRAY]);
}

void Player::move()
{

    if(direction == 1)
    {
        int temp = p.getY()+1;
        if( temp < 5 )
            p.setY( temp);
    }
    else if(direction == 2)
    {
        int temp = p.getX()+1;
        if( temp < 51 )
            p.setX( temp );
    }
    else if(direction == 3)
    {
        int temp = p.getX()-1;
        if( temp >= 0)
            p.setX( temp );
    }
    else if(direction == 4)
    {
        int temp = p.getY() - 1;
        if( temp >=0 )
            p.setY( temp );
    }
    else
    {
        cout << "Its Mars!!!!" << endl;
    }
    draw();
}

Player::~Player()
{

}

void Player::setDirection(int s)
{
    direction = s;
}