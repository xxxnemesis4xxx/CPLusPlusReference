#ifndef STLSTANDARD_H
#define STLSTANDARD_H

#include <QString>
#include <QStringList>

class StlStandard
{
public:
    StlStandard();
    ~StlStandard();

    enum indexStlStandard { BASICVECTOR, ARRAYSTRING, ASSOCIATIVEARRAY, BINARYPREDICATE, RETURN };

    static const QStringList listExamples()
    {
        return QStringList() << BasicVectorOperations() << PrintStringInArray() << AssociativeArray() << BinaryPredicates() << "Return";
    }

    static QString BasicVectorOperations() { return "Basic vector operations"; }
    static QString PrintStringInArray() { return "Print values inside an array of String"; }
    static QString AssociativeArray() { return "Associative array"; }
    static QString BinaryPredicates() { return "Binary predicates"; }

    static QString BasicVectorOperationsExample();
    static QString PrintStringInArrayExample();
    static QString AssociativeArrayExample();
    static QString BinaryPredicatesExample();

    static QString BasicVectorOperationsCode();
    static QString PrintStringInArrayCode();
    static QString AssociativeArrayCode();
    static QString BinaryPredicatesCode();
};

#endif // STLSTANDARD_H
