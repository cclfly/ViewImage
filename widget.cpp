#include "widget.h"
#include <QApplication>
#include <QPixmap>
#include <QImage>

Widget::Widget(QWidget *parent)
    : QWidget(parent), labImg(new QLabel(this))
{
    QString imgPath = QApplication::arguments()[1];
    QImage img(imgPath);
    imgSize=img.size();
    labImg->setPixmap(QPixmap::fromImage(img));
    labImg->setScaledContents(true);
    labImg->resize(imgSize*0.5);
}

Widget::~Widget()
{

}
