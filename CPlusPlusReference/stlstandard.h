#ifndef STLSTANDARD_H
#define STLSTANDARD_H

#include <QString>
#include <QStringList>

class StlStandard
{
public:
    StlStandard();
    ~StlStandard();

    enum indexStlStandard { RETURN };

    static const QStringList listExamples()
    {
        return QStringList() << "Return";
    }
};

#endif // STLSTANDARD_H
