#ifndef VIEWING_H
#define VIEWING_H

#include <QDialog>

namespace Ui {
class Viewing;
}

class Viewing : public QDialog
{
    Q_OBJECT

public:
    explicit Viewing(QWidget *parent = nullptr);
    ~Viewing();

private:
    Ui::Viewing *ui;
};

#endif // VIEWING_H
