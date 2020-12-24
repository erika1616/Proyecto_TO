#ifndef ELEJIRFICHA_H
#define ELEJIRFICHA_H

#include <QDialog>

namespace Ui {
class elejirficha;
}

class elejirficha : public QDialog
{
    Q_OBJECT

public:
    explicit elejirficha(QWidget *parent = nullptr);
    ~elejirficha();
    QString *eleccion;
    void setEleccion(QString* _eleccion);
private slots:
    void on_reina_clicked();

    void on_caballo_clicked();

    void on_alfil_clicked();

    void on_torre_clicked();

    void on_pushButton_clicked();

private:
    Ui::elejirficha *ui;
};

#endif // ELEJIRFICHA_H
