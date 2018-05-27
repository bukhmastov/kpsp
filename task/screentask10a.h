#ifndef SCREENTASK10A_H
#define SCREENTASK10A_H

#include <QFrame>
#include "util/core.h"
#include "util/screencontroller.h"
#include "view/chartview.h"

namespace Ui {
    class ScreenTask10A;
}

class ScreenTask10A : public ScreenController {
    Q_OBJECT

public:
    explicit ScreenTask10A(QWidget *parent = 0);
    ~ScreenTask10A();
    ScreenController* init(int, bool);
    bool validate(Core*, QString*);

protected:
    void init();

private:
    Ui::ScreenTask10A *ui;
    QList<QString> r;
};

#endif // SCREENTASK10A_H
