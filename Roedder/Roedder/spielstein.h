#ifndef SPIELSTEIN_H
#define SPIELSTEIN_H
#include <QPainter>

class spielstein
{
public:
    spielstein();
    float getX(){return x;}
    float getY(){return y;}
    float getSize(){return size;}
    float getSpeed(){return speed;}
    void setX(float pX){x = pX;}
    void setY(float pY){y = pY;}
    void draw(QPainter* painter, QPaintDevice* paintDevice);
    bool kollision(QRectF testRect);
    void move();
    bool isMoving;
    bool hasCollision;
private:
    float x;
    float y;
    float size;
    float speed;
};

#endif // SPIELSTEIN_H
