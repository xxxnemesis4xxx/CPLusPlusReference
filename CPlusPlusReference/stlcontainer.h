#ifndef STLCONTAINER_H
#define STLCONTAINER_H

#include <QString>
#include <QStringList>

class StlContainer
{
public:
    StlContainer();
    ~StlContainer();

    enum indexStlContainer { RETURN };

    static const QStringList ListExamples()
    {
        return QStringList() << "Return";
    }


};

#endif // STLCONTAINER_H
