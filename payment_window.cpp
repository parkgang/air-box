#include "payment_window.h"
#include "ui_payment_window.h"

#include <mainwindow.h>
#include <client_login.h>
#include <client_list.h>
#include <select_parcel.h>

int Trans_minute(QDate in_date, QTime in_time, QDate now_date, QTime now_time)
{
    int return_time = 0;    //입고된 날짜, 시간을 현재 시간과 빼서 모든정보를 분으로 바뀌서 리턴함

    int sub_date = in_date.daysTo(now_date);
    return_time += (sub_date * 24) * 60;            //(1일 * 24(시간)) * 분

    int temp_minute = in_time.secsTo(now_time)/60;  //sec -> minute 변경
    return_time += (temp_minute/60) * 60;           //(시간) * 분
    return_time += temp_minute%60;                  //분

    //qDebug() << kor("날짜 차이 : ") << sub_date;
    //qDebug() << kor("시간 차이 : ") << temp_minute/60;  //시간차 hour 출력
    //qDebug() << kor(" 분 차이 : ") << temp_minute%60;    //시간차 minute 출력

    return return_time;
}

int Use_price(int minute)
{
    return (minute/60) * Service_fee;
}

Payment_window::Payment_window(QWidget *parent) : QMainWindow(parent), ui(new Ui::Payment_window)
{
    ui->setupUi(this);

    //qDebug() << "Run";

    Person* Client = (person_prt + Client_Login_log);    

    ui->Name_label->setText(Client->Get_Name());
    ui->Birth_label->setText(Client->Get_Birth());
    ui->Phone_label->setText(Client->Get_Phone());

    ui->Index_label->setText(QString::number(Client->Get_Box_index(Select_parcel_log)));
    ui->Text_label->setText(Client->Get_Box_text(Select_parcel_log));
    ui->Intime_label->setText
    (
        Client->Get_Box_in_date(Select_parcel_log).toString(kor("20yy년 MM월 dd일")) +
        " " +
        Client->Get_Box_in_time(Select_parcel_log).toString(kor("hh시 mm분"))
    );
    ui->Systemtime_label->setText
    (
        Get_System_Date().toString(kor("20yy년 MM월 dd일")) +
        " " +
        Get_System_Time().toString(kor("hh시 mm분"))
    );

    int Sub_time = Trans_minute(Client->Get_Box_in_date(Select_parcel_log),Client->Get_Box_in_time(Select_parcel_log),Get_System_Date(),Get_System_Time());
    int price = Use_price(Sub_time);
    ui->Service_price_label->setText(QString::number(price));
}

Payment_window::~Payment_window()
{
    delete ui;
}

void Payment_window::on_Payment_pushButton_clicked()
{
    this->hide();
}
