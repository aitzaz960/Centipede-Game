#ifndef SEGMENT_H
#define SEGMENT_H
class Segment
{
    private:
    protected:
        
    public:
        virtual void setCX(int i);
        virtual void setCY(int i);
        virtual int getCX() const;
        virtual int getCY() const;
        virtual bool isMagic() const;
};
#endif