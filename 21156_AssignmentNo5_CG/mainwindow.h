#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QRgb val = qRgb(255,0,255);
    void dda(float,float,float,float,QRgb val);
   void mousePressEvent(QMouseEvent *event);
    int code(int,int);
    void cohen(int,int,int,int);
    int ver;
    bool start;
    bool flag;
    bool line;
    int a[100],b[100];
private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
