#include "window.h"
#include "ui_window.h"

Window::Window(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Window)
{
    ui->setupUi(this);
    this->setFixedHeight(this->height());
    this->setFixedWidth(this->width());
    this->setFixedSize(this->size());
}

Window::~Window()
{
    delete ui;
}
void Window::keyPressEvent(QKeyEvent* event){
    ui->Spielfeld->handleMovement(event);
}
void Window::on_pushButton_clicked()
{
    //ui->Canvas->start();
    if(ui->pushButton->text().contains("Start")){
        ui->Spielfeld->gameOn = true;
        ui->pushButton->setText("Pausieren");
    }
    else{
        ui->pushButton->setText("Start");
        ui->Spielfeld->gameOn = false;
    }
}

void Window::on_pushButton_2_clicked()
{
    ui->Spielfeld->speichern();
}

void Window::on_pushButton_3_clicked()
{
    ui->Spielfeld->laden();
}
