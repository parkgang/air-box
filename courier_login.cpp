#include "courier_login.h"
#include "ui_courier_login.h"

#include <mainwindow.h>

bool Courier_Login_flg;
int Courier_Login_log;

Courier_Login::Courier_Login(QWidget *parent) : QMainWindow(parent), ui(new Ui::Courier_Login)
{
    ui->setupUi(this);
}

Courier_Login::~Courier_Login()
{
    delete ui;
}

void Courier_Login::on_Login_Button_clicked()
{
    init_user();
    QString Name = ui->Name_lineEdit->text();
    QString Phone = ui->Phone_lineEdit->text();
    QString Affiliation = ui->Affiliation_lineEdit->text();

    for(int i=0;i<Courier::Courier_cnt;i++)
    {
        if((courier_prt+i)->Get_Name() == Name &&
           (courier_prt+i)->Get_Phone() == Phone &&
           (courier_prt+i)->Get_Affiliation() == Affiliation)
        {
            if((courier_prt+i)->Get_Image_path() == "")
                ui->Affiliation_logo->setText("Logo NULL");
            else
            {
                QPixmap Logo((courier_prt+i)->Get_Image_path()); //�̹��� ��� ����
                int w = ui->Affiliation_logo->width();    //�� W��ǥ �ҷ���
                int h = ui->Affiliation_logo->height();   //�� H��ǥ �ҷ���
                ui->Affiliation_logo->setPixmap(Logo);    //�̹��� ����
                ui->Affiliation_logo->setPixmap(Logo.scaled(w,h,Qt::KeepAspectRatio));  //�̹��� �ȼ��� �°� Setting
            }

            ui->Affiliation_logo->setStyleSheet("background-color : rgb(68, 114, 196);"
                                            "color: rgb(255, 255, 255);"
                                            "border-style : outset;"
                                            "border-width : 10px;"
                                            "border-radius : 20px;"
                                            "border-color : rgb(129, 143, 168);"
                                            "font: 20pt;"
                                            );

            ui->Parcel_in_button->setStyleSheet("background-color : rgb(68, 114, 196);"
                                                  "border-style : outset;"
                                                  "border-width : 5px;"
                                                  "border-radius : 35px;"
                                                  "border-color : rgb(129, 143, 168);"
                                                  "color: rgb(255, 255, 255);"
                                                  "font: 15pt;"
                                                  );

            ui->Parcel_out_button->setStyleSheet("background-color : rgb(68, 114, 196);"
                                                         "border-style : outset;"
                                                         "border-width : 5px;"
                                                         "border-radius : 35px;"
                                                         "border-color : rgb(129, 143, 168);"
                                                         "color: rgb(255, 255, 255);"
                                                         "font: 15pt;"
                                                         );
            Courier_Login_flg = true;
            Courier_Login_log = i;
            return; //�α��� ������, �ؿ� ���� �����Ű�� �ʱ� ���ؼ� return ���� Ż��
        }
    }

    //Login�� ���н� label�� �α��� errǥ��, Pushbutton ���� ������, err MessageBox ���

    ui->Affiliation_logo->setText("Login Err");
    ui->Affiliation_logo->setStyleSheet("background-color : rgb(255, 100, 100);"
                                    "color: rgb(255, 255, 255);"
                                    "border-style : outset;"
                                    "border-width : 10px;"
                                    "border-radius : 20px;"
                                    "border-color : rgb(129, 143, 168);"
                                    "font: 20pt;"
                                    );

    ui->Parcel_in_button->setStyleSheet("background-color : rgb(255, 100, 100);"
                                          "border-style : outset;"
                                          "border-width : 5px;"
                                          "border-radius : 35px;"
                                          "border-color : rgb(129, 143, 168);"
                                          "color: rgb(255, 255, 255);"
                                          "font: 15pt;"
                                          );

    ui->Parcel_out_button->setStyleSheet("background-color : rgb(255, 100, 100);"
                                                 "border-style : outset;"
                                                 "border-width : 5px;"
                                                 "border-radius : 35px;"
                                                 "border-color : rgb(129, 143, 168);"
                                                 "color: rgb(255, 255, 255);"
                                                 "font: 15pt;"
                                                 );
    QMessageBox::critical(this,kor("No Client ReSource"), kor("�α��� ������ ��ġ���� �ʽ��ϴ�"));

    Courier_Login_flg = false;
    Courier_Login_log = NULL;
}

void Courier_Login::on_Parcel_in_button_clicked()
{
    if(Courier_Login_flg)
    {
        storage_box = new Storage_box(this);
        storage_box->show();
    }
    else
        QMessageBox::critical(this,kor("No Client ReSource"), kor("�α��� �� �̿��ϼ���"));
}

void Courier_Login::on_Parcel_out_button_clicked()
{
    if(Courier_Login_flg)
    {
        select_parcel = new Select_parcel(this);
        select_parcel->show();
    }
    else
        QMessageBox::critical(this,kor("No Client ReSource"), kor("�α��� �� �̿��ϼ���"));
}
