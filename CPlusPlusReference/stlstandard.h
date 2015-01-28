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
                            FOREACH, TRANSFORM, FUNCOBJ, FUNCOBJ2, FUNCWRAPPER, HANDRANGES, INSERTITERATOR, ITERATORS, LAMBDA, LAMBDA2, LAMBDA3,
                            LIST, MULTIMAPS, MULTISET, PREDFUNCOBJ, PREDICATES, FUNCWRAPPERS, RETURN };

    static const QStringList listExamples()
    {
        return QStringList()    << BasicVectorOperations() << PrintStringInArray() << AssociativeArray() << BinaryPredicates() << Binder()
                                << TemplateInlineFunc() << deque() << templateSpecialization() << Find() << ForwardList() << ForEachWithContainer()
                                << TransformWithContainer() << FunctionObject() << FunctionObject2() << FunctionWrapper() << HandlingMultipleRanges()
                                << InsertIterator() << IteratorsManipulations() << LambdaAlgorithm() << LambdaAlgorithm2() << LambdaAlgorithm3()
                                << List() << MultimapOverview() << MultisetOverview() << PredefinedFuncObj() << Predicates() << FunctionWrapper()
                                << "Return";

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
    static QString FunctionWrapper() { return "Function wrapper"; }
    static QString HandlingMultipleRanges() { return "Handling multiples ranges"; }
    static QString InsertIterator() { return "Insert Iterators" ; }
    static QString IteratorsManipulations() { return "Iterator manipulations"; }
    static QString LambdaAlgorithm() { return "Using Lambda with Algorithm"; }
    static QString LambdaAlgorithm2() { return "Using Lambda with Algorithm 2"; }
    static QString LambdaAlgorithm3() { return "Using Lambda with Algorithm 3"; }
    static QString List() { return "List"; }
    static QString MultimapOverview() { return "Multimaps"; }
    static QString MultisetOverview() { return "Multisets"; }
    static QString PredefinedFuncObj() { return "Predefined function object"; }
    static QString Predicates() { return "Predicates"; }
    static QString ReferenceWrappers() { return "Reference wrappers"; }

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
    static QString FunctionWrapperExample();
    static QString HandlingMultipleRangesExample();
    static QString InsertIteratorExample();
    static QString IteratorsManipulationsExample();
    static QString LambdaAlgorithmExample();
    static QString LambdaAlgorithm2Example();
    static QString LambdaAlgorithm3Example();
    static QString ListExample();
    static QString MultimapOverviewExample();
    static QString MultisetOverviewExample();
    static QString PredefinedFuncObjExample();
    static QString PredicatesExample();
    static QString ReferenceWrappersExample();

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
    static QString FunctionWrapperCode();
    static QString HandlingMultipleRangesCode();
    static QString InsertIteratorCode();
    static QString IteratorsManipulationsCode();
    static QString LambdaAlgorithmCode();
    static QString LambdaAlgorithm2Code();
    static QString LambdaAlgorithm3Code();
    static QString ListCode();
    static QString MultimapOverviewCode();
    static QString MultisetOverviewCode();
    static QString PredefinedFuncObjCode();
    static QString PredicatesCode();
    static QString ReferenceWrappersCode();
};

#endif // STLSTANDARD_H
