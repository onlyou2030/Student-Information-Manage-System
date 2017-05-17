#ifndef ADDINFO_H
#define ADDINFO_H

#include <QMainWindow>
#include <QPushButton>
#include <QMessageBox>
#include <QProgressDialog>
#include "stuinfomanage.h"

namespace Ui {
class AddInfo;
}

class AddInfo : public QMainWindow
{
    Q_OBJECT

public:
    explicit AddInfo(QWidget *parent = 0);
    ~AddInfo();

private slots:
    void on_buttonBox_clicked(QAbstractButton *button);

private:
    Ui::AddInfo *ui;
    StuInfoManage *Sparent;
};

typedef struct stuInfo
{
    QString account;
    QString name;
    QString sex;
    int age;
    QString identify;
    QString tel;
    QString enroll_time;
    QString leave_time;
    QString scondition;
    QString text;
}my_stu;

#endif // ADDINFO_H
