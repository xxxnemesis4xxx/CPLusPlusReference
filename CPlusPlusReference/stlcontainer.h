#ifndef STLCONTAINER_H
#define STLCONTAINER_H

#include <QString>
#include <QStringList>
#include <QListWidgetItem>

class StlContainer
{
public:
    StlContainer();
    ~StlContainer();

    enum indexStlContainer { ARRAY, DEQUE, FORWARDLIST, LIST, MAPMULTIMAP, SETMULTISET, UNORDERED, VECTOR, RETURN };

    static const QStringList listContainer()
    {
        return QStringList() << "Return";
    }

    static QListWidgetItem* array()
    {
        QListWidgetItem* array = new QListWidgetItem("Array");
        array->setFlags(Qt::NoItemFlags);

        return array;
    }



    static QListWidgetItem* deque()
    {
        QListWidgetItem* array = new QListWidgetItem("Deque");
        array->setFlags(Qt::NoItemFlags);

        return array;
    }

    static QListWidgetItem* forwardlist()
    {
        QListWidgetItem* array = new QListWidgetItem("Forward List");
        array->setFlags(Qt::NoItemFlags);

        return array;
    }

    static QListWidgetItem* list()
    {
        QListWidgetItem* array = new QListWidgetItem("List");
        array->setFlags(Qt::NoItemFlags);

        return array;
    }

    static QListWidgetItem* mapmultimap()
    {
        QListWidgetItem* array = new QListWidgetItem("MapMultimap");
        array->setFlags(Qt::NoItemFlags);

        return array;
    }

    static QListWidgetItem* setmultiset()
    {
        QListWidgetItem* array = new QListWidgetItem("SetMultiset");
        array->setFlags(Qt::NoItemFlags);

        return array;
    }

    static QListWidgetItem* unordered()
    {
        QListWidgetItem* array = new QListWidgetItem("Unordered Container");
        array->setFlags(Qt::NoItemFlags);

        return array;
    }

    static QListWidgetItem* vector()
    {
        QListWidgetItem* array = new QListWidgetItem("Vector");
        array->setFlags(Qt::NoItemFlags);

        return array;
    }

};

#endif // STLCONTAINER_H
