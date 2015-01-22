#ifndef FUNCOBJANDLAMBDA_H
#define FUNCOBJANDLAMBDA_H

#include <QString>
#include <QStringList>

class FuncObjAndLambda
{
public:
    FuncObjAndLambda();
    ~FuncObjAndLambda();

    enum indexFuncObjAndLambda {BIND, BIND2, BIND3, RETURN };

    static const QStringList listExamples()
    {
        return QStringList() << MathematicalOperations() << CapitalAndLowercaseLetter() << SumOfAllIntInMap() << "Return";
    }

    static QString MathematicalOperations() { return "Mathematical operations"; }
    static QString CapitalAndLowercaseLetter() { return "Capital and lowercase letters"; }
    static QString SumOfAllIntInMap() { return "Sum of all ints in a map container"; }

    static QString MathematicalOperationsExample();
    static QString CapitalAndLowercaseLetterExample();
    static QString SumOfAllIntInMapExample();

    static QString MathematicalOperationsCode();
    static QString CapitalAndLowercaseLetterCode();
    static QString SumOfAllIntInMapCode();
};

#endif // FUNCOBJANDLAMBDA_H
