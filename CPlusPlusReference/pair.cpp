#include "pair.h"
#include <utility>
#include <tuple>
#include <iostream>
#include <QString>

using namespace std;

Pair::Pair()
{
}

Pair::~Pair()
{
}

QString Pair::DisplayPairValueExample()
{
    QString display;

    //Display the elements inside the PairStruct
    pair<int,int> PairStruct(5,6);
    display = QString(to_string(PairStruct.first) + " " + to_string(PairStruct.second));

    return display;
}

QString Pair::ReturnSizePairExample();
QString Pair::CreatePairWithPairMakeExample();
QString Pair::MovingPairValueWithSemanticExample();
QString Pair::EnforceRefMoveSemanticWithPairExample();
QString Pair::EnforceRefMoveSemanticWithTupleExample();
QString Pair::MakePairWithDefinedTypeExample();
QString Pair::ExtractSpecificValueFromPairExample();

QString Pair::DisplayPairValueExampleCode()
{
    QString display =
            QString("std::pair<int,int> PairStruct(5,6);\n")
            + QString("display = QString(to_string(PairStruct.first) + QString(PairStruct.second));");

    return display;
}

QString Pair::ReturnSizePairCode();
QString Pair::CreatePairWithPairMakeCode();
QString Pair::MovingPairValueWithSemanticCode();
QString Pair::EnforceRefMoveSemanticWithPairCode();
QString Pair::EnforceRefMoveSemanticWithTupleCode();
QString Pair::MakePairWithDefinedTypeCode();
QString Pair::ExtractSpecificValueFromPairCode();
