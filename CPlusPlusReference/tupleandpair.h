#ifndef TUPLEANDPAIR
#define TUPLEANDPAIR
#include <QStringList>
#include <QString>

class TupleAndPair
{
public:
    enum index { ITERATOR, MAKETUPLE, REFVALUE, TUPLEWITHREFVALUES, INITTUPLEWITHLIST}

    static const QStringList ListExamples()
    {
        return QStringList() << iteOverElms() << makeTuple() << referenceValue() << tupleWithRefValues() << initTupleList();
    }

    static const QString iteOverElms() { return "Iterate Over Elements"; }
    static const QString makeTuple() { return "Create an Tuple with make_tuple()"; }
    static const QString referenceValue() { return "Assign a reference Value to Tuple"; }
    static const QString tupleWithRefValues() { return "Create a Tuple with Reference Values"; }
    static const QString initTupleList() { return "Initialise a Tuple with a List"; }

    static void IterateOverElements();
    static void CreateTupleWithMakeTuple();
    static void AssignReferenceToTuple();
    static void CreateTupleWithReferenceValues();
    static void InitialiseTupleWithList();
};

#endif // TUPLEANDPAIR

