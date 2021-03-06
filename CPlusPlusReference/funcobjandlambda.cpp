#include "funcobjandlambda.h"
#include <functional>
#include <iostream>
#include <algorithm>
#include <locale>
#include <string>
#include <numeric>
#include <map>
#include <cmath>
#include <iterator>
#include <list>
#include <vector>
#include <set>

FuncObjAndLambda::FuncObjAndLambda()
{

}

FuncObjAndLambda::~FuncObjAndLambda()
{

}

QString FuncObjAndLambda::MathematicalOperationsExample()
{
    QString display = "7 + 10 = ";
    auto plus10 = std::bind(std::plus<int>(),std::placeholders::_1,10);
    int result = plus10(7);
    display += QString(QString::fromStdString(std::to_string(result)));

    auto plus10times2 = std::bind(std::multiplies<int>(),std::bind(std::plus<int>(),std::placeholders::_1,10),2);
    int result2 = plus10times2(7);
    display += QString("\n\n(7 + 10)*2 = " + QString::fromStdString(std::to_string(result2)));

    auto pow3 = std::bind(std::multiplies<int>(),std::bind(std::multiplies<int>(),std::placeholders::_1,std::placeholders::_1),std::placeholders::_1);
    int result3 = pow3(7);
    display += QString("\n\n7 * 7 * 7 = " + QString::fromStdString(std::to_string(result3)));

    auto inversDivide = std::bind(std::divides<double>(),std::placeholders::_2,std::placeholders::_1);
    double result4 = inversDivide(7,49);
    display += QString("\n\n49 / 7 = " + QString::fromStdString(std::to_string(result4)));

    return display;
}

QString FuncObjAndLambda::MathematicalOperationsCode()
{
    return QString(
                "auto plus10 = std::bind(std::plus<int>(),std::placeholders::_1,10);\n"
                "int result = plus10(7);\n\nauto plus10times2 = std::bind(std::multiplies<int>(),std::bind(std::plus<int>(),std::placeholders::_1,10),2);\n"
                "int result2 = plus10times2(7);\n\nauto pow3 = std::bind(std::multiplies<int>(),std::bind(std::multiplies<int>(),std::placeholders::_1,std::placeholders::_1),std::placeholders::_1);\n"
                "int result3 = pow3(7);\n\nauto inversDivide = std::bind(std::divides<double>(),std::placeholders::_2,std::placeholders::_1);\n"
                "double result4 = inversDivide(49,7);"
                );
}

char myToupper(char c)
{
    //Local is for international portability
    std::locale loc;

    return std::use_facet<std::ctype<char>>(loc).toupper(c);
}

char myTolower(char c)
{
    //Loal is for international portability
    std::locale loc;

    return std::use_facet<std::ctype<char>>(loc).tolower(c);
}

QString FuncObjAndLambda::CapitalAndLowercaseLetterExample()
{
    QString display = "Turning a lowercase word into a uppercase word\nhello -> ";
    std::string word = "hello";

    for(int i = 0; i < word.size(); ++i)
        word[i] = myToupper(word[i]);
    display += QString(QString::fromStdString(word) + "\n\n");

    for(int i = 0; i < word.size(); ++i)
        word[i] = myTolower(word[i]);
    display += QString("Turning a Capital word into a lowercase word\nHELLO -> " + QString::fromStdString(word));

    return display;
}

QString FuncObjAndLambda::CapitalAndLowercaseLetterCode()
{
    return QString(
                "char myToupper(char c)\n{\n   std::locale c;\n   return std::use_facet<std::ctype<char>>(loc).toupper(c);\n}\n\n"
                "char myTolower(char c)\n{\n   std::locale c;\n   return std::use_facet<std::ctype<char>>(loc).tolower(c);\n}\n\n"
                "std::string word = \"hello\";\n\nfor(int i = 0; i < word.size(); ++i)\n   word[i] = myToupper(word[i]);\ndisplay += word;\n\n"
                "for (int i = 0; i < word.size(); ++i)\n   word[i] = myTolower(word[i]);\ndisplay += word;"
                );
}

