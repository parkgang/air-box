#include "client_list.h"
#include "ui_client_list.h"

#include <mainwindow.h>

int Person::Person_cnt = 0;

Client_list::Client_list(QWidget *parent) : QMainWindow(parent), ui(new Ui::Client_list)
{
    ui->setupUi(this);

    QStringList tableHeader;
    tableHeader << kor("�̸�") << kor("�������") << kor("�ڵ�����ȣ") << kor("��") << kor("ȣ��");
    ui->tableWidget->setColumnCount(Person_list_cnt);
    ui->tableWidget->setHorizontalHeaderLabels(tableHeader);

    for(int i = 0; i < Person::Person_cnt; i++) //tableWidget person data ������Ʈ
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
            QMessageBox::critical(this,kor("���� ����"), kor("�� ������ �ֽ��ϴ�"));
    else
    {
        //���ߺ��Ǵ� �����Ͱ� ������ ���Ե��� �ʴ� ����ó�� �����߰��ϱ�
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
            QMessageBox::critical(this,kor("���� ����"), kor("������ �̸��� �Էµ��� �ʾҽ��ϴ�"));
    else
    {
        if(Person::Delete_Person(person_prt, Name))
        {
            ui->tableWidget->removeRow(0);              //tableWidget Row�� �Ѱ� ����
            for(int i = 0; i < Person::Person_cnt; i++) //tableWidget person data ������Ʈ
            {
                ui->tableWidget->setItem(i, 0, new QTableWidgetItem((person_prt+i)->Get_Name()));
                ui->tableWidget->setItem(i, 1, new QTableWidgetItem((person_prt+i)->Get_Birth()));
                ui->tableWidget->setItem(i, 2, new QTableWidgetItem((person_prt+i)->Get_Phone()));
                ui->tableWidget->setItem(i, 3, new QTableWidgetItem((person_prt+i)->Get_Block()));
                ui->tableWidget->setItem(i, 4, new QTableWidgetItem((person_prt+i)->Get_Unit()));
            }
        }
        else
            QMessageBox::information(this,"No", kor("�� ������ �������� �ʽ��ϴ�"));
    }
}
