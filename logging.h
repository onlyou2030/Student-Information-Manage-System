#ifndef LOGGING_H
#define LOGGING_H

#include <QMainWindow>
#include <QPushButton>
#include <QMessageBox>
#include <QProgressDialog>
#include "mysql.h"

namespace Ui {
class logging;
}

class logging : public QMainWindow
{
    Q_OBJECT

public:
    explicit logging(QWidget *parent = 0);
    ~logging();

private slots:

    void on_yesOrNoBox_clicked(QAbstractButton *button);

private:
    Ui::logging *ui;
    MainWindow *Mparent;
};

#endif // LOGGING_H