QString FuncObjAndLambda::SumOfAllIntInMapExample()
{
    QString display = "Calcul the sum of all values inside the map\nValues inside the container : \n";
    std::map<std::string,int> coll =
    {
        {"Number 1", 10},
        {"Number 2", 20},
        {"Number 3", 30},
        {"Number 4", 40},
        {"Number 5", 50},
        {"Number 6", 60},
        {"Number 7", 70},
        {"Number 8", 80}
    };
    for(const auto& elem : coll)
        display += QString("(" + QString::fromStdString(elem.first) + "," + QString::fromStdString(std::to_string(elem.second)) + ")\n");

    /* coll.begin() -> Beginning of the list
     * coll.end() -> End of the list
     * 0 -> starting value
     * std::bind(std::plus<int>(),std::placeholders::_1 -> Reference to the value 0 which is going to change as we sum new value to it
     * std::bind<&std::map<std::string,int>::value_type::second,std::placeholders::_2 ->Get the second value inside the map and sum it to the placeholder::_1 using the accumulate function
    */
    int sum = std::accumulate(coll.begin(),coll.end(),0,std::bind(std::plus<int>(),std::placeholders::_1,std::bind(&std::map<std::string,int>::value_type::second,std::placeholders::_2)));
    display += QString("\nSum of all the numbers : " + QString::fromStdString(std::to_string(sum)));

    return display;
}

QString FuncObjAndLambda::SumOfAllIntInMapCode()
{
    return QString(
                "std::map<std::string,int> coll =\n"
                "{\n   {\"Number 1\", 10},\n"
                "   {\"Number 2\", 20},\n"
                "   {\"Number 3\", 30},\n"
                "   {\"Number 4\", 40},\n"
                "   {\"Number 5\", 50},\n"
                "   {\"Number 6\", 60},\n"
                "   {\"Number 7\", 70},\n"
                "   {\"Number 8\", 80}\n};\n"
                "for(const auto& elem : coll)\n   display += ...;\n\n"
                "int sum = std::accumulate(coll.begin(),coll.end(),0,std::bind(std::plus<int>(),std::placeholders::_1,std::bind(&std::map<std::string,int>::value_type::second,std::placeholders::_2)));"
                );
}

template <typename T1, typename T2>
struct fopow
{
    T1 operator() (T1 base, T2 exp) const
    {
        return pow(base, exp);
    }
};

QString FuncObjAndLambda::PowerUp3WithValueInsideContainerExample()
{
    QString display = "Values inside the first container :\n";
    std::vector<int> coll = { 1,2,3,4,5,6,7,8,9 };
    std::vector<int> coll2;

    coll2.resize(coll.size());
    std::transform(coll.begin(),coll.end(),coll2.begin(),std::bind(fopow<float,int>(),std::placeholders::_1,3));

    for(const auto& elem : coll)
        display += QString(QString::fromStdString(std::to_string(elem)) + " ");
    display += QString("\n\nPower up every number with exponent 3\n");

    for (const auto& elem : coll2)
        display += QString(QString::fromStdString(std::to_string(elem)) + " ");

    return display;
}

QString FuncObjAndLambda::PowerUp3WithValueInsideContainerCode()
{
    return QString(
                "template <typename T1, typename T2>\nstruct fopow\n{\n"
                "   T1 operator() (T1 base, T2 exp)\n   {\n      return pow(base,exp);\n   }\n};"
                "\n\nstd::vector<int> coll = { 1,2,3,4,5,6,7,8,9 };\nstd::vector<int> coll2;\n\n"
                "coll2.resize(coll.size());\n"
                "std::transform(coll.begin(),coll.end(),coll2.begin(),std::bind(fopow<float,int>(),std::placeholders::_1,3));"
                );
}

QString FuncObjAndLambda::PrintMeanValueExample()
{
    QString display = "Process and print the mean value = \n";
    std::vector<int> coll = { 1,2,3,4,5,6,7,8,9 };

    long sum = 0;
    std::for_each(coll.begin(),coll.end(),[&sum] (int elem)
    {
       sum += elem;
    });

    double mv = static_cast<double>(sum)/static_cast<double>(coll.size());
    display += QString::fromStdString(std::to_string(mv));

    return display;
}

