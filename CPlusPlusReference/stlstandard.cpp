#include "stlstandard.h"
#include <algorithm>
#include <vector>
#include <array>
#include <string>
#include <unordered_map>
#include <deque>
#include <functional>
#include <set>
#include <locale>
#include <list>
#include <forward_list>

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

class Person
{
private :
    std::string m_firstName;
    std::string m_lastName;
public :
    std::string firstname() const {return m_firstName; }
    std::string lastname() const { return m_lastName; }
    Person(std::string strFirstName = "", std::string strLastName = "")
        : m_firstName(strFirstName), m_lastName(strLastName) {}
    static QString print(Person p)
    {
        return QString(QString::fromStdString(p.firstname()) + ", " + QString::fromStdString(p.lastname()) + "\n");
    }
};

//Binary function predicate:
//Return whether a person is less than another person
bool personSortCriterion(const Person& p1, const Person& p2)
{
    //a person is less than another person
    // if the last name is less
    // if the last name is equal and the first name is less
    return p1.lastname() < p2.lastname() || ( p1.lastname() == p2.lastname() && p1.firstname() < p2.firstname());
}

QString StlStandard::BinaryPredicatesExample()
{
    QString display = "Binary predicates typically compare a specific property of two arguments\n\n";
    Person P1("Bob","Martin");
    Person P2("Charlie","Tremblay");
    Person P3("Jonathan","Pneumatique");
    Person P4("Kevin","Masson");
    Person P5("Lydia","Bernier");
    Person P6("Catherine","Cantin");

    //Creater our Queue
    std::deque<Person> coll
    {
        P1,P2,P3,P4,P5,P6
    };

    display += QString("Values inside the container : \n");
    for (const auto& elem : coll)
        display += Person::print(elem);

    display += QString("\nSort all the person using our predicate\nValues inside the container after sorting :\n");
    std::sort(coll.begin(),coll.end(),personSortCriterion);

    for(const auto& elem : coll)
        display += Person::print(elem);

    return display;
}

QString StlStandard::BinaryPredicatesCode()
{
    return QString(
                "class Person\n{\nprivate:\n   std::string m_firstname;\n   std::string m_lastname;\npublic:\n   std::string firstname() const {return m_firstname;}\n"
                "   std::string lastname() const { reutnr m_lastname; }\n   Person(std::string strFirstName = \"\", std::string strLastName = \"\") : m_firstname(strFirstName),"
                "m_lastname(strLastName) {}\n   static QString print(Person p) { return QString(...) ;}\n};\n\n"
                "bool personSortCriterion(const Person& p1,const Person& p2)\n{\n   return p1.lastname() < p2.lastname() || ( p1.lastname() == p2.lastname() && p1.firstname() < p2.firstname());\n}\n\n"
                "Person P1(\"Bob\",\"Martin\");\nPerson P2(\"Charlie\",\"Tremblay\");\nPerson P3(\"Jonathan\",\"Pneumatique\");\nPerson P4(\"Kevin\",\"Masson\");\n"
                "Person P5(\"Lydia\",\"Bernier\");\nPerson P6(\"Catherine\",\"Cantin\");\n\nstd::deque<Person> coll { P1,P2,P3,P4,P5,P6 };\n\n"
                "for (const auto& elem : coll)\n   display += Person::print(elem);\n\n std::sort(coll.begin(),coll.end(),personSortCriterion);"
                );
}


