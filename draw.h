#ifndef DRAW_H
#define DRAW_H

#include <QObject>
#include <QImage>

class Draw : public QObject
{
    Q_OBJECT
public:
    explicit Draw(QObject *parent = nullptr);

signals:
    void drawDone(QImage img);

public slots:
    void drawPic();
};

#endif // DRAW_H
