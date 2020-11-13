#include "LazySeg.h"

LazySeg::LazySeg(){
}

LazySeg::LazySeg(int a, int b){
    lazyX = a;
    lazyY = b;   
}

void LazySeg::setLazyXY(int a, int b){
    lazyX = a;
    lazyY = b;   
}

void LazySeg::setCX(int i)
{
    lazyX = i;
}
void LazySeg::setCY(int i)
{
    lazyY = i;
}

int LazySeg::getCX() const{
    return lazyX;
}

int LazySeg::getCY() const{
    return lazyY;
}


LazySeg LazySeg::getCSeg() const
{
    return *this;
}

bool LazySeg::isMagic() const{
    return 0;
}

LazySeg::~LazySeg(){
}