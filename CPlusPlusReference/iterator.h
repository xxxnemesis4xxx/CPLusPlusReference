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
        return QStringList() << InsertElement() << DisplayElement() << Advance() << "Return";
    }

    static QString InsertElement() { return "Insert elements"; }
    static QString DisplayElement() { return "Display element"; }
    static QString Advance() { return "Function advance()"; }

    static QString InsertElementExample();
    static QString DisplayElementExample();
    static QString AdvanceExample();

    static QString InsertElementCode();
    static QString DisplayElementCode();
    static QString AdvanceCode();
};

#endif // ITERATOR_H
