#include "spielfeld.h"
#include <QDebug>

Spielfeld::Spielfeld(QWidget *parent) : QWidget(parent)
{
    //legt das Objekt der Spielfigur an
    avatar = Player();
    gameOn = false;
    punkte = 0;
    lastStein = 0;
    // erzeugt einen Timer, der alle 10 millisekunden die update() Funktion ausführt
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    connect(timer,SIGNAL(timeout()), this, SLOT(spawnSteine()));
    timer->start(10);
    timer->setSingleShot(false);

    // Erzeugt einen weißen Hintergrund
    QPalette pal;
    pal.setColor(QPalette::Background, Qt::white);
    setPalette(pal);
    setAutoFillBackground(true);

    for(int i = 0;i< 50; i++){
        steine[i] = spielstein();
    }
}

// Die Update() Funktion ruft auch immer ein paintEvent auf
void Spielfeld::paintEvent(QPaintEvent* event){
    QPainter painter;
    painter.begin(this);
    painter.setPen(Qt::black);
    painter.drawText(20,20,QString(QString::number(punkte / 50) +" Punkte"));
    painter.end();
    avatar.draw(&painter, this);

    if(gameOn)
    {
        punkte++;
        for(int i = 0; i< 50; i++){
            if(steine[i].isMoving){
                if(steine[i].hasCollision)
                    steine[i].draw(&painter,this);
                if(steine[i].kollision(QRectF(avatar.getX(),avatar.getY(),avatar.getSize(),avatar.getSize())) && steine[i].hasCollision)
                {
                    avatar.loseLife();
                    steine[i].hasCollision = false;
                }
                if(steine[i].getY() >= 300){
                    steine[i].isMoving = false;
                    steine[i].hasCollision = true;
                    steine[i].setX(10 + qrand() % 370);
                    steine[i].setY(60);
                }
                steine[i].move();
            }
        }
        if(avatar.getLife() < 1)
            gameOn = false;
    }
    else{
        for(int i = 0; i< 50; i++){
            if(steine[i].isMoving){
                if(steine[i].hasCollision)
                    steine[i].draw(&painter,this);
            }
        }
    }
}

// hier wird die Tastatureingabe weitergeleitet
void Spielfeld::handleMovement(QKeyEvent* event){
    if(gameOn)
        avatar.move(event);

}

// hier werden die Steine gespawnt;
void Spielfeld::spawnSteine(){
    if(((qrand() % 100) <  5) && gameOn){
        steine[lastStein].isMoving = true;
        steine[lastStein].hasCollision = true;
        lastStein++;
        if(lastStein == 50){
            lastStein = 0;
        }
    }
}

void Spielfeld::speichern(){
    QString fileName = QFileDialog::getSaveFileName(this, tr("Spielstand speichern"),"",tr("Spielstand (*.savegame)"));
    if(!fileName.isEmpty()){

        QFile file(fileName);
        if(!file.open(QIODevice::WriteOnly)){
            QMessageBox::information(this,tr("Kann die Datei nicht öffnen"), file.errorString());
            return;
        }
        else{
            QTextStream out(&file);
            if(gameOn)
                out << "1 ";
            else
                out << "0 ";
            out << punkte << " ";
            out << lastStein << endl;
            out << avatar.getX() << " " << avatar.getY() << " " << avatar.getLife() << endl;
            for(int i = 0;i<50; i++){
                if(steine[i].isMoving)
                    out << "1 ";
                else
                    out << "0 ";
                if(steine[i].hasCollision)
                    out << "1 ";
                else
                    out << "0 ";
                out << steine[i].getX() << " " << steine[i].getY() << endl;
            }
        }
    }
    else
        return;
}

void Spielfeld::laden(){
    QString fileName = QFileDialog::getOpenFileName(this, tr("Spielstand laden"),"",tr("Spielstand (*.savegame)"));
    if(!fileName.isEmpty()){
        QFile file(fileName);
        if (!file.open(QIODevice::ReadOnly)) {
                   QMessageBox::information(this, tr("Kann die Datei nicht öffnen"),
                       file.errorString());
                   return;
        }
        else{
            QTextStream in(&file);
            char nl;
            int temp, temp1;
            in >> temp;
            if (temp == 1)
                gameOn = true;
            else
                gameOn = false;
            in >> punkte;
            in >> lastStein;
            in >> nl;

            float temp2,temp3;
            in >> temp2 >> temp3 >> temp;
            avatar.setX(temp2);
            avatar.setLife(temp);
            in >> nl;

            for(int i  = 0; i < 50; i++){
                in >> temp;
                if(temp == 1)
                    steine[i].isMoving = true;
                        else
                    steine[i].isMoving = false;
                in >> temp1;
                if(temp1 == 1)
                    steine[i].hasCollision = true;
                else
                    steine[i].hasCollision = false;
                in >> temp2 >> temp3;
                qDebug() << temp << " " << temp1 << " " << temp2 << " " << temp3;
                steine[i].setX(temp2);
                steine[i].setY(temp3);
                in >> nl;
            }
        }

    }
    else
        return;
}
