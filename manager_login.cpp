#include "manager_login.h"
#include "ui_manager_login.h"

#include <mainwindow.h>

Manager_Login::Manager_Login(QWidget *parent) : QMainWindow(parent), ui(new Ui::Manager_Login)
{
    ui->setupUi(this);

    QPixmap Logo(":/people/PKE.JPG");   //�̹��� ��� ����
    int w = ui->manager_face->width();    //�� W��ǥ �ҷ���
    int h = ui->manager_face->height();   //�� H��ǥ �ҷ���
    ui->manager_face->setPixmap(Logo);    //�̹��� ����
    ui->manager_face->setPixmap(Logo.scaled(w,h,Qt::KeepAspectRatio));  //�̹��� �ȼ��� �°� Setting
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
        QMessageBox::critical(this,kor("�α��� ����"), kor("���̵�� ��й�ȣ�� �߸� �Էµƽ��ϴ�"));
    }
}
