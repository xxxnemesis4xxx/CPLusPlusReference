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

    display += "Pair values = ('" + to_string(newPair.first) + "',"
            + to_string(newPair.second) + ")";

    return display;
}

QString Pair::MovingPairValueWithSemanticExample()
{
    QString display = "Moving variable s and t in a pair\n";
    std::string s = "Hello";
    std::string t = "World";

    auto p = std::make_pair(std::move(s),std::move(t));

    display += "Value inside pair = (" + p.first + "," + p.second + ")\n";
    display += "Value inside s and t now.\ns = " + s + "\nt = " + t;

    return display;
}

QString Pair::EnforceRefMoveSemanticWithPairExample()
{
    QString display;
    int i = 0;
    auto k = std::make_pair(std::ref(i),std::ref(i));
    k.first++;
    k.second++;
    display += "Did our value changed? " + to_string(i);
    display += "\nValues in the pair : (" + to_string(k.first) + "," + to_string(k.second) + ")";

    return display;
}

QString Pair::EnforceRefMoveSemanticWithTupleExample()
{
    QString display;

    std::string strTest = "Hello";
    std::tuple<std::string&> oo(strTest);
    display = "Assign value \"Hello\" to our string and create the tuple with a reference to it\n";
    display += "Our tuple = " + std::get<o>(oo) + "\n\nAltering the value of our tuple\n";

    std::get<0>(oo) = "World";
    display += "Now, what is the value of our string?   string = " + strTest;

    return display;
}

QString Pair::MakePairWithDefinedTypeExample()
{
    QString display = "Creating a pair with defined type of <char,char> : \n";
    std::pair<char,char> a = std::make_pair('x','y');
    display += "value of the pair = ('" + to_string(a) + "','" + to_string(y) + "')";

    return display;
}

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

QString Pair::EnforceRefMoveSemanticWithPairCode()
{
    QString display = "int i = 0;\n" +
            "auto k = std::make_pair(std::ref(i),std::ref(i));\n" +
            "k.first++;\nk.second++;";

    return display;
}

QString Pair::EnforceRefMoveSemanticWithTupleCode()
{
    QString display =
            "std::string strTest = \"Hello\";\n" +
            "std::tuple<std::string&> oo(strTest);\n" +
            "std::get<0>(oo) = \"World\";\n";

    return display;
}

QString Pair::MakePairWithDefinedTypeCode()
{
    QString display = "std::pair<char,char> a = std::make_pair('x','y');";

    return display;
}

QString Pair::ExtractSpecificValueFromPairCode();
