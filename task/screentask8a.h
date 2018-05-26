#ifndef SCREENTASK8A_H
#define SCREENTASK8A_H

#include <QFrame>
#include "util/core.h"
#include "util/screencontroller.h"

namespace Ui {
    class ScreenTask8A;
}

class ScreenTask8A : public ScreenController {
    Q_OBJECT

public:
    explicit ScreenTask8A(QWidget *parent = 0);
    ~ScreenTask8A();
    ScreenController* init(int, bool);
    bool validate(Core*, QString*);

protected:
    void init();

private:
    Ui::ScreenTask8A *ui;
    QString fg1;
    QString fg2;
};

#endif // SCREENTASK8A_H
