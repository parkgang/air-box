#include "mainwindow.h"
#include "ui_mainwindow.h"

QString kor(const char* str)
{
    QString korStr = QString::fromLocal8Bit(str);
    return korStr;
}

QDate Get_System_Date()
{
    int YY = QDateTime::currentDateTime().date().year();
    int MM = QDateTime::currentDateTime().date().month();
    int DD = QDateTime::currentDateTime().date().day();
    QDate date(YY,MM,DD);
    return date;
}

QTime Get_System_Time()
{
    int hour = QDateTime::currentDateTime().time().hour();
    int minute = QDateTime::currentDateTime().time().minute();
    QTime time(hour,minute);
    return time;
}

void init_user()
{
    Client_Login_flg = 0;
    Client_Login_log = 0;
    Courier_Login_flg = 0;
    Courier_Login_log = 0;
}

void MainWindow::Basic_Setting()    //statusbar ������ �߰�
{
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this, SLOT(show_Date_Time()));
    timer->start(1000);

    ui->statusbar->addPermanentWidget(ui->label_date);
    ui->statusbar->addPermanentWidget(ui->label_time);
    ui->statusbar->showMessage(kor("2019551012 ICT���հ��а� �ڰ��� Ver.11.19"));

    //�ΰ� �� �� pushbutton�� �������߰�
    QPixmap Logo(":/image/AirBox.png"); //�̹��� ��� ����
    int w = ui->Logo_label->width();    //�� W��ǥ �ҷ���
    int h = ui->Logo_label->height();   //�� H��ǥ �ҷ���
    ui->Logo_label->setPixmap(Logo);    //�̹��� ����
    ui->Logo_label->setPixmap(Logo.scaled(w,h,Qt::KeepAspectRatio));  //�̹��� �ȼ��� �°� Setting

    QIcon back(":/image/back_button.png");
    ui->Back_Button->setIcon(back);
    ui->Back_Button->setIconSize(QSize(30,30));

    QIcon home(":/image/home_button.png");
    ui->Home_Button->setIcon(home);
    ui->Home_Button->setIconSize(QSize(30,30));
}

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    Basic_Setting();
}

void MainWindow::show_Date_Time()   //label�� Date, time ������ ����
{
    QString date_text = QDate::currentDate().toString("20yy . MM . dd / ");
    ui->label_date->setText(date_text);

    QTime time = QTime::currentTime();
    QString time_text = time.toString("hh : mm : ss");
    ui->label_time->setText(time_text);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Manager_Button_clicked()
{
    manager_Login = new Manager_Login(this);
    manager_Login->show();
}

void MainWindow::on_Client_Button_clicked()
{
    client_Login = new Client_Login(this);
    client_Login->show();
}

void MainWindow::on_Courier_Button_clicked()
{
    courier_Login = new Courier_Login(this);
    courier_Login->show();
}

void MainWindow::on_Storage_Box_Button_clicked()
{
    init_user(); //���⸸�ؾߵǴµ� cliend�̰ų� courier �̸� Ŭ���Ǳ� ������ �ʱ�ȭ
    storage_box = new Storage_box(this);
    storage_box->show();
}
