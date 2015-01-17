#include "iterator.h"
#include <iterator>
#include <iostream>
#include <list>
#include <algorithm>
#include <vector>
#include <algorithm>
#include <string>
#include <set>

Iterator::Iterator()
{

}

Iterator::~Iterator()
{

}

QString Iterator::InsertElementExample()
{
    std::list<int> coll;

    for (int i = 1; i <= 9; ++i)
        coll.push_back(i);

    QString display = "Inserted 9 elements in the list";

    return display;
}

QString Iterator::InsertElementCode()
{
    QString display = QString("std::list<int> coll;\nfor(int i = 1; i <= 9; ++i)\n   coll.push_back(i);");

    return display;
}

QString Iterator::DisplayElementExample()
{
    QString display;
    std::list<int> coll;

    for (int i = 1; i <= 9; ++i)
        coll.push_back(i);
    std::list<int>::iterator pos = coll.begin();

    display = QString("Print the actual value of the iterator : " +
                      QString::fromStdString(std::to_string(*pos)));

    return display;
}

QString Iterator::DisplayElementCode()
{
    QString display = QString(
                "std::list<int> coll;\n"
                "std::list<int>::iterator pos = coll.begin();\nstd::to_string(*pos);"
                );

    return display;
}

QString Iterator::MoveIteratorExample()
{
    QString display;
    std::list<int> coll;

    for (int i = 1; i <= 9; ++i)
        coll.push_back(i);
    std::list<int>::iterator pos = coll.begin();

    //step three elements forward
    advance(pos,3);

    //Print actual element
    display = QString("Value of the iterator after moving forward of 3 positions\nPos = " + QString::fromStdString(std::to_string(*pos)));

    //Step one element backward
    advance(pos,-1);

    //print actual element
    display += QString("\n\nValue of the iterator after moving backward of 1 position\n Pos = " + QString::fromStdString(std::to_string(*pos)));

    return display;
}

QString Iterator::MoveIteratorCode()
{
    QString display = QString(
                "advance(pos,3);\nadvance(pos,-1);"
                );

    return display;
}

QString Iterator::InsertElementAtEndExample()
{
    QString display;
    std::vector<int> coll;

    std::back_inserter(coll) = 44;
    std::back_inserter(coll) = 55;

    display = QString("Value inside the vector : ");
    for (const auto& elem : coll)
        display += QString(QString::fromStdString(std::to_string(elem)) + " ");

    return display;
}

QString Iterator::InsertElementAtEndCode()
{
    QString display = QString(
                "std::vector<int> coll;\n\nstd::back_inserter(coll) = 44;\nstd::back_inserter(coll) = 55;"
                );

    return display;
}

QString Iterator::AppendAllElementWithBackInserterExample()
{
    QString display;
    std::vector<int> coll;

    std::back_inserter(coll) = 44;
    std::back_inserter(coll) = 55;

    // Use back inserter to append all elements again
    // -Reserve enough memory to avoid reallocation
    coll.reserve(2*coll.size());
    std::copy(coll.begin(),coll.end(),std::back_inserter(coll));

    display = QString("Value inside the vector : ");
    for (const auto& elem : coll)
        display += QString(QString::fromStdString(std::to_string(elem)) + " ");

    return display;
}

QString Iterator::AppendAllElementWithBackInserterCode()
{
    QString display = QString(
                "std::vector<int> coll;\n\nstd::back_inserter(coll) = 44;\nstd::back_inserter(coll) = 55;"
                "\n\ncoll.reserve(2*coll.size());\nstd::copy(coll.begin(),coll.end(),std::back_inserter(coll));"
                );

    return display;
}

QString Iterator::FindElementInContainerExample()
{
    QString display;
    std::list<int> coll;

    //insert elements from -3 to 9
    for (int i=-3; i<=9;++i)
        coll.push_back(i);

    //Search element with value 5
    std::list<int>::iterator pos;
    pos = std::find(coll.begin(), coll.end(), 5);

    display = QString("Finding the value 5 inside the list. The value of the Iterator -> " + QString::fromStdString(std::to_string(*pos)));

    return display;
}

