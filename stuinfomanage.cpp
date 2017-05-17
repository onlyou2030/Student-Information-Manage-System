#include "stuinfomanage.h"
#include "changestuinfo.h"
#include "addinfo.h"
#include "ui_stuinfomanage.h"
#include <QSqlTableModel>
#include <QTableView>
#include <QInputDialog>
#include "mysql.h"
enum studentInfoIndex
{
    studentInfo_stuaccount = 0,
    studentInfo_stuname = 1,
    studentInfo_stusex = 2,
    studentInfo_stuage = 3,
    studentInfo_identify = 4,
    studentInfo_tel = 5,
    studentInfo_enroll_time = 6,
    studentInfo_leave_time = 7,
    studentInfo_scondition = 8,
    studentInfo_stu_text = 9
};

StuInfoManage::StuInfoManage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::StuInfoManage)
{
    ui->setupUi(this);
}

StuInfoManage::~StuInfoManage()
{
    delete ui;
}

void StuInfoManage::on_addfinfo_clicked()
{
    this->hide();
    AddInfo *AI=new AddInfo(this);
    AI->show();
}

void StuInfoManage::on_selectinfo_clicked()
{
    showdata();
}


void StuInfoManage::showdata()
{
    QSqlTableModel *model=new QSqlTableModel();
    model->setTable("studentInfo");
    model->setSort(studentInfo_stuaccount,Qt::AscendingOrder);
    model->setHeaderData(studentInfo_stuaccount,Qt::Horizontal,"学号");
    model->setHeaderData(studentInfo_stuname,Qt::Horizontal,"姓名");
    model->setHeaderData(studentInfo_stusex,Qt::Horizontal,"性别");
    model->setHeaderData(studentInfo_stuage,Qt::Horizontal,"年龄");
    model->setHeaderData(studentInfo_identify,Qt::Horizontal,"身份证号");
    model->setHeaderData(studentInfo_tel,Qt::Horizontal,"电话号码");
    model->setHeaderData(studentInfo_enroll_time,Qt::Horizontal,"入学时间");
    model->setHeaderData(studentInfo_leave_time,Qt::Horizontal,"毕业时间");
    model->setHeaderData(studentInfo_scondition,Qt::Horizontal,"学业状态");
    model->setHeaderData(studentInfo_stu_text,Qt::Horizontal,"备注");

    model->select();

    QTableView *view=new QTableView;
    view->setModel(model);
    view->setSelectionMode(QAbstractItemView::SingleSelection);
    view->setSelectionBehavior(QAbstractItemView::SelectRows);
    view->setColumnHidden(studentInfo_stuaccount, true);
    view->resizeColumnsToContents();
    view->setEditTriggers(QAbstractItemView::NoEditTriggers);

    QHeaderView *header=view->horizontalHeader();
    header->setStretchLastSection(true);
    view->resize(600, 450);

    view->show();
}

void StuInfoManage::on_changeinfo_clicked()
{
    ChangeStuInfo *change=new ChangeStuInfo(this);
    this->hide();
    change->show();
}

void StuInfoManage::on_deleteinfo_clicked()
{
    bool ok;
    QInputDialog ecf;
    QString account = ecf.getText(this, tr("删除信息"),tr("请输入学号："),QLineEdit::Normal, NULL,&ok);
    QProgressDialog dialog(tr("正在删除"),tr("取消"), 0, 30000, this);
    dialog.setWindowTitle(tr("进度"));
    dialog.setWindowModality(Qt::WindowModal);
    dialog.show();
    for(int k = 0; k < 30000; k++)
    {
        dialog.setValue(k);
        QCoreApplication::processEvents();
        if(dialog.wasCanceled())
        {
            break;
        }
    }
    dialog.setValue(30000);
    MySql mysql;
    bool ret = mysql.deletestu(account);
    if(ret == false)
    {
        QMessageBox::information(this, tr("消息"), tr("查无此人!"), QMessageBox::Ok);
        return;
    }
    QMessageBox::information(this, tr("消息"), tr("删除成功!"), QMessageBox::Ok);
    return;
}
