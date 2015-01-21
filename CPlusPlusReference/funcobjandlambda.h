#ifndef FUNCOBJANDLAMBDA_H
#define FUNCOBJANDLAMBDA_H

#include <QString>
#include <QStringList>

class FuncObjAndLambda
{
public:
    FuncObjAndLambda();
    ~FuncObjAndLambda();

    enum indexFuncObjAndLambda {BIND, RETURN };

    static const QStringList listExamples()
    {
        return QStringList() << MathematicalOperations() << "Return";
    }

    static QString MathematicalOperations() { return "Mathematical operations"; }

    static QString MathematicalOperationsExample();

    static QString MathematicalOperationsCode();
};

#endif // FUNCOBJANDLAMBDA_H
