#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    static MainWindow* getIntance();
    //explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QString name;
    QString passward;
    QString identify;

private slots:
    void on_registerBtn_clicked();

    void on_loginBtn_clicked();

    void on_forgetPasswdBtn_clicked();

    void on_exitBtn_clicked();

private:
    explicit MainWindow(QWidget *parent = 0);
    static MainWindow* MW;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
