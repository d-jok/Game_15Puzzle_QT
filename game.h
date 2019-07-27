#ifndef GAME_H
#define GAME_H

#include <QMainWindow>
#include <QGridLayout>
#include <QPoint>
#include <QPushButton>
#include <QList>
#include <QWidget>
#include <qlcdnumber.h>
#include <QLCDNumber>
namespace Ui {
class Game;
}

class Game : public QMainWindow
{
    Q_OBJECT

public:
    explicit Game(QWidget *parent = 0);
    ~Game();

   void shuffleButtons();
   bool checkGameOver();


private slots:
    void on_pushButton_clicked();

    void on_pushButton_18_clicked();

   // void on_pushButton_30_clicked();

    void move();

private:
    Ui::Game *ui;

};

#endif // GAME_H
