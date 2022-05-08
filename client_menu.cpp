#include "client_menu.h"
#include "ui_client_menu.h"

#include <mainwindow.h>

void Client_menu::Basic_Setting()    //statusbar ������ �߰�
{
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this, SLOT(show_Date_Time()));
    timer->start(1000);

    ui->statusbar->addPermanentWidget(ui->label_date);
    ui->statusbar->addPermanentWidget(ui->label_time);
    ui->statusbar->showMessage(kor("2019551012 ICT���հ��а� �ڰ��� Ver.11.19"));

    //�ΰ� �� �� pushbutton�� �������߰�
    QPixmap Logo(":/image/AirBox.png"); //�̹��� ��� ����
    int w = ui->Logo_label->width();    //�� W��ǥ �ҷ���
    int h = ui->Logo_label->height();   //�� H��ǥ �ҷ���
    ui->Logo_label->setPixmap(Logo);    //�̹��� ����
    ui->Logo_label->setPixmap(Logo.scaled(w,h,Qt::KeepAspectRatio));  //�̹��� �ȼ��� �°� Setting

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
