#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "QMouseEvent"
#include "QColorDialog"
#include <QTime>
using namespace std;
//#include "ui_mainwindow.h"
//#include "math.h"

//object
static QImage img(500,500,QImage::Format_RGB888);
static QColor color;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ver = 0; //initializing
    start = true;

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mousePressEvent(QMouseEvent *ev)
{
      if(start){
          int p = ev->pos().x(); //storing x
          int q = ev->pos().y(); //storing y
          a[ver] = p; //storing that x into array a
          b[ver] = q;  //storing that y into array b
          if(ev->button() == Qt::RightButton ){
              dda(a[ver-1],b[ver-1],a[0],b[0]);
              start = false;
          }
          else{
              if(ver > 0){
                  dda(a[ver],b[ver],a[ver-1],b[ver-1]);
              }
          }
          ver++;
      }

}



void MainWindow::dda(int x1, int y1, int x2, int y2)
{
    double x,y,dx,dy,len,xin,yin;
    x=x1;
    y=y1;
    dx = x2 -x1;
    dy = y2 - y1;
    img.setPixel(x,y,color.rgb());
    if(abs(dx) > abs(dy)){
        len = abs(dx);
    }
    else{
        len = abs(dy);
    }
    xin = dx/len;
    yin = dy/len;

    int i = 0;
    while(i <= len){
        x += xin;
        y += yin;
        img.setPixel(x,y,color.rgb());

        i++;
    }
    ui->label->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::scanfill()
{
    int ymin = 500000;
    int ymax = 0;
    for(int i=0;i < ver ;i++){
        if(b[i] < ymin){
            ymin = b[i]; //finding ymin from array
        }
        if(b[i] > ymax){
            ymax = b[i]; //finding ymax from the array
        }
    }
    a[ver] = a[0]; //copying the first ele. to last position
    b[ver] = b[0];
    for(int i=0;i < ver ;i++){
        float dx = a[i+1]-a[i];
        float dy = b[i+1]-b[i];
        if(dx == 0.0){slope[i] = 0.0;}
        if(dy == 0.0){slope[i] = 1.0;}
        if(dx!=0.0 && dy!=0.0){
            slope[i] =(float) dx/(float) dy;
        }
    }

    for(int i=ymin;i<=ymax;i++){
        int k = 0;
        for(int j=0;j < ver;j++){
            if(b[j] > i && b[j+1] <= i || b[j+1] > i && b[j] <=i){
                xi[k++] = (int)(a[j]+slope[j]*(i - b[j]));
            }
        }
        //bubble sort
        for(int f=0;f<k-1;f++){
            bool flag = true;
            for(int g = 0; g < k-f-1;g++){
                if(xi[g] > xi[g+1]){
                    int tmp = xi[g];
                    xi[g] = xi[g+1];
                    xi[g+1] = tmp;
                    flag = false;
                }
            }
           if(flag) break;
        }
        for(int z = 0;z < k;z+=2){
            dda(xi[z],i,xi[z+1],i);
            delay(10);
        }
    }
}



void MainWindow::mouseDoubleClickEvent(QMouseEvent *event)
{
    scanfill();
}
void MainWindow::on_pushButton_clicked()
{
    color = QColorDialog :: getColor(); //used for to select the color
}


void Delay::delay(int millisecondsToWait)
{
    QTime dieTime = QTime::currentTime().addMSecs(millisecondsToWait);
    while(QTime::currentTime() < dieTime)
    {
        QCoreApplication::processEvents(QEventLoop::AllEvents,100);
    }
}
