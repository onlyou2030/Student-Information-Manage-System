#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "register.h"
#include "logging.h"
#include "mysql.h"
#include <QInputDialog>

MainWindow * MainWindow::MW=NULL;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow *MainWindow::getIntance()
{
    if(MW == NULL)
    {
        MW = new MainWindow();
    }
    return MW;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_registerBtn_clicked()
{
    this->hide();
    Register *reg=new Register(this);
    reg->setWindowTitle("注册");
    reg->show();
}

void MainWindow::on_loginBtn_clicked()
{
    this->hide();
    logging *log=new logging(this);
    log->setWindowTitle("登录");
    log->show();
}


void MainWindow::on_forgetPasswdBtn_clicked()
{
    bool ok;
    QInputDialog ecf;
    name = ecf.getText(this,tr("忘记密码"),tr("请输入用户名："),QLineEdit::Normal,NULL,&ok);
    identify=ecf.getText(this,tr("忘记密码"),tr("请输入证件号："),QLineEdit::Normal,NULL,&ok);
    MySql mysql;
    bool ret=mysql.forgetpassward(name,identify);
    if(!ret)
        {
            QMessageBox::information(this,tr("消息"),tr("消息不匹配!"),QMessageBox::Ok);
            return;
        }
    QMessageBox::information(this,tr("消息"),tr("请妥善保管您的密码:%1").arg(passward),QMessageBox::Ok);
    return;
}

void MainWindow::on_exitBtn_clicked()
{
    this->close();
}
