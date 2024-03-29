#ifndef STORAGE_BOX_H
#define STORAGE_BOX_H

#include <QMainWindow>
#include <insert_box.h>

namespace Ui
{
    class Storage_box;
}

class Storage_box : public QMainWindow
{
    Q_OBJECT

public:
    explicit Storage_box(QWidget *parent = nullptr);
    ~Storage_box();

    void Update_Storage_Box();    
    void Storage_Box_flg(int num);

private slots:
    void on_pushButton_1_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_6_clicked();
    void on_pushButton_7_clicked();
    void on_pushButton_8_clicked();
    void on_pushButton_9_clicked();
    void on_pushButton_10_clicked();
    void on_pushButton_11_clicked();
    void on_pushButton_12_clicked();
    void on_pushButton_13_clicked();
    void on_pushButton_14_clicked();
    void on_pushButton_15_clicked();
    void on_pushButton_16_clicked();
    void on_pushButton_17_clicked();
    void on_pushButton_18_clicked();
    void on_pushButton_19_clicked();
    void on_pushButton_20_clicked();

private:
    Ui::Storage_box *ui;

    Insert_box* insert_box;
};

#endif // STORAGE_BOX_H
