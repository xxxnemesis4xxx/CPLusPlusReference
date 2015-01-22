#ifndef FUNCOBJANDLAMBDA_H
#define FUNCOBJANDLAMBDA_H

#include <QString>
#include <QStringList>

class FuncObjAndLambda
{
public:
    FuncObjAndLambda();
    ~FuncObjAndLambda();

    enum indexFuncObjAndLambda {BIND, BIND2, BIND3, BIND4, LAMBDA, LAMBDA2, LAMBDA3, RETURN };

    static const QStringList listExamples()
    {
        return QStringList() << MathematicalOperations() << CapitalAndLowercaseLetter() << SumOfAllIntInMap() << PowerUp3WithValueInsideContainer()
                             << PrintMeanValue() << RemoveThirdElement() << SearchSubcaseStringInsensitive() << "Return";
    }

    static QString MathematicalOperations() { return "Mathematical operations"; }
    static QString CapitalAndLowercaseLetter() { return "Capital and lowercase letters"; }
    static QString SumOfAllIntInMap() { return "Sum of all ints in a map container"; }
    static QString PowerUp3WithValueInsideContainer() { return "Multiples numbers exponent 3"; }
    static QString PrintMeanValue() { return "Print mean value"; }
    static QString RemoveThirdElement() { return "Remove the third element in a container"; }
    static QString SearchSubcaseStringInsensitive() { return "Search substring case insensitive"; }

    static QString MathematicalOperationsExample();
    static QString CapitalAndLowercaseLetterExample();
    static QString SumOfAllIntInMapExample();
    static QString PowerUp3WithValueInsideContainerExample();
    static QString PrintMeanValueExample();
    static QString RemoveThirdElementExample();
    static QString SearchSubcaseStringInsensitiveExample();

    static QString MathematicalOperationsCode();
    static QString CapitalAndLowercaseLetterCode();
    static QString SumOfAllIntInMapCode();
    static QString PowerUp3WithValueInsideContainerCode();
    static QString PrintMeanValueCode();
    static QString RemoveThirdElementCode();
    static QString SearchSubcaseStringInsensitiveCode();
};

#endif // FUNCOBJANDLAMBDA_H
