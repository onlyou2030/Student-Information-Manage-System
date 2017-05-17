#include "register.h"
#include "ui_register.h"

Register::Register(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Register)
{
    Mparent = (MainWindow*)parent;
    ui->setupUi(this);
    ui->passwd->setEchoMode(QLineEdit::Password);                   //密码方式显示文本
    ui->passwd2->setEchoMode(QLineEdit::Password);                   //密码方式显示文本
}

Register::~Register()
{
    delete ui;
}


void Register::on_yesOrNoBox_clicked(QAbstractButton *button)
{
    if(ui->yesOrNoBox->button(QDialogButtonBox::Ok) == button)
    {
        if((ui->name->text() == "") || (ui->ID->text() == "") || (ui->passwd->text() == "") || (ui->passwd2->text() == ""))
        {
            QMessageBox::information(this, tr("警告"), tr("输入不能为空！!"), QMessageBox::Ok);
            return;
        }
        if(ui->passwd->text() != ui->passwd2->text())
        {
            QMessageBox::information(this, tr("警告"), tr("输入密码错误！!"), QMessageBox::Ok);
            return;
        }

        QString name = ui->name->text();
        QString identify = ui->ID->text();
        QString passward = ui->passwd->text();

        QProgressDialog dialog(tr("正在注册"),tr("取消"), 0, 30000, this);
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

        MySql* mysql = new MySql;
        bool ret = mysql->inituser(name, identify, passward);
        if(ret == false)
        {
            QMessageBox::information(this, tr("消息"), tr("用户已被注册!"), QMessageBox::Ok);
            this->close();
            Mparent->show();
            return;
        }
        QMessageBox::information(this, tr("消息"), tr("注册成功!"), QMessageBox::Ok);
        //Mparent->name = name;
        this->close();
        Mparent->show();
    }
    else if(ui->yesOrNoBox->button(QDialogButtonBox::Cancel) == button)
    {
        this->close();
        QProgressDialog dialog(tr("正在返回主界面"),tr("取消"), 0, 30000, this);
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
        Mparent->show();
    }
}
