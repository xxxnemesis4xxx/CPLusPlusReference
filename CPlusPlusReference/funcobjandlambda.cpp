#include "funcobjandlambda.h"
#include <functional>
#include <iostream>

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

