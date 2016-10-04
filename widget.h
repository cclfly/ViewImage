#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QLabel>
#include <QScrollBar>
#include <QResizeEvent>
#include <QImageReader>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();
private:
    void Init();
private:
    //窗口大小改变事件
    void resizeEvent(QResizeEvent *event);
private:
    QImageReader img;       //图片本体
    QLabel *labImg;         //放图片的label
    QSize imgConstSize;     //图片的原始大小
    double imgSlope;        //图片高宽比
    QRect imgRect;          //图片显示的位置大小
    QMovie *mv;             //图片动画本体如gif

    double imgMagn;         //图片放大倍数

    // //缩略图窗口
};

#endif // WIDGET_H
