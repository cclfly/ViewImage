#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QLabel>
#include <QScrollBar>
#include <QResizeEvent>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();
private:
    //窗口大小改变事件
    void resizeEvent(QResizeEvent *event);
private:
    QImage *img;            //图片本体
    QLabel *labImg;         //放图片的label
    QSize imgConstSize;     //图片的原始大小
    QPoint imgPot;          //图片在窗口中的位置
    QSize imgSize;          //图片显示大小
    QString imgExt;         //图片的扩展名
    QMovie *mv;             //图片动画本体如gif

    double imgMagn;         //图片放大倍数

    // //缩略图窗口
};

#endif // WIDGET_H
