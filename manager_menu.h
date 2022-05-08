#ifndef MANAGER_MENU_H
#define MANAGER_MENU_H

#include <client_list.h>
#include <courier_list.h>
#include <service_edit.h>

#include <QMainWindow>

namespace Ui
{
    class Manager_Menu;
}

class Manager_Menu : public QMainWindow
{
    Q_OBJECT

public:
    explicit Manager_Menu(QWidget *parent = nullptr);
    ~Manager_Menu();

private slots:
    void on_Client_Search_Button_clicked();

    void on_Courier_Search_Button_clicked();

    void on_Service_time_Button_clicked();

private:
    Ui::Manager_Menu *ui;

    Client_list* client_list;
    Courier_list* courier_list;
    Service_edit* service_edit;
};

#endif // MANAGER_MENU_H
