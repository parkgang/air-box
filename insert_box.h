#ifndef INSERT_BOX_H
#define INSERT_BOX_H

#include <QMainWindow>

namespace Ui
{
    class Insert_box;
}

extern bool Select_flg;

class Insert_box : public QMainWindow
{
    Q_OBJECT

public:
    explicit Insert_box(QWidget *parent = nullptr);
    ~Insert_box();

private slots:
    void on_Select_Button_clicked();

    void on_Insert_Button_clicked();

private:
    Ui::Insert_box *ui;
};

#endif // INSERT_BOX_H
