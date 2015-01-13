#ifndef TUPLE
#define TUPLE
#include "dialog.h"

class Tuple
{
public:
    enum indexTuple { ITERATOR, MAKETUPLE, REFVALUE, TUPLEWITHREFVALUES, INITTUPLEWITHLIST, RETURN};

    static const QStringList ListExamples()
    {
        return QStringList() << iteOverElms() << makeTuple() << referenceValue() << tupleWithRefValues() << initTupleList() << "Return";
    }

    static const QString iteOverElms() { return "Iterate Over Elements"; }
    static const QString makeTuple() { return "Create an Tuple with make_tuple()"; }
    static const QString referenceValue() { return "Assign a reference Value to Tuple"; }
    static const QString tupleWithRefValues() { return "Create a Tuple with Reference Values"; }
    static const QString initTupleList() { return "Initialise a Tuple with a List"; }

    static QString IterateOverElements();
    static QString CreateTupleWithMakeTuple();
    static QString AssignReferenceToTuple();
    static QString CreateTupleWithReferenceValues();
    static QString InitialiseTupleWithList();

    static QString IterateOverElementsCode();
    static QString CreateTupleWithMakeTupleCode();
    static QString AssignReferenceToTupleCode();
    static QString CreateTupleWithReferenceValuesCode();
    static QString InitialiseTupleWithListCode();
};

#endif // TUPLE

