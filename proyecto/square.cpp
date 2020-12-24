#include "square.h"
#include <QDebug>
#include <QMessageBox>
#include "mainwindow.h"
#include "board.h"
#include "piece.h"
#include "pawn.h"
#include "tower.h"
#include "bishop.h"
#include "queen.h"
#include "horse.h"
#include <string>
#include "movimientos.h"
#include "./ui_elejirficha.h"
#include "choose.h"
#include "./ui_winnerdialog.h"
#include "winnerdialog.h"
extern MainWindow *mainwindow;

cuadrado::cuadrado(QGraphicsItem *parent) :QGraphicsRectItem(parent)
{
     setRect(0,0,70,70);
     brush.setStyle(Qt::SolidPattern);
     setZValue(-1);
     setColorP("NONE");
     estaOcupado(false);
     piezaa =  NULL;
     item = NULL;
     estado = false;
     mainwindow->setText("ERIKADASDA");
     eleccion = new QString("GAB");

}

void cuadrado::setColor(QColor color)
{
    brush.setColor(color);
    setBrush(color);
}
void cuadrado::setOriginalColor(QColor value)
{
    originalColor = value;
    setColor(originalColor);
}

void cuadrado::setText(std::string _texto){
    texto = _texto;
}

void cuadrado::ubicacion(Piece *piece){

    if(piece->ficha == "peon" && (fila == 0 || fila == 7)){
            piece = cambiarPeon(piece);
    }
    piece->setPos(x()+35 -piece->pixmap().width()/2  ,y()+30- piece->pixmap().width()/2 );

    piece->setCuadrado(this);
    estaOcupado(true,piece);
    piezaa = piece;
    estado = true;
}


void cuadrado::ubicacion2(Movimientos *itemm){



        itemm->setPos(x()+35 -itemm->pixmap().width()/2  ,y()+30- itemm->pixmap().width()/2 );
        item = itemm;

}

void cuadrado::estaOcupado(bool value, Piece *piece)
{
    ocupado = value;
    if(value)
        setColorP(piece->getColor());
    else
        setColorP("NONE");
}
void cuadrado::setColorP(QString value)
{
    piezaColor = value;
}
Piece *cuadrado::getVecino(int fil, int col){
    if(col<8 && col>=0 && fil>=0 && fil<8){
        return mainwindow->collection[fil][col]->piezaa;
    }else
        return NULL;
}
void cuadrado::mousePressEvent(QGraphicsSceneMouseEvent *event){
    int columnaB, filaB;


    if((piezaa != NULL && mainwindow->turno == piezaa->getColor())|| item != NULL){
        if(mainwindow->piezaSeleccionada == NULL){
            clearBoxes();
            QList<Coordenada> opciones;
            if(estado){
                mainwindow->piezaSeleccionada = piezaa;
                opciones = piezaa->movimientos();
                for(int i = 0; i < opciones.size(); ++i){
                  columnaB = opciones.at(i).col;
                  filaB = opciones.at(i).fil;
                  cuadrado *box =mainwindow->collection[filaB][columnaB];
                  if (box->item == NULL){

                      MarcarCuadrado(box,filaB,columnaB);
                  }
                }
              }
            }else{
                if(item !=NULL){
                    if(piezaa !=NULL){
                        Matar();
                    }else
                        MoverFicha();
                }else{
                    clearBoxes();
                    if(piezaa !=NULL){
                        mainwindow->piezaSeleccionada = NULL;
                        mousePressEvent(event);
                        return;
                    }else{
                        return;
                    }
                }
            }

    }


}
bool cuadrado::isEmpty(){
    return estado;
}

