#ifndef MAGICSEG_H
#define MAGICSEG_H
#include "Segment.h"
class MagicSeg: public Segment
{
    private:
    protected:
        int magicX,
            magicY;
    public:
        MagicSeg();
        MagicSeg(int a, int b);
        void setMagicSeg(int a, int b);
        void setCX(int i);
        void setCY(int i);
        int getCX() const;
        int getCY() const;
        MagicSeg getCSeg() const;
        bool isMagic() const;
        ~MagicSeg();
};
#endif