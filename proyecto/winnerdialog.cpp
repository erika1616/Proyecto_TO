#include "winnerdialog.h"
#include "ui_winnerdialog.h"

WinnerDialog::WinnerDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WinnerDialog)
{
    ui->setupUi(this);
}

WinnerDialog::~WinnerDialog()
{
    delete ui;
}

void WinnerDialog::on_pushButton_clicked()
{
    close();
}
void WinnerDialog::printWinner(QString _ganador){
    ui->ganador->setText(_ganador);
}
