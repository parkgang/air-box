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

    //고객이 가져가야하는 택배
    if(Client_Login_flg)
    {
        ui->Guide_label->setText(kor("찾으실 택배를 선택하세요"));

        QStringList IconPath;

        IconPath << ":/image/delivery_icon1.png"
                 << ":/image/delivery_icon2.png"
                 << ":/image/delivery_icon3.png"
                 << ":/image/delivery_icon4.png";

        for(int i = 0; i < (person_prt+Client_Login_log)->Get_Box_cnt(); i++)
        {
            int int_index = (person_prt+Client_Login_log)->Get_Box_index(i);
            QString index = kor("★") + QString::number(int_index) + kor("번★ ");
            QString in_date = (person_prt+Client_Login_log)->Get_Box_in_date(i).toString(kor("20yy년 MM월 dd일"));
            QString in_time = (person_prt+Client_Login_log)->Get_Box_in_time(i).toString(kor("hh시 mm분"));
            QString text = kor("품목 : ") + (person_prt+Client_Login_log)->Get_Box_text(i);

            QListWidgetItem* pItem = new QListWidgetItem; //listWidget 동적 변수 선언

            //아이콘 추가(택배함 번호에 따라서 다르게 출력)
            if(int_index < 8)
                pItem->setIcon(QIcon(IconPath.at(0)));
            else if(int_index < 15)
                pItem->setIcon(QIcon(IconPath.at(1)));
            else if(int_index == 15)
                pItem->setIcon(QIcon(IconPath.at(2)));
            else
                pItem->setIcon(QIcon(IconPath.at(3)));

            //리스트 내용추가
            pItem->setText(
                            index + kor("\n") +
                            text + kor("\n") +
                            kor("입고 : ") +
                            in_date + kor(" , ") +
                            in_time
                           );

            //아이템 추가
            ui->listWidget->addItem(pItem);
        }
    }
    //택배기사가 가져가야하는 택배
    else if(Courier_Login_flg)
    {
        ui->Guide_label->setText(kor("수거하실 택배를 선택하세요"));

        for(int i = 0; i < (courier_prt+Courier_Login_log)->Get_Box_cnt(); i++)
        {
            int int_index = (courier_prt+Courier_Login_log)->Get_Box_index(i);
            QString index = kor("★") + QString::number(int_index) + kor("번★ ");
            QString in_date = (courier_prt+Courier_Login_log)->Get_Box_in_date(i).toString(kor("20yy년 MM월 dd일"));
            QString in_time = (courier_prt+Courier_Login_log)->Get_Box_in_time(i).toString(kor("hh시 mm분"));
            QString text = kor("품목 : ") + (courier_prt+Courier_Login_log)->Get_Box_text(i);

            QListWidgetItem* pItem = new QListWidgetItem; //listWidget 동적 변수 선언

            //리스트 내용추가
            pItem->setText(
                            index + kor("\n") +
                            text + kor("\n") +
                            kor("입고 : ") +
                            in_date + kor(" , ") +
                            in_time
                           );

            //아이템 추가
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
    QMessageBox::StandardButton value = QMessageBox::question(this, "Select", ui->listWidget->currentItem()->text() + kor("의 택배함을 선택하시겠습니까?"), QMessageBox::Yes | QMessageBox::No);
    if(value == QMessageBox::Yes)   //Yes 버튼 동작
    {
        Select_parcel_log = ui->listWidget->currentRow();    //선택한 index번호 출력

        //고객이 가져가야하는 택배
        if(Client_Login_flg)
        {
            payment_window = new Payment_window(this);
            payment_window->show();

            //★payment_window 에서 결제를 눌렀을때만 index 제거하도록 하기
            ui->listWidget->takeItem(Select_parcel_log);                                //Widget상에서 선택한 index번호 아이템 삭제

            int index = (person_prt+Client_Login_log)->Get_Box_index(Select_parcel_log);
            Delivery_box_flg[index] = false;

            (person_prt+Client_Login_log)->Delete_Person_Box_Data(Select_parcel_log);   //Person class안에 있는 Box 스트럭처 데이터 삭제
        }
        //택배기사가 가져가야하는 택배
        else if(Courier_Login_flg)
        {
            //★payment_window 에서 결제를 눌렀을때만 index 제거하도록 하기
            ui->listWidget->takeItem(Select_parcel_log);                                //Widget상에서 선택한 index번호 아이템 삭제

            int index = (courier_prt+Courier_Login_log)->Get_Box_index(Select_parcel_log);
            Delivery_box_flg[index] = false;

            (courier_prt+Courier_Login_log)->Delete_Person_Box_Data(Select_parcel_log);   //Person class안에 있는 Box 스트럭처 데이터 삭제
        }
    }
    else                            // No 버튼 동작
    {

    }
}
