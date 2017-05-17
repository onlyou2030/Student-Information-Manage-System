#ifndef STUINFOMANAGE_H
#define STUINFOMANAGE_H

#include <QMainWindow>

namespace Ui {
class StuInfoManage;
}

class StuInfoManage : public QMainWindow
{
    Q_OBJECT

public:
    explicit StuInfoManage(QWidget *parent = 0);
    ~StuInfoManage();
    void showdata();

private slots:
    void on_addfinfo_clicked();

    void on_selectinfo_clicked();

    void on_changeinfo_clicked();

    void on_deleteinfo_clicked();

private:
    Ui::StuInfoManage *ui;
};

#endif // STUINFOMANAGE_H