QString FuncObjAndLambda::PrintMeanValueCode()
{
    return QString(
                "std::vector<int> coll = { 1,2,3,4,5,6,7,8,9 };\n\nlong sum = 0;\n"
                "std::for_each(coll.begin(),coll.end(),[&sum] (int elem)\n{\n   sum += elem;\n});\n\n"
                "double mv = static_cast<double>(sum)/static_cast<double>(coll.size());"
                );
}

QString FuncObjAndLambda::RemoveThirdElementExample()
{
    QString display = "Remove the third element inside a container\n\nValue inside the container :\n";
    std::list<int> coll = { 1,2,3,4,5,6,7,8,9,10 };

    for(const auto& elem : coll)
        display += QString(QString::fromStdString(std::to_string(elem)) + " ");

    std::list<int>::iterator pos;
    int count = 0;
    pos = remove_if(coll.begin(),coll.end(),[&count] (int) mutable
    {
       return ++count == 3;
    });
    coll.erase(pos,coll.end());

    display += QString("\n\nValue inside the container now :\n");
    for (const auto& elem : coll)
        display += QString(QString::fromStdString(std::to_string(elem)) + " ");

    return display;
}

QString FuncObjAndLambda::RemoveThirdElementCode()
{
    return QString(
                "std::list<int> coll = { 1,2,3,4,5,6,7,8,9,10 };\nstd::list<int>::iterator pos;\nint count = 0;\n"
                "\npos = remove_if(coll.begin(),coll.end(),[&count] (int) mutable\n{\n   return ++count == 3;\n}\n"
                "coll.erase(pos,coll.end());"
                );
}

QString FuncObjAndLambda::SearchSubcaseStringInsensitiveExample()
{
    QString display = "Search substring case insensitive\n";
    std::string s("Internationalization");
    std::string sub("Nation");
    display += QString("First word = " + QString::fromStdString(s) + "\nSecond word = " + QString::fromStdString(sub) + "\n\n");

    std::string::iterator pos;
    pos = search(s.begin(),s.end(),sub.begin(),sub.end(),[] (char c1, char c2)
    {
       return myToupper(c1)==myToupper(c2);
    });

    if (pos != s.end())
        display += QString("\"" + QString::fromStdString(sub) + "\" is part of \"" + QString::fromStdString(s) + "\"");

    return display;
}

QString FuncObjAndLambda::SearchSubcaseStringInsensitiveCode()
{
    return QString(
                "char myToupper(char c)\n{\n   std::locale c;\n   return std::use_facet<std::ctype<char>>(loc).toupper(c);\n}\n\n"
                "std::string s(\"Internationalization\");\nstd::string sub(\"nation\");\n\n"
                "std::string::iterator pos;\npos = search(s.begin(),s.end(),sub.begin(),sub.end(),[] (char c1, char c2)\n{\n   return myToupper(c1)==myToupper(c2);\n}\n\n"
                "if (pos != s.end())\n   display += ...; "
                );
}

class Nth
{
private:
    int nth;
    int count;
public :
    Nth(int n) : nth(n), count(0) {}
    bool operator() (int) { return ++count == nth; }
};

QString FuncObjAndLambda::RemoveIfWithFunctionObjectExample()
{
    QString display = "Remove third element inside a container\n\n";
    std::list<int> coll = { 1,2,3,4,5,6,7,8,9,10 };
    display += QString("Value inside the container : \n");
    for (const auto& elem : coll)
        display += QString(QString::fromStdString(std::to_string(elem)) + " ");

    std::list<int>::iterator pos;
    pos = std::remove_copy_if(coll.begin(), coll.end(),coll.begin(),Nth(3));
    coll.erase(pos, coll.end());

    display += QString("\n\nThird element has been removed\nValues inside the container : \n");
    for (const auto& elem : coll)
        display += QString(QString::fromStdString(std::to_string(elem)) + " ");

    return display;
}

