#include "ScoreBoard.h"

ScoreBoard::ScoreBoard():GameObject(5,80){
    lives = 3;
    score = 0;
    fstream file;
    file.open("high_score.txt", ios::in);
    file >> highScore;
    file.close();
}

void ScoreBoard::updateScore( int n ){
    score += n;
}

void ScoreBoard::setLives(){
    lives = 3;
}

int ScoreBoard::getLives() const{
    return lives;
}

int ScoreBoard::getScore() const{
    return score;
}
void ScoreBoard::decreaseLives()
{
    lives--;
    if(lives < 1)
    {
        setLives();
    }
}
int ScoreBoard::getHighScore() const{
    return highScore;
}
void ScoreBoard::draw(){
    string str1, str2, str3;
    stringstream sx, sy, sz;

    sx << score;
    str1 = "Score: "+sx.str();
    
    sy << lives;
    str2 = "Lives: "+sy.str();
    
    sz << highScore;
    str3 = "High Score: " + sz.str();
    
    DrawString(p.getX()*10, p.getY()*10, str1, colors[WHITE] );
    DrawString(p.getX()*10+400, p.getY()*10, str2, colors[WHITE] );
    DrawString(p.getX()*10+700, p.getY()*10, str3, colors[WHITE] );
}

ScoreBoard::~ScoreBoard(){

}