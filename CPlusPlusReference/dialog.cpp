#include "dialog.h"
#include "ui_dialog.h"
#include "categorie.h"
#include "tupleandpair.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    ui->listWidget->addItems(Categorie::Categories());
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_listWidget_doubleClicked(const QModelIndex &index)
{
    int row = index.row();
    ui->listWidget->clear();

    switch(row)
    {
    case Categorie::TUPLE:
        ui->listWidget->addItems(TupleAndPair::ListExamples());
        break;
    case Categorie::ITERATOR:
        break;
    case Categorie::FUNCOBJLAM :
        break;
    case Categorie::STLALGO :
        break;
    case Categorie::STLSTAND :
        break;
    case Categorie::THREAD:
        break;
    default:
        ui->listWidget->addItems(Categorie::Categories());
        break;
    }
}
