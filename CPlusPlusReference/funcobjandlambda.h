#ifndef FUNCOBJANDLAMBDA_H
#define FUNCOBJANDLAMBDA_H

#include <QString>
#include <QStringList>

class FuncObjAndLambda
{
public:
    FuncObjAndLambda();
    ~FuncObjAndLambda();

    enum indexFuncObjAndLambda { RETURN };

    static const QStringList listExamples()
    {
        return QStringList() << "Return";
    }
};

#endif // FUNCOBJANDLAMBDA_H
