#ifndef STLSTANDARD_H
#define STLSTANDARD_H

#include <QString>
#include <QStringList>

class StlStandard
{
public:
    StlStandard();
    ~StlStandard();

    enum indexStlStandard { BASICVECTOR, ARRAYSTRING, ASSOCIATIVEARRAY, BINARYPREDICATE, BINDER, TEMPLINLINE, DEQUE, TEMPLSPECI, FIND, FORWARDLIST,
                            FOREACH, TRANSFORM, FUNCOBJ, FUNCOBJ2, RETURN };

    static const QStringList listExamples()
    {
        return QStringList()    << BasicVectorOperations() << PrintStringInArray() << AssociativeArray() << BinaryPredicates() << Binder()
                                << TemplateInlineFunc() << deque() << templateSpecialization() << Find() << ForwardList() << ForEachWithContainer()
                                << TransformWithContainer() << FunctionObject() << FunctionObject2() << "Return";

    }

    static QString BasicVectorOperations() { return "Basic vector operations"; }
    static QString PrintStringInArray() { return "Print values inside an array of String"; }
    static QString AssociativeArray() { return "Associative array"; }
    static QString BinaryPredicates() { return "Binary predicates"; }
    static QString Binder() { return "Binder"; }
    static QString TemplateInlineFunc() { return "Template inline function"; }
    static QString deque() { return "Deque"; }
    static QString templateSpecialization() { return "Template specialization"; }
    static QString Find() { return "Find"; }
    static QString ForwardList() { return "Forward List"; }
    static QString ForEachWithContainer() { return "Using for_each() with container;"; }
    static QString TransformWithContainer() { return "Using transform() with container"; }
    static QString FunctionObject() { return "Function object"; }
    static QString FunctionObject2() { return "Function object2"; }

    static QString BasicVectorOperationsExample();
    static QString PrintStringInArrayExample();
    static QString AssociativeArrayExample();
    static QString BinaryPredicatesExample();
    static QString BinderExample();
    static QString TemplateInlineFuncExample();
    static QString dequeExample();
    static QString templateSpecializationExample();
    static QString FindExample();
    static QString ForwardListExample();
    static QString ForEachWithContainerExample();
    static QString TransformWithContainerExample();
    static QString FunctionObjectExample();
    static QString FunctionObject2Example();

    static QString BasicVectorOperationsCode();
    static QString PrintStringInArrayCode();
    static QString AssociativeArrayCode();
    static QString BinaryPredicatesCode();
    static QString BinderCode();
    static QString TemplateInlineFuncCode();
    static QString dequeCode();
    static QString templateSpecializationCode();
    static QString FindCode();
    static QString ForwardListCode();
    static QString ForEachWithContainerCode();
    static QString TransformWithContainerCode();
    static QString FunctionObjectCode();
    static QString FunctionObject2Code();
};

#endif // STLSTANDARD_H
