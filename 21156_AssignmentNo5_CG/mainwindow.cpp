#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMouseEvent"

static QImage img(500,500,QImage::Format_RGB888);
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    start = true;
    line = 0;
    ver = 0;
    QRgb val = qRgb(60,88,135);
    dda(100,100,100,300,val);
    dda(100,100,300,100,val);
    dda(300,100,300,300,val);
    dda(100,300,300,300,val);
}
int xmin = 100,xmax = 300,ymin = 100,ymax = 300;
int top = 8,bottom = 4,right=2,left=1,inside=0;
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::dda(float x1, float y1, float x2, float y2,QRgb val)
{
    float x,y,dx,dy,len,xin,yin;
    x = x1;
    y = y1;
    dx = x2 - x1;
    dy = y2 - y1;
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
        img.setPixel(x,y,val);
         x+=xin;
         y+=yin;
         i++;
    }
    ui->label->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if(start){
        QRgb val = qRgb(255,0,22);
        int p = event->pos().x();
        int q = event->pos().y();
        a[ver] = p;
        b[ver] = q;
//       if(event->button() == Qt::RightButton){
//            dda(a[ver-1],b[ver-1],a[0],b[0],val);
//                start = false;
//       }
//        else{
//               if(ver > 0){

//                dda(a[ver],b[ver],a[ver-1],b[ver-1],val);
//               }
//            }

//        ver++;
        if(line){
             dda(a[ver],b[ver],a[ver-1],b[ver-1],val);
             line = false;
        }
        else{
           line = true;
        }

        ver++;
    }
}

int MainWindow::code(int x1, int y1)
{
    int c = inside;
    if(x1 < xmin){
        c = c|left;
    }
    else if(x1 > xmax){
        c=c|right;
    }
    if(y1 > ymax){
        c=c|top;
    }
    else if(y1 < ymin){
        c=c|bottom;
    }
    return c;
}

void MainWindow::cohen(int x1, int y1, int x2, int y2)
{
    int code1=code(x1,y1),code2=code(x2,y2);
    int a=x1,b=y1,c=x2,d=y2;
    flag = false;
    bool outside = false;
    while(true){
        if(code1==0 && code2==0){
            flag = true;
            break;
        }
        else if(code1&code2){
            outside = true;
            break;
        }
        else{
            int codeout;
            if(code1 != 0){
                codeout = code1;
            }
            else{
                codeout = code2;
            }
            double x,y;
            if(codeout&top){
                y=ymax;
                x=x1+(double)(((x2-x1)*(ymax-y1))/(y2-y1));
            }
            else if(codeout&bottom){
                y=ymin;
                 x=x1+(double)(((x2-x1)*(ymin-y1))/(y2-y1));
            }
            else if(codeout&left){
                x=xmin;
                y=y1+(double)(((y2-y1)*(xmin-x1))/(x2-x1));
            }
            else if(codeout&right){
                x=xmax;
                y=y1+(double)(((y2-y1)*(xmax-x1))/(x2-x1));
            }
            if(codeout==code1){
                x1=x;
                y1=y;
                code1=code(x1,y1);
            }
            else{
                x2=x;
                y2=y;
                code2=code(x2,y2);
            }
        }
    }
    if(flag){
        QRgb old = qRgb(0,0,0);
        dda(a,b,c,d,old);
        QRgb new1 = qRgb(233,98,10);
        dda(x1,y1,x2,y2,new1);
    }
    if(outside){
        dda(a,b,c,d,qRgb(0,0,0));
    }
}


void MainWindow::on_pushButton_clicked()
{
     for(int i=0; i < ver;i+=2){
         cohen(a[i+1],b[i+1],a[i],b[i]);
     }
//     cohen(a[ver-1],b[ver-1],a[0],b[0]);
//    float x1,y1,x2,y2;
//    x1 = ui->textEdit->toPlainText().toFloat();
//    y1 = ui->textEdit_2->toPlainText().toFloat();
//    x2 = ui->textEdit_3->toPlainText().toFloat();
//    y2 = ui->textEdit_4->toPlainText().toFloat();

//    cohen(x1,y1,x2,y2);
}

void MainWindow::on_pushButton_2_clicked()
{
    float x1,y1,x2,y2;
    QRgb val = qRgb(23,44,234);
    x1 = ui->textEdit->toPlainText().toFloat();
    y1 = ui->textEdit_2->toPlainText().toFloat();
    x2 = ui->textEdit_3->toPlainText().toFloat();
    y2 = ui->textEdit_4->toPlainText().toFloat();


    dda(x1,y1,x2,y2,val);
}
