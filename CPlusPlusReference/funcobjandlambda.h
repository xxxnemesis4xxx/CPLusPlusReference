#ifndef FUNCOBJANDLAMBDA_H
#define FUNCOBJANDLAMBDA_H

#include <QString>
#include <QStringList>

class FuncObjAndLambda
{
public:
    FuncObjAndLambda();
    ~FuncObjAndLambda();

    enum indexFuncObjAndLambda {BIND, BIND2, BIND3, BIND4, RETURN };

    static const QStringList listExamples()
    {
        return QStringList() << MathematicalOperations() << CapitalAndLowercaseLetter() << SumOfAllIntInMap() << PowerUp3WithValueInsideContainer()
                             << "Return";
    }

    static QString MathematicalOperations() { return "Mathematical operations"; }
    static QString CapitalAndLowercaseLetter() { return "Capital and lowercase letters"; }
    static QString SumOfAllIntInMap() { return "Sum of all ints in a map container"; }
    static QString PowerUp3WithValueInsideContainer() { return "Multiples numbers exponent 3"; }

    static QString MathematicalOperationsExample();
    static QString CapitalAndLowercaseLetterExample();
    static QString SumOfAllIntInMapExample();
    static QString PowerUp3WithValueInsideContainerExample();

    static QString MathematicalOperationsCode();
    static QString CapitalAndLowercaseLetterCode();
    static QString SumOfAllIntInMapCode();
    static QString PowerUp3WithValueInsideContainerCode();
};

#endif // FUNCOBJANDLAMBDA_H
