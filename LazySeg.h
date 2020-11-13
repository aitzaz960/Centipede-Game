#ifndef LAZYSEG_H
#define LAZYSEG_H
#include "Segment.h"
class LazySeg: public Segment
{
    private:
    protected:
        int lazyX;
        int lazyY;
    public:
        LazySeg();
        LazySeg(int a, int b);
        void setLazyXY(int a, int b);
        void setCX(int i);
        void setCY(int i);
        int getCX() const;
        int getCY() const;
        LazySeg getCSeg() const;
        bool isMagic() const;
        ~LazySeg();
};
#endif