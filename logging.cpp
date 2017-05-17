#include "logging.h"
#include "manage.h"
#include "ui_logging.h"

logging::logging(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::logging)
{
    Mparent=(MainWindow*)parent;
    ui->setupUi(this);
    ui->passward->setEchoMode(QLineEdit::Password);  //密码方式显示文本
    if(Mparent->name != "")
        ui->name->addItem(QString("%1").arg(Mparent->name));
}

logging::~logging()
{
    delete ui;
}


void logging::on_yesOrNoBox_clicked(QAbstractButton *button)
{
    if(ui->yesOrNoBox->button(QDialogButtonBox::Ok)==button)
        {
            if((ui->name->currentText()=="")||(ui->passward->text()==""))
                {
                    QMessageBox::information(this,tr("警告"),tr("输入不能为空！"),QMessageBox::Ok);
                    return;
                }
            QString name= ui->name->currentText();
            QString passward=ui->passward->text();

            QProgressDialog dialog(tr("正在登录"),tr("取消"),0,30000,this);
            dialog.setWindowTitle(tr("进度"));
            dialog.setWindowModality(Qt::WindowModal);
            dialog.show();
            for(int k=0;k<30000;k++)
                {
                    dialog.setValue(k);
                    QCoreApplication::processEvents();
                    if(dialog.wasCanceled())
                        {
                            break;
                        }
                }
            dialog.setValue(30000);

            MySql *mysql=new MySql;
            bool ret=mysql->loguser(name,passward);
            if(!ret)
                {
                    QMessageBox::information(this,tr("消息"),tr("帐号密码不匹配！"),QMessageBox::Ok);
                    this->close();
                    Mparent->show();   //回到上一个窗口
                    return;
                }
            QMessageBox::information(this,tr("消息"),tr("登录成功！"),QMessageBox::Ok);
            this->close();
            Manage *m=new Manage(this);
            m->show();
            return;
        }
    else if(ui->yesOrNoBox->button(QDialogButtonBox::Cancel)==button)
        {
            this->close();
            QProgressDialog dialog(tr("正在返回主界面"),tr("取消"),0,30000,this);
            dialog.setWindowTitle(tr("进度"));
            dialog.setWindowModality(Qt::WindowModal);
            dialog.show();
            for(int k=0;k<30000;k++)
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
