#include "queen.h"
#include "eje.h"
reina::reina(QString team,QGraphicsItem *parent):Piece(team,parent)
{
    setFigura();
}
void reina::setFigura(){

    if(color == "WHITE"){
        this->setPixmap(QPixmap("://images/png_48/reina1.png"));

    }else
        setPixmap(QPixmap("://images/png_48/reina.png"));
}
QList<Coordenada> reina::movimientos(){
    bool ArribaD = true;
    bool ArribaI = true;
    bool AbajoD = true;
    bool AbajoI = true;
    bool arriba = true;
    bool abajo = true;
    bool derecha = true;
    bool izquierda = true;
    QList<Coordenada> opciones;

    int i = 1;
    while(i<8){
        if(arriba  && this->getCuadrado()->fila+i< 8){
            if(this->getCuadrado()->getVecino(this->getCuadrado()->fila+i,this->getCuadrado()->columna) == NULL){
                opciones.append(Coordenada(this->getCuadrado()->columna,this->getCuadrado()->fila+i));
            }else{
                if(getCuadrado()->getVecino(getCuadrado()->fila+i,getCuadrado()->columna)->getColor() == getColor())
                    arriba=false;
                else{
                    opciones.append(Coordenada(getCuadrado()->columna,getCuadrado()->fila+i));
                    arriba=false;
                }

            }
        }if(abajo  && this->getCuadrado()->fila-i >=0){
            if(getCuadrado()->getVecino(getCuadrado()->fila-i,getCuadrado()->columna)==NULL )
                opciones.append(Coordenada(getCuadrado()->columna,getCuadrado()->fila-i));
            else{
                if(getCuadrado()->getVecino(getCuadrado()->fila-i,getCuadrado()->columna)->getColor() == getColor()){
                    abajo=false;
                 }else{
                    opciones.append(Coordenada(getCuadrado()->columna,getCuadrado()->fila-i));
                    abajo=false;
                }

            }
        }if(derecha && getCuadrado()->columna+i<8){
            if(getCuadrado()->getVecino(getCuadrado()->fila,getCuadrado()->columna+i)==NULL){
                opciones.append(Coordenada(getCuadrado()->columna+i,getCuadrado()->fila));
            }else{
                if(getCuadrado()->getVecino(getCuadrado()->fila,getCuadrado()->columna+i)->getColor() == getColor()){
                    derecha=false;
                 }else{
                    opciones.append(Coordenada(getCuadrado()->columna+i,getCuadrado()->fila));
                    derecha=false;
                }

            }
        }
        if(izquierda  && getCuadrado()->columna-i>=0){
                    if(getCuadrado()->getVecino(getCuadrado()->fila,getCuadrado()->columna-i)==NULL)
                        opciones.append(Coordenada(getCuadrado()->columna-i,getCuadrado()->fila));
                    else{
                        if(getCuadrado()->getVecino(getCuadrado()->fila,getCuadrado()->columna-i)->getColor() == getColor()){
                            izquierda=false;
                         }else{
                            opciones.append(Coordenada(getCuadrado()->columna-i,getCuadrado()->fila));
                            izquierda=false;
                        }
                    }
                }
        if(AbajoD  && this->getCuadrado()->fila+i< 8 && this->getCuadrado()->columna+i< 8){
            if(this->getCuadrado()->getVecino(this->getCuadrado()->fila+i,this->getCuadrado()->columna+i) == NULL){
                opciones.append(Coordenada(this->getCuadrado()->columna+i,this->getCuadrado()->fila+i));
            }else{
                if(getCuadrado()->getVecino(getCuadrado()->fila+i,getCuadrado()->columna+i)->getColor() == getColor())
                    AbajoD=false;
                else{
                    opciones.append(Coordenada(getCuadrado()->columna+i,getCuadrado()->fila+i));
                    AbajoD=false;
                }

            }
        }if(AbajoI  && this->getCuadrado()->fila+i< 8 && this->getCuadrado()->columna-i>=0){
            if(getCuadrado()->getVecino(getCuadrado()->fila+i,getCuadrado()->columna-i)==NULL )
                opciones.append(Coordenada(getCuadrado()->columna-i,getCuadrado()->fila+i));
            else{
                if(getCuadrado()->getVecino(getCuadrado()->fila+i,getCuadrado()->columna-i)->getColor() == getColor()){
                    AbajoI=false;
                 }else{
                    opciones.append(Coordenada(getCuadrado()->columna-i,getCuadrado()->fila+i));
                    AbajoI=false;
                }

            }
        }if(ArribaD && this->getCuadrado()->fila-i>= 0 && this->getCuadrado()->columna+i<8){
            if(getCuadrado()->getVecino(getCuadrado()->fila-i,getCuadrado()->columna+i)==NULL){
                opciones.append(Coordenada(getCuadrado()->columna+i,getCuadrado()->fila-i));
            }else{
                if(getCuadrado()->getVecino(getCuadrado()->fila-i,getCuadrado()->columna+i)->getColor() == getColor()){
                    ArribaD=false;
                 }else{
                    opciones.append(Coordenada(getCuadrado()->columna+i,getCuadrado()->fila-i));
                    ArribaD=false;
                }

            }
        }
        if(ArribaI  && this->getCuadrado()->fila-i>= 0 && this->getCuadrado()->columna-i>=0){
                    if(getCuadrado()->getVecino(getCuadrado()->fila-i,getCuadrado()->columna-i)==NULL)
                        opciones.append(Coordenada(getCuadrado()->columna-i,getCuadrado()->fila-i));
                    else{
                        if(getCuadrado()->getVecino(getCuadrado()->fila-i,getCuadrado()->columna-i)->getColor() == getColor()){
                            ArribaI=false;
                         }else{
                            opciones.append(Coordenada(getCuadrado()->columna-i,getCuadrado()->fila-i));
                            ArribaI=false;
                        }
                    }
                }
       i++;
    }

    return opciones;
}
