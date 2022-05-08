#ifndef PAYMENT_WINDOW_H
#define PAYMENT_WINDOW_H

#include <QMainWindow>
#include <QDateTime>

namespace Ui
{
    class Payment_window;
}

int Trans_minute(QDate in_date, QTime in_time, QDate now_date, QTime now_time);
int Use_price(int minute);

class Payment_window : public QMainWindow
{
    Q_OBJECT

public:
    explicit Payment_window(QWidget *parent = nullptr);
    ~Payment_window();

    void Box_Set(int index, QDate in_date, QTime in_time, QString text);

private slots:
    void on_Payment_pushButton_clicked();

private:
    Ui::Payment_window *ui;
};

#endif // PAYMENT_WINDOW_H
