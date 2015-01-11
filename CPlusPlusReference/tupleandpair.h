#ifndef TUPLEANDPAIR
#define TUPLEANDPAIR
#include "dialog.h"

class TupleAndPair
{
public:
    enum index { ITERATOR, MAKETUPLE, REFVALUE, TUPLEWITHREFVALUES, INITTUPLEWITHLIST};

    static const QStringList ListExamples()
    {
        return QStringList() << iteOverElms() << makeTuple() << referenceValue() << tupleWithRefValues() << initTupleList();
    }

    static const QString iteOverElms() { return "Iterate Over Elements"; }
    static const QString makeTuple() { return "Create an Tuple with make_tuple()"; }
    static const QString referenceValue() { return "Assign a reference Value to Tuple"; }
    static const QString tupleWithRefValues() { return "Create a Tuple with Reference Values"; }
    static const QString initTupleList() { return "Initialise a Tuple with a List"; }

    static QString IterateOverElements();
    static std::string CreateTupleWithMakeTuple();
    static std::string AssignReferenceToTuple();
    static std::string CreateTupleWithReferenceValues();
    static std::string InitialiseTupleWithList();
};

#endif // TUPLEANDPAIR

