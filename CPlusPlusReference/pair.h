#ifndef PAIR_H
#define PAIR_H

#include <QString>
#include <QStringList>


class Pair
{
public:
    enum indexPair {DISPLAYVALUE, CREATEPAIR, MOVSEMPAIR, REFMOVSEMPAIR, REFMOVSEMTUPLE,
                   CREATEPAIRDEFTYPE ,EXTSPECVALUEFROMPAIR, RETURN};

    static const QStringList ListExamples()
    {
        return QStringList() << DisplayPairValue() << CreatePairWithPairMake() << MovingPairValueWithSemantic() << EnforceRefMoveSemanticWithPair()
                                  << EnforceRefMoveSemanticWithTuple() << MakePairWithDefinedType() << ExtractSpecificValueFromPair()
                                  << "Return";
    }

    Pair();
    ~Pair();

    static const QString DisplayPairValue() { return "Display or Access Pair values"; }
    static const QString CreatePairWithPairMake() { return "Create a pair with pair_make()"; }
    static const QString MovingPairValueWithSemantic() { return "Move Pair Values with Semantic"; }
    static const QString EnforceRefMoveSemanticWithPair() { return "Force ref move semantic with pair"; }
    static const QString EnforceRefMoveSemanticWithTuple() { return "Force ref move semantic with tuple"; }
    static const QString MakePairWithDefinedType() { return "Use make_pair with defined type"; }
    static const QString ExtractSpecificValueFromPair() { return "Extracting a value from the pair"; }

    static QString DisplayPairValueExample();
    static QString CreatePairWithPairMakeExample();
    static QString MovingPairValueWithSemanticExample();
    static QString EnforceRefMoveSemanticWithPairExample();
    static QString EnforceRefMoveSemanticWithTupleExample();
    static QString MakePairWithDefinedTypeExample();
    static QString ExtractSpecificValueFromPairExample();

    static QString DisplayPairValueExampleCode();
    static QString CreatePairWithPairMakeCode();
    static QString MovingPairValueWithSemanticCode();
    static QString EnforceRefMoveSemanticWithPairCode();
    static QString EnforceRefMoveSemanticWithTupleCode();
    static QString MakePairWithDefinedTypeCode();
    static QString ExtractSpecificValueFromPairCode();
};

#endif // PAIR_H
