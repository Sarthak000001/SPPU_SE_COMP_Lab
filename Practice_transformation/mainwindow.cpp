#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<cmath>
#include<math.h>

QImage img(500,500,QImage::Format_RGB888);
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::DDA(int x1, int y1, int x2, int y2)
{
    float dx, dy, x, y, len, Xinc, Yinc;

    dx = x2 - x1 ;
    dy = y2 - y1 ;

    if (abs(dx)>=abs(dy))
    {
        len = abs(dx);
    }

    else
    {
        len = abs(dy);
    }

    x = x1 ;
    y = y1 ;

    int i = 0 ;
    //img.setPixel(x,y);
    Xinc = dx/len;
    Yinc = dy/len ;

    while (i<len)
    {
        img.setPixel(x,y, qRgb(255,255,255));
        x = x + Xinc;
        y = y + Yinc ;
        i++;
    };

    ui -> label->setPixmap(QPixmap :: fromImage(img));
}
void MainWindow::on_pushButton_clicked()
{
    DDA(250,0,250,500);
    DDA(0,250,500,250);
}


void MainWindow::on_pushButton_2_clicked()
{
    x1=ui->textEdit_3->toPlainText().toInt();
    y1=ui->textEdit_4->toPlainText().toInt();
    x2=ui->textEdit_5->toPlainText().toInt();
    y2=ui->textEdit_6->toPlainText().toInt();
    x3=ui->textEdit_7->toPlainText().toInt();
    y3=ui->textEdit_8->toPlainText().toInt();
    DDA(x1+250,y1+250,x2+250,y2+250);
    DDA(x1+250,y1+250,x3+250,y3+250);
    DDA(x3+250,y3+250,x2+250,y2+250);
}


void MainWindow::on_pushButton_3_clicked()
{
    int tx,ty;
    tx=ui->textEdit->toPlainText().toInt();
    ty=ui->textEdit_2->toPlainText().toInt();

    DDA(x1+250+tx,y1+250+ty,x2+250+tx,y2+250+ty);
    DDA(x1+250+tx,y1+250+ty,x3+250+tx,y3+250+ty);
    DDA(x3+250+tx,y3+250+ty,x2+250+tx,y2+250+ty);
}


void MainWindow::on_pushButton_4_clicked()
{
    int Sx,Sy;
    Sx=ui->textEdit_9->toPlainText().toFloat();
    Sy=ui->textEdit_10->toPlainText().toFloat();

    x1=Sx*x1;
    y1=Sy*y1;
    x2=Sx*x2;
    y2=Sy*y2;
    x3=Sx*x3;
    y3=Sy*y3;

    DDA(x1+250,y1+250,x2+250,y2+250);
    DDA(x1+250,y1+250,x3+250,y3+250);
    DDA(x3+250,y3+250,x2+250,y2+250);

}


void MainWindow::on_pushButton_5_clicked()
{
    float r;
    r=ui->textEdit_11->toPlainText().toFloat();\

    float radian_angle=r*(0.01745);

    float X1,Y1,X2,Y2,X3,Y3;
    X1=  x1*cos(radian_angle)+y1*sin(radian_angle);
    Y1 = -x1*sin(radian_angle)+y1*cos(radian_angle);
    X2=  x2*cos(radian_angle)+y2*sin(radian_angle);
    Y2 = -x2*sin(radian_angle)+y2*cos(radian_angle);
    X3=  x3*cos(radian_angle)+y3*sin(radian_angle);
    Y3 = -x3*sin(radian_angle)+y3*cos(radian_angle);

    DDA(X1+250,Y1+250,X2+250,Y2+250) ;
    DDA(X2+250,Y2+250,X3+250,Y3+250) ;
    DDA(X3+250,Y3+250,X1+250,Y1+250) ;


}