QString StlStandard::BinderExample()
{
    QString display = "Creating a container with a sorting criterion : \n";
    std::set<int,std::greater<int>> coll1 { 1,2,3,4,5,6,7,8,9 };
    std::deque<int> coll2;

    display += printContainer(coll1);
    display += QString("\n\nCopy every value into another container by multiplying them by 10 :\n");

    std::transform(coll1.begin(),coll1.end(),std::back_inserter(coll2),std::bind(std::multiplies<int>(),std::placeholders::_1,10));
    display += printContainer(coll2);
    display += QString("\n\nReplace value 70 with 42\n");

    std::replace_if(coll2.begin(),coll2.end(),std::bind(std::equal_to<int>(),std::placeholders::_1,70),42);
    display += printContainer(coll2);
    display += QString("\n\nRemove all elements with values between 50 and 80\n");

    coll2.erase(std::remove_if(coll2.begin(), coll2.end(),
                               std::bind(std::logical_and<bool>(),
                                         std::bind(std::greater_equal<int>(),std::placeholders::_1,50),
                                         std::bind(std::less_equal<int>(),std::placeholders::_1,80))),
                coll2.end());
    display += printContainer(coll2);

    return display;
}

QString StlStandard::BinderCode()
{
    return QString(
                "std::set<int,std::greater<int>> coll1 { 1,2,3,4,5,6,7,8,9 };\nstd::deque<int> coll2;\n\n"
                "std::transform(coll1.begin(),coll1.end(),std::back_inserter(coll2),std::bind(std::multiplies<int>(),std::placeholders::_1,10));\n\n"
                "std::replace_if(coll2.begin(),coll2.end(),std::bind(std::equal_to<int>(),std::placeholders::_1,70),42);\n\n"
                "coll2.erase(std::remove_if(coll2.begin(), coll2.end(),\n    std::bind(std::logical_and<bool>(),\n   "
                "std::bind(std::greater_equal<int>(),std::placeholders::_1,50),\n   std::bind(std::less_equal<int>(),std::placeholders::_1,80))),\n"
                "coll2.end());"
                );
}

//Print optional string optstr followed by
// all element of the collection coll
// in one line, separated by spaces
template <typename T>
inline QString PRINT_ELEMENTS (const T& coll, const std::string& optstr="")
{
    QString display = QString::fromStdString(optstr);

    for (const auto& elem : coll)
        display += QString(QString::fromStdString(std::to_string(elem)) + " ");

    return display;
}

QString StlStandard::TemplateInlineFuncExample()
{
    QString display = "Print optional string followed by all element in the container\n\n";
    std::set<int> Test2
    {
        1,2,3,4,5,6
    };

    display += PRINT_ELEMENTS(Test2, "All elements : ");

    return display;
}

QString StlStandard::TemplateInlineFuncCode()
{
    return QString(
                "template <typename T>\ninline QString PRINT_ELEMENTS (const T& coll, const std::string& optstr=\"\")\n"
                "{\n   QString display = QString::fromStdString(optstr);\n\n   for (const auto& elem : coll)\n   "
                "display += QString(QString::fromStdString(std::to_string(elem)) + \" \");\n\n   return display;\n}\n\n"
                "std::set<int> Test2 { 1,2,3,4,5,6 };\n\ndisplay += PRINT_ELEMENTS(Test2,\"All elements : \");"
                );
}


QString StlStandard::dequeExample()
{
    QString display = "Display the values inside deque container :\n";
    std::deque<float> coll;

    for (int i = 1; i <= 6; ++i)
        coll.push_back(i*1.1);
    display += printContainer(coll);

    return display;
}

QString StlStandard::dequeCode()
{
    return QString(
                "std::deque<float> coll;\n\nfor(int i = 1; i <= 6; ++i)\n   coll.push_back(i*1.1);"
                );
}

//General template
template <typename T>
QString foo(T var)
{
    QString display = "This is not a string ";
    if (std::is_integral<T>::value)
    {
        display += "\nThis is a integral value\n\n";
    }
    else
    {
        display += "\nThis is not a integral value\n\n";
    }

    return display;
}

//Template specialization
template<>
QString foo<std::string>(std::string var)
{
    return QString("This is a string : " + QString::fromStdString(var) + "\n\n");
}

