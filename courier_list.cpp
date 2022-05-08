#include "courier_list.h"
#include "ui_courier_list.h"

#include <mainwindow.h>

int Courier::Courier_cnt = 0;

Courier_list::Courier_list(QWidget *parent) : QMainWindow(parent), ui(new Ui::Courier_list)
{
    ui->setupUi(this);

    QStringList tableHeader;
    tableHeader << kor("�̸�") << kor("�ڵ�����ȣ") << kor("�Ҽ�");
    ui->tableWidget->setColumnCount(Courier_list_cnt);
    ui->tableWidget->setHorizontalHeaderLabels(tableHeader);

    for(int i = 0; i < Courier::Courier_cnt; i++) //tableWidget person data ������Ʈ
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
            QMessageBox::critical(this,kor("���� ����"), kor("�� ������ �ֽ��ϴ�"));
    else
    {
        //�ߺ��Ǵ� �����Ͱ� ������ ���Ե��� �ʴ� ����ó�� �����߰��ϱ�
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
            QMessageBox::critical(this,kor("���� ����"), kor("������ �̸��� �Էµ��� �ʾҽ��ϴ�"));
    else
    {
        if(Courier::Delete_Courier(courier_prt, Name))
        {
            ui->tableWidget->removeRow(0);              //tableWidget Row�� �Ѱ� ����
            for(int i = 0; i < Courier::Courier_cnt; i++) //tableWidget person data ������Ʈ
            {
                ui->tableWidget->setItem(i, 0, new QTableWidgetItem((courier_prt+i)->Get_Name()));
                ui->tableWidget->setItem(i, 1, new QTableWidgetItem((courier_prt+i)->Get_Phone()));
                ui->tableWidget->setItem(i, 2, new QTableWidgetItem((courier_prt+i)->Get_Affiliation()));
            }
        }
        else
            QMessageBox::information(this,"No", kor("�� ������ �������� �ʽ��ϴ�"));
    }
}
