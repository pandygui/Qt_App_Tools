#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QMouseEvent>

#define DRAW_CIR_Timer 10       //定时器触发时间



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->window()->showFullScreen();
    isDraw = 0;
    count = 0;
//    resize(500,500);
//    pix = QPixmap(500,500);
//    pix.fill(Qt::white);
    QCursor cursor;
    cursor.setShape(Qt::OpenHandCursor);
    setCursor(cursor);

    p_timer = new QTimer();
    connect(p_timer,SIGNAL(timeout()),this,SLOT(Draw_Timer()));//连接信号到槽
    p_timer->start(DRAW_CIR_Timer);

    p_win = new QTimer();
    connect(p_win,SIGNAL(timeout()),this,SLOT(Win_Timer()));
    p_win->start(1);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Win_Timer()
{
    win_H = MainWindow::height();
    win_W = MainWindow::width();
    resize(win_W,win_H);
    pix = QPixmap(win_W,win_H);
    pix.fill(Qt::white);
    //update();
}

void MainWindow::Draw_Timer()
{
    count++;
    //qDebug()<<"Draw_Timer";
    cir_R = qrand()%300 + 100;
    cirPoint.setX(qrand()%win_W-cir_R/2);
    cirPoint.setY(qrand()%win_H-cir_R/2);
    cirPoint1.setX(qrand()%win_W-cir_R/2);
    cirPoint1.setY(qrand()%win_H-cir_R/2);
    cirPoint2.setX(qrand()%win_W-cir_R/2);
    cirPoint2.setY(qrand()%win_H-cir_R/2);
    cirPoint3.setX(qrand()%win_W-cir_R/2);
    cirPoint3.setY(qrand()%win_H-cir_R/2);
    cirPoint4.setX(qrand()%win_W-cir_R/2);
    cirPoint4.setY(qrand()%win_H-cir_R/2);
    cirPoint5.setX(qrand()%win_W-cir_R/2);
    cirPoint5.setY(qrand()%win_H-cir_R/2);
    cirPoint6.setX(qrand()%win_W-cir_R/2);
    cirPoint6.setY(qrand()%win_H-cir_R/2);
    cirPoint7.setX(qrand()%win_W-cir_R/2);
    cirPoint7.setY(qrand()%win_H-cir_R/2);
    cirPoint8.setX(qrand()%win_W-cir_R/2);
    cirPoint8.setY(qrand()%win_H-cir_R/2);
    cirPoint9.setX(qrand()%win_W-cir_R/2);
    cirPoint9.setY(qrand()%win_H-cir_R/2);
    cirPoint10.setX(qrand()%win_W-cir_R/2);
    cirPoint10.setY(qrand()%win_H-cir_R/2);
    color = qrand()%10;
    //qDebug()<<"cirPoint.X : "<<cirPoint.x();
    //qDebug()<<"cirPoint.Y : "<<cirPoint.y();
    //qDebug()<<"cir_R : "<<cir_R;
    if(count%2 == 0)
    {
        if(count > 10000) count = 0;
        isDraw = 1;
    }
    else
    {
        isDraw = 0;
    }
    update();
}

