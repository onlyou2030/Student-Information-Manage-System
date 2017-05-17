#include "addinfo.h"
#include "ui_addinfo.h"
#include "mysql.h"

AddInfo::AddInfo(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AddInfo)
{
    Sparent=(StuInfoManage*) parent;
    ui->setupUi(this);
}

AddInfo::~AddInfo()
{
    delete ui;
}

void AddInfo::on_buttonBox_clicked(QAbstractButton *button)
{
    if(ui->buttonBox->button(QDialogButtonBox::Ok) == button)
    {
        my_stu tran;
        tran.account = ui->acount->text();
        tran.name = ui->name->text();
        tran.sex = ui->sex->currentText();
        tran.age = ui->age->text().toInt();
        tran.identify = ui->identify->text();
        tran.tel = ui->tel->text();
        tran.enroll_time = ui->enroll->text();
        tran.leave_time = ui->leave->text();
        tran.scondition = ui->condition->currentText();
        tran.text = ui->textEdit->toPlainText();

        QProgressDialog dialog(tr("正在添加"),tr("取消"), 0, 30000, this);
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
        bool ret = mysql.addstu(&tran);
        if(ret == false)
        {
            QMessageBox::information(this, tr("消息"), tr("添加失败!"), QMessageBox::Ok);
            this->close();
            Sparent->show();
            return;
        }
        QMessageBox::information(this, tr("消息"), tr("添加成功!"), QMessageBox::Ok);
        this->close();
        Sparent->show();
        return;
    }
    else if(ui->buttonBox->button(QDialogButtonBox::Cancel) == button)
    {
        this->close();
        QProgressDialog dialog(tr("正在返回主界面"),tr("取消"), 0, 3000, this);
        dialog.setWindowTitle(tr("进度"));
        dialog.setWindowModality(Qt::WindowModal);
        dialog.show();
        for(int k = 0; k < 3000; k++)
        {
            dialog.setValue(k);
            QCoreApplication::processEvents();
            if(dialog.wasCanceled())
            {
                break;
            }
        }
        dialog.setValue(3000);
        Sparent->show();
    }
}
