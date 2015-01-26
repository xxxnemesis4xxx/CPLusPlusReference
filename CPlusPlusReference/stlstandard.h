#ifndef STLSTANDARD_H
#define STLSTANDARD_H

#include <QString>
#include <QStringList>

class StlStandard
{
public:
    StlStandard();
    ~StlStandard();

    enum indexStlStandard { BASICVECTOR, ARRAYSTRING, ASSOCIATIVEARRAY, BINARYPREDICATE, BINDER, TEMPLINLINE, DEQUE, RETURN };

    static const QStringList listExamples()
    {
        return QStringList()    << BasicVectorOperations() << PrintStringInArray() << AssociativeArray() << BinaryPredicates() << Binder()
                                << TemplateInlineFunc() << deque() << "Return";
    }

    static QString BasicVectorOperations() { return "Basic vector operations"; }
    static QString PrintStringInArray() { return "Print values inside an array of String"; }
    static QString AssociativeArray() { return "Associative array"; }
    static QString BinaryPredicates() { return "Binary predicates"; }
    static QString Binder() { return "Binder"; }
    static QString TemplateInlineFunc() { return "Template inline function"; }
    static QString deque() { return "Deque"; }

    static QString BasicVectorOperationsExample();
    static QString PrintStringInArrayExample();
    static QString AssociativeArrayExample();
    static QString BinaryPredicatesExample();
    static QString BinderExample();
    static QString TemplateInlineFuncExample();
    static QString dequeExample();

    static QString BasicVectorOperationsCode();
    static QString PrintStringInArrayCode();
    static QString AssociativeArrayCode();
    static QString BinaryPredicatesCode();
    static QString BinderCode();
    static QString TemplateInlineFuncCode();
    static QString dequeCode();
};

#endif // STLSTANDARD_H
