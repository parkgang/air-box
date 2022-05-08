#include "courier_list.h"
#include "ui_courier_list.h"

#include <mainwindow.h>

int Courier::Courier_cnt = 0;

Courier_list::Courier_list(QWidget *parent) : QMainWindow(parent), ui(new Ui::Courier_list)
{
    ui->setupUi(this);

    QStringList tableHeader;
    tableHeader << kor("이름") << kor("핸드폰번호") << kor("소속");
    ui->tableWidget->setColumnCount(Courier_list_cnt);
    ui->tableWidget->setHorizontalHeaderLabels(tableHeader);

    for(int i = 0; i < Courier::Courier_cnt; i++) //tableWidget person data 업데이트
    {
        ui->tableWidget->insertRow(ui->tableWidget->rowCount());
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem((courier_prt+i)->Get_Name()));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem((courier_prt+i)->Get_Phone()));
        ui->tableWidget->setItem(i, 2, new QTableWidgetItem((courier_prt+i)->Get_Affiliation()));
    }
}

Courier_list::~Courier_list()
{
    delete ui;
}

void Courier_list::on_Add_Button_clicked()
{
    QString Name = ui->Name_lineEdit->text();
    QString Phone = ui->Phone_lineEdit->text();
    QString Affiliation = ui->Affiliation_lineEdit->text();

    if(Name == "" || Phone == "" || Affiliation == "")
            QMessageBox::critical(this,kor("공백 오류"), kor("빈 내용이 있습니다"));
    else
    {
        //중복되는 데이터가 있으면 삽입되지 않는 예외처리 구문추가하기
        (courier_prt+Courier::Courier_cnt)->Set(Name, Phone, Affiliation);

        int index = ui->tableWidget->rowCount();
        ui->tableWidget->insertRow(ui->tableWidget->rowCount());

        ui->tableWidget->setItem(index, 0, new QTableWidgetItem(Name));
        ui->tableWidget->setItem(index, 1, new QTableWidgetItem(Phone));
        ui->tableWidget->setItem(index, 2, new QTableWidgetItem(Affiliation));
    }
}

void Courier_list::on_Delete_Button_clicked()
{
    QString Name = ui->Name_lineEdit->text();

    if(Name == "")
            QMessageBox::critical(this,kor("공백 오류"), kor("삭제할 이름이 입력되지 않았습니다"));
    else
    {
        if(Courier::Delete_Courier(courier_prt, Name))
        {
            ui->tableWidget->removeRow(0);              //tableWidget Row행 한개 삭제
            for(int i = 0; i < Courier::Courier_cnt; i++) //tableWidget person data 업데이트
            {
                ui->tableWidget->setItem(i, 0, new QTableWidgetItem((courier_prt+i)->Get_Name()));
                ui->tableWidget->setItem(i, 1, new QTableWidgetItem((courier_prt+i)->Get_Phone()));
                ui->tableWidget->setItem(i, 2, new QTableWidgetItem((courier_prt+i)->Get_Affiliation()));
            }
        }
        else
            QMessageBox::information(this,"No", kor("고객 정보가 존재하지 않습니다"));
    }
}