QString StlStandard::templateSpecializationExample()
{
    QString display = "Template specilization\n\n";
    std::string Test = "Hello";
    int Test2 = 123;
    double test3 = 123.123;

    display += foo(Test);
    display += foo(Test2);
    display += foo(test3);

    return display;
}

QString StlStandard::templateSpecializationCode()
{
    return QString(
                "template <typename T>\nQString foo(T var)\n{\n   QString display = \"This is not a string\";\n"
                "   if (std::is_integral<T>::value)\n   {\n   display += \"This is a integral value\";\n   }\n"
                "   else\n   {\n      display += \"This is not a integral value\";\n   }\n\n   return display;\n}\n\n"
                "template<>\nQString foo<std::string>(std::string var)\n{\n   "
                "return QString(\"This is a string : \" + QString::fromStdString(var));\n}\n\n"
                "QString display = ...;\nstd::string test = \"Hello\";\nint test2 = 123;\ndouble test3 = 123.123;\n\n"
                "display += foo(test);\ndisplay += foo(test2);\ndisplay += foo(test3);"
                );
}

QString StlStandard::FindExample()
{
    QString display = "Multiples std::find() usage\n\n";
    std::list<int> coll;

    for(int i = 20; i < 40; ++i)
        coll.push_back(i);
    display += QString("Values inside the container :\n" + printContainer(coll));

    auto pos3 = std::find(coll.begin(), coll.end(), 3);
    display += QString("\n\nTrying to find value 3 inside our container :\npos3 = coll.end() -> because these is no value 3 in our container\n\n");

    display +=  QString("Trying to reverse container with pos3, but nothing will happen because it will reverse an empty range\n");
    std::reverse(pos3,coll.end());
    display += printContainer(coll);

    std::list<int>::const_iterator pos25,pos35;
    pos25 = std::find(coll.begin(),coll.end(),25);
    pos35 = std::find(coll.begin(),coll.end(),35);
    int maxvalue = *std::max_element(pos25,++pos35);
    display += QString("\n\nPrint the max value between pos25 and pos35\nValue = " + QString::fromStdString(std::to_string(maxvalue)) + "\n\n");

    display += QString("Advance way to find the first element that has either value 25 or value 35\n");
    auto pos = std::find_if(coll.begin(),coll.end(),
                            [] (int i)
    {
        return i == 25 || i == 35;
    });

    if (pos == coll.end())
    {
        display += "No element with value 25 or 35 found";
    }
    else if (*pos == 25)
    {
        pos25 = pos;
        pos35 = std::find(++pos,coll.end(),35);
        display += "We found 25 first";
    }
    else
    {
        pos35 = pos;
        pos25 = std::find(++pos,coll.end(),25);
        display += "We found 35 first";
    }

    return display;
}

QString StlStandard::FindCode()
{
    return QString(
                "std::list<int> coll;\n\nfor (int i = 20; i < 40; ++i)\n   coll.push_back(i);\n\n"
                "auto pos3 = std::find(coll.begin(),coll.end(),3);\n\nstd::list<int>::const_iterator pos25,pos35;\n"
                "pos25 = std::find(coll.begin(),coll.end(),25);\npos35 = std::find(coll.begin(),coll.end(),35);\nint"
                " maxvalue = *std::max_element(pos25,++pos35);\n\nauto pos = std::find_if(coll.begin(),coll.end(), [] (int i)\n"
                "{\n   return i == 25 || i == 35;\n});\n\nif(pos == coll.end())\n{\n   display += ...;\n}\nelse if (*pos == 25)\n{\n"
                "   pos25 = pos;\n   pos35 = std::find(++pos,coll.end(),35);\n}\nelse\n{\n   pos35 = pos;\n   pos25 = std::find(++pos,coll.end(),25);\n}"
                );
}

QString StlStandard::ForwardListExample()
{
    QString display = "Values inside the forward list :\n";

    std::forward_list<long> coll = { 2,3,5,7,11,13,17 };
    display += printContainer(coll);

    return display;
}

