#ifndef FUNCOBJANDLAMBDA_H
#define FUNCOBJANDLAMBDA_H

#include <QString>
#include <QStringList>

class FuncObjAndLambda
{
public:
    FuncObjAndLambda();
    ~FuncObjAndLambda();

    enum indexFuncObjAndLambda {BIND, BIND2, RETURN };

    static const QStringList listExamples()
    {
        return QStringList() << MathematicalOperations() << CapitalAndLowercaseLetter() << "Return";
    }

    static QString MathematicalOperations() { return "Mathematical operations"; }
    static QString CapitalAndLowercaseLetter() { return "Capital and lowercase letters"; }

    static QString MathematicalOperationsExample();
    static QString CapitalAndLowercaseLetterExample();

    static QString MathematicalOperationsCode();
    static QString CapitalAndLowercaseLetterCode();
};

#endif // FUNCOBJANDLAMBDA_H
