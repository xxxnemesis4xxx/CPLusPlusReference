#ifndef ITERATOR_H
#define ITERATOR_H

#include <QString>
#include <QStringList>

class Iterator
{
public:
    Iterator();
    ~Iterator();

    enum indexIterator {INSERTELEMENT,DISPLAYVALUE,ADVANCE,BACKINSERTER, BACKINSERTER2, FIND, DISTANCE, FRONTINSERTER, FRONTINSERTER2,
                        INSERTER, INSERTER2, INSERTER3, ADVANCES, RETURN};

    static const QStringList listExamples()
    {
        return QStringList() << InsertElement() << DisplayElement() << MoveIterator() << InsertElementAtEnd()
                             << AppendAllElementWithBackInserter() << FindElementInContainer() << DistanceFromBeginning()
                             << InsertElementAtBeginning() << AppendAllElementWithFrontInserter() << InsertValueWithAnInserter()
                             << AppendAllElementWithInserter() << InsertElementAtSpecificLocation() << MoveIteratorOffNPosition()
                             <<"Return";
    }

    static QString InsertElement() { return "Insert elements"; }
    static QString DisplayElement() { return "Display element"; }
    static QString MoveIterator() { return "Moving Iterator"; }
    static QString InsertElementAtEnd() { return "Insert element at the end"; }
    static QString AppendAllElementWithBackInserter() { return "Append all elements with back_inserter()"; }
    static QString FindElementInContainer() { return "Find element inside a container"; }
    static QString DistanceFromBeginning() { return "Distance from the beginning"; }
    static QString InsertElementAtBeginning() { return "Insert element at the beginning"; }
    static QString AppendAllElementWithFrontInserter() { return "Append all elements with front_inserter()"; }
    static QString InsertValueWithAnInserter() { return "Insert value with the function inserter()"; }
    static QString AppendAllElementWithInserter() { return "Append all elements with inserter()"; }
    static QString InsertElementAtSpecificLocation() { return "Insert element at a specific location"; }
    static QString MoveIteratorOffNPosition() { return "Advances the iterator by N elements"; }

    static QString InsertElementExample();
    static QString DisplayElementExample();
    static QString MoveIteratorExample();
    static QString InsertElementAtEndExample();
    static QString AppendAllElementWithBackInserterExample();
    static QString FindElementInContainerExample();
    static QString DistanceFromBeginningExample();
    static QString InsertElementAtBeginningExample();
    static QString AppendAllElementWithFrontInserterExample();
    static QString InsertValueWithAnInserterExample();
    static QString AppendAllElementWithInserterExample();
    static QString InsertElementAtSpecificLocationExample();
    static QString MoveIteratorOffNPositionExample();

    static QString InsertElementCode();
    static QString DisplayElementCode();
    static QString MoveIteratorCode();
    static QString InsertElementAtEndCode();
    static QString AppendAllElementWithBackInserterCode();
    static QString FindElementInContainerCode();
    static QString DistanceFromBeginningCode();
    static QString InsertElementAtBeginningCode();
    static QString AppendAllElementWithFrontInserterCode();
    static QString InsertValueWithAnInserterCode();
    static QString AppendAllElementWithInserterCode();
    static QString InsertElementAtSpecificLocationCode();
    static QString MoveIteratorOffNPositionCode();
};

#endif // ITERATOR_H
