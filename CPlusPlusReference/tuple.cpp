#include <tuple>
#include <iostream>
#include <complex>
#include <string>
#include <vector>
#include "tuple.h"
using namespace std;

QString Tuple::AssignReferenceToTuple()
{
    //Like Pair, you can assign reference variable to a tuple
    std::string s;
    tuple<std::string&> t4(s);
    s = "Hello";

    std::string display = "Creating a tuple with a reference variable\n" + get<0>(t4);

    return QString::fromStdString(display);
}

QString Tuple::AssignReferenceToTupleCode()
{
    QString display = QString("std::string s;\ntuple<std::string&> t4(s);s = \"Hello\"; \n\n")
            + QString("std::string display = \"Creating a tuple with a reference variable\n + get<0>(t4);\n\n")
            + QString("return QString::fromStdString(display)");

    return display;
}

QString Tuple::CreateTupleWithMakeTuple()
{
    string display;
    // create tuple with make_tuple()
    // - auto declares t2 with type of right-hand side
    // - thus, type of t2 is tuple
    auto t2 = make_tuple(22,44,"nico");
    tuple<int,float,string> t1(41,6.3,"nico");

    // assign second value in t2 to t1 we declared earlier
    display = "Value stored in t2 : " + to_string(get<0>(t2)) + " " + to_string(get<1>(t2)) +
            " " + get<2>(t2) + "\n";
    get<1>(t1) = get<1>(t2);
    display += "Value stored in t1 after the assignment : " + to_string(get<0>(t1)) +
            " " + to_string(get<1>(t1)) + " " + get<2>(t1) + "\n";

    // comparison and assignment
    // - including type conversion from tuple<int,int,const char*>
    // to tuple<int,float,string>
    //each tuple will compare value according to their position in the tuple get<0> with get<0>, get<1> with get<1>, etc.
    if (t1 < t2) { // compares value for value
        t1 = t2; // OK, assigns value for value
    }

    return QString::fromStdString(display);
}

QString Tuple::CreateTupleWithMakeTupleCode()
{
    QString display = QString("string display;\n\nauto t2 = make_tuple(22,44,\"nico\");\ntuple<int,float,string>t1(41,6.3,\"nico\");\n\n")
            + QString("display = \"Value stored in t2 :\" + to_string(get<0>(t2)) + to_string(get<1>(t2))")
            + QString(" + get<2>(t2);\nget<1>(t1) = get<1>(t2);\n")
            + QString("display += \"Value stored in t1 after the assignment : \" + to_string(get<0>(t1)) + ")
            + QString(" + to_string(get<1>(t1)) + get<2>(t1);\n");

    return display;
}

QString Tuple::CreateTupleWithReferenceValues()
{
    //There is 2 way to create a tuple with the current library in c++11

    //First way - This is the Hard WAY!
    std::tuple <int,float,std::string> t5(77,1.1,"more light");
    int int1;
    float float1;
    std::string str1;
    // assign values of t to i, f, and s:
    std::make_tuple(std::ref(int1),std::ref(float1),std::ref(str1)) = t5;

    //Second way - This is the Easy way
    std::tuple <int,float,std::string> t6(77,1.1,"more light");
    int int2;
    float float2;
    std::string str2;
    //Tie does the exact same thing as  std::ref on all value inside the tuple
    std::tie(int2,float2,str2) = t6; // assigns values of t to i, f, and s

    //Third Way - Lazy ass !
    auto t7 = make_tuple(456,2.6,"Light shall burn you!");
    std::tie(int2,float2,str2) = t7;

    return QString("");
}

QString Tuple::CreateTupleWithReferenceValuesCode()
{
    QString display = QString("First way:\nstd::tuple <int,float,std::string> t5(77,1.1,\"more light\");")
            + QString("\nint int1;\nfloat float1;\nstd::string str1;\n")
            + QString("std::make_tuple(std::ref(int1),std::ref(float1),std::ref(str1)) = t5;\n\n")
            + QString("Second way : \nstd::tuple <int,float,std::string> t6(77,1.1,\"more light\");\n")
            + QString("int int2;\nfloat float2;\nstd::string str2;\nstd::tie(int2,float2,str2) = t6;\n\n")
            + QString("Third way : \nauto t7 = make_tuple(456,2.6,\"Light shall burn you!\");\n")
            + QString("std::tie(int2,float2,str2) = t7;");

    return display;
}

QString Tuple::InitialiseTupleWithList()
{
    //There is one main difference between Pair and Tuple
    //Tuple-> You can only initialize a tuple explicitly, so we are sure no one can initiate one with a single value
    //Pair-> You an initialize a pair explicitly or implicitly

    //This is a error with tuple
    //std::vector<std::tuple<int,float>> v { {1,1.0}, {2,2.0} }; // ERROR
    //But this can be done with a pair container
    std::vector<std::pair<int,float>> v1 { {1,1.0}, {2,2.0} }; // OK -> Not supported by MCVS 2012

    return QString("");
}

QString Tuple::InitialiseTupleWithListCode()
{
    QString display = QString("std::vector<std::pair<int,float>> v1 { {1,1.0}, {2,2.0} };");

    return display;
}

QString Tuple::IterateOverElements()
{
    //create a four-element tuple
    //- elements are initialized with default value (0 for fundamental types)
    tuple<string,int,int,complex<double>> t;

    //create and initialize a tuple explicitly
    tuple<int,float,string> t1(41,6.3,"nico");

    //‘‘iterate’’ over elements:
    std::string display = to_string(get<0>(t1)) + " " + to_string(get<1>(t1)) + " " + get<2>(t1);

    return QString::fromStdString(display);
}

QString Tuple::IterateOverElementsCode()
{
    QString display = QString("tuple<string,int,int,complex<double>> t;\n\ntuple<int,float,string> t1(41,6.3,\"nice\");\n\n")
            + QString("std::string display = to_string(get<0>(t1)) + to_string(get<1>(t1)) + ")
            + QString("get<2>(t1);");

    return display;
}

