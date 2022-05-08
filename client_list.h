#ifndef CLIENT_LIST_H
#define CLIENT_LIST_H

#include <QMainWindow>
#include <QMessageBox>
#include <QDateTime>
#include <QDebug>

#define Person_size_MAX 200
#define Person_list_cnt 5

typedef struct Box_Data
{
    int index;      //택배함 번호
    QDate in_date;  //택배 입고 날짜
    QTime in_time;  //택배 입고 시간    
    QString text;   //품목(내용)
}Box_Data;

namespace Ui
{
    class Client_list;
}

class Person
{
private:
    QString Name;
    QString Birth;
    QString Phone;
    QString Block;
    QString Unit;
    QString Image_path; //Login_image Path Save

    int Box_cnt=0;        //Box_Data 갯수
    Box_Data Box[20];
public:
    static int Person_cnt;
    void Set(QString Image_path)
    {
        this->Image_path = Image_path;
    }
    void Set(QString Name, QString Birth, QString Phone, QString Block, QString Unit)
    {
        this->Name = Name;
        this->Birth = Birth;
        this->Phone = Phone;
        this->Block = Block;
        this->Unit = Unit;
        Person::Person_cnt++;
    }    
    void Box_Set(int index, QDate in_date, QTime in_time, QString text)
    {
        (Box+Box_cnt)->index = index;
        (Box+Box_cnt)->in_date = in_date;
        (Box+Box_cnt)->in_time = in_time;
        (Box+Box_cnt)->text = text;
        Box_cnt++;
    }
    static bool Delete_Person(Person* person_prt, QString Name)
    {
        for (int i = 0; i < Person::Person_cnt; i++)
        {
            if ((person_prt+i)->Name == Name)
            {
                for (int j = i; j < Person_size_MAX - 1; j++)
                {
                    (person_prt+j)->Name = (person_prt+j+1)->Name;
                    (person_prt+j)->Birth = (person_prt+j+1)->Birth;
                    (person_prt+j)->Phone = (person_prt+j+1)->Phone;
                    (person_prt+j)->Block = (person_prt+j+1)->Block;
                    (person_prt+j)->Unit = (person_prt+j+1)->Unit;
                }
                Person::Person_cnt--;
                return true;
            }
        }
        return false;
    }
    void Delete_Person_Box_Data(int index)
    {
        for (int i = index; i < 20 - 1; i++)
        {
            Box[i].index = Box[i + 1].index;
            Box[i].in_date = Box[i + 1].in_date;
            Box[i].in_time = Box[i + 1].in_time;
            Box[i].text = Box[i + 1].text;
        }
        Box_cnt--;
    }
    QString Get_Name(){ return this->Name; }
    QString Get_Birth(){ return this->Birth; }
    QString Get_Phone(){ return this->Phone; }
    QString Get_Block(){ return this->Block; }
    QString Get_Unit(){ return this->Unit; }
    QString Get_Image_path(){ return this->Image_path; }

    int Get_Box_cnt() {return this->Box_cnt; }
    int Get_Box_index(int num) { return (Box+num)->index; }
    QDate Get_Box_in_date(int num) { return (Box+num)->in_date; }
    QTime Get_Box_in_time(int num) { return (Box+num)->in_time; }
    QString Get_Box_text(int num) { return (Box+num)->text; }
};

class Client_list : public QMainWindow
{
    Q_OBJECT

public:
    explicit Client_list(QWidget *parent = nullptr);
    ~Client_list();

private slots:
    void on_Add_Button_clicked();

    void on_Delete_Button_clicked();

private:
    Ui::Client_list *ui;
};

#endif // CLIENT_LIST_H
