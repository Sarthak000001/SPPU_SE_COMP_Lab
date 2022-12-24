#include "mainwindow.h"
#include "ui_mainwindow.h"
//#include<cstdlib>
//#include "math.h"
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

void MainWindow::DDA(float x1,float y1,float x2,float y2)
{
    float xinc,yinc,dx,dy,length,x,y,i;
    dx=x2-x1;
    dy=y2-y1;
    if(abs(dx)>=abs(dy)){
        length=abs(dx);
    }
    else {
        length=abs(dy);
    }
    xinc=dx/length;
    yinc=dy/length;
    x=x1;
    y=y1;
    i=0;
    while(i<length){
        img.setPixel(x,y,qRgb(255,255,255));
        x=x+xinc;
        y=y+yinc;
        i++;
    }
}

void MainWindow::circle(float h,float k,float r)
{
float x=0;
float y=r;
float d=3-(2*r);
while(x<y){
    img.setPixel(h+x,k+y,qRgb(255,255,255));
    img.setPixel(h-x,k+y,qRgb(255,255,255));
    img.setPixel(h+x,k-y,qRgb(255,255,255));
    img.setPixel(h-x,k-y,qRgb(255,255,255));
    img.setPixel(h+y,k+x,qRgb(255,255,255));
    img.setPixel(h-y,k+x,qRgb(255,255,255));
    img.setPixel(h+y,k-x,qRgb(255,255,255));
    img.setPixel(h-y,k-x,qRgb(255,255,255));
x+=1;
if(d>=0){
    d+=4*(x-y)+10;
    y=y-1;
}
else{
    d+=4*(x)+6;
}
}
}
void MainWindow::on_pushButton_clicked()
{
 float x1,y1,l,b;
 x1=ui->textEdit->toPlainText().toFloat();
 y1=ui->textEdit_2->toPlainText().toFloat();
 l=ui->textEdit_3->toPlainText().toFloat();
 b=ui->textEdit_4->toPlainText().toFloat();
 DDA(x1,y1,x1,y1+l);
 DDA(x1,y1,x1+b,y1);
 DDA(x1+b,y1,x1+b,y1+l);
 DDA(x1+b,y1+l,x1,y1+l);
 ui->label->setPixmap(QPixmap::fromImage(img));
}


void MainWindow::on_pushButton_2_clicked()
{
    float x1, y1,l,b ;

       x1=ui->textEdit->toPlainText().toFloat();
       y1=ui->textEdit_2->toPlainText().toFloat();
       l=ui->textEdit_3->toPlainText().toFloat();
       b=ui->textEdit_4->toPlainText().toFloat();
       /*DDA(x1,y1+b/2,x1+l/2,y1);
        DDA(x1,y1+b/2,x1+l/2,y1+b);
        DDA(x1+l/2,y1+b,x1+l,y1+b/2);
          DDA(x1+l/2,y1,x1+l,y1+b/2);*/
      DDA(x1+l/2,y1,x1+l,y1+b/2);
      DDA(x1+l/2,y1,x1,y1+b/2);
      DDA(x1,y1+b/2,x1+l/2,y1+b);
      DDA(x1+l,y1+b/2,x1+l/2,y1+b);
      ui->label->setPixmap(QPixmap::fromImage(img));
}


void MainWindow::on_pushButton_3_clicked()
{
    float x1, y1,l,b ;
      x1=ui->textEdit->toPlainText().toFloat();
      y1=ui->textEdit_2->toPlainText().toFloat();
      l=ui->textEdit_3->toPlainText().toFloat();
      b=ui->textEdit_4->toPlainText().toFloat();
//      circle((x1+l/2),(y1+b/2),sqrt(((l/2)*(l/2))+((b/2)*(b/2)))/2);
      circle(x1+l/2,y1+b/2,sqrt((l*l)+(b*b))/4);
 ui->label->setPixmap(QPixmap::fromImage(img));
}

