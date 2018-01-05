#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QTimer>
#include <QDialog>
#include <QMouseEvent>
#include <QPainter>
#include <QPixmap>
#include <QPoint>
#include <QtGlobal>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QTimer *p_timer;
    QTimer *p_win;
    QPixmap pix;
    QPixmap tempPix;
    QPoint cirPoint;
    QPoint cirPoint1;
    QPoint cirPoint2;
    QPoint cirPoint3;
    QPoint cirPoint4;
    QPoint cirPoint5;
    QPoint cirPoint6;
    QPoint cirPoint7;
    QPoint cirPoint8;
    QPoint cirPoint9;
    QPoint cirPoint10;
    bool isDraw;
    int cir_R;
    int color;

    int win_H;
    int win_W;
    int count;

    void Draw_Circle();
    QPoint offset;

private slots:
    void Draw_Timer();
    void Win_Timer();

protected:
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *event);
    void mouseDoubleClickEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

};

#endif // MAINWINDOW_H
