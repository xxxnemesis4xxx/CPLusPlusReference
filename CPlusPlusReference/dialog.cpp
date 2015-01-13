#include "dialog.h"
#include "ui_dialog.h"
#include "categorie.h"
#include "tupleandpair.h"
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
    else
    {
        if (TupleAndPair::ListExamples().contains(text))
        {
            switch(row)
            {
            case TupleAndPair::ITERATOR :
                ui->outputExample->setText(TupleAndPair::IterateOverElements());
                ui->codeOverview->setText(TupleAndPair::IterateOverElementsCode());
                break;
            case TupleAndPair::INITTUPLEWITHLIST :
                ui->outputExample->setText(TupleAndPair::InitialiseTupleWithList());
                ui->codeOverview->setText(TupleAndPair::InitialiseTupleWithListCode());
                break;
            case TupleAndPair::MAKETUPLE :
                ui->outputExample->setText(TupleAndPair::CreateTupleWithMakeTuple());
                ui->codeOverview->setText(TupleAndPair::CreateTupleWithMakeTupleCode());
                break;
            case TupleAndPair::REFVALUE :
                ui->outputExample->setText(TupleAndPair::AssignReferenceToTuple());
                ui->codeOverview->setText(TupleAndPair::AssignReferenceToTupleCode());
                break;
            case TupleAndPair::TUPLEWITHREFVALUES:
                ui->outputExample->setText(TupleAndPair::CreateTupleWithReferenceValues());
                ui->codeOverview->setText(TupleAndPair::CreateTupleWithReferenceValuesCode());
                break;
            }
        }
    }
}
