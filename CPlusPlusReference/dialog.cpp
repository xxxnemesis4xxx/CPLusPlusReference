#include "dialog.h"
#include "ui_dialog.h"
#include "categorie.h"
#include "tuple.h"
#include <QVariant>
#include <QDebug>

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
    QVariant result = index.data();
    QString text = result.toString();

    if (Categorie::Categories().contains(text))
    {
        ui->listWidget->clear();
        switch(row)
        {
        case Categorie::TUPLES :
            ui->listWidget->addItems(Tuple::ListExamples());
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
    else
    {
        if (Tuple::ListExamples().contains(text))
        {
            switch(row)
            {
            case Tuple::ITERATOR :
                ui->outputExample->setText(Tuple::IterateOverElements());
                ui->codeOverview->setText(Tuple::IterateOverElementsCode());
                break;
            case Tuple::INITTUPLEWITHLIST :
                ui->outputExample->setText(Tuple::InitialiseTupleWithList());
                ui->codeOverview->setText(Tuple::InitialiseTupleWithListCode());
                break;
            case Tuple::MAKETUPLE :
                ui->outputExample->setText(Tuple::CreateTupleWithMakeTuple());
                ui->codeOverview->setText(Tuple::CreateTupleWithMakeTupleCode());
                break;
            case Tuple::REFVALUE :
                ui->outputExample->setText(Tuple::AssignReferenceToTuple());
                ui->codeOverview->setText(Tuple::AssignReferenceToTupleCode());
                break;
            case Tuple::TUPLEWITHREFVALUES:
                ui->outputExample->setText(Tuple::CreateTupleWithReferenceValues());
                ui->codeOverview->setText(Tuple::CreateTupleWithReferenceValuesCode());
                break;
            case Tuple::RETURN :
                ui->listWidget->clear();
                ui->listWidget->addItems(Categorie::Categories());
                break;
            }
        }
    }
}