void cuadrado::clearBoxes(){
    for (int i = 0; i < 8 ; i++){
        for (int j = 0; j < 8 ; j++){
            Movimientos *tempPosible = mainwindow->collection[i][j]->item;
            if(mainwindow->collection[i][j]->item != NULL){
                mainwindow->collection[i][j]->item = NULL;
                delete (tempPosible);
            }
        }
    }
}
void cuadrado::MarcarCuadrado(cuadrado *box, int filaB, int columnaB){
    if((box->piezaa != NULL && box->piezaa->getColor()==mainwindow->turno)){
        return;
    }
   Movimientos *option = new Movimientos(1);
    box->ubicacion2(option);
    mainwindow->addScene(option);
}
void cuadrado::Matar(){
    if(piezaa->ficha == "rey"){
        WinnerDialog guiR;
        guiR.setModal(true);
        if(piezaa->getColor()=="WHITE")
            guiR.printWinner("GANASTEEEEE N!!!");
        else
            guiR.printWinner("GANASTEEEE B!!!");
        guiR.exec();
        exit(1);
    }
    Piece *a =mainwindow->collection[fila][columna]->piezaa;
    if(a->getColor()=="WHITE")
        mainwindow->chess->white.removeOne(a);
    else
        mainwindow->chess->black.removeOne(a);
    mainwindow->collection[fila][columna]->piezaa = mainwindow->piezaSeleccionada;

    mainwindow->PiezaEliminada(a);

    mainwindow->piezaSeleccionada->getCuadrado()->estado = false;
    mainwindow->piezaSeleccionada->getCuadrado()->piezaa = NULL;

    mainwindow->collection[fila][columna]->ubicacion(piezaa);
    mainwindow->piezaSeleccionada = NULL;
    clearBoxes();

    if(piezaa->getColor() == "WHITE"){
        mainwindow->turno = &mainwindow->turnoB;
    }else{
        mainwindow->turno = &mainwindow->turnoA;
    }
    mainwindow->verificarJaque();

}
void cuadrado::MoverFicha(){
    cuadrado *boxTmp = mainwindow->piezaSeleccionada->getCuadrado();
    piezaa = mainwindow->piezaSeleccionada;
    mainwindow->collection[fila][columna]->ubicacion(piezaa);

    boxTmp->estado = false;
    boxTmp->piezaa=nullptr;

    Movimientos *tempPosible = mainwindow->collection[fila][columna]->item;
    mainwindow->collection[fila][columna]->item = nullptr;
    clearBoxes();
    delete(tempPosible);
    mainwindow->piezaSeleccionada = nullptr;
    if(piezaa->getColor() == "WHITE"){
        mainwindow->turno = &mainwindow->turnoB;
    }else{
        mainwindow->turno = &mainwindow->turnoA;
    }
    mainwindow->verificarJaque();

}
Piece* cuadrado::cambiarPeon(Piece *piece){
    elejirficha guiR;
    guiR.setModal(true);
    guiR.setEleccion(eleccion);
    guiR.exec();
    if(mainwindow->piezaSeleccionada->getColor()=="WHITE"){
        Piece *a =piece;
        piece = NULL;
        if(*eleccion == "torre"){
            piece = new torre("WHITE");
            piece->ficha ="torre";
        }else if(*eleccion =="reina"){
            piece = new reina("WHITE");
            piece->ficha ="reina";
        }else if(*eleccion=="alfil"){
            piece = new alfil("WHITE");
            piece->ficha ="alfil";
        }else if(*eleccion =="caballo"){
            piece = new caballo("WHITE");
            piece->ficha ="caballo";
        }
        mainwindow->addScene(piece);
        mainwindow->chess->white.append(piece);
        mainwindow->chess->white.removeOne(a);
        delete(a);
    }else {

        Piece *a =piece;
        if(*eleccion == "torre"){
            piece = new torre("BLACK");
            piece->ficha ="torre";
        }else if(*eleccion =="reina"){
            piece = new reina("BLACK");
            piece->ficha ="reina";
        }else if(*eleccion=="alfil"){
            piece = new alfil("BLACK");
            piece->ficha ="alfil";
        }else if(*eleccion =="caballo"){
            piece = new caballo("BLACK");
            piece->ficha ="caballo";
        }
        mainwindow->addScene(piece);
        mainwindow->chess->black.append(piece);
        mainwindow->chess->black.removeOne(a);
        delete(a);
    }
    return piece;
}

