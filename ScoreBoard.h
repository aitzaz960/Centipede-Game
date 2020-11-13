#ifndef SCOREBOARD_H
#define SCOREBOARD_H
#include "GameObject.h"
#include<fstream>
#include<string>
#include<sstream>
using namespace std;
class ScoreBoard: public GameObject
{
    private:
    protected:
        int score;
        int lives;
        int highScore;
    public:
        ScoreBoard();
        void updateScore( int n );
        void setLives();
        int getLives() const;
        int getScore() const;
        void decreaseLives();
        int getHighScore() const;
        void draw();
        ~ScoreBoard();
};
#endif