QString Iterator::FindElementInContainerCode()
{
    QString display = QString(
                "std::list<int> coll;\n\nfor (int i = -3;i <= 9; ++i)\n   coll.push_back(i);\n\n"
                "std::list<int>::iterator pos;\npos = std::find(coll.begin(),coll.end(), 5);"
                );

    return display;
}

QString Iterator::DistanceFromBeginningExample()
{
    QString display;
    std::list<int> coll;

    //insert elements from -3 to 9
    for (int i=-3; i<=9;++i)
        coll.push_back(i);

    //Search element with value 5
    std::list<int>::iterator pos;
    pos = std::find(coll.begin(), coll.end(), 5);

    if (pos != coll.end())
    {
        //Process and print difference from the beginning
        display = QString("Difference between beginning and 5: " + QString::fromStdString(std::to_string(std::distance(coll.begin(),pos))));
    }
    else
    {
        display = QString("5 not found");
    }

    return display;
}

QString Iterator::DistanceFromBeginningCode()
{
    QString display = QString(
                "std::list<int> coll;\n\nfor (int i = -3;i <= 9; ++i)\n   coll.push_back(i);\n\n"
                "std::list<int>::iterator pos;\npos = std::find(coll.begin(),coll.end(), 5);\n\n"
                "if (pos != coll.end())\n{\ndisplay = std::distance(coll.begin(),pos);\n}\nelse\n{\n"
                "display = \"5 not found\";\n}"
                );

    return display;
}

QString Iterator::InsertElementAtBeginningExample()
{
    QString display;
    std::list<int> coll;

    std::front_inserter(coll) = 44;
    std::front_inserter(coll) = 55;

    display = QString("Inserting value 44 and 55 to the container.\n\nValue inside the container :\n");

    for(const auto& elem : coll)
        display += QString(QString::fromStdString(std::to_string(elem)) + " ");



    return display;
}

QString Iterator::InsertElementAtBeginningCode()
{
    QString display = QString(
                "std::list<int> coll;\n\nstd::front_inserter(coll) = 44;\nstd::front_inserter(coll) = 55;"
                );

    return display;
}

QString Iterator::AppendAllElementWithFrontInserterExample()
{
    QString display;
    std::list<int> coll;

    std::front_inserter(coll) = 44;
    std::front_inserter(coll) = 55;

    display = QString("Inserting value 44 and 55 to the container.\n\nValue inside the container :\n");

    for(const auto& elem : coll)
        display += QString(QString::fromStdString(std::to_string(elem)) + " ");

    std::copy(coll.begin(),coll.end(),std::front_inserter(coll));
    display += QString("\n\nNow, we are appending values inside the container to the same container:\nValue inside the container :");

    for(const auto& elem : coll)
        display += QString(QString::fromStdString(std::to_string(elem)) + " ");

    return display;
}

QString Iterator::AppendAllElementWithFrontInserterCode()
{
    QString display = QString(
                "std::list<int> coll;\n\nstd::front_inserter(coll) = 44;\nstd::front_inserter(coll) = 55;\n"
                "std::copy(coll.begin(),coll.end(),std::front_inserter(coll));"
                );

    return display;
}

QString Iterator::InsertValueWithAnInserterExample()
{
    QString display;
    std::set<int> coll;

    std::inserter(coll,coll.end()) = 44;
    std::inserter(coll,coll.end()) = 55;

    display = QString("Inserter value 44 and 55 inside the container\nValues in the container :");

    for(const auto& elem : coll)
        display += QString(QString::fromStdString(std::to_string(elem))+ " ");

    return display;
}

QString Iterator::InsertValueWithAnInserterCode()
{
    QString display = QString(
                "std::set<int> coll;\n\nstd::inserter(coll,coll.end()) = 44;\nstd::inserter(coll,coll.end()) = 55;"
                );

    return display;
}
