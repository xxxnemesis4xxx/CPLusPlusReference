#ifndef ITERATOR_H
#define ITERATOR_H

#include <QString>
#include <QStringList>

class Iterator
{
public:
    Iterator();
    ~Iterator();

    enum indexIterator {RETURN};

    static const QStringList listExamples()
    {
        return QStringList() << "Return";
    }
};

#endif // ITERATOR_H
