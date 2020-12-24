#include "board.h"
#include <QPixmap>
#include "pawn.h"
#include "king.h"
#include "queen.h"
#include "bishop.h"
#include "tower.h"
#include "horse.h"
#include "square.h"
#include "mainwindow.h"
extern MainWindow *mainwindow;
tablero::tablero()
{
    setUpBlack();
    setUpWhite();
}
void tablero::dibujarCasillas(int x,int y)
{
    int SHIFT = 70;
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++)
        {
            cuadrado *casilla = new cuadrado();
            mainwindow->collection[i][j] = casilla;
            casilla->fila = i;
            casilla->columna = j;
            casilla->setPos(x+SHIFT*j,y+SHIFT*i);
            if((i+j)%2==0){
                casilla->setOriginalColor(QColor(255,255,255));
            }else
                casilla->setOriginalColor(QColor(35,52,67));
            mainwindow->addScene(casilla);
        }
    }
}

void tablero::addPieza() {
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++)
        {
            cuadrado *box =mainwindow->collection[i][j];
            if(i < 2) {
                static int k;
                box->ubicacion(black[k]);
                mainwindow->piezaViva.append(black[k]);
                mainwindow->addScene(black[k++]);
            }
            if(i > 5) {
                static int h;
                box->ubicacion(white[h]);
                mainwindow->piezaViva.append(white[h]);
                mainwindow->addScene(white[h++]);
            }

        }
    }
}

void tablero::setUpBlack()
{
    Piece *piece;
    piece = new torre("BLACK");
    piece->ficha = "torre";
    black.append(piece);
    piece = new caballo("BLACK");
    black.append(piece);
    piece->ficha = "caballo";
    piece = new alfil("BLACK");
    black.append(piece);
    piece->ficha = "alfilB";
    piece = new reina("BLACK");
    black.append(piece);
    piece->ficha ="reina";
    piece = new rey("BLACK");
     piece->ficha = "rey";
     mainwindow->reyBlack = piece;
    black.append(piece);
    piece = new alfil("BLACK");
     piece->ficha = "alfilN";
    black.append(piece);
    piece = new caballo("BLACK");
     piece->ficha = "caballo";
    black.append(piece);
    piece = new torre("BLACK");
     piece->ficha = "torre";
    black.append(piece);
    for(int i = 0; i < 8; i++) {
        piece = new Peon("BLACK");
        piece->ficha = "peon";
        black.append(piece);
    }
}
void tablero::setUpWhite()
{
    Piece *piece;
    for(int i = 0; i < 8; i++) {

        piece = new Peon("WHITE");
        piece->ficha = "peon";

        white.append(piece);
    }
    piece = new torre("WHITE");
    piece->ficha = "torre";
    white.append(piece);
    piece = new caballo("WHITE");
    piece->ficha = "caballo";
    white.append(piece);
    piece = new alfil("WHITE");
    piece->ficha = "alfilN";
    white.append(piece);
    piece = new reina("WHITE");
    piece->ficha = "reina";
    white.append(piece);
    piece = new rey("WHITE");
    piece->ficha = "rey";
    mainwindow->reyWhite = piece;
    white.append(piece);
    piece = new alfil("WHITE");
    piece->ficha = "alfilB";
    white.append(piece);
    piece = new caballo("WHITE");
    piece->ficha = "caballo";
    white.append(piece);
    piece = new torre("WHITE");
    piece->ficha = "torre";
    white.append(piece);

}


