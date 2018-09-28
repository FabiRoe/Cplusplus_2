#ifndef WINDOW_H
#define WINDOW_H

#include <QMainWindow>
#include <QKeyEvent>

namespace Ui {
class Window;
}

class Window : public QMainWindow
{
    Q_OBJECT

public:
    explicit Window(QWidget *parent = nullptr);
    ~Window();

private slots:
    void on_pushButton_clicked();
    void keyPressEvent(QKeyEvent* event);
    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::Window *ui;
};

#endif // WINDOW_H
