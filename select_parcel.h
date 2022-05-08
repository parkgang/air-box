#ifndef SELECT_PARCEL_H
#define SELECT_PARCEL_H

#include <payment_window.h>

#include <QMainWindow>
#include <QMessageBox>

extern int Select_parcel_log;

namespace Ui
{
    class Select_parcel;
}

class Select_parcel : public QMainWindow
{
    Q_OBJECT

public:
    explicit Select_parcel(QWidget *parent = nullptr);
    ~Select_parcel();

private slots:
    void on_Select_pushButton_clicked();

private:
    Ui::Select_parcel *ui;

    Payment_window* payment_window;
};

#endif // SELECT_PARCEL_H
