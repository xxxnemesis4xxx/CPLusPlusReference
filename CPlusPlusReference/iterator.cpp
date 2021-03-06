#include "iterator.h"
#include <iterator>
#include <iostream>
#include <list>
#include <algorithm>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <QDebug>
#include <unordered_set>


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

QString Iterator::AppendAllElementWithInserterExample()
{
    QString display;
    std::set<int> coll;
    std::list<int> coll2;

    std::inserter(coll,coll.end()) = 44;
    std::inserter(coll,coll.end()) = 55;

    display = QString("Inserter value 44 and 55 inside the container\nValues in the container :");

    for(const auto& elem : coll)
        display += QString(QString::fromStdString(std::to_string(elem))+ " ");

    display += QString("\n\nUse inserter to insert all elements into a list\nValues in the list :");
    std::copy(coll.begin(),coll.end(),inserter(coll2,coll2.begin()));

    for (const auto& elem : coll2)
        display += QString(QString::fromStdString(std::to_string(elem)) + " ");

    return display;
}

QString Iterator::AppendAllElementWithInserterCode()
{
    QString display = QString(
                "std::set<int> coll;\nstd::list<int> coll2;\n\nstd::inserter(coll,coll.end()) = 44;\n"
                "std::inserter(coll,coll.end()) = 55;\n\n"
                "std::copy(coll.begin(),coll.end(),inserter(coll2,coll2.begin()));"
                );

    return display;
}

QString Iterator::InsertElementAtSpecificLocationExample()
{
    QString display;
    std::set<int> coll;
    std::list<int> coll2;

    std::inserter(coll,coll.end()) = 44;
    std::inserter(coll,coll.end()) = 55;

    display = QString("Inserter value 44 and 55 inside the container\nValues in the container :");

    for(const auto& elem : coll)
        display += QString(QString::fromStdString(std::to_string(elem))+ " ");

    display += QString("\n\nUse inserter to insert all elements into a list\nValues in the list :");
    std::copy(coll.begin(),coll.end(),inserter(coll2,coll2.begin()));

    for (const auto& elem : coll2)
        display += QString(QString::fromStdString(std::to_string(elem)) + " ");

    display += QString("\n\nReinsert all element into the list before second element\nValues in the list :");
    std::copy(coll.begin(),coll.end(),inserter(coll2, ++coll2.begin()));

    for (const auto& elem : coll2)
        display += QString(QString::fromStdString(std::to_string(elem)) + " ");

    return display;
}

QString Iterator::InsertElementAtSpecificLocationCode()
{
    QString display = QString(
                "std::set<int> coll;\nstd::list<int> coll2;\n\nstd::inserter(coll,coll.end()) = 44;\n"
                "std::inserter(coll,coll.end()) = 55;\n\n"
                "std::copy(coll.begin(),coll.end(),inserter(coll2,coll2.begin()));\n\n"
                "std::copy(coll.begin(),coll.end(),inserter(coll2,++coll2.begin()));"
                );

    return display;
}

QString Iterator::MoveIteratorOffNPositionExample()
{
    QString display;
    std::list<int> mylist;
    for (int i=0; i<10; ++i)
        mylist.push_back(i*10);

    std::list<int>::iterator it = mylist.begin();

    std::advance (it,5);
    display = QString("The sixth element in mylist is: " + QString::fromStdString(std::to_string(*it)));

    return display;
}

QString Iterator::MoveIteratorOffNPositionCode()
{
    QString display = QString(
                "std::list<int> mylist;\nfor (int i=0; i<10; ++i)\n  mylist.push_back(i*10);\n\n"
                "std::list<int>::iterator it = mylist.begin();\n\n std::advance(it,5);"
                );

    return display;
}

QString Iterator::SwapFirstAndSecondValueExample()
{
    QString display;
    std::list<int> coll;

    for(int i = 0; i <= 9; ++i)
        coll.push_back(i);

    display = QString(
                "Insert values from 0 to 9 in the container.\nValues in the container : "
                );
    for(const auto& elem : coll)
        display += QString(QString::fromStdString(std::to_string(elem)) + " ");

    std::iter_swap(coll.begin(),std::next(coll.begin()));
    display += QString("\n\nSwapping first and second value in the container\nValues in the container : ");

    for(const auto& elem : coll)
        display += QString(QString::fromStdString(std::to_string(elem)) + " ");

    return display;
}

QString Iterator::SwapFirstAndSecondValueCode()
{
    QString display = QString(
                "std::list<int> coll;\n\nfor(int i = 0;i <= 9; ++i)\n  coll.push_back(i);\n\n"
                "std::iter_swap(coll.begin(),std::next(coll.begin()));"
                );

    return display;
}

QString Iterator::SwapFirstAndLastValueExample()
{
    QString display;
    std::list<int> coll;

    for(int i = 0; i <= 9; ++i)
        coll.push_back(i);

    display = QString(
                "Insert values from 0 to 9 in the container.\nValues in the container : "
                );
    for(const auto& elem : coll)
        display += QString(QString::fromStdString(std::to_string(elem)) + " ");

    std::iter_swap(coll.begin(), prev(coll.end()));
    display += QString("\n\nSwapping first and last value in the container\nValues in the container : ");

    for(const auto& elem : coll)
        display += QString(QString::fromStdString(std::to_string(elem)) + " ");

    return display;
}

