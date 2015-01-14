#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();
    void setPosition (int i) { positionList = i; }
    int getPosition() { return positionList; }
    void setDebut(bool deb) { debut = deb; }
    bool getDebut() { return debut; }

private slots:
    void on_listWidget_doubleClicked(const QModelIndex &index);

private:
    Ui::Dialog *ui;
    int positionList;
    bool debut = true;
};

#endif // DIALOG_H
