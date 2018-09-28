#ifndef PLAYER_H
#define PLAYER_H

#include <QKeyEvent>
#include <QPainter>

class Player
{
public:
    Player();
    Player(float pX, float pY);
    float getX(){return x;}
    float getY(){return y;}
    void setX(float pX){x = pX;}

    float getSize(){return size;}
    float getSpeed(){return speed;}
    void move(QKeyEvent* event);
    void draw(QPainter* painter, QPaintDevice* paintDevice);
    void loseLife(){if(lives > 0)lives--;};
    int getLife(){return lives;};
    void setLife(int p){lives = p;}
private:
    float x;
    float y;
    float size;
    float speed;
    int lives;
    QBrush heartfull;
    QBrush heartempty;
    QBrush brushplayer;
    QPolygon heart1,heart2,heart3;
};

#endif // PLAYER_H
