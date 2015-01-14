#include "dialog.h"
#include "ui_dialog.h"
#include "categorie.h"
#include "tuple.h"
#include "pair.h"
#include "iterator.h"
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

    if (getDebut())
    {
        ui->listWidget->clear();
        switch(row)
        {
        case Categorie::TUPLES :
            ui->listWidget->addItems(Tuple::ListExamples());
            setPosition(0);
            setDebut(false);
            break;
        case Categorie::PAIRS:
            ui->listWidget->addItems(Pair::ListExamples());
            setPosition(1);
            setDebut(false);
            break;
        case Categorie::ITERATOR:
            ui->listWidget->addItems(Iterator::listExamples());
            setPosition(2);
            setDebut(false);
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
        switch(getPosition())
        {
        case 0:
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
                setDebut(true);
                break;
            }
            break;
        case 1:
            switch(row)
            {
            case Pair::CREATEPAIRDEFTYPE :
                ui->outputExample->setText(Pair::MakePairWithDefinedTypeExample());
                ui->codeOverview->setText(Pair::MakePairWithDefinedTypeCode());
                break;
            case Pair::DISPLAYVALUE :
                ui->outputExample->setText(Pair::DisplayPairValueExample());
                ui->codeOverview->setText(Pair::DisplayPairValueExampleCode());
                break;
            case Pair::EXTSPECVALUEFROMPAIR :
                ui->outputExample->setText(Pair::ExtractSpecificValueFromPairExample());
                ui->codeOverview->setText(Pair::ExtractSpecificValueFromPairCode());
                break;
            case Pair::MOVSEMPAIR :
                ui->outputExample->setText(Pair::MovingPairValueWithSemanticExample());
                ui->codeOverview->setText(Pair::MovingPairValueWithSemanticCode());
                break;
            case Pair::REFMOVSEMPAIR :
                ui->outputExample->setText(Pair::EnforceRefMoveSemanticWithPairExample());
                ui->codeOverview->setText(Pair::EnforceRefMoveSemanticWithPairCode());
                break;
            case Pair::REFMOVSEMTUPLE :
                ui->outputExample->setText(Pair::EnforceRefMoveSemanticWithTupleExample());
                ui->codeOverview->setText(Pair::EnforceRefMoveSemanticWithTupleCode());
                break;
            case Pair::RETURN :
                ui->listWidget->clear();
                ui->listWidget->addItems(Categorie::Categories());
                setDebut(true);
                break;
            }
            break;
        case 2:
            switch(row)
            {
            case Iterator::INSERTELEMENT:
                ui->codeOverview->setText(Iterator::InsertElementCode());
                ui->outputExample->setText(Iterator::InsertElementExample());
                break;
            case Iterator::RETURN:
                ui->listWidget->clear();
                ui->listWidget->addItems(Categorie::Categories());
                setDebut(true);
                break;
            }
            break;
        default:
            break;
        }
    }
}
