#include "widget.h"
#include "ui_widget.h"
#include "draw.h"
#include <QThread>
#include <QPainter>
#include <QPaintEvent>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    resize(600,600);//画布的大小
    Draw * draw = new Draw();
    QThread * thread = new QThread();
    draw->moveToThread(thread);

    thread->start();
    connect(ui->pushButton,&QPushButton::clicked,draw,&Draw::drawPic);

    connect(draw,&Draw::drawDone,this,[=](QImage img){
        m_img = img; //成员变量来接收img
        update();
 });
       //关闭
    connect(this,&Widget::destroyed,[=](){
        thread->quit();
        thread->wait();
        delete draw;
 });


}
void Widget::paintEvent(QPaintEvent*)
{
    QPainter painter(this);
    painter.drawImage(0,0,m_img);
}

Widget::~Widget()
{
    delete ui;
}
