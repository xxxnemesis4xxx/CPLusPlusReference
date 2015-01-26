#include "stlstandard.h"
#include <algorithm>
#include <vector>
#include <array>
#include <string>
#include <unordered_map>

template <typename Container>
QString printContainer(Container coll)
{
    QString display = "";
    for(const auto& elem : coll)
        display += QString(QString::fromStdString(std::to_string(elem)) + " ");

    return display;
}

StlStandard::StlStandard()
{

}

StlStandard::~StlStandard()
{

}

QString StlStandard::BasicVectorOperationsExample()
{
    QString display = "Find and print minimum and maximum elements : \n";

    std::vector<int> coll = { 2,5,4,1,6,3 };

    auto minpos = std::min_element(coll.cbegin(), coll.cend());
    auto maxpos = std::max_element(coll.cbegin(),coll.cend());
    display += QString("(" + QString::fromStdString(std::to_string(*minpos)) + "," + QString::fromStdString(std::to_string(*maxpos)) + ")\n\n");

    display += QString("Value inside the vector before sorting :\n" + printContainer(coll));
    std::sort(coll.begin(),coll.end());
    display += QString("\n\nValue inside the vector after sorting :\n" + printContainer(coll));

    display += QString("\n\nFind the first element with value 3\n");
    auto pos3 = std::find(coll.begin(),coll.end(),3);
    display += QString(QString::fromStdString(std::to_string(*pos3)) + "\n\n");

    display += QString("Reverse the order of the found element with all the following elements\nValue in the container : \n");
    std::reverse(pos3,coll.end());
    display += printContainer(coll);

    return display;
}

QString StlStandard::BasicVectorOperationsCode()
{
    return QString(
                "std::vector<int> coll = { 2,5,4,1,6,3 };\n\nauto minpos = std::min_element(coll.cbegin(), coll.cend());\nauto maxpos = std::max_element(coll.cbegin(),coll.cend());"
                "\n\nstd::sort(coll.begin(),coll.end());\n\nauto pos3 = std::find(coll.begin(),coll.end(),3);\n\nstd::reverse(pos3,coll.end());"
                );
}

QString StlStandard::PrintStringInArrayExample()
{
    QString display = "Values inside de array : \n";

    std::array<std::string,5> coll = { "Hello", "World" };
    for (const auto& elem : coll)
        display += QString("\"" + QString::fromStdString(elem) + "\" ");

    display += QString("\n\nPrint each element of the array : \n");
    for(int i = 0; i < coll.size(); ++i)
        display += QString("[" + QString::fromStdString(std::to_string(i)) + "] : \"" + QString::fromStdString(coll[i] + "\"\n"));

    return display;
}

QString StlStandard::PrintStringInArrayCode()
{
    return QString(
                "std::array<std::string,5> coll = { \"Hello\", \"World\" };\n\n"
                "for(int i = 0; i < coll.size(); ++i)\n   display += ...;"
                );
}

QString StlStandard::AssociativeArrayExample()
{
    QString display = "Insert elements in the container and display his content :\n";
    std::unordered_map<std::string,float> coll;

    coll["VAT1"] = 0.16;
    coll["VAT2"] = 0.07;
    coll["Pi"] = 3.1415;
    coll["an arbitrary number"] = 4983.223;
    coll["Null"] = 0;

    for (const auto elem : coll)
        display += QString("(\"" + QString::fromStdString(elem.first) +"\"," + QString::fromStdString(std::to_string(elem.second)) + ")\n");

    return display;
}

QString StlStandard::AssociativeArrayCode()
{
    return QString(
                "std::unordered_map<std::string,float> coll;\n\n"
                "coll[\"VAT1\"] = 0.16;\ncoll[\"VAT2\"] = 0.07;\ncoll[\"Pi\"] = 3.1415;\ncoll[\"an arbitrary number\"] = 4983.223;\ncoll[\"Null\"] = 0;"
                );
}
