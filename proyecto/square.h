#ifndef CUADRADO_H
#define CUADRADO_H
#include <QGraphicsRectItem>
#include <QBrush>
#include <string>
#include "piece.h"
#include "movimientos.h"

class Piece;
class cuadrado:public QGraphicsRectItem
{
public:
    cuadrado(QGraphicsItem *parent=0) ;
    void ubicacion(Piece *piece);
    void ubicacion2(Movimientos *itemm);
    /**
     * @brief setColor Establece el color del cuadrado del tablero
     * @param color El color propiamente dicho del tablero
     */
    void setColor(QColor color);
    /**
     * @brief setOriginalColor
     * @param value
     */
    void setOriginalColor(QColor value);
    /**
     * @brief setText
     * @param _texto
     */
    void setText(std::string _texto);
    Piece *getVecino(int fil, int col);
    void MarcarCuadrado(cuadrado *box, int filaB, int columnaB);
    void estaOcupado(bool value, Piece *piece=0);
    void setColorP(QString value);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void clearBoxes();
    void MoverFicha();
    void Matar();
    void sacarDeLista(Piece *a);
    bool isEmpty();
    Piece* cambiarPeon(Piece *piece);
    int fila;
    int columna;
    Piece *piezaa;
    Movimientos *item;
    QString *eleccion;
    bool estado;
private:
    QString piezaColor;
    bool ocupado;
    std::string texto;
    QColor color;
    QString color_nombre;
    QBrush brush;
    QColor originalColor;

};

#endif // CUADRADO_H
