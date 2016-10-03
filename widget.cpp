#include "widget.h"
#include <QApplication>
#include <QPixmap>
#include <QImage>
#include <QMovie>

Widget::Widget(QWidget *parent)
    : QWidget(parent), mv(NULL), imgMagn(0.5)
{
    labImg = new QLabel(this);

    QString imgPath = QApplication::arguments()[1];
    img.setFileName(imgPath);

    imgConstSize = img.size();
    imgRect.setSize(imgConstSize*0.5);
    imgSlope = imgConstSize.height()*1.0/imgConstSize.width();

    labImg->setPixmap(QPixmap::fromImage(img.read()));
    labImg->setScaledContents(true);
    labImg->resize(imgRect.size());

    //判断是不是动图
    if(img.supportsAnimation())
    {
        mv = new QMovie(imgPath);
        mv->start();
        labImg->setMovie(mv);
    }
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
#include <QDebug>
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
        imgRect =QRect(QPoint((newSize.width()-imgRect.width())/2,0),imgMagn*imgConstSize);
    }

    labImg->setGeometry(imgRect);
}
