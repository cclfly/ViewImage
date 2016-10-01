#include "widget.h"
#include <QApplication>
#include <QPixmap>
#include <QImage>
#include <QMovie>

Widget::Widget(QWidget *parent)
    : QWidget(parent), labImg(new QLabel(this)), mv(NULL)
{
    QString imgPath = QApplication::arguments()[1];
    QImage img(imgPath);
    imgExt = imgPath.right(imgPath.length()-imgPath.lastIndexOf('.'));
    imgSize = img.size();
    labImg->setPixmap(QPixmap::fromImage(img));
    labImg->setScaledContents(true);
    labImg->resize(imgSize*0.5);

    mv = new QMovie(imgPath);
    mv->start();
    labImg->setMovie(mv);
}

Widget::~Widget()
{
    delete labImg;
}
