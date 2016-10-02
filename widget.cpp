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
    img = new QImage(imgPath);
    imgExt = imgPath.right(imgPath.length()-imgPath.lastIndexOf('.'));
    imgConstSize = img->size();
    imgSize = imgConstSize*0.5;
    labImg->setPixmap(QPixmap::fromImage(*img));
    labImg->setScaledContents(true);
    labImg->resize(imgSize);

    //这里应该判断，，但是算了
    //if(imgExt==".gif"){
    mv = new QMovie(imgPath);
    mv->start();
    labImg->setMovie(mv);
    //}
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
    double slope = imgConstSize.height()*1.0/imgConstSize.width();

    if(newSize.height()*1.0/newSize.width()>slope)
    {
        imgMagn = newSize.width()*1.0/imgConstSize.width();
        imgSize = imgMagn*imgConstSize;
        imgPot = QPoint(0,(newSize.height()-imgSize.height())/2);
    }
    else
    {
        imgMagn = newSize.height()*1.0/imgConstSize.height();
        imgSize = imgMagn*imgConstSize;
        imgPot = QPoint((newSize.width()-imgSize.width())/2,0);
    }

    labImg->setGeometry(QRect(imgPot,imgSize));
}
