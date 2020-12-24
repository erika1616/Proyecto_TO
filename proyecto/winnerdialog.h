#ifndef WINNERDIALOG_H
#define WINNERDIALOG_H

#include <QDialog>

namespace Ui {
class WinnerDialog;
}

class WinnerDialog : public QDialog
{
    Q_OBJECT

public:
    explicit WinnerDialog(QWidget *parent = nullptr);
    ~WinnerDialog();
    void printWinner(QString _ganador);

private slots:
    void on_pushButton_clicked();

private:
    Ui::WinnerDialog *ui;
};

#endif
