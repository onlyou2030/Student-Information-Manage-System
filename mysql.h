#ifndef MYSQL_H
#define MYSQL_H

#include <QSql>
#include <QSqlDatabase>
#include <QDebug>
#include <QSqlQuery>
#include "mainwindow.h"
#include "addinfo.h"


class MySql
{
public:
    MySql();
    void initsql();                     //初始化连接数据库
    void createtable();            //建表 索引 触发器
    bool inituser(QString name,QString identify,QString passward);                               //将注册信息添加数据库
    bool loguser(QString name,QString passward);                                                           //验证登录信息
    bool forgetpassward(QString name,QString identify);                                                 //根据姓名和身份信息找回密码
    bool addstu(my_stu* stu);                                                                                               //添加学生信息
    bool updatestu(my_stu* stu);                                                                                         //修改学生信息
    bool deletestu(QString account);                                                                                   //删除学生信息

private:
    QSqlQuery *query;
};

#endif // MYSQL_H
