#ifndef COURIER_LIST_H
#define COURIER_LIST_H

#include <QMainWindow>
#include <QMessageBox>
#include <QDateTime>
#include <QDebug>

#define Courier_size_MAX 200
#define Courier_list_cnt 3

typedef struct Box_Data2
{
    int index;      //택배함 번호
    QDate in_date;  //택배 입고 날짜
    QTime in_time;  //택배 입고 시간
    QString text;   //품목(내용)
}Box_Data2;

namespace Ui
{
    class Courier_list;
}

class Courier
{
private:
    QString Name;
    QString Phone;
    QString Affiliation;
    QString Image_path; //Logo_image Path Save

    int Box_cnt=0;        //Box_Data 갯수
    Box_Data2 Box[20];
public:
    static int Courier_cnt;
    void Set(QString Image_path)
    {
        this->Image_path = Image_path;
    }
    void Set(QString Name, QString Phone, QString Affiliation)
    {
        this->Name = Name;
        this->Phone = Phone;
        this->Affiliation = Affiliation;
        Courier::Courier_cnt++;
    }
    void Box_Set(int index, QDate in_date, QTime in_time, QString text)
    {
        (Box+Box_cnt)->index = index;
        (Box+Box_cnt)->in_date = in_date;
        (Box+Box_cnt)->in_time = in_time;
        (Box+Box_cnt)->text = text;
        Box_cnt++;
    }
    static bool Delete_Courier(Courier* courier_prt, QString Name)
    {
        for (int i = 0; i < Courier::Courier_cnt; i++)
        {
            if ((courier_prt+i)->Name == Name)
            {
                for (int j = i; j < Courier_size_MAX - 1; j++)
                {
                    (courier_prt+j)->Name = (courier_prt+j+1)->Name;
                    (courier_prt+j)->Phone = (courier_prt+j+1)->Phone;
                    (courier_prt+j)->Affiliation = (courier_prt+j+1)->Affiliation;
                }
                Courier::Courier_cnt--;
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
    QString Get_Phone(){ return this->Phone; }
    QString Get_Affiliation(){ return this->Affiliation; }
    QString Get_Image_path(){ return this->Image_path; }

    int Get_Box_cnt() {return this->Box_cnt; }
    int Get_Box_index(int num) { return (Box+num)->index; }
    QDate Get_Box_in_date(int num) { return (Box+num)->in_date; }
    QTime Get_Box_in_time(int num) { return (Box+num)->in_time; }
    QString Get_Box_text(int num) { return (Box+num)->text; }
};

class Courier_list : public QMainWindow
{
    Q_OBJECT

public:
    explicit Courier_list(QWidget *parent = nullptr);
    ~Courier_list();

private slots:
    void on_Add_Button_clicked();

    void on_Delete_Button_clicked();

private:
    Ui::Courier_list *ui;
};

#endif // COURIER_LIST_H