QString StlStandard::ForwardListCode()
{
    return QString(
                "std::forward_list<long> coll = { 2,3,5,7,11,13,17 };"
                );
}

void doubleValueforeach(int& elem)
{
    elem *= elem;
}

QString StlStandard::ForEachWithContainerExample()
{
    QString display = "Print the value inside the container :\n";
    std::vector<int> coll;

    for(int i = 1; i <= 9; ++i)
        coll.push_back(i);
    display += printContainer(coll);

    std::for_each(coll.begin(),coll.end(),doubleValueforeach);
    display += QString("\n\nValues inside the container now :\n" + printContainer(coll));

    return display;
}

QString StlStandard::ForEachWithContainerCode()
{
    return QString(
                "void doubleValue(int& elem)\n{\n   elem *= elem;\n}\n\n"
                "std::vector<int> coll;\n\nfor(int i = 1; i <= 9;++i)\n   coll.push_back(i);\n\n"
                "std::for_each(coll.begin(),coll.end(),doubleValue);"
                );
}

int square(int value)
{
    return value*value;
}

QString StlStandard::TransformWithContainerExample()
{
    QString display = "Values inside our first container:\n";
    std::set<int> coll1;
    std::vector<int> coll2;

    //Insert elements from 1 to 9 into coll1
    for(int i = 1; i <= 9; ++i)
        coll1.insert(i);
    display += printContainer(coll1);

    std::transform(coll1.begin(),coll1.end(),std::back_inserter(coll2),square);
    display += QString("\n\nInserting the square of every value of our first container into the second container\nValues inside the container :\n" + printContainer(coll2));

    return display;
}

QString StlStandard::TransformWithContainerCode()
{
    return QString(
                "int square(int value)\n{\n   return value*value;\n}\n\nstd::set<int> coll1;\nstd::vector<int> coll2;\n\n"
                "for(int i = 1;i <= 9; ++i)\n   coll1.insert(i);\n\nstd::transform(coll1.begin(),coll1.end(),std::back_inserter(coll2),square);"
                );
}

class PrintInt
{
private:
    QString display = "";
public:
    void operator() (int elem)
    {
        display += QString(QString::fromStdString(std::to_string(elem)) + " ");
    }

    QString Display() { return display; }
};

QString StlStandard::FunctionObjectExample()
{
    QString display = "Print values inside the container using our function object class :\n";
    std::vector<int> coll;

    for (int i = 1; i <= 9; ++i)
        coll.push_back(i);

    PrintInt pi = std::for_each(coll.begin(),coll.end(),PrintInt());
    display +=  pi.Display();

    return display;
}

QString StlStandard::FunctionObjectCode()
{
    return QString(
                "class PrintInt\n{\nprivate :\n   QString display = \"\";\npublic :\n   void operator() (int elem)\n   {\n"
                "      display += ...;\n   }\n\n   QString Display() { return display; }\n};\n\n"
                "std::vector<int> coll;\n\nfor(int i = 1;i <= 9; ++i)\n   coll.push_back(i);\n\n"
                "PrintInt pi = std::for_each(coll.begin(),coll.end(),PrintInt());"
                );
}

class AddValue
{
private :
    int theValue;
public :
    //Constructor initializes the value to add
    AddValue(int v) : theValue(v) {}

    //The function call for the elements adds the value
    void operator() (int& elem) const
    {
        elem += theValue;
    }
};

QString StlStandard::FunctionObject2Example()
{
    QString display = "Initialized our container\nValues inside :\n";
    std::list<int> coll;
    AddValue addx(40);

    for(int i = 1; i <= 9; ++i)
        coll.push_back(i);
    display += printContainer(coll);

    std::for_each(coll.begin(),coll.end(),AddValue(10));
    display += QString("\n\nAfter adding 10 to each element :\n" + printContainer(coll) + "\n\n");

    std::for_each(coll.begin(), coll.end(),AddValue(*coll.begin()));
    display += QString("After adding first element to each element:\n" + printContainer(coll) + "\n\n");

    std::for_each(coll.begin(),coll.end(),addx);
    display += QString("After adding addx to each element :\n" + printContainer(coll) + "\n\n");

    return display;
}

