#include "client_list.h"
#include "ui_client_list.h"

#include <mainwindow.h>

int Person::Person_cnt = 0;

Client_list::Client_list(QWidget *parent) : QMainWindow(parent), ui(new Ui::Client_list)
{
    ui->setupUi(this);

    QStringList tableHeader;
    tableHeader << kor("이름") << kor("생년월일") << kor("핸드폰번호") << kor("동") << kor("호수");
    ui->tableWidget->setColumnCount(Person_list_cnt);
    ui->tableWidget->setHorizontalHeaderLabels(tableHeader);

    for(int i = 0; i < Person::Person_cnt; i++) //tableWidget person data 업데이트
    {
        ui->tableWidget->insertRow(ui->tableWidget->rowCount());
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem((person_prt+i)->Get_Name()));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem((person_prt+i)->Get_Birth()));
        ui->tableWidget->setItem(i, 2, new QTableWidgetItem((person_prt+i)->Get_Phone()));
        ui->tableWidget->setItem(i, 3, new QTableWidgetItem((person_prt+i)->Get_Block()));
        ui->tableWidget->setItem(i, 4, new QTableWidgetItem((person_prt+i)->Get_Unit()));
    }
}

Client_list::~Client_list()
{
    delete ui;
}

void Client_list::on_Add_Button_clicked()
{
    QString Name = ui->Name_lineEdit->text();
    QString Birth = ui->Birth_lineEdit->text();
    QString Phone = ui->Phone_lineEdit->text();
    QString Block = ui->Block_lineEdit->text();
    QString Unit = ui->Unit_lineEdit->text();

    if(Name == "" || Birth == "" || Phone == "" || Block == "" || Unit=="")
            QMessageBox::critical(this,kor("공백 오류"), kor("빈 내용이 있습니다"));
    else
    {
        //★중복되는 데이터가 있으면 삽입되지 않는 예외처리 구문추가하기
        (person_prt+Person::Person_cnt)->Set(Name, Birth, Phone, Block, Unit);

        int index = ui->tableWidget->rowCount();
        ui->tableWidget->insertRow(ui->tableWidget->rowCount());

        ui->tableWidget->setItem(index, 0, new QTableWidgetItem(Name));
        ui->tableWidget->setItem(index, 1, new QTableWidgetItem(Birth));
        ui->tableWidget->setItem(index, 2, new QTableWidgetItem(Phone));
        ui->tableWidget->setItem(index, 3, new QTableWidgetItem(Block));
        ui->tableWidget->setItem(index, 4, new QTableWidgetItem(Unit));
    }
}

void Client_list::on_Delete_Button_clicked()
{
    QString Name = ui->Name_lineEdit->text();

    if(Name == "")
            QMessageBox::critical(this,kor("공백 오류"), kor("삭제할 이름이 입력되지 않았습니다"));
    else
    {
        if(Person::Delete_Person(person_prt, Name))
        {
            ui->tableWidget->removeRow(0);              //tableWidget Row행 한개 삭제
            for(int i = 0; i < Person::Person_cnt; i++) //tableWidget person data 업데이트
            {
                ui->tableWidget->setItem(i, 0, new QTableWidgetItem((person_prt+i)->Get_Name()));
                ui->tableWidget->setItem(i, 1, new QTableWidgetItem((person_prt+i)->Get_Birth()));
                ui->tableWidget->setItem(i, 2, new QTableWidgetItem((person_prt+i)->Get_Phone()));
                ui->tableWidget->setItem(i, 3, new QTableWidgetItem((person_prt+i)->Get_Block()));
                ui->tableWidget->setItem(i, 4, new QTableWidgetItem((person_prt+i)->Get_Unit()));
            }
        }
        else
            QMessageBox::information(this,"No", kor("고객 정보가 존재하지 않습니다"));
    }
}
