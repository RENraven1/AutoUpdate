#ifndef AUTOUP_H
#define AUTOUP_H

#include <QMainWindow>

namespace Ui {
class autoup;
}

class autoup : public QMainWindow
{
    Q_OBJECT

public:
    explicit autoup(QWidget *parent = 0);
    ~autoup();

private:
    Ui::autoup *ui;
};

#endif // AUTOUP_H
