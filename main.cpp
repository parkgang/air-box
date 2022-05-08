#include "mainwindow.h"

#include <QApplication>

Person* person_prt;
Courier* courier_prt;
int Service_fee = 1000; //이용료 디폴드값
bool Delivery_box_flg[20];
int Select_box_index = NULL;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    //★수정 해야되는 코드들
    //택배 번호마다 아이콘 다른거 설명
    //선택한곳에 무슨 택배랑 누가 사용하는지 명시하기
    //Person 변수명 Client 로 변경, 이름이 모호함
    /* Person와 Courier 에서 받는 Box는 공동적인 데이터, 함수 이므로 상속받아서 사용하도록 수정
     * 현제 struct 재정의 떄문에 Courier 에서는 이름을 변경함
     */
    //데이터 삽입시 중복되는 데이터가 있으면 삽입되지 않는 예외처리 구문추가하기
    //payment_window 에서 결제를 눌렀을때만 index 제거하도록 하기

    person_prt = new Person[Person_size_MAX];
    courier_prt = new Courier[Courier_size_MAX];

    //하드코딩(데이터 수정하기)
    (person_prt+0)->Set(":/people/PKE.JPG");
    (person_prt+1)->Set(":/people/JBS.jpg");
    (person_prt+2)->Set(":/people/LIH.jpg");
    (person_prt+8)->Set(":/people/KJG.png");

    (person_prt+Person::Person_cnt)->Set(kor("홍길동01"),"29990101","010-9999-9999",kor("제2생활관"),"999");
    (person_prt+Person::Person_cnt)->Set(kor("홍길동02"),"29990101","010-9999-9999",kor("제2생활관"),"999");
    (person_prt+Person::Person_cnt)->Set(kor("홍길동03"),"29990101","010-9999-9999",kor("제2생활관"),"999");
    (person_prt+Person::Person_cnt)->Set(kor("홍길동04"),"29990101","010-9999-9999",kor("제2생활관"),"999");
    (person_prt+Person::Person_cnt)->Set(kor("홍길동05"),"29990101","010-9999-9999",kor("제2생활관"),"999");
    (person_prt+Person::Person_cnt)->Set(kor("홍길동06"),"29990101","010-9999-9999",kor("제2생활관"),"999");
    (person_prt+Person::Person_cnt)->Set(kor("홍길동07"),"29990101","010-9999-9999",kor("제2생활관"),"999");
    (person_prt+Person::Person_cnt)->Set(kor("홍길동08"),"29990101","010-9999-9999",kor("제2생활관"),"999");
    (person_prt+Person::Person_cnt)->Set(kor("홍길동09"),"29990101","010-9999-9999",kor("제2생활관"),"999");
    (person_prt+Person::Person_cnt)->Set(kor("홍길동10"),"29990101","010-9999-9999",kor("제2생활관"),"999");
    (person_prt+Person::Person_cnt)->Set(kor("홍길동11"),"29990101","010-9999-9999",kor("제2생활관"),"999");
    (person_prt+Person::Person_cnt)->Set(kor("홍길동12"),"29990101","010-9999-9999",kor("제2생활관"),"999");

    (person_prt+Person::Person_cnt)->Set(kor("1"),"1","1",kor("1"),"1");    //사용자 root 계정

    (courier_prt+0)->Set(":/Express_Logo/CJ_Korea_Express_Logo.png");
    (courier_prt+1)->Set(":/Express_Logo/Hanjin_Shipping_Logo.jpg");
    (courier_prt+2)->Set(":/Express_Logo/Lotte_Parcel_Logo.png");
    (courier_prt+3)->Set(":/Express_Logo/Post_office_parcel_Logo.jfif");

    (courier_prt+Courier::Courier_cnt)->Set(kor("홍길동 기사1"),"010-9999-9999",kor("CJ대한통운"));
    (courier_prt+Courier::Courier_cnt)->Set(kor("홍길동 기사2"),"010-9999-9999",kor("한진택배"));
    (courier_prt+Courier::Courier_cnt)->Set(kor("홍길동 기사3"),"010-9999-9999",kor("롯데택배"));
    (courier_prt+Courier::Courier_cnt)->Set(kor("홍길동 기사4"),"010-9999-9999",kor("우체국택배"));
    (courier_prt+Courier::Courier_cnt)->Set(kor("홍길동 기사5"),"010-9999-9999",kor("로젠택배"));
    (courier_prt+Courier::Courier_cnt)->Set(kor("홍길동 기사6"),"010-9999-9999",kor("동부익스프레스"));
    (courier_prt+Courier::Courier_cnt)->Set(kor("홍길동 기사7"),"010-9999-9999",kor("KGB택배"));

    (courier_prt+Courier::Courier_cnt)->Set(kor("1"),"1",kor("1"));


    QDate temp_date(2019,12,1);
    QTime temp_time(12+8,16);

    (person_prt+0)->Box_Set( 1,temp_date,temp_time,kor("책"));
    (person_prt+0)->Box_Set(11,temp_date,temp_time,kor("과일"));

    /*
    (person_prt+12)->Box_Set( 1,Get_System_Date(),Get_System_Time(),kor("책"));
    (person_prt+12)->Box_Set(11,Get_System_Date(),Get_System_Time(),kor("과일"));
    (person_prt+12)->Box_Set(15,Get_System_Date(),Get_System_Time(),kor("캐리어"));
    (person_prt+12)->Box_Set(16,Get_System_Date(),Get_System_Time(),kor("가전제품"));
    */

    w.show();
    return a.exec();
}
