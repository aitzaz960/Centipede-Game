#include "MagicSeg.h"

MagicSeg::MagicSeg(int a, int b)
{
    magicX = a;
    magicY = b;
}

void MagicSeg::setMagicSeg(int a, int b)
{
    magicX = a;
    magicY = b;
}
void MagicSeg::setCX(int i)
{
    magicX = i;
}

void MagicSeg::setCY(int i){
    magicY = i;
}
int MagicSeg::getCX() const
{
    return magicX;
}

int MagicSeg::getCY() const
{
    return magicY;
}

MagicSeg MagicSeg::getCSeg() const
{
    return *this;
}

bool MagicSeg::isMagic() const
{
    return 1;
}
MagicSeg::~MagicSeg()
{
    
}