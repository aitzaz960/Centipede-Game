#include "Centipede.h"

Centipede::Centipede(){
    life = 1;
    lock = 0;
    preFace = 3;
    face = 3;

    p.setX(40);
    p.setY(39);
    //cout <<"R";
    noOfSegments = 1;
    segments = new Segment*[noOfSegments];
    
    if(noOfSegments == 1)
        segments[0] = new MagicSeg(p.getX(), p.getY() );
    else
    {
        segments[0] = new MagicSeg(p.getX(), p.getY() );
        int tempX = p.getX();
        int tempY = p.getY();
        for(int a=1; a<noOfSegments; a++)
        {
            segments[a] = new LazySeg(--tempX, tempY); 
        }
    }
    p.setX( segments[0]->getCX() );
    p.setY( segments[0]->getCY() );

    centi_location = new int*[51];
    for(int z=0; z<51; z++)
        centi_location[z] = new int[42];
    
    for(int a=0; a<51; a++)
    {   for(int b=0; b<42; b++)
            centi_location[a][b] = 0;
    }
    
    for(int m=0; m<noOfSegments; m++)
    {
        centi_location[ segments[m]->getCX() ] [ segments[m]->getCY() ] = 112;
    }
}

Centipede::Centipede(int s)
{
    life = 1;
    lock = 0;
    preFace = 3;
    face = 3;

    p.setX(40);
    p.setY(39); 
    
    noOfSegments = 10;
    segments = new Segment*[noOfSegments];
    
    if(noOfSegments == 1)
        segments[0] = new MagicSeg(p.getX(), p.getY() );
    else
    {
        segments[0] = new MagicSeg(p.getX(), p.getY() );
        int tempX = p.getX();
        int tempY = p.getY();
        for(int a=1; a<noOfSegments; a++)
        {
            segments[a] = new LazySeg(--tempX, tempY); 
        }
    }

    p.setX( segments[0]->getCX() );
    p.setY( segments[0]->getCY() );

    centi_location = new int*[51];
    for(int z=0; z<51; z++)
        centi_location[z] = new int[42];
    
    for(int a=0; a<51; a++)
    {   for(int b=0; b<42; b++)
            centi_location[a][b] = 0;
    }
    
    for(int m=0; m<noOfSegments; m++)
    {
        centi_location[ segments[m]->getCX() ] [ segments[m]->getCY() ] = 112;
    }
    
}

void Centipede::draw()
{   
    DrawCircle( (segments[0]->getCX() * 20)+10, (segments[0]->getCY() * 20)+10, 10, colors[ORANGE] );
    for(int a=1; a<noOfSegments; a++)
    {
        DrawCircle( (segments[a]->getCX() * 20)+10, (segments[a]->getCY() * 20)+10, 10, colors[RED] );
    }
    //cout << "drawing"<<endl;
}

void Centipede::move()
{
    //cout << "face: "<<face<<endl;
    if( face == 1 && lock == 1 )
    {

        int tx = segments[0]->getCX();
        int ty = segments[0]->getCY();
        if( ty+1 >40)
        {
            
            face = 3;
            lock =0;
        }
        else
        {
            for(int a=noOfSegments-1; a>0; a--)
            {
                segments[a]->setCX( segments[a-1]->getCX() );
                segments[a]->setCY( segments[a-1]->getCY() );
            }
            segments[0]->setCY(ty+1);
             //cout << "face: "<<face<<endl;
        }
  
    }

    else if( face == 2 )
    {
        int tx = segments[0]->getCX();
        int ty = segments[0]->getCY();
        
        if( tx+1 > 50|| ( tx+1!=51 && (centi_location[tx+1][ty] == 65 || centi_location[tx+1][ty] == 112 ) ) )
        {
            preFace = 2;
            face = 4;
            lock = 1;
        }
        else
        {
            for(int a=noOfSegments-1; a>0; a--)
            {
                segments[a]->setCX( segments[a-1]->getCX() );
                segments[a]->setCY( segments[a-1]->getCY() );
            }
            lock = 0;
            segments[0]->setCX(tx+1);
             //cout << "face: "<<face<<endl;
        }
        
    }

    else if( face == 3 )
    {
        int tx = segments[0]->getCX();
        int ty = segments[0]->getCY();
        if( tx-1 < 0|| ( tx-1!=-1 && (centi_location[tx-1][ty] == 65|| centi_location[tx-1][ty] == 112) )  )
        {
            preFace = 3;
            face = 4;
            lock = 1;
        }
        else
        {
            for(int a=noOfSegments-1; a>0; a--)
            {
                segments[a]->setCX( segments[a-1]->getCX() );
                segments[a]->setCY( segments[a-1]->getCY() );
            }
            segments[0]->setCX(tx-1);
            lock = 0;
             //cout << "face: "<<face<<endl;
        }
    }

    else if( face == 4 && lock == 1 )
    {
        int tx = segments[0]->getCX();
        int ty = segments[0]->getCY();
        if( ty-1 < 0)
        {
            if(preFace == 2)
                face = 3;
            if(preFace == 3)
                face = 2;
            lock =0;
        }
        else
        {
            for(int a=noOfSegments-1; a>0; a--)
            {
                segments[a]->setCX( segments[a-1]->getCX() );
                segments[a]->setCY( segments[a-1]->getCY() );
            }
            segments[0]->setCY(ty-1);
            if(preFace == 2)
                face = 3;
            if(preFace == 3)
                face = 2;
            lock = 0;
            // cout << "face: "<<face<<endl;
        }
    }

    
    for(int a=0; a<51; a++)
    {
        for(int b=0; b<42; b++)
        {
            if(centi_location[a][b]==112)
                centi_location[a][b] = 0;
        }
    }

    for(int m=0; m<noOfSegments; m++)
    {
        centi_location[ segments[m]->getCX() ] [ segments[m]->getCY() ] = 112;
    } 

    p.setX( segments[0]->getCX() );
    p.setY( segments[0]->getCY() );   
    //cout << "Moving"<<endl;
}

