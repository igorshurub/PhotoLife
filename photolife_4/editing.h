#ifndef EDITING_H
#define EDITING_H

#include <QDialog>


namespace Ui {
class Editing;
}

class Editing : public QDialog
{
    Q_OBJECT

public:
    explicit Editing(QWidget *parent = nullptr);
    ~Editing();

private:
    Ui::Editing *ui;

};

#endif // EDITING_H
