#ifndef COURIER_LOGIN_H
#define COURIER_LOGIN_H

#include <QMainWindow>

#include <storage_box.h>
#include <select_parcel.h>

extern bool Courier_Login_flg;
extern int Courier_Login_log;

namespace Ui
{
    class Courier_Login;
}

class Courier_Login : public QMainWindow
{
    Q_OBJECT

public:
    explicit Courier_Login(QWidget *parent = nullptr);
    ~Courier_Login();

private slots:
    void on_Login_Button_clicked();

    void on_Parcel_in_button_clicked();

    void on_Parcel_out_button_clicked();

private:
    Ui::Courier_Login *ui;

    Storage_box* storage_box;
    Select_parcel* select_parcel;
};

#endif // COURIER_LOGIN_H