int Centipede::getFace() const{
    return face;
}

void Centipede::setLife(Centipede& centi, int g, int b){
    cout << "Going in "<< endl;
    //deleting the previously declared array of segments
    for(int f=0; f<noOfSegments; f++)
        delete segments[f];
    delete segments;
    
    //setting some gernal settings
    life = 1;
    lock = 1;
    face = 4;
    preFace = centi.preFace;
    //cout << "Check" << endl;
    //getting exact noOfSegments for new dead centipede
    for(int a=0; a<centi.noOfSegments; a++)
    {   if( centi.segments[a]->getCX() == g && centi.segments[a]->getCY() == b )
        {
            noOfSegments = centi.noOfSegments - ( a + 1);
        }
    }
    //cout << centi.noOfSegments <<" "<< noOfSegments<<endl;
    //creating a new array of segments using the new noOfSegments
    
    segments = new Segment*[noOfSegments];
    if(noOfSegments == 1)
        segments[0] = new MagicSeg(g, b );
    else
    {
        segments[0] = new MagicSeg(g, b );
        for(int a=1; a<noOfSegments; a++)
        {
            segments[a] = new LazySeg(g, b); 
        }
    }

    int t=0;
    for(int h=0; h<centi.noOfSegments; h++)
    {
        if(centi.segments[h]->getCX() == g  && centi.segments[h]->getCY() == b )
        {
            cout << h<<endl;
            t=h;
        }  
    }
    

    int temp_new = t;
    t = t+1;
    //cout << "t: "<<t<<endl;
      
    for(int a=0; a<noOfSegments; a++)
    {
        segments[a]->setCX( centi.segments[t]->getCX() );
        segments[a]->setCY( centi.segments[t]->getCY() );
        t++;
    }

    for(int a=0; a<51; a++)
    {   for(int b=0; b<42; b++)
            centi_location[a][b] = 0;
    }
    

    for(int m=0; m<noOfSegments; m++)
    {
        centi_location[ segments[m]->getCX() ] [ segments[m]->getCY() ] = 112;
    }
    
    int temp_old = centi.noOfSegments;
    centi.noOfSegments = temp_new;
    Segment** t_seg  = new Segment*[temp_new];

    if(centi.noOfSegments == 1)
        t_seg[0] = new MagicSeg(g, b );
    else
    {
        t_seg[0] = new MagicSeg(g, b );
        for(int a=1; a<centi.noOfSegments; a++)
        {
            t_seg[a] = new LazySeg(g, b); 
        }
    }

    for(int k=0; k<centi.noOfSegments; k++)
    {
        t_seg[k]->setCX( centi.segments[k]->getCX() );
        t_seg[k]->setCY( centi.segments[k]->getCY() );
    }
  
    for(int y=0; y<temp_old; y++)
    {
        delete centi.segments[y];
    }
    delete [] centi.segments;

    centi.segments = t_seg;
    
    for(int a=0; a<51; a++)
    {   for(int b=0; b<42; b++)
            centi.centi_location[a][b] = 0;
    }
    
    for(int m=0; m<centi.noOfSegments; m++)
    {
        centi.centi_location[ centi.segments[m]->getCX() ] [ centi.segments[m]->getCY() ] = 112;
    }

    p.setX( segments[0]->getCX() );
    p.setY( segments[0]->getCY() );
    
    centi.p.setX( centi.segments[0]->getCX() );
    centi.p.setY( centi.segments[0]->getCY() );
    cout << "Yo"<<endl;
}

bool Centipede::isAlive(){
    return life;
}

void Centipede::killCentipede(){
    life = 0;
}

void Centipede::shiftHead(){
    cout << "shifting";
    if(noOfSegments-1 < 1)
    {
        killCentipede();
    }
    else
    {
        noOfSegments = noOfSegments-1;
        Segment** temp_seg = new Segment*[noOfSegments];
        
        if(noOfSegments == 1)
            temp_seg[0] = new MagicSeg(p.getX(), p.getY() );
        else
        {
            temp_seg[0] = new MagicSeg(p.getX(), p.getY() );
            int tempX = p.getX();
            int tempY = p.getY();
            for(int a=1; a<noOfSegments; a++)
            {
                temp_seg[a] = new LazySeg(--tempX, tempY); 
            }
        }
        
        for(int a=0; a<51; a++)
        {   for(int b=0; b<42; b++)
                centi_location[a][b] = 0;
        }
        
        for(int a=0; a<noOfSegments; a++)
        {
            temp_seg[a]->setCX( segments[a+1]->getCX() );
            temp_seg[a]->setCY( segments[a+1]->getCY() );
        }

        for(int y=0; y<noOfSegments+1; y++)
        {
            delete segments[y];
        }
        delete [] segments;

        segments = temp_seg;
        
        for(int m=0; m<noOfSegments; m++)
        {
            centi_location[ segments[m]->getCX() ] [ segments[m]->getCY() ] = 112;
        }

        p.setX( segments[0]->getCX() );
        p.setY( segments[0]->getCY() );
    }
}

Segment** Centipede::getSegments() const
{
    return segments;
}

Centipede::~Centipede(){
    for(int a=0; a<noOfSegments; a++)
    {
        delete segments[a];
    }
    delete [] segments;
} 