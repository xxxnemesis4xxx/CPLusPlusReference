#ifndef STLSTANDARD_H
#define STLSTANDARD_H

#include <QString>
#include <QStringList>

class StlStandard
{
public:
    StlStandard();
    ~StlStandard();

    enum indexStlStandard { BASICVECTOR, ARRAYSTRING, ASSOCIATIVEARRAY, RETURN };

    static const QStringList listExamples()
    {
        return QStringList() << BasicVectorOperations() << PrintStringInArray() << AssociativeArray() << "Return";
    }

    static QString BasicVectorOperations() { return "Basic vector operations"; }
    static QString PrintStringInArray() { return "Print values inside an array of String"; }
    static QString AssociativeArray() { return "Associative array"; }

    static QString BasicVectorOperationsExample();
    static QString PrintStringInArrayExample();
    static QString AssociativeArrayExample();

    static QString BasicVectorOperationsCode();
    static QString PrintStringInArrayCode();
    static QString AssociativeArrayCode();
};

#endif // STLSTANDARD_H
