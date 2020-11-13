#ifndef CENTIPEDE_H
#define CENTIPEDE_H
#include "MoveableObject.h"
#include "Segment.h"
#include "MagicSeg.h"
#include "LazySeg.h"
class Centipede: public MoveableObject
{
    private:
        bool life;
        int lock;
        int preFace;
    protected:
        int face;
        int noOfSegments;
        Segment** segments;
    public:
        int** centi_location;
        Centipede();
        Centipede(int s);
        void setLife(Centipede& centi, int g, int b);
        bool isAlive();
        void killCentipede();
        void draw();
        void move();
        void shiftHead();
        int getFace() const;
        Segment** getSegments() const;
        ~Centipede();

        
};
#endif