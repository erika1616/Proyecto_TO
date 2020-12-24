#include "choose.h"
#include "ui_elejirficha.h"

elejirficha::elejirficha(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::elejirficha)
{
    ui->setupUi(this);
}

elejirficha::~elejirficha()
{
    delete ui;
}
void elejirficha::setEleccion(QString* _eleccion){
    eleccion = _eleccion;
}
void elejirficha::on_reina_clicked()
{
    *eleccion = "reina";
}
void elejirficha::on_caballo_clicked()
{
    *eleccion = "caballo";
}

void elejirficha::on_alfil_clicked()
{
    *eleccion = "alfil";

}

void elejirficha::on_torre_clicked()
{
    *eleccion = "torre";
}

void elejirficha::on_pushButton_clicked()
{
    eleccion = NULL;
    close();
}
