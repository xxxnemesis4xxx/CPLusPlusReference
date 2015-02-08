#ifndef STLCONTAINER_H
#define STLCONTAINER_H

#include <QString>
#include <QStringList>

class StlContainer
{
public:
    StlContainer();
    ~StlContainer();

    enum indexStlContainer { ARRAY, DEQUE, FORWARDLIST, LIST, MAPMULTIMAP, SETMULTISET, UNORDERED, VECTOR, RETURN };

    static const QStringList ListContainer()
    {
        return QStringList() << "Array" << "Deque" << "Forward List" << "List" << "Map and Multimap" << "Set and Multiset"
                             << "Unordered Containers" << "Vector" << "Return";
    }


};

#endif // STLCONTAINER_H
