#ifndef ITERATOR_H
#define ITERATOR_H

#include <QString>
#include <QStringList>
#include <iterator>

template <typename Container>
class asso_insert_iterator : public std::iterator
        <std::output_iterator_tag,typename Container::value_type>
{
protected:
    Container& container; //Container in whcih elements are inserted

public :
    //Constructor
    explicit asso_insert_iterator(Container& c) : container(c) {}

    //Assignment operator
    //- insert a value into the container
    asso_insert_iterator<Container>& operator= (const typename Container::value_type& value)
    {
        container.insert(value);
        return *this;
    }

    //Dereferencing is a no-op that returns the iterator itself
    asso_insert_iterator<Container>& operator* () {return *this;}

    //Increment operation is a no-op that returns the iterator itself
    asso_insert_iterator<Container>& operator++ () { return *this; }
    asso_insert_iterator<Container>& operator++ (int) { return *this; }
};

//Convenience function to create the inserter
template <typename Container>
inline asso_insert_iterator<Container> asso_inserter (Container& c)
{
    return asso_insert_iterator<Container>(c);
}

class Iterator
{
public:
    Iterator();
    ~Iterator();

    enum indexIterator {INSERTELEMENT,DISPLAYVALUE,ADVANCE,BACKINSERTER, BACKINSERTER2, FIND, DISTANCE, FRONTINSERTER, FRONTINSERTER2,
                        INSERTER, INSERTER2, INSERTER3, ADVANCES, SWAP, SWAP2, OSTREAM, PREVANDNEXT, RANDOMACCESS, REVERSE, FOREACH,
                        USERDEFINEDITERATOR, RETURN};

    static const QStringList listExamples()
    {
        return QStringList() << InsertElement() << DisplayElement() << MoveIterator() << InsertElementAtEnd()
                             << AppendAllElementWithBackInserter() << FindElementInContainer() << DistanceFromBeginning()
                             << InsertElementAtBeginning() << AppendAllElementWithFrontInserter() << InsertValueWithAnInserter()
                             << AppendAllElementWithInserter() << InsertElementAtSpecificLocation() << MoveIteratorOffNPosition()
                             << SwapFirstAndSecondValue() << SwapFirstAndLastValue() << ReadValueWithOstreamIterator()
                             << UsageOfPrevAndNext() << RandomAccessIterator() << PrintAllElementInReverse() << UsageOfForEach()
                             << UserDefineIterators() << "Return";
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
    static QString SwapFirstAndSecondValue() { return "Swap first and second value"; }
    static QString SwapFirstAndLastValue(){ return "Swap first and last value" ; }
    static QString ReadValueWithOstreamIterator() { return "Read value with ostream iterator"; }
    static QString UsageOfPrevAndNext() { return "Usage of prev() and next() with iterator";}
    static QString RandomAccessIterator() { return "Random access with Iterator"; }
    static QString PrintAllElementInReverse() { return "Print all element in reverse"; }
    static QString UsageOfForEach() { return "How to use for_each()"; }
    static QString UserDefineIterators() { return "User defined Iterators"; }

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
    static QString SwapFirstAndSecondValueExample();
    static QString SwapFirstAndLastValueExample();
    static QString ReadValueWithOstreamIteratorExample();
    static QString UsageOfPrevAndNextExample();
    static QString RandomAccessIteratorExample();
    static QString PrintAllElementInReverseExample();
    static QString UsageOfForEachExample();
    static QString UserDefineIteratorsExample();

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
    static QString SwapFirstAndSecondValueCode();
    static QString SwapFirstAndLastValueCode();
    static QString ReadValueWithOstreamIteratorCode();
    static QString UsageOfPrevAndNextCode();
    static QString RandomAccessIteratorCode();
    static QString PrintAllElementInReverseCode();
    static QString UsageOfForEachCode();
    static QString UserDefineIteratorsCode();
};

#endif // ITERATOR_H