QString Iterator::SwapFirstAndLastValueCode()
{
    QString display = QString(
                "std::list<int> coll;\n\nfor(int i = 0;i <= 9; ++i)\n  coll.push_back(i);\n\n"
                "std::iter_swap(coll.begin(),std::prev(coll.end()));"
                );

    return display;
}

QString Iterator::ReadValueWithOstreamIteratorExample()
{
    //Create ostream iterator for stream cout
    std::ostream_iterator<int> intWriter(std::cout,"\n");

    //Write element with the usual iterator interface
    *intWriter = 42;
    ++intWriter;
    *intWriter = 77;
    ++intWriter;
    *intWriter = -5;

    //Create a collection with elements from 1 to 9
    std::vector<int> coll = {1,2,3,4,5,6,7,8,9};

    //Write all elementw without delimiter
    std::copy(coll.cbegin(),coll.cend(),std::ostream_iterator<int>(std::cout));
    std::cout << std::endl;

    //Write all elements with " < " delimiter
    std::copy(coll.cbegin(),coll.cend(),std::ostream_iterator<int>(std::cout," < "));
    std::cout << std::endl;

    //Write all element with a string deliter
    // Note : .c_str() convert out string array into a char* string because the function only accept c style string
    std::string strDelimiter = " != ";
    std::copy(coll.cbegin(), coll.cend(), std::ostream_iterator<int>(std::cout,strDelimiter.c_str()));

    return QString("This can only be run on console!");
}

QString Iterator::ReadValueWithOstreamIteratorCode()
{
    return QString(
                "<FONT COLOR=green>//Create ostream iterator for stream cout</font><br/>"
                "std::ostream_iterator<int> intWritter(std::cout,\"\\n\");<br/><br/>"
                "<FONT COLOR=green>//Write elements with the usual iterator interface</font><br/>"
                "*intWritter = 42;<br/>++intWritter;<br/>*intWritter = 77;<br/>++intWritter;<br/>*intWritter = -5;<br/><br/>"
                "<FONT COLOR=green>//Create collection with elements from 1 to 9</font><br/>"
                "std::vector<int> coll = {1,2,3,4,5,6,7,8,9};<br/><br/>"
                "<FONT COLOR=green>Write all elements without delimiter</font><br/>"
                "std::copy(coll.cbegin(),coll.cend(),std::ostream_iterator<int>(std::cout));<br/><br/>"
                "<FONT COLOR=green>Write all elements with delimiter</font><br/>"
                "std::copy(coll.cbegin(),coll.cend(),std::ostream_iterator<int>(std::cout,\"  \"));<br/><br/>"
                "<FONT COLOR=green>Write all element with a string delimiter</font><br/>"
                "std::string strDelimiter = \" != \";<br/>"
                "std::copy(coll.cbegin(),coll.cend(),std::ostream_iterator<int>(std::cout,strDelimiter.c_str()));"
                );
}

QString Iterator::UsageOfPrevAndNextExample()
{
    QString display = "Comparing values : \n";
    std::list<int> coll
    {
        3,40,12,62,1,16,34,12,98,25,12,32,50,33,65,42,21,30
    };

    auto pos = coll.begin();
    while (pos !=coll.end() && std::next(pos) != coll.end())
    {
        auto var = std::next(pos);
        if (*pos > *var)
            display += QString(QString::fromStdString(std::to_string(*pos)) + " > " + QString::fromStdString(std::to_string(*var)) + "\n");
        else if (*pos == *var)
            display += QString(QString::fromStdString(std::to_string(*pos)) + " = " + QString::fromStdString(std::to_string(*var)) + "\n");
        else
            display += QString(QString::fromStdString(std::to_string(*pos)) + " < " + QString::fromStdString(std::to_string(*var)) + "\n");

        ++pos;
    };

    return display;
}

QString Iterator::UsageOfPrevAndNextCode()
{
    return QString(
                "std::list<int> coll { 3,40,12,62,1,16,34,12,98,25,12,32,50,33,65,42,21,30 };"
                "\n\nauto pos = coll.begin();\nwhile(pos != coll.end() && std::next(pos) != coll.end())\n{\n"
                "auto var = std::next(pos);\nif(*pos > *var)\ndisplay += ...;\nelse if (*pos == *var)\ndisplay += ...;\n"
                "else\ndisplay += ...;\n\n++pos;\n};"
                );
}

