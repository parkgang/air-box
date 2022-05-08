#include "manager_menu.h"
#include "ui_manager_menu.h"

Manager_Menu::Manager_Menu(QWidget *parent) : QMainWindow(parent), ui(new Ui::Manager_Menu)
{
    ui->setupUi(this);
}

Manager_Menu::~Manager_Menu()
{
    delete ui;
}

void Manager_Menu::on_Client_Search_Button_clicked()
{
    client_list = new Client_list(this);
    client_list ->show();
    //this->hide();
}

void Manager_Menu::on_Courier_Search_Button_clicked()
{
    courier_list = new Courier_list(this);
    courier_list->show();
    //this->hide();
}

void Manager_Menu::on_Service_time_Button_clicked()
{
    service_edit = new Service_edit(this);
    service_edit -> show();
    //this->hide();
}
