#include "autoup.h"
#include "ui_autoup.h"

autoup::autoup(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::autoup)
{
    ui->setupUi(this);

}

autoup::~autoup()
{
    delete ui;
}
