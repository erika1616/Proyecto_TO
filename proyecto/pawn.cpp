#include "pawn.h"
#include "mainwindow.h"
#include <QDebug>
#include "eje.h"
extern MainWindow * mainwindow;
Peon::Peon(QString team,QGraphicsItem *parent):Piece(team,parent)
{
    setFigura();
}

void Peon::setFigura(){
    ;
    if(color == "WHITE"){
        this->setPixmap(QPixmap("://images/png_48/peon1.png"));


    }else
        setPixmap(QPixmap("://images/png_48/peon.png"));
}
QList<Coordenada> Peon::movimientos(){
    QList<Coordenada> opciones;


    if(this->getColor()=="BLACK"){

        if(getCuadrado()->getVecino(getCuadrado()->fila+1,getCuadrado()->columna) == NULL &&
                getCuadrado()->getVecino(getCuadrado()->fila+1,getCuadrado()->columna+1) == NULL &&
                getCuadrado()->getVecino(getCuadrado()->fila+1,getCuadrado()->columna-1) == NULL ){


            if(getCuadrado()->fila == 1){
                opciones.append(Coordenada(this->getCuadrado()->columna,this->getCuadrado()->fila+1));
                if(getCuadrado()->getVecino(getCuadrado()->fila+2,getCuadrado()->columna)==NULL){

                    opciones.append(Coordenada(this->getCuadrado()->columna,this->getCuadrado()->fila+2));
                }
            }else{

                opciones.append(Coordenada(this->getCuadrado()->columna,this->getCuadrado()->fila+1));
            }

        }else{

           if(getCuadrado()->getVecino(getCuadrado()->fila+1,getCuadrado()->columna+1) != NULL && getCuadrado()->getVecino(getCuadrado()->fila+1,getCuadrado()->columna+1)->getColor() != getColor()){//derecha está vacio
               opciones.append(Coordenada(this->getCuadrado()->columna+1,this->getCuadrado()->fila+1));
           }
           if(getCuadrado()->getVecino(getCuadrado()->fila+1,getCuadrado()->columna-1) != NULL && getCuadrado()->getVecino(getCuadrado()->fila+1,getCuadrado()->columna-1)->getColor() != getColor()){//derecha está vacio
               opciones.append(Coordenada(this->getCuadrado()->columna-1,this->getCuadrado()->fila+1));
           }
           if(getCuadrado()->getVecino(getCuadrado()->fila+1,getCuadrado()->columna) == NULL){
               opciones.append(Coordenada(this->getCuadrado()->columna,this->getCuadrado()->fila+1));
           }
           if(getCuadrado()->getVecino(getCuadrado()->fila+1,getCuadrado()->columna) == NULL &&
                   getCuadrado()->fila == 1 &&
                   getCuadrado()->getVecino(getCuadrado()->fila+2,getCuadrado()->columna)==NULL){
               opciones.append(Coordenada(this->getCuadrado()->columna,this->getCuadrado()->fila+2));
           }

        }

    }else{

        if(getCuadrado()->getVecino(getCuadrado()->fila-1,getCuadrado()->columna) == NULL &&
                getCuadrado()->getVecino(getCuadrado()->fila-1,getCuadrado()->columna+1) == NULL &&
                getCuadrado()->getVecino(getCuadrado()->fila-1,getCuadrado()->columna-1) == NULL ){


            if(getCuadrado()->fila == 6){
                opciones.append(Coordenada(this->getCuadrado()->columna,this->getCuadrado()->fila-1));
                if(getCuadrado()->getVecino(getCuadrado()->fila-2,getCuadrado()->columna)==NULL){

                    opciones.append(Coordenada(this->getCuadrado()->columna,this->getCuadrado()->fila-2));
                }
            }else{

                opciones.append(Coordenada(this->getCuadrado()->columna,this->getCuadrado()->fila-1));
            }

        }else{

           if(getCuadrado()->getVecino(getCuadrado()->fila-1,getCuadrado()->columna+1) != NULL && getCuadrado()->getVecino(getCuadrado()->fila-1,getCuadrado()->columna+1)->getColor() != getColor()){
               opciones.append(Coordenada(this->getCuadrado()->columna+1,this->getCuadrado()->fila-1));
           }
           if(getCuadrado()->getVecino(getCuadrado()->fila-1,getCuadrado()->columna-1) != NULL && getCuadrado()->getVecino(getCuadrado()->fila-1,getCuadrado()->columna-1)->getColor() != getColor()){
               opciones.append(Coordenada(this->getCuadrado()->columna-1,this->getCuadrado()->fila-1));
           }
           if(getCuadrado()->getVecino(getCuadrado()->fila-1,getCuadrado()->columna) == NULL){
               opciones.append(Coordenada(this->getCuadrado()->columna,this->getCuadrado()->fila-1));
           }
           if(getCuadrado()->getVecino(getCuadrado()->fila-1,getCuadrado()->columna) == NULL &&
                   getCuadrado()->fila == 1 &&
                   getCuadrado()->getVecino(getCuadrado()->fila-2,getCuadrado()->columna)==NULL){
               opciones.append(Coordenada(this->getCuadrado()->columna,this->getCuadrado()->fila-2));
           }

        }

    }
    return opciones;

}
