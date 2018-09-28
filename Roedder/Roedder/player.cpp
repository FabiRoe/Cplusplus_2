#include "player.h"
#include <QKeyEvent>


Player::Player()
{
x = 190.0;
y = 280.0;
size = 20.0;
speed = 4.5;
lives = 3;

heart1.append(QPoint(240,45));
heart1.append(QPoint(230,30));
heart1.append(QPoint(235,20));
heart1.append(QPoint(240,25));
heart1.append(QPoint(245,20));
heart1.append(QPoint(250,30));

heart2.append(QPoint(240+30,45));
heart2.append(QPoint(230+30,30));
heart2.append(QPoint(235+30,20));
heart2.append(QPoint(240+30,25));
heart2.append(QPoint(245+30,20));
heart2.append(QPoint(250+30,30));

heart3.append(QPoint(240+60,45));
heart3.append(QPoint(230+60,30));
heart3.append(QPoint(235+60,20));
heart3.append(QPoint(240+60,25));
heart3.append(QPoint(245+60,20));
heart3.append(QPoint(250+60,30));

brushplayer = QBrush(QColor(0,0,0),Qt::BDiagPattern);
heartfull = QBrush(QColor(255,100,100),Qt::SolidPattern);
heartempty = QBrush(QColor(255,230,230),Qt::SolidPattern);
}

Player::Player(float pX, float pY)
{
x = pX;
y = pY;
size = 20.0;
speed = 4.5;
lives = 3;

heart1.append(QPoint(240,45));
heart1.append(QPoint(230,30));
heart1.append(QPoint(235,20));
heart1.append(QPoint(240,25));
heart1.append(QPoint(245,20));
heart1.append(QPoint(250,30));

heart2.append(QPoint(240+30,45));
heart2.append(QPoint(230+30,30));
heart2.append(QPoint(235+30,20));
heart2.append(QPoint(240+30,25));
heart2.append(QPoint(245+30,20));
heart2.append(QPoint(250+30,30));

heart3.append(QPoint(240+60,45));
heart3.append(QPoint(230+60,30));
heart3.append(QPoint(235+60,20));
heart3.append(QPoint(240+60,25));
heart3.append(QPoint(245+60,20));
heart3.append(QPoint(250+60,30));

brushplayer = QBrush(QColor(0,0,0),Qt::BDiagPattern);
heartfull = QBrush(QColor(255,100,100),Qt::SolidPattern);
heartempty = QBrush(QColor(255,230,230),Qt::SolidPattern);
}

void Player::move(QKeyEvent* event){
    if((x + size + speed <= 380) && event->key() == Qt::Key_Right){
        x = x + speed;
    }
    else if((x - speed >= 8) && event->key() == Qt::Key_Left){
        x = x - speed;
    }
}

void Player::draw(QPainter* painter, QPaintDevice* paintDevice){
    painter->begin(paintDevice);
    painter->setPen(QPen(Qt::black, 2));
    painter->setBrush(brushplayer);
    painter->drawRect(QRectF(x,y,size,size));
    switch(lives){
    case (3):
        painter->setBrush(heartfull);
        painter->drawPolygon(heart1);
        painter->drawPolygon(heart2);
        painter->drawPolygon(heart3);
        break;
    case (2):
        painter->setBrush(heartempty);
        painter->drawPolygon(heart1);
        painter->setBrush(heartfull);
        painter->drawPolygon(heart2);
        painter->drawPolygon(heart3);
        break;
    case (1):
        painter->setBrush(heartempty);
        painter->drawPolygon(heart1);
        painter->drawPolygon(heart2);
        painter->setBrush(heartfull);
        painter->drawPolygon(heart3);
        break;
    default:
        painter->setBrush(heartempty);
        painter->drawPolygon(heart1);
        painter->drawPolygon(heart2);
        painter->drawPolygon(heart3);
        break;
    }

    painter->end();
}

