#include "service_edit.h"
#include "ui_service_edit.h"

#include <mainwindow.h>

Service_edit::Service_edit(QWidget *parent) : QMainWindow(parent), ui(new Ui::Service_edit)
{
    ui->setupUi(this);

    ui->price_label->setText(kor("현재 가격") + QString::number(Service_fee) + kor("원"));
}

Service_edit::~Service_edit()
{
    delete ui;
}

void Service_edit::on_Ok_Button_clicked()
{
    QString value = ui->Service_lineEdit->text();

    if(value == "")
        QMessageBox::critical(this,kor("공백 오류"), kor("값이 없습니다"));
    else
    {
        Service_fee = value.toInt();
        this->hide();
    }
}
