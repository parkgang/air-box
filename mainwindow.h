#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <manager_login.h>
#include <client_login.h>
#include <courier_login.h>
#include <storage_box.h>

#include <QMainWindow>
#include <QTimer>
#include <QString>
#include <QDateTime>

QT_BEGIN_NAMESPACE
namespace Ui
{
    class MainWindow;
}
QT_END_NAMESPACE

QString kor(const char* str);
QDate Get_System_Date();
QTime Get_System_Time();
void init_user();

extern Person* person_prt;
extern Courier* courier_prt;
extern int Service_fee;
extern bool Delivery_box_flg[20]; //박스 사용하는지 안하는지 나타냄
extern int Select_box_index;    //insert_box에서 선택된 번호를 가지고 있음

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    void Basic_Setting();
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void show_Date_Time();

private slots:
    void on_Manager_Button_clicked();

    void on_Client_Button_clicked();

    void on_Courier_Button_clicked();

    void on_Storage_Box_Button_clicked();

private:
    Ui::MainWindow *ui;
    QTimer* timer;

    Client_Login* client_Login;
    Manager_Login* manager_Login;
    Courier_Login* courier_Login;
    Storage_box* storage_box;
};
#endif // MAINWINDOW_H
