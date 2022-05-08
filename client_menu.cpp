#include "client_menu.h"
#include "ui_client_menu.h"

#include <mainwindow.h>

void Client_menu::Basic_Setting()    //statusbar 데이터 추가
{
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this, SLOT(show_Date_Time()));
    timer->start(1000);

    ui->statusbar->addPermanentWidget(ui->label_date);
    ui->statusbar->addPermanentWidget(ui->label_time);
    ui->statusbar->showMessage(kor("2019551012 ICT융합공학과 박경은 Ver.11.19"));

    //로고 라벨 및 pushbutton에 아이콘추가
    QPixmap Logo(":/image/AirBox.png"); //이미지 경로 설정
    int w = ui->Logo_label->width();    //라벨 W좌표 불러옴
    int h = ui->Logo_label->height();   //라벨 H좌표 불러옴
    ui->Logo_label->setPixmap(Logo);    //이미지 띄우기
    ui->Logo_label->setPixmap(Logo.scaled(w,h,Qt::KeepAspectRatio));  //이미지 픽셀에 맞게 Setting

    QIcon back(":/image/back_button.png");
    ui->Back_Button->setIcon(back);
    ui->Back_Button->setIconSize(QSize(30,30));

    QIcon home(":/image/home_button.png");
    ui->Home_Button->setIcon(home);
    ui->Home_Button->setIconSize(QSize(30,30));
}

Client_menu::Client_menu(QWidget *parent) : QMainWindow(parent), ui(new Ui::Client_menu)
{
    ui->setupUi(this);

    Basic_Setting();
}

Client_menu::~Client_menu()
{
    delete ui;
}
