#include "storage_box.h"
#include "ui_storage_box.h"

#include <mainwindow.h>
#include <QDebug>
#include <QMessageBox>

void Storage_box::Update_Storage_Box()
{
    QString insert_cmd = "background-color : rgb(255, 255, 255);"
                         "border-style : outset;"
                         "border-width : 3px;"
                         "border-radius : 5px;"
                         "border-color : rgb(129, 143, 168);";

    QString delete_cmd = "background-color : rgb(68, 114, 196);"
                         "border-style : outset;"
                         "border-width : 3px;"
                         "border-radius : 5px;"
                         "border-color : rgb(129, 143, 168);";

    if(Delivery_box_flg[0] == true) ui->pushButton_1->setStyleSheet(insert_cmd);
    else                            ui->pushButton_1->setStyleSheet(delete_cmd);

    if(Delivery_box_flg[1] == true) ui->pushButton_2->setStyleSheet(insert_cmd);
    else                            ui->pushButton_2->setStyleSheet(delete_cmd);

    if(Delivery_box_flg[2] == true) ui->pushButton_3->setStyleSheet(insert_cmd);
    else                            ui->pushButton_3->setStyleSheet(delete_cmd);

    if(Delivery_box_flg[3] == true) ui->pushButton_4->setStyleSheet(insert_cmd);
    else                            ui->pushButton_4->setStyleSheet(delete_cmd);

    if(Delivery_box_flg[4] == true) ui->pushButton_5->setStyleSheet(insert_cmd);
    else                            ui->pushButton_5->setStyleSheet(delete_cmd);

    if(Delivery_box_flg[5] == true) ui->pushButton_6->setStyleSheet(insert_cmd);
    else                            ui->pushButton_6->setStyleSheet(delete_cmd);

    if(Delivery_box_flg[6] == true) ui->pushButton_7->setStyleSheet(insert_cmd);
    else                            ui->pushButton_7->setStyleSheet(delete_cmd);

    if(Delivery_box_flg[7] == true) ui->pushButton_8->setStyleSheet(insert_cmd);
    else                            ui->pushButton_8->setStyleSheet(delete_cmd);

    if(Delivery_box_flg[8] == true) ui->pushButton_9->setStyleSheet(insert_cmd);
    else                            ui->pushButton_9->setStyleSheet(delete_cmd);

    if(Delivery_box_flg[9] == true) ui->pushButton_10->setStyleSheet(insert_cmd);
    else                            ui->pushButton_10->setStyleSheet(delete_cmd);

    if(Delivery_box_flg[10] == true) ui->pushButton_11->setStyleSheet(insert_cmd);
    else                             ui->pushButton_11->setStyleSheet(delete_cmd);

    if(Delivery_box_flg[11] == true) ui->pushButton_12->setStyleSheet(insert_cmd);
    else                             ui->pushButton_12->setStyleSheet(delete_cmd);

    if(Delivery_box_flg[12] == true) ui->pushButton_13->setStyleSheet(insert_cmd);
    else                             ui->pushButton_13->setStyleSheet(delete_cmd);

    if(Delivery_box_flg[13] == true) ui->pushButton_14->setStyleSheet(insert_cmd);
    else                             ui->pushButton_14->setStyleSheet(delete_cmd);

    if(Delivery_box_flg[14] == true) ui->pushButton_15->setStyleSheet(insert_cmd);
    else                             ui->pushButton_15->setStyleSheet(delete_cmd);

    if(Delivery_box_flg[15] == true) ui->pushButton_16->setStyleSheet(insert_cmd);
    else                             ui->pushButton_16->setStyleSheet(delete_cmd);

    if(Delivery_box_flg[16] == true) ui->pushButton_17->setStyleSheet(insert_cmd);
    else                             ui->pushButton_17->setStyleSheet(delete_cmd);

    if(Delivery_box_flg[17] == true) ui->pushButton_18->setStyleSheet(insert_cmd);
    else                             ui->pushButton_18->setStyleSheet(delete_cmd);

    if(Delivery_box_flg[18] == true) ui->pushButton_19->setStyleSheet(insert_cmd);
    else                             ui->pushButton_19->setStyleSheet(delete_cmd);

    if(Delivery_box_flg[19] == true) ui->pushButton_20->setStyleSheet(insert_cmd);
    else                             ui->pushButton_20->setStyleSheet(delete_cmd);
}

void Storage_box::Storage_Box_flg(int num)
{
    if(Client_Login_flg || Courier_Login_flg)
    {
        Select_box_index = num;
        if(Delivery_box_flg[Select_box_index] == 0)
        {
            Delivery_box_flg[Select_box_index] = true;
            qDebug() << Select_box_index;
            this->hide();
            insert_box->show();
        }
        else
            QMessageBox::critical(this,kor("No"), kor("사용중인 보관함 입니다"));
    }
}

Storage_box::Storage_box(QWidget *parent) : QMainWindow(parent), ui(new Ui::Storage_box)
{
    ui->setupUi(this);

    if(Client_Login_flg || Courier_Login_flg)
        ui->Guide_label->setText(kor("★ 맞기실 택배의 보관함을 선택하세요 ★"));
    else
        ui->Guide_label->setText("");

    insert_box = new Insert_box(this);

    for(int i=0;i<20;i++)
        qDebug() << i << kor("번 : ") << Delivery_box_flg[i];

    Update_Storage_Box();
}

Storage_box::~Storage_box()
{
    delete ui;
}

void Storage_box::on_pushButton_1_clicked()
{
    Storage_Box_flg(0);
}

void Storage_box::on_pushButton_2_clicked()
{
    Storage_Box_flg(1);
}

void Storage_box::on_pushButton_3_clicked()
{
    Storage_Box_flg(2);
}

void Storage_box::on_pushButton_4_clicked()
{
    Storage_Box_flg(3);
}

void Storage_box::on_pushButton_5_clicked()
{
    Storage_Box_flg(4);
}

void Storage_box::on_pushButton_6_clicked()
{
    Storage_Box_flg(5);
}

void Storage_box::on_pushButton_7_clicked()
{
    Storage_Box_flg(6);
}

void Storage_box::on_pushButton_8_clicked()
{
    Storage_Box_flg(7);
}

void Storage_box::on_pushButton_9_clicked()
{
    Storage_Box_flg(8);
}

void Storage_box::on_pushButton_10_clicked()
{
    Storage_Box_flg(9);
}

void Storage_box::on_pushButton_11_clicked()
{
    Storage_Box_flg(10);
}

void Storage_box::on_pushButton_12_clicked()
{
    Storage_Box_flg(11);
}

void Storage_box::on_pushButton_13_clicked()
{
    Storage_Box_flg(12);
}

void Storage_box::on_pushButton_14_clicked()
{
    Storage_Box_flg(13);
}

void Storage_box::on_pushButton_15_clicked()
{
    Storage_Box_flg(14);
}

void Storage_box::on_pushButton_16_clicked()
{
    Storage_Box_flg(15);
}

void Storage_box::on_pushButton_17_clicked()
{
    Storage_Box_flg(16);
}

void Storage_box::on_pushButton_18_clicked()
{
    Storage_Box_flg(17);
}

void Storage_box::on_pushButton_19_clicked()
{
    Storage_Box_flg(18);
}

void Storage_box::on_pushButton_20_clicked()
{
    Storage_Box_flg(19);
}
