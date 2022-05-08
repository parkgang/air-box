#include "select_parcel.h"
#include "ui_select_parcel.h"

#include <mainwindow.h>
#include <client_login.h>
#include <QDebug>

int Select_parcel_log = 0;

Select_parcel::Select_parcel(QWidget *parent) : QMainWindow(parent), ui(new Ui::Select_parcel)
{
    ui->setupUi(this);

    ui->listWidget->setIconSize(QSize(70,70));    

    //���� ���������ϴ� �ù�
    if(Client_Login_flg)
    {
        ui->Guide_label->setText(kor("ã���� �ù踦 �����ϼ���"));

        QStringList IconPath;

        IconPath << ":/image/delivery_icon1.png"
                 << ":/image/delivery_icon2.png"
                 << ":/image/delivery_icon3.png"
                 << ":/image/delivery_icon4.png";

        for(int i = 0; i < (person_prt+Client_Login_log)->Get_Box_cnt(); i++)
        {
            int int_index = (person_prt+Client_Login_log)->Get_Box_index(i);
            QString index = kor("��") + QString::number(int_index) + kor("���� ");
            QString in_date = (person_prt+Client_Login_log)->Get_Box_in_date(i).toString(kor("20yy�� MM�� dd��"));
            QString in_time = (person_prt+Client_Login_log)->Get_Box_in_time(i).toString(kor("hh�� mm��"));
            QString text = kor("ǰ�� : ") + (person_prt+Client_Login_log)->Get_Box_text(i);

            QListWidgetItem* pItem = new QListWidgetItem; //listWidget ���� ���� ����

            //������ �߰�(�ù��� ��ȣ�� ���� �ٸ��� ���)
            if(int_index < 8)
                pItem->setIcon(QIcon(IconPath.at(0)));
            else if(int_index < 15)
                pItem->setIcon(QIcon(IconPath.at(1)));
            else if(int_index == 15)
                pItem->setIcon(QIcon(IconPath.at(2)));
            else
                pItem->setIcon(QIcon(IconPath.at(3)));

            //����Ʈ �����߰�
            pItem->setText(
                            index + kor("\n") +
                            text + kor("\n") +
                            kor("�԰� : ") +
                            in_date + kor(" , ") +
                            in_time
                           );

            //������ �߰�
            ui->listWidget->addItem(pItem);
        }
    }
    //�ù��簡 ���������ϴ� �ù�
    else if(Courier_Login_flg)
    {
        ui->Guide_label->setText(kor("�����Ͻ� �ù踦 �����ϼ���"));

        for(int i = 0; i < (courier_prt+Courier_Login_log)->Get_Box_cnt(); i++)
        {
            int int_index = (courier_prt+Courier_Login_log)->Get_Box_index(i);
            QString index = kor("��") + QString::number(int_index) + kor("���� ");
            QString in_date = (courier_prt+Courier_Login_log)->Get_Box_in_date(i).toString(kor("20yy�� MM�� dd��"));
            QString in_time = (courier_prt+Courier_Login_log)->Get_Box_in_time(i).toString(kor("hh�� mm��"));
            QString text = kor("ǰ�� : ") + (courier_prt+Courier_Login_log)->Get_Box_text(i);

            QListWidgetItem* pItem = new QListWidgetItem; //listWidget ���� ���� ����

            //����Ʈ �����߰�
            pItem->setText(
                            index + kor("\n") +
                            text + kor("\n") +
                            kor("�԰� : ") +
                            in_date + kor(" , ") +
                            in_time
                           );

            //������ �߰�
            ui->listWidget->addItem(pItem);
        }
    }
}

Select_parcel::~Select_parcel()
{
    delete ui;
}

void Select_parcel::on_Select_pushButton_clicked()
{    
    QMessageBox::StandardButton value = QMessageBox::question(this, "Select", ui->listWidget->currentItem()->text() + kor("�� �ù����� �����Ͻðڽ��ϱ�?"), QMessageBox::Yes | QMessageBox::No);
    if(value == QMessageBox::Yes)   //Yes ��ư ����
    {
        Select_parcel_log = ui->listWidget->currentRow();    //������ index��ȣ ���

        //���� ���������ϴ� �ù�
        if(Client_Login_flg)
        {
            payment_window = new Payment_window(this);
            payment_window->show();

            //��payment_window ���� ������ ���������� index �����ϵ��� �ϱ�
            ui->listWidget->takeItem(Select_parcel_log);                                //Widget�󿡼� ������ index��ȣ ������ ����

            int index = (person_prt+Client_Login_log)->Get_Box_index(Select_parcel_log);
            Delivery_box_flg[index] = false;

            (person_prt+Client_Login_log)->Delete_Person_Box_Data(Select_parcel_log);   //Person class�ȿ� �ִ� Box ��Ʈ��ó ������ ����
        }
        //�ù��簡 ���������ϴ� �ù�
        else if(Courier_Login_flg)
        {
            //��payment_window ���� ������ ���������� index �����ϵ��� �ϱ�
            ui->listWidget->takeItem(Select_parcel_log);                                //Widget�󿡼� ������ index��ȣ ������ ����

            int index = (courier_prt+Courier_Login_log)->Get_Box_index(Select_parcel_log);
            Delivery_box_flg[index] = false;

            (courier_prt+Courier_Login_log)->Delete_Person_Box_Data(Select_parcel_log);   //Person class�ȿ� �ִ� Box ��Ʈ��ó ������ ����
        }
    }
    else                            // No ��ư ����
    {

    }
}
