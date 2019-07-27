#include "game.h"
#include "ui_game.h"
#include "MainWindow.h"
#include <QtGlobal>
#include <QGridLayout>
#include <QPoint>
#include <QPushButton>
#include <QTime>
#include "QMessageBox"
#include <cstdlib>
#include<time.h>
#include <QLCDNumber>

int matr[4][4],i,j,count=0,lcdNumber;
QPushButton* buttons[4][4];
Game::Game(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Game)
{
    ui->setupUi(this);
}

Game::~Game()
{
    delete ui;
}

void Game::move()
{
    int row, col, rs, cs;
    int t;
    QPushButton* clickedBtn = static_cast<QPushButton*>(sender());
    ui->gridLayout_2->getItemPosition(ui->gridLayout_2->indexOf(clickedBtn),&row,&col,&rs,&cs);

    if(row>0 && matr[row-1][col]==0)    // рух вгору
        {
            buttons[row][col]->setVisible(false);
            buttons[row-1][col]->setText(buttons[row][col]->text());
            buttons[row-1][col]->setVisible(true);
            t=matr[row][col];
            matr[row][col]=matr[row-1][col];
            matr[row-1][col]=t;
            ++count;
            ui->label->setText(QString::number(count));
        }
    else                                // рух вниз
        if(row<3 && matr[row+1][col]==0)
        {
            buttons[row][col]->setVisible(false);
            buttons[row+1][col]->setText(buttons[row][col]->text());
            buttons[row+1][col]->setVisible(true);
            t=matr[row][col];
            matr[row][col]=matr[row+1][col];
            matr[row+1][col]=t;
            ++count;
            ui->label->setText(QString::number(count));
        }
    else                                //рух вліво
        if(col>0 && matr[row][col-1]==0)
        {
            buttons[row][col]->setVisible(false);
            buttons[row][col-1]->setText(buttons[row][col]->text());
            buttons[row][col-1]->setVisible(true);
            t=matr[row][col];
            matr[row][col]=matr[row][col-1];
            matr[row][col-1]=t;
            ++count;
            ui->label->setText(QString::number(count));
        }
    else                                //рух вправо
        if(col<3 && matr[row][col+1]==0)
        {
            buttons[row][col]->setVisible(false);
            buttons[row][col+1]->setText(buttons[row][col]->text());
            buttons[row][col+1]->setVisible(true);
            t=matr[row][col];
            matr[row][col]=matr[row][col+1];
            matr[row][col+1]=t;
            ++count;
            ui->label->setText(QString::number(count));
        }

    if(checkGameOver()==true)
    {
        QMessageBox::information(this,"","Ви виграли");
    }

}



void Game::shuffleButtons()
{
    std::vector<int> random;
    for(i=0;i<16;i++)
    {
        random.push_back(i);
    }
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(random.begin(),random.end(),g);


    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
                matr[i][j]=random[4*i+j];
        }
    }


buttons[0][0]=ui->pushButton_19;
buttons[0][1]=ui->pushButton_20;
buttons[0][2]=ui->pushButton_21;
buttons[0][3]=ui->pushButton_22;
buttons[1][0]=ui->pushButton_23;
buttons[1][1]=ui->pushButton_24;
buttons[1][2]=ui->pushButton_25;
buttons[1][3]=ui->pushButton_26;
buttons[2][0]=ui->pushButton_27;
buttons[2][1]=ui->pushButton_28;
buttons[2][2]=ui->pushButton_29;
buttons[2][3]=ui->pushButton_30;
buttons[3][0]=ui->pushButton_31;
buttons[3][1]=ui->pushButton_32;
buttons[3][2]=ui->pushButton_33;
buttons[3][3]=ui->pushButton_34;


    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            connect(buttons[i][j], SIGNAL(clicked()), this, SLOT(move()));
            buttons[i][j]->setText(QString::number(matr[i][j]));
            if(matr[i][j]==0)
            {
                buttons[i][j]->setVisible(false);
            }
        }
    }

}

bool Game::checkGameOver()
{
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
        if(matr[i][j]!=4*i+j+1)
        {
            return false;
        }
        }
    }
    return true;
}


void Game::on_pushButton_clicked()//start
{
    ui->pushButton->setVisible(false);



    shuffleButtons();

}

void Game::on_pushButton_18_clicked()
{
    close();
}
