#include "widget.h"
#include <QApplication>
#include <QPixmap>
#include <QImage>
#include <QMovie>
#include <QDesktopWidget>

Widget::Widget(QWidget *parent)
    : QWidget(parent), mv(NULL)
{
    //setWindowFlags(Qt::FramelessWindowHint);
    Init();
}

Widget::~Widget()
{
    if(mv)
    {
        mv->stop();
        delete mv;
    }
    delete labImg;
}

void Widget::Init()
{
    labImg = new QLabel(this);

    QString imgPath = QApplication::arguments()[1];
    img.setFileName(imgPath);
    imgConstSize = img.size();
    imgSlope = imgConstSize.height()*1.0/imgConstSize.width();

    QRect scRect = QApplication::desktop()->screenGeometry();
    QSize widSize = scRect.size()/3;
    setGeometry(widSize.width(),widSize.height(),widSize.width(),widSize.height());

    if(widSize.height()*1.0/widSize.width()<imgSlope)
    {
        imgMagn = widSize.height()*1.0/imgConstSize.height();
        imgRect.setSize(imgConstSize*imgMagn);
        imgRect.setY((width()-imgRect.width())/2);
    }
    else
    {
        imgMagn = widSize.width()*1.0/imgConstSize.width();
        imgRect.setSize(imgConstSize*imgMagn);
        imgRect.setX((height()-imgRect.height())/2);
    }

    labImg->setPixmap(QPixmap::fromImage(img.read()));
    labImg->setScaledContents(true);
    labImg->setGeometry(imgRect);

    //判断是不是动图
    if(img.supportsAnimation())
    {
        mv = new QMovie(imgPath);
        mv->start();
        labImg->setMovie(mv);
    }
}

void Widget::resizeEvent(QResizeEvent *event)
{
    QSize newSize = event->size();

    if(newSize.height()*1.0/newSize.width()>imgSlope)
    {
        imgMagn = newSize.width()*1.0/imgConstSize.width();
        imgRect = QRect(QPoint(0,(newSize.height()-imgRect.height())/2),imgMagn*imgConstSize);
    }
    else
    {
        imgMagn = newSize.height()*1.0/imgConstSize.height();
        imgRect = QRect(QPoint((newSize.width()-imgRect.width())/2,0),imgMagn*imgConstSize);
    }

    labImg->setGeometry(imgRect);
}