QString StlStandard::FunctionObject2Code()
{
    return QString(
                "class AddValue\n{\nprivate :\n   int theValue;\npublic :\n   AddValue(int v) : theValue(v) {}\n\n   void operator() (int& elem) const\n"
                "   {\n      elem += theValue;\n   }\n};\n\nstd::list<int> coll;\nAddValue addx(40);\n\nfor(int i = 1;i <= 9;++i)\n   coll.push_back(i);\n\n"
                "std::for_each(coll.begin(),coll.end(),AddValue(10));\n\nstd::for_each(coll.begin(), coll.end(),AddValue(*coll.begin()));\n\n"
                "std::for_each(coll.begin(),coll.end(),addx);"
                );
}

QString foo(int x, int y)
{
    return QString(
                "This is C\n"
                "This is the first value " + QString::fromStdString(std::to_string(x)) + "\n"
                                                                                         "This is the second value " + QString::fromStdString(std::to_string(y)) + "\n\n"
                );
}

class C
{
public:
    QString memfunc(int x,int y) const
    {
        return QString(
                    "This is C\n"
                    "This is the first value " + QString::fromStdString(std::to_string(x)) + "\n"
                                                                                             "This is the second value " + QString::fromStdString(std::to_string(y)) + "\n\n"
                    );
    }
};

//Function returning a lambda
std::function<int(int,int)> returnLambda()
{
    return [] (int x,int y)
    {
        return x*y;
    };
}

QString StlStandard::FunctionWrapperExample()
{
    QString display = "Calling multiples functions \n\n";
    std::vector<std::function<QString(int,int)>> tasks;

    tasks.push_back(foo);

    tasks.push_back([] (int x, int y) {
        return QString(
                    "This is lambda\n"
                    "This is the first value " + QString::fromStdString(std::to_string(x)) + "\n"
                    "This is the second value " + QString::fromStdString(std::to_string(y)) + "\n"
                    );
    });

    for(std::function<QString(int,int)> f : tasks)
        display += f(30,50);

    display += QString("------------------------------------\nMember with function prototype:\n");
    std::function<QString(const C,int, int)> mf;

    mf = &C::memfunc;
    display += mf(C(),42,77);

    display += QString("------------------------------------\nWith lambda:\n");
    auto lf = returnLambda();
    display += QString::fromStdString(std::to_string(lf(6,7)));

    return display;
}

QString StlStandard::FunctionWrapperCode()
{
    return QString(
                "QString foo(int x, int y)\n{\n   return QString(...);\n}\n\n"
                "class C\n{\npublic:\n   QString memfunc(int x, int y) const\n   {\n      return QString(...);\n   }\n}\n\n"
                "std::function<int(int,int)> returnLambda()\n{\n   return [] (int x,int y)\n   {\n      return x*y;\n"
                "   };\n}\n\n"
                "QString display = \"\";\n"
                "std::vector<std::function<QString(int,int)>> tasks;\ntasks.push_back(foo);\ntasks.push_back([] (int x,int y) {\n"
                "   return QString(...);\n});\n\nfor(std::function<QString(int,int)> f : tasks)\n   display += f(30,50);\n\n"
                "std::function<QString(const C,int,int)> mf;\nmf = &C::memfunc;\ndisplay += mf(C(),42,77);\n\nauto lf = returnLambda();\n"
                "display += QString::fromStdString(std::to_string(lf(6,7)));"
                );
}

