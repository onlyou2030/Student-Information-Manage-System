#ifndef REGISTER_H
#define REGISTER_H

#include <QMainWindow>
#include <QPushButton>
#include <QMessageBox>
#include <QProgressDialog>
#include "mysql.h"
#include "mainwindow.h"

namespace Ui{
class Register;
}

class Register : public QMainWindow
{
    Q_OBJECT

public:
    explicit Register(QWidget *parent = 0);
    ~Register();

private slots:

    void on_yesOrNoBox_clicked(QAbstractButton *button);

private:
    Ui::Register *ui;
    MainWindow* Mparent;
};

#endif // REGISTER_H
