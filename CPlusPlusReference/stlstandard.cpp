#include "stlstandard.h"
#include <algorithm>
#include <vector>
#include <array>
#include <string>
#include <unordered_map>
#include <deque>

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
