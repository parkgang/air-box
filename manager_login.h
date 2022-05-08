#ifndef MANAGER_LOGIN_H
#define MANAGER_LOGIN_H

#include <manager_menu.h>

#include <QMainWindow>
#include <QMessageBox>

namespace Ui
{
    class Manager_Login;
}

class Manager_Login : public QMainWindow
{
    Q_OBJECT

public:
    explicit Manager_Login(QWidget *parent = nullptr);
    ~Manager_Login();

private slots:
    void on_Login_Button_clicked();

private:
    Ui::Manager_Login *ui;

    Manager_Menu* manager_Menu;
};

#endif // MANAGER_LOGIN_H
