#ifndef CATEGORIE
#define CATEGORIE

#include <QStringList>
#include <QList>
#include <QString>

class Categorie
{
public:
    static const QStringList Categories()
    {
        return QStringList() << "Tuple and Pair" << "Iterators" << "Function Objet and Lambda" <<
                                               "Stl Algorithms" << "Stl Containers" << "Stl Standard Overview" << "Thread";
    }
};

#endif // CATEGORIE

