#include "payment_window.h"
#include "ui_payment_window.h"

#include <mainwindow.h>
#include <client_login.h>
#include <client_list.h>
#include <select_parcel.h>

int Trans_minute(QDate in_date, QTime in_time, QDate now_date, QTime now_time)
{
    int return_time = 0;    //�԰�� ��¥, �ð��� ���� �ð��� ���� ��������� ������ �ٲ ������

    int sub_date = in_date.daysTo(now_date);
    return_time += (sub_date * 24) * 60;            //(1�� * 24(�ð�)) * ��

    int temp_minute = in_time.secsTo(now_time)/60;  //sec -> minute ����
    return_time += (temp_minute/60) * 60;           //(�ð�) * ��
    return_time += temp_minute%60;                  //��

    //qDebug() << kor("��¥ ���� : ") << sub_date;
    //qDebug() << kor("�ð� ���� : ") << temp_minute/60;  //�ð��� hour ���
    //qDebug() << kor(" �� ���� : ") << temp_minute%60;    //�ð��� minute ���

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
        Client->Get_Box_in_date(Select_parcel_log).toString(kor("20yy�� MM�� dd��")) +
        " " +
        Client->Get_Box_in_time(Select_parcel_log).toString(kor("hh�� mm��"))
    );
    ui->Systemtime_label->setText
    (
        Get_System_Date().toString(kor("20yy�� MM�� dd��")) +
        " " +
        Get_System_Time().toString(kor("hh�� mm��"))
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
