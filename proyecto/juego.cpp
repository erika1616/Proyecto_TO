#include "juego.h"
#include <QPixmap>

Juego::Juego(QWidget *parent):QGraphicsView(parent)
{
    gameScene = new QGraphicsScene();
    gameScene->setSceneRect(0,0,1400,700);
    setFixedSize(1400,900);//1400
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setScene(gameScene);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::black);
    setBackgroundBrush(brush);

}

