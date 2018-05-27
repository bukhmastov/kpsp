#ifndef SCREENTASK9A_H
#define SCREENTASK9A_H

#include <QFrame>
#include "util/core.h"
#include "util/screencontroller.h"
#include "view/chartview.h"

namespace Ui {
    class ScreenTask9A;
}

class ScreenTask9A : public ScreenController {
    Q_OBJECT

public:
    explicit ScreenTask9A(QWidget *parent = 0);
    ~ScreenTask9A();
    ScreenController* init(int, bool);
    bool validate(Core*, QString*);

protected:
    void init();

private:
    Ui::ScreenTask9A *ui;
    QList<QString> r;
};

#endif // SCREENTASK9A_H
