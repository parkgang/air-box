#ifndef SERVICE_EDIT_H
#define SERVICE_EDIT_H

#include <QMainWindow>

#include <QDebug>
#include <QMessageBox>

namespace Ui
{
    class Service_edit;
}

class Service_edit : public QMainWindow
{
    Q_OBJECT

public:
    explicit Service_edit(QWidget *parent = nullptr);
    ~Service_edit();

private slots:
    void on_Ok_Button_clicked();

private:
    Ui::Service_edit *ui;
};

#endif // SERVICE_EDIT_H