QString FuncObjAndLambda::RemoveIfWithFunctionObjectCode()
{
    return QString(
                "class Nth\n{\nprivate :\n   int nth;\n   int count;\npublic:\n"
                "   Nth(int n) : nth(n),count(0) {}\n   bool operator() (int) { return ++count == nth; }\n};\n\n"
                "std::list<int> coll = { 1,2,3,4,5,6,7,8,9,10 };"
                "std::list<int>::iterator pos;\npos = std::remove_copy_if(coll.begin(), coll.end(),coll.begin(),Nth(3));\n"
                "coll.erase(pos,coll.end());"
                );
}

class IntSequence
{
private:
    int value;
public :
    IntSequence(int initialValue)
        : value(initialValue) {}

    //Function call
    int operator() () { return ++value; }
};

QString FuncObjAndLambda::MultipleStageFuncObExample()
{
    QString display = "Function with multiples states at the same time";
    std::list<int> coll;

    std::generate_n(std::back_inserter(coll),9,IntSequence(1));

    display += QString("\n\nValues inside the container : \n");
    for (const auto& elem : coll)
        display += QString(QString::fromStdString(std::to_string(elem)) + " ");

    std::generate(std::next(coll.begin()),std::prev(coll.end()),IntSequence(42));
    display += QString("\n\nReplace second to last element but one with value starting at 43 : \n");
    for (const auto& elem : coll)
        display += QString(QString::fromStdString(std::to_string(elem)) + " ");

    return display;
}

QString FuncObjAndLambda::MultipleStageFuncObCode()
{
    return QString(
                "class IntSequence\n{\nprivate :\n   int value;\npublic :\n   IntSequence(int initialValue) : value(initialValue) {}\n"
                "   int operator() (){ return ++value; }\n};\n\n"
                "std::list<int> coll;\nstd::generate_n(std::back_inserter(coll),9,IntSequence(1));\n"
                "std::generate(std::next(coll.begin()),std::prev(coll.end()),IntSequence(42));"
                );
}

QString FuncObjAndLambda::PassingValuesToFuncObjExample()
{
    QString display = "Multiple ways to pass value to a function object \n\n";
    std::list<int> coll;
    IntSequence seq(1);

    std::generate_n<std::back_insert_iterator<std::list<int>>,int,IntSequence&>(std::back_inserter(coll),4,seq);
    display += QString("Values inside the container using a reference:\n");
    for (const auto& elem : coll)
        display += QString(QString::fromStdString(std::to_string(elem)) + " ");

    display += QString("\n\nValues inside the container using by value:\n");
    std::generate_n(std::back_inserter(coll),4,seq);
    for (const auto& elem : coll)
        display += QString(QString::fromStdString(std::to_string(elem)) + " ");

    return display;
}

QString FuncObjAndLambda::PassingValuesToFuncObjCode()
{
    return QString(
                "class IntSequence\n{\nprivate :\n   int value;\npublic :\n   IntSequence(int initialValue) : value(initialValue) {}\n"
                "   int operator() (){ return ++value; }\n};\n\n"
                "std::list<int> coll;\nIntSequence seq(1);\n\n"
                "std::generate_n<std::back_insert_iterator<std::list<int>>,int,IntSequence&>(std::back_inserter(coll),4,seq);\n\n"
                "std::generate_n(std::back_inserter(coll),4,seq);"
                );
}

class MeanValue
{
private :
    long num; //Number of elements
    long sum; //Sum of all element values

public :
    MeanValue()
        : num(0), sum(0) {}

    //Function call
    // - Process one more element of the sequence
    void operator() (int elem)
    {
        ++num;
        sum += elem;
    }

    //return mean value
    double value() { return static_cast<double>(sum) / static_cast<double>(num) ; }
};


QString FuncObjAndLambda::PrintMeanValue2Example()
{
    QString display = "Print mean value of a container\n\n";
    std::vector<int> coll = { 1,2,3,4,5,6,7,8,9,10 };

    MeanValue mv = std::for_each(coll.begin(),coll.end(),MeanValue());
    display += "Values inside the container : \n";
    for (const auto& elem : coll)
        display += QString(QString::fromStdString(std::to_string(elem)) + " ");

    display += QString("\n\nMean value = " + QString::fromStdString(std::to_string(mv.value())));

    return display;
}

