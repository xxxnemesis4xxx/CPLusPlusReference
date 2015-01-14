#ifndef ITERATOR_H
#define ITERATOR_H

#include <QString>
#include <QStringList>

class Iterator
{
public:
    Iterator();
    ~Iterator();

    enum indexIterator {INSERTELEMENT,DISPLAYVALUE,ADVANCE, RETURN};

    static const QStringList listExamples()
    {
        return QStringList() << InsertElement() << DisplayElement() << MoveIterator() << "Return";
    }

    static QString InsertElement() { return "Insert elements"; }
    static QString DisplayElement() { return "Display element"; }
    static QString MoveIterator() { return "Moving Iterator"; }

    static QString InsertElementExample();
    static QString DisplayElementExample();
    static QString MoveIteratorExample();

    static QString InsertElementCode();
    static QString DisplayElementCode();
    static QString MoveIteratorCode();
};

#endif // ITERATOR_H
