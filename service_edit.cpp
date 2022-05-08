#include "service_edit.h"
#include "ui_service_edit.h"

#include <mainwindow.h>

Service_edit::Service_edit(QWidget *parent) : QMainWindow(parent), ui(new Ui::Service_edit)
{
    ui->setupUi(this);

    ui->price_label->setText(kor("���� ����") + QString::number(Service_fee) + kor("��"));
}

Service_edit::~Service_edit()
{
    delete ui;
}

void Service_edit::on_Ok_Button_clicked()
{
    QString value = ui->Service_lineEdit->text();

    if(value == "")
        QMessageBox::critical(this,kor("���� ����"), kor("���� �����ϴ�"));
    else
    {
        Service_fee = value.toInt();
        this->hide();
    }
}
