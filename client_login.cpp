#include "client_login.h"
#include "ui_client_login.h"

#include <mainwindow.h>

bool Client_Login_flg;
int Client_Login_log;

Client_Login::Client_Login(QWidget *parent) : QMainWindow(parent), ui(new Ui::Client_Login)
{
    ui->setupUi(this);
}

Client_Login::~Client_Login()
{
    delete ui;
}

void Client_Login::on_Login_Button_clicked()
{
    init_user();
    QString Name = ui->Name_lineEdit->text();
    QString Birth = ui->Birth_lineEdit->text();
    QString Phone = ui->Phone_lineEdit->text();

    for(int i=0;i<Person::Person_cnt;i++)
    {
        if((person_prt+i)->Get_Name() == Name &&
           (person_prt+i)->Get_Birth() == Birth &&
           (person_prt+i)->Get_Phone() == Phone)
        {
            if((person_prt+i)->Get_Image_path() == "")
                ui->manager_face->setText("Face NULL");
            else
            {
                QPixmap Face((person_prt+i)->Get_Image_path()); //이미지 경로 설정
                int w = ui->manager_face->width();    //라벨 W좌표 불러옴
                int h = ui->manager_face->height();   //라벨 H좌표 불러옴
                ui->manager_face->setPixmap(Face);    //이미지 띄우기
                ui->manager_face->setPixmap(Face.scaled(w,h,Qt::KeepAspectRatio));  //이미지 픽셀에 맞게 Setting
            }

            ui->manager_face->setStyleSheet("background-color : rgb(68, 114, 196);"
                                            "color: rgb(255, 255, 255);"
                                            "border-style : outset;"
                                            "border-width : 10px;"
                                            "border-radius : 20px;"
                                            "border-color : rgb(129, 143, 168);"
                                            "font: 20pt;"
                                            );

            ui->Parcel_Find_button->setStyleSheet("background-color : rgb(68, 114, 196);"
                                                  "border-style : outset;"
                                                  "border-width : 5px;"
                                                  "border-radius : 35px;"
                                                  "border-color : rgb(129, 143, 168);"
                                                  "color: rgb(255, 255, 255);"
                                                  "font: 15pt;"
                                                  );

            ui->Parcel_Reservation_button->setStyleSheet("background-color : rgb(68, 114, 196);"
                                                         "border-style : outset;"
                                                         "border-width : 5px;"
                                                         "border-radius : 35px;"
                                                         "border-color : rgb(129, 143, 168);"
                                                         "color: rgb(255, 255, 255);"
                                                         "font: 15pt;"
                                                         );
            Client_Login_flg = true;
            Client_Login_log = i;
            return; //로그인 성공시, 밑에 구문 실행시키지 않기 위해서 return 으로 탈출
        }
    }

    //Login인 실패시 label로 로그인 err표시, Pushbutton 색깔 돌리고, err MessageBox 출력

    ui->manager_face->setText("Login Err");
    ui->manager_face->setStyleSheet("background-color : rgb(255, 100, 100);"
                                    "color: rgb(255, 255, 255);"
                                    "border-style : outset;"
                                    "border-width : 10px;"
                                    "border-radius : 20px;"
                                    "border-color : rgb(129, 143, 168);"
                                    "font: 20pt;"
                                    );

    ui->Parcel_Find_button->setStyleSheet("background-color : rgb(255, 100, 100);"
                                          "border-style : outset;"
                                          "border-width : 5px;"
                                          "border-radius : 35px;"
                                          "border-color : rgb(129, 143, 168);"
                                          "color: rgb(255, 255, 255);"
                                          "font: 15pt;"
                                          );

    ui->Parcel_Reservation_button->setStyleSheet("background-color : rgb(255, 100, 100);"
                                                 "border-style : outset;"
                                                 "border-width : 5px;"
                                                 "border-radius : 35px;"
                                                 "border-color : rgb(129, 143, 168);"
                                                 "color: rgb(255, 255, 255);"
                                                 "font: 15pt;"
                                                 );
    QMessageBox::critical(this,kor("No Client ReSource"), kor("로그인 정보가 일치하지 않습니다"));

    Client_Login_flg = false;
    Client_Login_log = NULL;
}

void Client_Login::on_Parcel_Find_button_clicked()
{
    if(Client_Login_flg)
    {
        select_parcel = new Select_parcel(this);
        select_parcel->show();        
    }
    else
        QMessageBox::critical(this,kor("No Client ReSource"), kor("로그인 후 이용하세요"));
}

void Client_Login::on_Parcel_Reservation_button_clicked()
{
    if(Client_Login_flg)
    {
        storage_box = new Storage_box(this);
        storage_box->show();
    }
    else
        QMessageBox::critical(this,kor("No Client ReSource"), kor("로그인 후 이용하세요"));
}
