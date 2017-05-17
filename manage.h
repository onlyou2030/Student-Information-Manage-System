#ifndef MANAGE_H
#define MANAGE_H

#include <QMainWindow>

namespace Ui {
class Manage;
}

class Manage : public QMainWindow
{
    Q_OBJECT

public:
    explicit Manage(QWidget *parent = 0);
    ~Manage();

private slots:
    void on_stuInfo_clicked();

private:
    Ui::Manage *ui;
};

#endif // MANAGE_H
