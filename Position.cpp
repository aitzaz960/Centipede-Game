#include "Position.h"

Position::Position()
{
    x = 0;
    y = 0;
}

Position::Position(int a, int b)
{
    x = a;
    y = b;

}

Position::Position(Position& pos)
{
    x = pos.getX();
    y = pos.getY();
}

void Position::setX(int a)
{
    x = a;
}

void Position::setY(int b)
{
    y = b;
}

int Position::getX() const
{
    return x;
}

int Position::getY() const
{
    return y;
}

Position::~Position()
{
}