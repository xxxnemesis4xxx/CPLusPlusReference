#include "iterator.h"
#include <iterator>
#include <iostream>
#include <list>
#include <algorithm>


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

//QString Iterator::AdvanceExample()
//{
//    list<int>::iterator pos = coll.begin();

//    //Print actual element
//    cout << *pos << endl;

//    //step three elements forward
//    advance(pos,3);

//    //Print actual element
//    cout << *pos << endl;

//    //Step one element backward
//    advance(pos,-1);

//    //print actual element
//    cout << *pos << endl;

//}
