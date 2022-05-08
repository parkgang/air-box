#include "manager_login.h"
#include "ui_manager_login.h"

#include <mainwindow.h>

Manager_Login::Manager_Login(QWidget *parent) : QMainWindow(parent), ui(new Ui::Manager_Login)
{
    ui->setupUi(this);

    QPixmap Logo(":/people/PKE.JPG");   //이미지 경로 설정
    int w = ui->manager_face->width();    //라벨 W좌표 불러옴
    int h = ui->manager_face->height();   //라벨 H좌표 불러옴
    ui->manager_face->setPixmap(Logo);    //이미지 띄우기
    ui->manager_face->setPixmap(Logo.scaled(w,h,Qt::KeepAspectRatio));  //이미지 픽셀에 맞게 Setting
}

Manager_Login::~Manager_Login()
{
    delete ui;
}

void Manager_Login::on_Login_Button_clicked()
{
    QString root_ID = "123";
    QString root_PW = "123";

    QString id = ui->Id_lineEdit->text();
    QString pw = ui->Password_lineEdit->text();

    if(id == root_ID && pw == root_PW)
    {
        manager_Menu = new Manager_Menu(this);
        manager_Menu->show();
        this->hide();
    }
    else
    {
        QMessageBox::critical(this,kor("로그인 실패"), kor("아이디와 비밀번호가 잘못 입력됐습니다"));
    }
}
