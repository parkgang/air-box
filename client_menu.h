#ifndef CLIENT_MENU_H
#define CLIENT_MENU_H

#include <QMainWindow>
#include <QTimer>

namespace Ui
{
    class Client_menu;
}

class Client_menu : public QMainWindow
{
    Q_OBJECT

public:
    void Basic_Setting();
    explicit Client_menu(QWidget *parent = nullptr);
    ~Client_menu();

private:
    Ui::Client_menu *ui;
    QTimer* timer;
};

#endif // CLIENT_MENU_H
