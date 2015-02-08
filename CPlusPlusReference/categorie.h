#ifndef CATEGORIE
#define CATEGORIE

#include <QStringList>
#include <QList>
#include <QString>

class Categorie
{
public:
    enum indexCategorie { TUPLES,PAIRS, ITERATOR, FUNCOBJLAM, STLSTAND, CONTAINER, STLALGO, THREAD };

    static const QStringList Categories()
    {
        return QStringList() << Tuple() << Pair() << Iterators() << FunctionObjetAndLambda()
                             << StlStandardOverview() << StlContainer() << StlAlgorithms()  << Thread();
    }

    static const QString Tuple() { return "Tuple"; }
    static const QString Pair() { return "Pair"; }
    static const QString Iterators() { return "Iterators"; }
    static const QString FunctionObjetAndLambda() { return "Function Objet and Lambda"; }
    static const QString StlAlgorithms() { return "Stl Algorithms"; }
    static const QString StlStandardOverview() { return "Stl Standard Overview"; }
    static const QString StlContainer() { return "Stl Containers"; }
    static const QString Thread() { return "Thread"; }
};

#endif // CATEGORIE

