#include "insert_box.h"
#include "ui_insert_box.h"

#include <mainwindow.h>

bool Select_flg;

Insert_box::Insert_box(QWidget *parent) : QMainWindow(parent), ui(new Ui::Insert_box)
{
    ui->setupUi(this);

    //Select_flg = false;

    ui->listWidget->setIconSize(QSize(60,60));

    //고객이 반품할때, 택배기사 정보 로딩
    if(Client_Login_flg)
    {
        for(int i = 0; i < courier_prt->Courier_cnt; i++)
        {
            QString Name = (courier_prt+i)->Get_Name();
            QString Affiliation = (courier_prt+i)->Get_Affiliation();
            QString Phone = (courier_prt+i)->Get_Phone();

            QListWidgetItem* pItem = new QListWidgetItem; //listWidget 동적 변수 선언

            //리스트 내용추가
            pItem->setText(kor(" 이름 : ") + Name + "\n" +
                           kor(" 소속 : ") + Affiliation + "\n" +
                           kor(" 폰번호 : ") + Phone+ + "\n"
                           );

            //아이템 추가
            ui->listWidget->addItem(pItem);
        }
    }
    //택배기사가 고객 선택할떄, 고객정보 로딩
    else if(Courier_Login_flg)
    {
        for(int i = 0; i < person_prt->Person_cnt; i++)
        {
            QString Name = (person_prt+i)->Get_Name();
            QString Birth = (person_prt+i)->Get_Birth();
            QString Phone = (person_prt+i)->Get_Phone();

            QListWidgetItem* pItem = new QListWidgetItem; //listWidget 동적 변수 선언

            //리스트 내용추가
            pItem->setText(kor("       이름 : ") + Name + "\n" +
                           kor("생년월일 : ") + Birth + "\n" +
                           kor("   폰번호 : ") + Phone+ + "\n"
                           );

            //아이템 추가
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
    int i = ui->listWidget->currentRow();    //선택한 index번호 출력

    Select_flg = true;

    //고객이 택배기사 선택할떄
    if(Client_Login_flg)
    {
        ui->Information_label->setText(kor("택배기사 정보"));
        ui->Name_label->setText((courier_prt+i)->Get_Name());

        ui->main_Change_label->setText(kor("소속"));
        ui->Change_label->setText((courier_prt+i)->Get_Affiliation());

        ui->Phone_label->setText((courier_prt+i)->Get_Phone());

    }
    //택배기사가 고객 선택할떄
    else if(Courier_Login_flg)
    {
        ui->Information_label->setText(kor("고객정보"));
        ui->Name_label->setText((person_prt+i)->Get_Name());

        ui->main_Change_label->setText(kor("생년월일"));
        ui->Change_label->setText((person_prt+i)->Get_Birth());

        ui->Phone_label->setText((person_prt+i)->Get_Phone());
    }

    //공통정보 로딩
    ui->Index_label->setText(QString::number(Select_box_index + 1));

    ui->Intime_label->setText(
                                Get_System_Date().toString(kor("20yy년 MM월 dd일")) +
                                kor(" , ") +
                                Get_System_Time().toString(kor("hh시 mm분"))
                             );
}

void Insert_box::on_Insert_Button_clicked()
{
    QString Text = ui->Text_lineEdit->text();

    if(Select_flg == 0)
        QMessageBox::critical(this,kor("정보 없음"), kor("정보가 선택되지 않았습니다"));
    else if(Text == "")
        QMessageBox::critical(this,kor("공백 오류"), kor("품목이 입력되지 않았습니다"));
    else
    {
        int i = ui->listWidget->currentRow();    //선택한 index번호 출력
        //고객이 택배기사 선택할떄
        if(Client_Login_flg)
        {
            (courier_prt+i)->Box_Set(Select_box_index,Get_System_Date(),Get_System_Time(),Text); //고객에게 데이터 삽입
        }
        //택배기사가 고객 선택할떄
        else if(Courier_Login_flg)
        {
            (person_prt+i)->Box_Set(Select_box_index,Get_System_Date(),Get_System_Time(),Text); //고객에게 데이터 삽입
            this->hide();
        }
        this->hide();
    }
}