QString FuncObjAndLambda::PrintMeanValue2Code()
{
    return QString(
                "class MeanValue\n{\nprivate :\n   long num;\n   long sum;\npublic :\n"
                "   MeanValue() : num(0),sum(0) {}\n\n   void operator() (int elem)\n{\n"
                "   ++num;\n   sum += elem;\n}\n\n   double value() { return static_cast<double>(sum) / static_cast<double>(num) ; }\n};\n\n"
                "std::vector<int> coll = { 1,2,3,4,5,6,7,8,9,10 };\n\nMeanValue mv = std::for_each(coll.begin(),coll.end(),MeanValue());\n"
                "display += mv.value();"
                );
}

class Person
{
private :
    std::string m_firstname;
    std::string m_lastname;
public:
    Person(std::string first, std::string last)
        : m_firstname(first), m_lastname(last) {}
    std::string firstname() const { return m_firstname; }
    std::string lastname() const { return m_lastname; }
};

//Class for function predicateR
// - Operator () returns whether a person is less than another person
class PersonSortCriterion
{
public:
    bool operator() (const Person& p1, const Person& p2) const
    {
        //a person if less than another person
        // if the last name is less
        // if the last name is equal and the first name is less
        return p1.lastname() < p2.lastname() ||
               (p1.lastname() == p2.lastname() &&
                p1.firstname() < p2.firstname());
    }
};

QString FuncObjAndLambda::SortSetWithCriterionExample()
{
    QString display = "Sorting a container with criterion\n\n";


    //Create a set with special sorting criterion
    std::set<Person,PersonSortCriterion> coll;
    Person p1("Marc","Tetris");
    Person p2("Jaysen","Gagnon");
    Person p3("Patrick","St-Pierre");
    Person p4("Catherine","Sirois");
    Person p5("Steeve","Bertrand");
    Person p6("Lydia","Migneault");
    Person p7("Christopher","Gagne");
    Person p8("Pascal","Savard");
    Person p9("Imaqtpie","Twitch");

    //Everytime we insert something, the set will be restructured according to the sorting criterion.
    coll.insert({p1,p2,p3,p4,p5,p6,p7,p8,p9});

    display += QString("Values inside the container : \n");
    for(const auto& elem : coll)
        display += QString(QString::fromStdString(elem.lastname()) + "," + QString::fromStdString(elem.firstname()) + "\n");

    return display;
}

QString FuncObjAndLambda::SortSetWithCriterionCode()
{
    return QString(
                "class Person\n{\nprivate :\n   std::string m_firstname;\n   std::string m_lastname;\npublic:\n"
                "   Person(std::string first,std::string last) : m_firstname(first), m_lastname(last) {}\n"
                "   std::string firstname() const { return m_firstname; }"
                "   std::string lastname() const { return m_lastname; }\n};\n\n"
                "class PersonSortCriterion\n{\npublic :\n"
                "   bool operator() (const Person& p1, const Person& p2) const\n{\n   "
                "return p1.lastname() < p2.lastname() || (p1.lastname() == p2.lastname() && p1.firstname() < p2.firstname());\n}\n};\n\n"
                "std::set<Person,PersonSortCriterion> coll;\n"
                "Person p1(\"Marc\",\"Tetris\");\n"
                "Person p2(\"Jaysen\",\"Gagnon\");\n"
                "Person p3(\"Patrick\",\"St-Pierre\");\n"
                "Person p4(\"Catherine\",\"Sirois\");\n"
                "Person p5(\"Steeve\",\"Bertrand\");\n"
                "Person p6(\"Lydia\",\"Migneault\");\n"
                "Person p7(\"Christopher\",\"Gagne\");\n"
                "Person p8(\"Pascal\",\"Savard\");\n"
                "Person p9(\"Iamqtpie\",\"Twitch\");\n\n"
                "coll.insert({p1,p2,p3,p4,p5,p6,p7,p8,p9});"
                );
}
