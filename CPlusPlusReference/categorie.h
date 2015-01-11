#ifndef CATEGORIE
#define CATEGORIE

#include <QStringList>
#include <QList>
#include <QString>

class Categorie
{
public:
    enum Index { TUPLE, ITERATOR, FUNCOBJLAM, STLALGO, STLSTAND, THREAD };

    static const QStringList Categories()
    {
        return QStringList() << TupleAndPair() << Iterators() << FunctionObjetAndLambda()
                             << StlAlgorithms() << StlStandardOverview() << Thread();
    }

    static const QString TupleAndPair() { return "Tuple and Pair"; }
    static const QString Iterators() { return "Iterators"; }
    static const QString FunctionObjetAndLambda() { return "Function Objet and Lambda"; }
    static const QString StlAlgorithms() { return "Stl Algorithms"; }
    static const QString StlStandardOverview() { return "Stl Standard Overview"; }
    static const QString Thread() { return "Thread"; }
};

#endif // CATEGORIE

