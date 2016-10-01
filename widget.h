#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QLabel>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();
private:
    QLabel *labImg;         //放图片的label
    QSize imgSize;          //图片的大小
    QString imgExt;         //图片的扩展名
    QMovie *mv;              //图片本体包括gif
};

#endif // WIDGET_H