QString Iterator::RandomAccessIteratorExample()
{
    QString display("Print all elements inside the container :\n");
    std::vector<int> coll;

    for (int i = -3; i <= 9; ++i)
        coll.push_back(i);

    std::vector<int>::iterator pos;
    for (pos = coll.begin(); pos < coll.end(); ++pos)
        display += QString(QString::fromStdString(std::to_string(*pos)) + ",");

    display += QString("\n\nPrint all element inside the container with a second technique :\n");
    for (int i = 0; i < coll.size(); ++i)
        display += QString(QString::fromStdString(std::to_string(coll.begin()[i])) + ",");

    display += QString("\n\nPrint number of elements by processing the the distance : ");
    display += QString("\nNumber/distance : " + QString::fromStdString(std::to_string(coll.end()-coll.begin())));
    display += QString("\n\nPrint every second element :\n");

    for (pos = coll.begin(); pos < coll.end() -1 ; pos += 2)
        display += QString(QString::fromStdString(std::to_string(*pos)) + ",");

    return display;
}

QString Iterator::RandomAccessIteratorCode()
{
    return QString(
                "std::vector<int> coll;\n\nfor(int i = -3; i <= 9; ++i)\n  coll.push_back(i);\n\n"
                "std::vector<int> pos;\nfor (pos = coll.begin(); pos < coll.end(); ++pos)\n  display += *pos;\n\n"
                "display += coll.end() - coll.begin();\n\nfor (int i = 0; i < coll.size(); ++i)\n  display += coll.begin()[i];\n\n"
                "for (pos = coll.begin(); pos < coll.end() - 1; pos += 2)\n  display += *pos;"
                );
}

QString Iterator::PrintAllElementInReverseExample()
{
    QString display = "Print values from left to right :\n";
    std::list<int> coll { 1,2,3,4,5,6,7,8,9};

    for(const auto& elem : coll)
        display += QString(QString::fromStdString(std::to_string(elem)) + " ");

    display += QString ("\n\nPrint values from right to left :\n");
    auto pos = coll.rbegin();
    while (pos != coll.rend())
    {
        display += QString(QString::fromStdString(std::to_string(*pos)) + " ");
        ++pos;
    }

    return display;
}

QString Iterator::PrintAllElementInReverseCode()
{
    return QString(
                "std::list<int> coll { 1,2,3,4,5,6,7,8,9 };\n\nfor(const auto& elem : coll)\n"
                "  display += ...;\n\nauto pos = coll.rbegin();\nwhile(pos != coll.rend())\n{\ndisplay += ...;\n"
                "++pos;\n}"
                );
}

void doubleValue(int& elem)
{
    elem = elem * 2;
}

QString Iterator::UsageOfForEachExample()
{
    QString display = "Print all elements in a container\n";
    std::list<int> coll = {1,2,3,4,5,6,7,8,9 };

    std::for_each(coll.begin(),coll.end(),doubleValue);
    for(const auto& elem : coll)
        display += QString(QString::fromStdString(std::to_string(elem)) + " ");

    return display;
}

QString Iterator::UsageOfForEachCode()
{
    return QString(
                "void doubleValue(int& elem)\n{\n   elem = elem * 2;\n}\n\n"
                "std::list<int> coll = { 1,2,3,4,5,6,7,8,9 };\nstd::for_each(coll.begin();coll.end();doubleValue);"
                );
}

QString Iterator::UserDefineIteratorsExample()
{
    QString display = "Iterator class defined by the user\n\n";
    std::unordered_set<int> coll;

    //Create inserter for coll
    display += QString("Insert elements 44 and 55 inside the container\n");
    asso_inserter(coll) = 44;
    asso_inserter(coll) = 55;
    for(const auto& elem : coll)
        display += QString(QString::fromStdString(std::to_string(elem)) + " ");

    //User inserter with an algorithm
    display += QString("\n\nInsert elements of another container in our unordered_set\n");
    std::vector<int> vals = { 33,67,-4,13,5,2 };
    std::copy(vals.begin(),vals.end(),asso_inserter(coll));
    for (const auto& elem : coll)
        display += QString(QString::fromStdString(std::to_string(elem)) + " ");

    return display;
}

QString Iterator::UserDefineIteratorsCode()
{
    return QString(
                "template <typename Container>\n"
                "class asso_insert_iterator : public std::iterator\n"
                "<std::output_iterator_tag, typename Container::value_type>\n"
                "{\nprotected:\n  Container& container;\n\npublic :\n"
                "   explicit asso_insert_iterator(Container& c) : container(c) {}\n\n"
                "   asso_insert_iterator<Container>& operator= (const typename Container::value_type& value)\n"
                "   {\n      container.insert(value);\n      return *this;\n   }\n\n"
                "   asso_insert_iterator<Container>& operator* ()\n   {\n      return *this;\n   }\n\n"
                "   asso_insert_iterator<Container>& operator++ () { return *this; }\n"
                "   asso_insert_iterator<Container>& operator++ (int) { return *this; }\n"
                "};\n\ntemplate <typename Container>\n"
                "inline asso_insert_iterator<Container> asso_inserter( Container& c)\n{\n"
                "   return asso_insert_iterator<Container>(c);\n}\n\n"
                "----------------------------------------------------------------------------"
                "std::unordered_set<int> coll;\n\nasso_inserter(coll) = 44;\nasso_inserter(coll) = 55;\n\n"
                "std::vector<int> vals = { 33,67,-4,13,5,2 };\nstd::copy(vals.begin(),vals.end(),asso_inserter(coll));"
                );
}
