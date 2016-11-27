/*!
 * \file imageview.h
 * \brief image display
 * 图片查看部件
 * \author cclfly
 * \date 2016-11-28
 * \version 0.1
 */

#ifndef IMAGEVIEW_H
#define IMAGEVIEW_H

#include <QWidget>

/*!
 * \file imageview.h
 * \brief The ImageView class
 * 显示图片主体的控件
 * \extends QWidget
 */
class ImageView : public QWidget
{
    Q_OBJECT
public:
    explicit ImageView(QWidget *parent = 0);

signals:

public slots:
};

#endif // IMAGEVIEW_H
