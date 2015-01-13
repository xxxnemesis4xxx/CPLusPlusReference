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
    display = QString(QString::fromStdString(to_string(PairStruct.first)) + " " + QString::fromStdString(to_string(PairStruct.second)));

    return display;
}

QString Pair::MovingPairValueWithSemanticExample()
{
    QString display = "Moving variable s and t in a pair\n";
    std::string s = "Hello";
    std::string t = "World";

    auto p = std::make_pair(std::move(s),std::move(t));

    display += QString("Value inside pair = (" + QString::fromStdString(p.first) + "," + QString::fromStdString(p.second) + ")\n");
    display += QString("Value inside s and t now.\ns = " + QString::fromStdString(s) + "\nt = " + QString::fromStdString(t));

    return display;
}

QString Pair::EnforceRefMoveSemanticWithPairExample()
{
    QString display;
    int i = 0;
    auto k = std::make_pair(std::ref(i),std::ref(i));
    k.first++;
    k.second++;
    display += QString("Did our value changed? " + QString::fromStdString(to_string(i)));
    display += QString("\nValues in the pair : (" + QString::fromStdString(to_string(k.first)) + "," + QString::fromStdString(to_string(k.second)) + ")");

    return display;
}

QString Pair::EnforceRefMoveSemanticWithTupleExample()
{
    QString display;

    std::string strTest = "Hello";
    std::tuple<std::string&> oo(strTest);
    display = QString("Assign value \"Hello\" to our string and create the tuple with a reference to it\n");
    display += QString("Our tuple = " + QString::fromStdString(std::get<0>(oo)) + "\n\nAltering the value of our tuple\n");

    std::get<0>(oo) = "World";
    display += QString("Now, what is the value of our string?   string = " + QString::fromStdString(strTest));

    return display;
}

QString Pair::MakePairWithDefinedTypeExample()
{
    QString display = "Creating a pair with defined type of <char,char> : \n";
    std::pair<char,char> a = std::make_pair('x','y');
    display += QString("value of the pair = ('" + QString::fromStdString(to_string(a.first)) + "','" + QString::fromStdString(to_string(a.second)) + "')");

    return display;
}

QString Pair::ExtractSpecificValueFromPairExample()
{
    QString display;
    char c;
    std::pair<char,char> a = std::make_pair('x','y');

    std::tie(std::ignore,c) = a;
    display = QString("We extract the value : '" + QString::fromStdString(to_string(c)) + "' from the pair a = ('" + QString::fromStdString(to_string(a.first)) + "','" + QString::fromStdString(to_string(a.second)) + "')");

    return display;
}

QString Pair::DisplayPairValueExampleCode()
{
    QString display =
            QString("std::pair<int,int> PairStruct(5,6);\n")
            + QString("display = QString(to_string(PairStruct.first) + QString(PairStruct.second));");

    return display;
}

QString Pair::MovingPairValueWithSemanticCode()
{
    QString display = "auto p = std::make_pair(std::move(s),std::move(t));";

    return display;
}

QString Pair::EnforceRefMoveSemanticWithPairCode()
{
    QString display = QString("int i = 0;\n" +
            QString("auto k = std::make_pair(std::ref(i),std::ref(i));\n") +
            QString("k.first++;\nk.second++;"));

    return display;
}

QString Pair::EnforceRefMoveSemanticWithTupleCode()
{
    QString display =
            QString("std::string strTest = \"Hello\";\n" +
            QString("std::tuple<std::string&> oo(strTest);\n") +
            QString("std::get<0>(oo) = \"World\";\n"));

    return display;
}

QString Pair::MakePairWithDefinedTypeCode()
{
    QString display = "std::pair<char,char> a = std::make_pair('x','y');";

    return display;
}

QString Pair::ExtractSpecificValueFromPairCode()
{
    QString display =
            QString("char c;\nstd::pair<char,char> a = std::make_pair('x','y');\n" +
            QString("std::tie(std::ignore,c) = a;"));

    return display;
}
