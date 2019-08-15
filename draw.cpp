#include "draw.h"
#include <QPainter>
#include<QImage>


Draw::Draw(QObject *parent) : QObject(parent)
{

}
void Draw::drawPic()
{
    QImage img(600,600,QImage::Format_RGB32);
    QPainter painter(&img);
    //设置平笔、填充颜色
    painter.setPen(QPen(Qt::green));
    painter.setBrush(Qt::blue);
    //设置随机点
    QPoint points[]=
    {
    QPoint(qrand()%550,qrand()%550),
    QPoint(qrand()%550,qrand()%550),
    QPoint(qrand()%550,qrand()%550),
    QPoint(qrand()%550,qrand()%550),
    QPoint(qrand()%550,qrand()%550),
    QPoint(qrand()%550,qrand()%550),
    QPoint(qrand()%550,qrand()%550),
    QPoint(qrand()%550,qrand()%550),
    };
    //画多边形
    painter.drawPolygon(points,8);
    //发送多边形
    emit drawDone(img);//send
}
