#include "dialog.h"
#include "ui_dialog.h"
#include "categorie.h"
#include "tuple.h"
#include "pair.h"
#include "iterator.h"
#include "funcobjandlambda.h"
#include "stlstandard.h"
#include "stlcontainer.h"
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
            ui->listWidget->addItems(FuncObjAndLambda::listExamples());
            setPosition(3);
            setDebut(false);
            break;
        case Categorie::STLALGO :
            break;
        case Categorie::STLSTAND :
            ui->listWidget->addItems(StlStandard::listExamples());
            setPosition(4);
            setDebut(false);
            break;
        case Categorie::CONTAINER :
            ui->listWidget->addItems(StlContainer::ListExamples());
            setPosition(5);
            setDebut(false);
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
            case Iterator::DISPLAYVALUE :
                ui->codeOverview->setText(Iterator::DisplayElementCode());
                ui->outputExample->setText(Iterator::DisplayElementExample());
                break;
            case Iterator::ADVANCE :
                ui->outputExample->setText(Iterator::MoveIteratorExample());
                ui->codeOverview->setText(Iterator::MoveIteratorCode());
                break;
            case Iterator::BACKINSERTER :
                ui->outputExample->setText(Iterator::InsertElementAtEndExample());
                ui->codeOverview->setText(Iterator::InsertElementAtEndCode());
                break;
            case Iterator::BACKINSERTER2:
                ui->outputExample->setText(Iterator::AppendAllElementWithBackInserterExample());
                ui->codeOverview->setText(Iterator::AppendAllElementWithBackInserterCode());
                break;
            case Iterator::FIND:
                ui->outputExample->setText(Iterator::FindElementInContainerExample());
                ui->codeOverview->setText(Iterator::FindElementInContainerCode());
                break;
            case Iterator::DISTANCE:
                ui->outputExample->setText(Iterator::DistanceFromBeginningExample());
                ui->codeOverview->setText(Iterator::DistanceFromBeginningCode());
                break;
            case Iterator::FRONTINSERTER:
                ui->outputExample->setText(Iterator::InsertElementAtBeginningExample());
                ui->codeOverview->setText(Iterator::InsertElementAtBeginningCode());
                break;
            case Iterator::FRONTINSERTER2 :
                ui->outputExample->setText(Iterator::AppendAllElementWithFrontInserterExample());
                ui->codeOverview->setText(Iterator::AppendAllElementWithFrontInserterCode());
                break;
            case Iterator::INSERTER :
                ui->outputExample->setText(Iterator::InsertValueWithAnInserterExample());
                ui->codeOverview->setText(Iterator::InsertValueWithAnInserterCode());
                break;
            case Iterator::INSERTER2:
                ui->outputExample->setText(Iterator::AppendAllElementWithInserterExample());
                ui->codeOverview->setText(Iterator::AppendAllElementWithInserterCode());
                break;
            case Iterator::INSERTER3:
                ui->outputExample->setText(Iterator::InsertElementAtSpecificLocationExample());
                ui->codeOverview->setText(Iterator::InsertElementAtSpecificLocationCode());
                break;
            case Iterator::ADVANCES:
                ui->outputExample->setText(Iterator::MoveIteratorOffNPositionExample());
                ui->codeOverview->setText(Iterator::MoveIteratorOffNPositionCode());
                break;
            case Iterator::SWAP:
                ui->outputExample->setText(Iterator::SwapFirstAndSecondValueExample());
                ui->codeOverview->setText(Iterator::SwapFirstAndSecondValueCode());
                break;
            case Iterator::SWAP2:
                ui->outputExample->setText(Iterator::SwapFirstAndLastValueExample());
                ui->codeOverview->setText(Iterator::SwapFirstAndLastValueCode());
                break;
            case Iterator::OSTREAM:
                ui->outputExample->setText(Iterator::ReadValueWithOstreamIteratorExample());
                ui->codeOverview->setText(Iterator::ReadValueWithOstreamIteratorCode());
                break;
            case Iterator::PREVANDNEXT :
                ui->outputExample->setText(Iterator::UsageOfPrevAndNextExample());
                ui->codeOverview->setText(Iterator::UsageOfPrevAndNextCode());
                break;
            case Iterator::RANDOMACCESS:
                ui->outputExample->setText(Iterator::RandomAccessIteratorExample());
                ui->codeOverview->setText(Iterator::RandomAccessIteratorCode());
                break;
            case Iterator::REVERSE :
                ui->outputExample->setText(Iterator::PrintAllElementInReverseExample());
                ui->codeOverview->setText(Iterator::PrintAllElementInReverseCode());
                break;
            case Iterator::FOREACH :
                ui->outputExample->setText(Iterator::UsageOfForEachExample());
                ui->codeOverview->setText(Iterator::UsageOfForEachCode());
                break;
            case Iterator::USERDEFINEDITERATOR :
                ui->outputExample->setText(Iterator::UserDefineIteratorsExample());
                ui->codeOverview->setText(Iterator::UserDefineIteratorsCode());
                break;
            case Iterator::RETURN:
                ui->listWidget->clear();
                ui->listWidget->addItems(Categorie::Categories());
                setDebut(true);
                break;
            }
            break;
        case 3:
            switch(row)
            {
            case FuncObjAndLambda::BIND:
                ui->outputExample->setText(FuncObjAndLambda::MathematicalOperationsExample());
                ui->codeOverview->setText(FuncObjAndLambda::MathematicalOperationsCode());
                break;
            case FuncObjAndLambda::BIND2 :
                ui->outputExample->setText(FuncObjAndLambda::CapitalAndLowercaseLetterExample());
                ui->codeOverview->setText(FuncObjAndLambda::CapitalAndLowercaseLetterCode());
                break;
            case FuncObjAndLambda::BIND3 :
                ui->outputExample->setText(FuncObjAndLambda::SumOfAllIntInMapExample());
                ui->codeOverview->setText(FuncObjAndLambda::SumOfAllIntInMapCode());
                break;
            case FuncObjAndLambda::BIND4 :
                ui->outputExample->setText(FuncObjAndLambda::PowerUp3WithValueInsideContainerExample());
                ui->codeOverview->setText(FuncObjAndLambda::PowerUp3WithValueInsideContainerCode());
                break;
            case FuncObjAndLambda::LAMBDA :
                ui->outputExample->setText(FuncObjAndLambda::PrintMeanValueExample());
                ui->codeOverview->setText(FuncObjAndLambda::PrintMeanValueCode());
                break;
            case FuncObjAndLambda::LAMBDA2 :
                ui->outputExample->setText(FuncObjAndLambda::RemoveThirdElementExample());
                ui->codeOverview->setText(FuncObjAndLambda::RemoveThirdElementCode());
                break;
            case FuncObjAndLambda::LAMBDA3 :
                ui->outputExample->setText(FuncObjAndLambda::SearchSubcaseStringInsensitiveExample());
                ui->codeOverview->setText(FuncObjAndLambda::SearchSubcaseStringInsensitiveCode());
                break;
            case FuncObjAndLambda::REMOVEIF :
                ui->outputExample->setText(FuncObjAndLambda::RemoveIfWithFunctionObjectExample());
                ui->codeOverview->setText(FuncObjAndLambda::RemoveIfWithFunctionObjectCode());
                break;
            case FuncObjAndLambda::SEQUENCE :
                ui->outputExample->setText(FuncObjAndLambda::MultipleStageFuncObExample());
                ui->codeOverview->setText(FuncObjAndLambda::MultipleStageFuncObCode());
                break;
            case FuncObjAndLambda::SEQUENCE2 :
                ui->outputExample->setText(FuncObjAndLambda::PassingValuesToFuncObjExample());
                ui->codeOverview->setText(FuncObjAndLambda::PassingValuesToFuncObjCode());
                break;
            case FuncObjAndLambda::SEQUENCE3 :
                ui->outputExample->setText(FuncObjAndLambda::PrintMeanValue2Example());
                ui->codeOverview->setText(FuncObjAndLambda::PrintMeanValue2Code());
                break;
            case FuncObjAndLambda::SORTING :
                ui->outputExample->setText(FuncObjAndLambda::SortSetWithCriterionExample());
                ui->codeOverview->setText(FuncObjAndLambda::SortSetWithCriterionCode());
                break;
            case FuncObjAndLambda::RETURN :
                ui->listWidget->clear();
                ui->listWidget->addItems(Categorie::Categories());
                setDebut(true);
                break;
            }

            break;
        case 4:
            switch(row)
            {
            case StlStandard::BASICVECTOR :
                ui->outputExample->setText(StlStandard::BasicVectorOperationsExample());
                ui->codeOverview->setText(StlStandard::BasicVectorOperationsCode());
                break;
            case StlStandard::ARRAYSTRING :
                ui->outputExample->setText(StlStandard::PrintStringInArrayExample());
                ui->codeOverview->setText(StlStandard::PrintStringInArrayCode());
                break;
            case StlStandard::ASSOCIATIVEARRAY :
                ui->outputExample->setText(StlStandard::AssociativeArrayExample());
                ui->codeOverview->setText(StlStandard::AssociativeArrayCode());
                break;
            case StlStandard::BINARYPREDICATE :
                ui->outputExample->setText(StlStandard::BinaryPredicatesExample());
                ui->codeOverview->setText(StlStandard::BinaryPredicatesCode());
                break;
            case StlStandard::BINDER :
                ui->outputExample->setText(StlStandard::BinderExample());
                ui->codeOverview->setText(StlStandard::BinderCode());
                break;
            case StlStandard::TEMPLINLINE :
                ui->outputExample->setText(StlStandard::TemplateInlineFuncExample());
                ui->codeOverview->setText(StlStandard::TemplateInlineFuncCode());
                break;
            case StlStandard::DEQUE :
                ui->outputExample->setText(StlStandard::dequeExample());
                ui->codeOverview->setText(StlStandard::dequeCode());
                break;
            case StlStandard::TEMPLSPECI :
                ui->outputExample->setText(StlStandard::templateSpecializationExample());
                ui->codeOverview->setText(StlStandard::templateSpecializationCode());
                break;
            case StlStandard::FIND :
                ui->outputExample->setText(StlStandard::FindExample());
                ui->codeOverview->setText(StlStandard::FindCode());
                break;
            case StlStandard::FORWARDLIST :
                ui->outputExample->setText(StlStandard::ForwardListExample());
                ui->codeOverview->setText(StlStandard::ForwardListCode());
                break;
            case StlStandard::FOREACH :
                ui->outputExample->setText(StlStandard::ForEachWithContainerExample());
                ui->codeOverview->setText(StlStandard::ForEachWithContainerCode());
                break;
            case StlStandard::TRANSFORM :
                ui->outputExample->setText(StlStandard::TransformWithContainerExample());
                ui->codeOverview->setText(StlStandard::TransformWithContainerCode());
                break;
            case StlStandard::FUNCOBJ :
                ui->outputExample->setText(StlStandard::FunctionObjectExample());
                ui->codeOverview->setText(StlStandard::FunctionObjectCode());
                break;
            case StlStandard::FUNCOBJ2 :
                ui->outputExample->setText(StlStandard::FunctionObject2Example());
                ui->codeOverview->setText(StlStandard::FunctionObject2Code());
                break;
            case StlStandard::FUNCWRAPPER :
                ui->outputExample->setText(StlStandard::FunctionWrapperExample());
                ui->codeOverview->setText(StlStandard::FunctionWrapperCode());
                break;
            case StlStandard::HANDRANGES :
                ui->outputExample->setText(StlStandard::HandlingMultipleRangesExample());
                ui->codeOverview->setText(StlStandard::HandlingMultipleRangesCode());
                break;
            case StlStandard::INSERTITERATOR :
                ui->outputExample->setText(StlStandard::InsertIteratorExample());
                ui->codeOverview->setText(StlStandard::InsertIteratorCode());
                break;
            case StlStandard::ITERATORS :
                ui->outputExample->setText(StlStandard::IteratorsManipulationsExample());
                ui->codeOverview->setText(StlStandard::IteratorsManipulationsCode());
                break;
            case StlStandard::LAMBDA :
                ui->outputExample->setText(StlStandard::LambdaAlgorithmExample());
                ui->codeOverview->setText(StlStandard::LambdaAlgorithmCode());
                break;
            case StlStandard::LAMBDA2 :
                ui->outputExample->setText(StlStandard::LambdaAlgorithm2Example());
                ui->codeOverview->setText(StlStandard::LambdaAlgorithm2Code());
                break;
            case StlStandard::LAMBDA3 :
                ui->outputExample->setText(StlStandard::LambdaAlgorithm3Example());
                ui->codeOverview->setText(StlStandard::LambdaAlgorithm3Code());
                break;
            case StlStandard::LIST :
                ui->outputExample->setText(StlStandard::ListExample());
                ui->codeOverview->setText(StlStandard::ListCode());
                break;
            case StlStandard::MULTIMAPS :
                ui->outputExample->setText(StlStandard::MultimapOverviewExample());
                ui->codeOverview->setText(StlStandard::MultimapOverviewCode());
                break;
            case StlStandard::MULTISET :
                ui->outputExample->setText(StlStandard::MultisetOverviewExample());
                ui->codeOverview->setText(StlStandard::MultisetOverviewCode());
                break;
            case StlStandard::PREDFUNCOBJ :
                ui->outputExample->setText(StlStandard::PredefinedFuncObjExample());
                ui->codeOverview->setText(StlStandard::PredefinedFuncObjCode());
                break;
            case StlStandard::PREDICATES :
                ui->outputExample->setText(StlStandard::PredicatesExample());
                ui->codeOverview->setText(StlStandard::PredicatesCode());
                break;
            case StlStandard::FUNCWRAPPERS :
                ui->outputExample->setText(StlStandard::ReferenceWrappersExample());
                ui->codeOverview->setText(StlStandard::ReferenceWrappersCode());
                break;
            case StlStandard::REMOVE1 :
                ui->outputExample->setText(StlStandard::Remove1Example());
                ui->codeOverview->setText(StlStandard::Remove1Code());
                break;
            case StlStandard::REMOVE2 :
                ui->outputExample->setText(StlStandard::Remove2Example());
                ui->codeOverview->setText(StlStandard::Remove2Code());
                break;
            case StlStandard::REVITERATORS :
                ui->outputExample->setText(StlStandard::ReverseIteratorsExample());
                ui->codeOverview->setText(StlStandard::ReverseIteratorsCode());
                break;
            case StlStandard::UNORDEREDMULTIMAP :
                ui->outputExample->setText(StlStandard::UnorderedMultimapExample());
                ui->codeOverview->setText(StlStandard::UnorderedMultimapCode());
                break;
            case StlStandard::UNORDEREDMULTISET :
                ui->outputExample->setText(StlStandard::UnorderedMultisetExample());
                ui->codeOverview->setText(StlStandard::UnorderedMultisetCode());
                break;
            case StlStandard::RETURN :
                ui->listWidget->clear();
                ui->listWidget->addItems(Categorie::Categories());
                setDebut(true);
                break;
            }
        case 5:
            switch(row)
            {
                case StlContainer::RETURN :
                ui->listWidget->clear();
                ui->listWidget->addItems(Categorie::Categories());
                setDebut(true);
                break;
            }

        default:
            break;
        }
    }
}
