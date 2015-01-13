#include "pair.h"
#include <utility>
#include <tuple>
#include <iostream>
#include <QString>
#include <string>
#include <functional>

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

QString Pair::CreatePairWithPairMakeExample()
{
    QString display = "Making a pair with pair_make()\n";
    pair newPair = std::make_pair('C',3.1416);

    display += QString("Pair values = ('" + to_string(newPair.first) + "',"
            + to_string(newPair.second) + ")");

    return display;
}

QString Pair::MovingPairValueWithSemanticExample()
{
    QString display = "Moving variable s and t in a pair\n";
    std::string s = "Hello";
    std::string t = "World";

    auto p = std::make_pair(std::move(s),std::move(t));

    display += "Value inside pair = (" + p.first + "," + p.second + ")\n";
    display += "Value inside s and t now.\ns = " + QString::fromStdString(s) + "\nt = " + QString::fromStdString(t);

    return display;
}

QString Pair::EnforceRefMoveSemanticWithPairExample()
{
}

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

QString Pair::CreatePairWithPairMakeCode()
{
    QString display = QString(
                "std::pair newPair = std::make_pair('C',3.1416);\n";
                );

    return display;
}

QString Pair::MovingPairValueWithSemanticCode()
{
    QString display = "auto p = std::make_pair(std::move(s),std::move(t));";

    return display;
}

QString Pair::EnforceRefMoveSemanticWithPairCode();
QString Pair::EnforceRefMoveSemanticWithTupleCode();
QString Pair::MakePairWithDefinedTypeCode();
QString Pair::ExtractSpecificValueFromPairCode();
