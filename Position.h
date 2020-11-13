#ifndef POSITION_H
#define POSITION_H
class Position
{
    private:
    protected:
        int x, 
            y;
    public:
        Position();
        Position(int a, int b);
        Position(Position& pos);
        void setX(int a);
        void setY(int b);
        int getX() const;
        int getY() const;
        ~Position();
};
#endif