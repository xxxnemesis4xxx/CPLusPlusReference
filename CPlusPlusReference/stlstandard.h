#ifndef STLSTANDARD_H
#define STLSTANDARD_H

#include <QString>
#include <QStringList>

class StlStandard
{
public:
    StlStandard();
    ~StlStandard();

    enum indexStlStandard { BASICVECTOR, RETURN };

    static const QStringList listExamples()
    {
        return QStringList() << BasicVectorOperations() << "Return";
    }

    static QString BasicVectorOperations() { return "Basic vector operations"; }


    static QString BasicVectorOperationsExample();

    static QString BasicVectorOperationsCode();

};

#endif // STLSTANDARD_H
