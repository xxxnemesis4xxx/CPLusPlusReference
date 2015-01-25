#ifndef STLSTANDARD_H
#define STLSTANDARD_H

#include <QString>
#include <QStringList>

class StlStandard
{
public:
    StlStandard();
    ~StlStandard();

    enum indexStlStandard { BASICVECTOR, ARRAYSTRING, RETURN };

    static const QStringList listExamples()
    {
        return QStringList() << BasicVectorOperations() << PrintStringInArray() << "Return";
    }

    static QString BasicVectorOperations() { return "Basic vector operations"; }
    static QString PrintStringInArray() { return "Print values inside an array of String"; }

    static QString BasicVectorOperationsExample();
    static QString PrintStringInArrayExample();

    static QString BasicVectorOperationsCode();
    static QString PrintStringInArrayCode();
};

#endif // STLSTANDARD_H
