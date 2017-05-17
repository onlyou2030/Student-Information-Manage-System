#ifndef CHANGESTUINFO_H
#define CHANGESTUINFO_H

#include <QMainWindow>
#include <QPushButton>
#include <QMessageBox>
#include <QProgressDialog>
#include "stuinfomanage.h"
namespace Ui {
class ChangeStuInfo;
}

class ChangeStuInfo : public QMainWindow
{
    Q_OBJECT

public:
    explicit ChangeStuInfo(QWidget *parent = 0);
    ~ChangeStuInfo();

private slots:
    void on_buttonBox_clicked(QAbstractButton *button);

private:
    Ui::ChangeStuInfo *ui;
    StuInfoManage *Sparent;
};

#endif // CHANGESTUINFO_H