void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter paint(this);
    if(isDraw)
    {
        tempPix = pix;
        QPainter pp(&tempPix);
        color = qrand()%100;
        if(color < 20)
        {
            pp.setPen(QPen(Qt::red,qrand()%50+10,Qt::SolidLine));
        }
        else if(color < 40)
        {
            pp.setPen(QPen(Qt::green,qrand()%50+10,Qt::SolidLine));
        }
        else if(color < 60)
        {
            pp.setPen(QPen(Qt::yellow,qrand()%50+10,Qt::SolidLine));
        }
        else if(color < 80)
        {
            pp.setPen(QPen(Qt::blue,qrand()%50+10,Qt::SolidLine));
        }
        else
        {
            pp.setPen(QPen(Qt::black,qrand()%50+10,Qt::SolidLine));
        }
        pp.drawEllipse(cirPoint.x(),cirPoint.y(),cir_R,cir_R);
        paint.drawPixmap(0,0,tempPix);
        pp.drawEllipse(cirPoint1.x(),cirPoint1.y(),cir_R*2,cir_R*2);
        paint.drawPixmap(0,0,tempPix);
        pp.drawEllipse(cirPoint2.x(),cirPoint2.y(),cir_R,cir_R);
        paint.drawPixmap(0,0,tempPix);
        pp.drawEllipse(cirPoint3.x(),cirPoint3.y(),cir_R*2,cir_R*2);
        paint.drawPixmap(0,0,tempPix);
        pp.drawEllipse(cirPoint4.x(),cirPoint4.y(),cir_R,cir_R);
        paint.drawPixmap(0,0,tempPix);
        pp.drawEllipse(cirPoint5.x(),cirPoint5.y(),cir_R*2,cir_R*2);
        paint.drawPixmap(0,0,tempPix);
        pp.drawEllipse(cirPoint6.x(),cirPoint6.y(),cir_R*2,cir_R*2);
        paint.drawPixmap(0,0,tempPix);
        pp.drawEllipse(cirPoint7.x(),cirPoint7.y(),cir_R,cir_R);
        paint.drawPixmap(0,0,tempPix);
        pp.drawEllipse(cirPoint8.x(),cirPoint8.y(),cir_R*2,cir_R*2);
        paint.drawPixmap(0,0,tempPix);
        pp.drawEllipse(cirPoint9.x(),cirPoint9.y(),cir_R,cir_R);
        paint.drawPixmap(0,0,tempPix);
        pp.drawEllipse(cirPoint10.x(),cirPoint10.y(),cir_R*2,cir_R*2);
        paint.drawPixmap(0,0,tempPix);
    }
    else
    {
        if(count >2)
        {
            pix = tempPix;
        }
        QPainter pp(&pix);
        if(qrand()%10 > 5)
        {
            pp.setPen(QPen(Qt::gray,qrand()%50+10,Qt::SolidLine));
        }
        else
        {
            pp.setPen(QPen(Qt::magenta,qrand()%50+10,Qt::SolidLine));
        }
        pp.drawEllipse(cirPoint.x(),cirPoint.y(),cir_R,cir_R);
        paint.drawPixmap(0,0,pix);
        pp.drawEllipse(cirPoint1.x(),cirPoint1.y(),cir_R,cir_R);
        paint.drawPixmap(0,0,pix);
        pp.drawEllipse(cirPoint2.x(),cirPoint2.y(),cir_R,cir_R);
        paint.drawPixmap(0,0,pix);
        pp.drawEllipse(cirPoint3.x(),cirPoint3.y(),cir_R,cir_R);
        paint.drawPixmap(0,0,pix);
        pp.drawEllipse(cirPoint4.x(),cirPoint4.y(),cir_R,cir_R);
        paint.drawPixmap(0,0,pix);
        pp.drawEllipse(cirPoint5.x(),cirPoint5.y(),cir_R,cir_R);
        paint.drawPixmap(0,0,pix);
        pp.drawEllipse(cirPoint6.x(),cirPoint6.y(),cir_R,cir_R);
        paint.drawPixmap(0,0,pix);
        pp.drawEllipse(cirPoint7.x(),cirPoint7.y(),cir_R,cir_R);
        paint.drawPixmap(0,0,pix);
        pp.drawEllipse(cirPoint8.x(),cirPoint8.y(),cir_R,cir_R);
        paint.drawPixmap(0,0,pix);
        pp.drawEllipse(cirPoint9.x(),cirPoint9.y(),cir_R,cir_R);
        paint.drawPixmap(0,0,pix);
        pp.drawEllipse(cirPoint10.x(),cirPoint10.y(),cir_R,cir_R);
        paint.drawPixmap(0,0,pix);
    }
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if(event->button()==Qt::LeftButton)
    {
        QCursor cursor;
        cursor.setShape(Qt::ClosedHandCursor);
        QApplication::setOverrideCursor(cursor);
        offset=event->globalPos()-pos();
    }
}
void MainWindow::mouseReleaseEvent(QMouseEvent *)
{
    QApplication::restoreOverrideCursor();
}

void MainWindow::mouseDoubleClickEvent(QMouseEvent *)
{
    QApplication::exit(0);
}
