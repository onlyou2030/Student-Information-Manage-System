#include "manage.h"
#include "stuinfomanage.h"
#include "ui_manage.h"

Manage::Manage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Manage)
{
    ui->setupUi(this);
}

Manage::~Manage()
{
    delete ui;
}

void Manage::on_stuInfo_clicked()
{
    this->hide();
    StuInfoManage *SIM=new StuInfoManage(this);
    SIM->show();
}
