#ifndef SPIELFELD_H
#define SPIELFELD_H

#include <QWidget>
#include <QPaintEvent>
#include <QTimer>
#include <QFileDialog>
#include <QMessageBox>
#include <QString>
#include <QTextStream>
#include "player.h"
#include "spielstein.h"

class Spielfeld : public QWidget
{
    Q_OBJECT
public:
    explicit Spielfeld(QWidget *parent = nullptr);
    void handleMovement(QKeyEvent* event);
    spielstein steine[50];
    bool gameOn;
    void speichern();
    void laden();
protected:
    void paintEvent(QPaintEvent* event);
private:
    Player avatar;
    QTimer* timer;
    int lastStein;
    int punkte;
signals:

public slots:

    void spawnSteine();
};

#endif // SPIELFELD_H