QString StlStandard::HandlingMultipleRangesExample()
{
    QString display = "Values inside our first container :\n";
    std::list<int> coll1 { 1,2,3,4,5,6,7,8,9 };
    std::vector<int> coll2;
    display += printContainer(coll1);

    display += QString("\n\nResize our second container so we can copy the values of the first container inside the second!\nValues in the second container :\n");
    coll2.resize(coll1.size());
    std::copy(coll1.begin(),coll1.end(),coll2.begin());
    display += printContainer(coll2);

    display += QString("\n\nCreate a third container with enough size for us to copy values of the 2nd container to the third one\nValues in the third container :\n");
    std::deque<int> coll3(coll2.size());
    std::copy(coll2.begin(),coll2.end(),coll3.begin());
    display += printContainer(coll3);

    return display;
}

QString StlStandard::HandlingMultipleRangesCode()
{
    return QString(
                "std::list<int> coll1 { 1,2,3,4,5,6,7,8,9 };\nstd::vector<int> coll2;\n\ncoll2.resize(coll1.size());\n"
                "std::copy(coll1.begin(),coll1.end(),coll2.begin());\n\nstd::deque<int> coll3(coll2.size());\n"
                "std::copy(coll2.begin(),coll2.end(),coll3.begin());"
                );
}

QString StlStandard::InsertIteratorExample()
{
    QString display = "Print all elements in the first container :\n";
    std::list<int> coll1 { 1,2,3,4,5,6,7,8,9 };
    display += printContainer(coll1);

    std::vector<int> coll2;
    std::copy(coll1.cbegin(), coll1.cend(),std::back_inserter(coll2));
    display += QString("\n\nPrint all elements in the second container :\n" + printContainer(coll2));

    std::deque<int> coll3;
    std::copy(coll1.cbegin(),coll1.cend(),std::front_inserter(coll3));
    display += QString("\n\nPrint all elements in the third container :\n" + printContainer(coll3));

    std::set<int> coll4;
    std::copy(coll1.cbegin(),coll1.cend(),std::inserter(coll4,coll4.begin()));
    display += QString("\n\nPrint all elements in the fourth container :\n" + printContainer(coll4));

    return display;
}

QString StlStandard::InsertIteratorCode()
{
    return QString(
                "std::list<int> coll1 { 1,2,3,4,5,6,7,8,9 };\n\nstd::vector<int> coll2;\nstd::copy(coll1.cbegin(), coll1.cend(),std::back_inserter(coll2));\n\n"
                "std::deque<int> coll3;\nstd::copy(coll1.cbegin(),coll1.cend(),std::front_inserter(coll3));\n\nstd::set<int> coll4;\n"
                "std::copy(coll1.cbegin(),coll1.cend(),std::inserter(coll4,coll4.begin()));"
                );
}

QString StlStandard::IteratorsManipulationsExample()
{
    QString display = "Print all elements inside the first container :\n";
    std::list<char> coll;
    for(char c='a'; c <= 'z'; ++c)
        coll.push_back(c);
    display += printContainer(coll);

    std::map<int,int> coll2
    {
        {1,2},
        {3,4},
        {5,6},
        {7,8},
        {9,10}
    };
    std::map<int,int>::const_iterator pos;
    display += QString("\n\nPrint all elements inside the second container :\n");
    for (pos = coll2.begin(); pos != coll2.end(); ++pos)
        display += QString(QString::fromStdString(std::to_string(pos->first)) + ", " + QString::fromStdString(std::to_string(pos->second)));

    return display;
}

QString StlStandard::IteratorsManipulationsCode()
{
    return QString(
                "std::list<char> coll;\nfor(char c='a'; c <= 'z'; ++c)\n  coll.push_back(c);\n\nstd::map<int,int> coll2 { {1,2},{3,4},"
                "{5,6},{7,8},{9,10}};\nstd::map<int,int>::const_iterator pos;\nfor (pos = coll2.begin(); pos != coll2.end(); ++pos)\n"
                "   display += ...;"
                );
}
