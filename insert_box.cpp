#include "insert_box.h"
#include "ui_insert_box.h"

#include <mainwindow.h>

bool Select_flg;

Insert_box::Insert_box(QWidget *parent) : QMainWindow(parent), ui(new Ui::Insert_box)
{
    ui->setupUi(this);

    //Select_flg = false;

    ui->listWidget->setIconSize(QSize(60,60));

    //���� ��ǰ�Ҷ�, �ù��� ���� �ε�
    if(Client_Login_flg)
    {
        for(int i = 0; i < courier_prt->Courier_cnt; i++)
        {
            QString Name = (courier_prt+i)->Get_Name();
            QString Affiliation = (courier_prt+i)->Get_Affiliation();
            QString Phone = (courier_prt+i)->Get_Phone();

            QListWidgetItem* pItem = new QListWidgetItem; //listWidget ���� ���� ����

            //����Ʈ �����߰�
            pItem->setText(kor(" �̸� : ") + Name + "\n" +
                           kor(" �Ҽ� : ") + Affiliation + "\n" +
                           kor(" ����ȣ : ") + Phone+ + "\n"
                           );

            //������ �߰�
            ui->listWidget->addItem(pItem);
        }
    }
    //�ù��簡 �� �����ҋ�, ������ �ε�
    else if(Courier_Login_flg)
    {
        for(int i = 0; i < person_prt->Person_cnt; i++)
        {
            QString Name = (person_prt+i)->Get_Name();
            QString Birth = (person_prt+i)->Get_Birth();
            QString Phone = (person_prt+i)->Get_Phone();

            QListWidgetItem* pItem = new QListWidgetItem; //listWidget ���� ���� ����

            //����Ʈ �����߰�
            pItem->setText(kor("       �̸� : ") + Name + "\n" +
                           kor("������� : ") + Birth + "\n" +
                           kor("   ����ȣ : ") + Phone+ + "\n"
                           );

            //������ �߰�
            ui->listWidget->addItem(pItem);
        }
    }
}

Insert_box::~Insert_box()
{
    delete ui;
}

void Insert_box::on_Select_Button_clicked()
{
    int i = ui->listWidget->currentRow();    //������ index��ȣ ���

    Select_flg = true;

    //���� �ù��� �����ҋ�
    if(Client_Login_flg)
    {
        ui->Information_label->setText(kor("�ù��� ����"));
        ui->Name_label->setText((courier_prt+i)->Get_Name());

        ui->main_Change_label->setText(kor("�Ҽ�"));
        ui->Change_label->setText((courier_prt+i)->Get_Affiliation());

        ui->Phone_label->setText((courier_prt+i)->Get_Phone());

    }
    //�ù��簡 �� �����ҋ�
    else if(Courier_Login_flg)
    {
        ui->Information_label->setText(kor("������"));
        ui->Name_label->setText((person_prt+i)->Get_Name());

        ui->main_Change_label->setText(kor("�������"));
        ui->Change_label->setText((person_prt+i)->Get_Birth());

        ui->Phone_label->setText((person_prt+i)->Get_Phone());
    }

    //�������� �ε�
    ui->Index_label->setText(QString::number(Select_box_index + 1));

    ui->Intime_label->setText(
                                Get_System_Date().toString(kor("20yy�� MM�� dd��")) +
                                kor(" , ") +
                                Get_System_Time().toString(kor("hh�� mm��"))
                             );
}

void Insert_box::on_Insert_Button_clicked()
{
    QString Text = ui->Text_lineEdit->text();

    if(Select_flg == 0)
        QMessageBox::critical(this,kor("���� ����"), kor("������ ���õ��� �ʾҽ��ϴ�"));
    else if(Text == "")
        QMessageBox::critical(this,kor("���� ����"), kor("ǰ���� �Էµ��� �ʾҽ��ϴ�"));
    else
    {
        int i = ui->listWidget->currentRow();    //������ index��ȣ ���
        //���� �ù��� �����ҋ�
        if(Client_Login_flg)
        {
            (courier_prt+i)->Box_Set(Select_box_index,Get_System_Date(),Get_System_Time(),Text); //������ ������ ����
        }
        //�ù��簡 �� �����ҋ�
        else if(Courier_Login_flg)
        {
            (person_prt+i)->Box_Set(Select_box_index,Get_System_Date(),Get_System_Time(),Text); //������ ������ ����
            this->hide();
        }
        this->hide();
    }
}
