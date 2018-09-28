#include "spielstein.h"

spielstein::spielstein()
{
x = 10 + qrand() % 370;
y = 60;
size = 5;
speed = 0.5f;
isMoving = false;
hasCollision = true;
}

bool spielstein::kollision(QRectF testRect){
    if(QRectF(x,y,size,size).intersects(testRect))
        return true;
    else
        return false;
}

void spielstein::move(){
    y += speed;
}

void spielstein::draw(QPainter* painter, QPaintDevice* paintDevice){
    painter->begin(paintDevice);
    painter->setBrush(QBrush(QColor(0,255,0),Qt::SolidPattern));
    painter->drawRect(x,y,size,size);
    painter->end();
}


