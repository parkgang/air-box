#ifndef CLIENT_LOGIN_H
#define CLIENT_LOGIN_H

#include <QMainWindow>
#include <QMessageBox>

#include <select_parcel.h>
#include <storage_box.h>

extern bool Client_Login_flg;
extern int Client_Login_log;

namespace Ui
{
    class Client_Login;
}

class Client_Login : public QMainWindow
{
    Q_OBJECT

public:
    explicit Client_Login(QWidget *parent = nullptr);
    ~Client_Login();

private slots:
    void on_Login_Button_clicked();

    void on_Parcel_Find_button_clicked();

    void on_Parcel_Reservation_button_clicked();

private:
    Ui::Client_Login *ui;

    Select_parcel* select_parcel;
    Storage_box* storage_box;
};

#endif // CLIENT_LOGIN_H
