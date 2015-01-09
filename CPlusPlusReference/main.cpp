#include "main.h"
#include "ui_main.h"

Main::Main(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Main)
{
    ui->setupUi(this);
}

Main::~Main()
{
    delete ui;
}
