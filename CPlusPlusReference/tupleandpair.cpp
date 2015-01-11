#include <tuple>
#include <iostream>
#include <complex>
#include <string>
#include <vector>
#include "tupleandpair.h"
using namespace std;

string TupleAndPair::AssignReferenceToTuple()
{
    //Like Pair, you can assign reference variable to a tuple
    std::string s;
    tuple<std::string&> t4(s);
    s = "Hello";
    cout << "\n\nCreating a tuple with a reference variable" << endl;
    cout << get<0>(t4) << endl;

    return "";
}

string TupleAndPair::CreateTupleWithMakeTuple()
{
    // create tuple with make_tuple()
    // - auto declares t2 with type of right-hand side
    // - thus, type of t2 is tuple
    auto t2 = make_tuple(22,44,"nico");
    tuple<int,float,string> t1(41,6.3,"nico");

    // assign second value in t2 to t1 we declared earlier
    cout << "\nValue stored in t2 : " << get<0>(t2) << " " << get<1>(t2) << " " << get<2>(t2) << endl;
    get<1>(t1) = get<1>(t2);
    cout << "Value stored in t1 after the assignment : " << get<0>(t1) << " " << get<1>(t1) << " " << get<2>(t1) << endl;

    // comparison and assignment
    // - including type conversion from tuple<int,int,const char*>
    // to tuple<int,float,string>
    //each tuple will compare value according to their position in the tuple get<0> with get<0>, get<1> with get<1>, etc.
    if (t1 < t2) { // compares value for value
        t1 = t2; // OK, assigns value for value
    }

    return "";
}

string TupleAndPair::CreateTupleWithReferenceValues()
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

    return "";
}

string TupleAndPair::InitialiseTupleWithList()
{
    //There is one main difference between Pair and Tuple
    //Tuple-> You can only initialize a tuple explicitly, so we are sure no one can initiate one with a single value
    //Pair-> You an initialize a pair explicitly or implicitly

    //This is a error with tuple
    //std::vector<std::tuple<int,float>> v { {1,1.0}, {2,2.0} }; // ERROR
    //But this can be done with a pair container
    std::vector<std::pair<int,float>> v1 { {1,1.0}, {2,2.0} }; // OK -> Not supported by MCVS 2012

    return "";
}

QString TupleAndPair::IterateOverElements()
{
    //create a four-element tuple
    //- elements are initialized with default value (0 for fundamental types)
    tuple<string,int,int,complex<double>> t;

    //create and initialize a tuple explicitly
    tuple<int,float,string> t1(41,6.3,"nico");

    //‘‘iterate’’ over elements:
    std::string Test = to_string(get<0>(t1)) + " " + to_string(get<1>(t1)). + " " + get<2>(t1);

    return QString::fromStdString(Test);
}

