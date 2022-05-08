#include "mainwindow.h"

#include <QApplication>

Person* person_prt;
Courier* courier_prt;
int Service_fee = 1000; //�̿�� �����尪
bool Delivery_box_flg[20];
int Select_box_index = NULL;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    //�ڼ��� �ؾߵǴ� �ڵ��
    //�ù� ��ȣ���� ������ �ٸ��� ����
    //�����Ѱ��� ���� �ù�� ���� ����ϴ��� ����ϱ�
    //Person ������ Client �� ����, �̸��� ��ȣ��
    /* Person�� Courier ���� �޴� Box�� �������� ������, �Լ� �̹Ƿ� ��ӹ޾Ƽ� ����ϵ��� ����
     * ���� struct ������ ������ Courier ������ �̸��� ������
     */
    //������ ���Խ� �ߺ��Ǵ� �����Ͱ� ������ ���Ե��� �ʴ� ����ó�� �����߰��ϱ�
    //payment_window ���� ������ ���������� index �����ϵ��� �ϱ�

    person_prt = new Person[Person_size_MAX];
    courier_prt = new Courier[Courier_size_MAX];

    //�ϵ��ڵ�(������ �����ϱ�)
    (person_prt+0)->Set(":/people/PKE.JPG");
    (person_prt+1)->Set(":/people/JBS.jpg");
    (person_prt+2)->Set(":/people/LIH.jpg");
    (person_prt+8)->Set(":/people/KJG.png");

    (person_prt+Person::Person_cnt)->Set(kor("ȫ�浿01"),"29990101","010-9999-9999",kor("��2��Ȱ��"),"999");
    (person_prt+Person::Person_cnt)->Set(kor("ȫ�浿02"),"29990101","010-9999-9999",kor("��2��Ȱ��"),"999");
    (person_prt+Person::Person_cnt)->Set(kor("ȫ�浿03"),"29990101","010-9999-9999",kor("��2��Ȱ��"),"999");
    (person_prt+Person::Person_cnt)->Set(kor("ȫ�浿04"),"29990101","010-9999-9999",kor("��2��Ȱ��"),"999");
    (person_prt+Person::Person_cnt)->Set(kor("ȫ�浿05"),"29990101","010-9999-9999",kor("��2��Ȱ��"),"999");
    (person_prt+Person::Person_cnt)->Set(kor("ȫ�浿06"),"29990101","010-9999-9999",kor("��2��Ȱ��"),"999");
    (person_prt+Person::Person_cnt)->Set(kor("ȫ�浿07"),"29990101","010-9999-9999",kor("��2��Ȱ��"),"999");
    (person_prt+Person::Person_cnt)->Set(kor("ȫ�浿08"),"29990101","010-9999-9999",kor("��2��Ȱ��"),"999");
    (person_prt+Person::Person_cnt)->Set(kor("ȫ�浿09"),"29990101","010-9999-9999",kor("��2��Ȱ��"),"999");
    (person_prt+Person::Person_cnt)->Set(kor("ȫ�浿10"),"29990101","010-9999-9999",kor("��2��Ȱ��"),"999");
    (person_prt+Person::Person_cnt)->Set(kor("ȫ�浿11"),"29990101","010-9999-9999",kor("��2��Ȱ��"),"999");
    (person_prt+Person::Person_cnt)->Set(kor("ȫ�浿12"),"29990101","010-9999-9999",kor("��2��Ȱ��"),"999");

    (person_prt+Person::Person_cnt)->Set(kor("1"),"1","1",kor("1"),"1");    //����� root ����

    (courier_prt+0)->Set(":/Express_Logo/CJ_Korea_Express_Logo.png");
    (courier_prt+1)->Set(":/Express_Logo/Hanjin_Shipping_Logo.jpg");
    (courier_prt+2)->Set(":/Express_Logo/Lotte_Parcel_Logo.png");
    (courier_prt+3)->Set(":/Express_Logo/Post_office_parcel_Logo.jfif");

    (courier_prt+Courier::Courier_cnt)->Set(kor("ȫ�浿 ���1"),"010-9999-9999",kor("CJ�������"));
    (courier_prt+Courier::Courier_cnt)->Set(kor("ȫ�浿 ���2"),"010-9999-9999",kor("�����ù�"));
    (courier_prt+Courier::Courier_cnt)->Set(kor("ȫ�浿 ���3"),"010-9999-9999",kor("�Ե��ù�"));
    (courier_prt+Courier::Courier_cnt)->Set(kor("ȫ�浿 ���4"),"010-9999-9999",kor("��ü���ù�"));
    (courier_prt+Courier::Courier_cnt)->Set(kor("ȫ�浿 ���5"),"010-9999-9999",kor("�����ù�"));
    (courier_prt+Courier::Courier_cnt)->Set(kor("ȫ�浿 ���6"),"010-9999-9999",kor("�����ͽ�������"));
    (courier_prt+Courier::Courier_cnt)->Set(kor("ȫ�浿 ���7"),"010-9999-9999",kor("KGB�ù�"));

    (courier_prt+Courier::Courier_cnt)->Set(kor("1"),"1",kor("1"));


    QDate temp_date(2019,12,1);
    QTime temp_time(12+8,16);

    (person_prt+0)->Box_Set( 1,temp_date,temp_time,kor("å"));
    (person_prt+0)->Box_Set(11,temp_date,temp_time,kor("����"));

    /*
    (person_prt+12)->Box_Set( 1,Get_System_Date(),Get_System_Time(),kor("å"));
    (person_prt+12)->Box_Set(11,Get_System_Date(),Get_System_Time(),kor("����"));
    (person_prt+12)->Box_Set(15,Get_System_Date(),Get_System_Time(),kor("ĳ����"));
    (person_prt+12)->Box_Set(16,Get_System_Date(),Get_System_Time(),kor("������ǰ"));
    */

    w.show();
    return a.exec();
}
