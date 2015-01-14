#ifndef ITERATOR_H
#define ITERATOR_H

#include <QString>
#include <QStringList>

class Iterator
{
public:
    Iterator();
    ~Iterator();

    enum indexIterator {INSERTELEMENT, RETURN};

    static const QStringList listExamples()
    {
        return QStringList() << InsertElement() << "Return";
    }

    static QString InsertElement() { return "Insert elements"; }
    static QString Advance() { return "Advance function"; }

    static QString InsertElementExample();
    static QString AdvanceExample();

    static QString InsertElementCode();
    static QString AdvanceCode();
};

#endif // ITERATOR_H
