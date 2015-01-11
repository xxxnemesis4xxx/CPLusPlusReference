#ifndef TUPLEANDPAIR
#define TUPLEANDPAIR
#include <QStringList>
#include <QString>

class TupleAndPair
{
public:
    static const QStringList ListExamples()
    {
        return QStringList() << "Iterate Over Elements" << "Create an Tuple with make_tuple()" << "Assign a reference Value to Tuple" <<
                                "Create a Tuple with Reference Values" << "Initialise a Tuple with a List";
    }

    //static const QString

    static void IterateOverElements();
    static void CreateTupleWithMakeTuple();
    static void AssignReferenceToTuple();
    static void CreateTupleWithReferenceValues();
    static void InitialiseTupleWithList();
};

#endif // TUPLEANDPAIR

