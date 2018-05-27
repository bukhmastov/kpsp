#ifndef SCREENTASK9B_H
#define SCREENTASK9B_H

#include <QFrame>
#include "util/core.h"
#include "util/screencontroller.h"
#include "view/chartview.h"

namespace Ui {
    class ScreenTask9B;
}

class ScreenTask9B : public ScreenController {
    Q_OBJECT

public:
    explicit ScreenTask9B(QWidget *parent = 0);
    ~ScreenTask9B();
    ScreenController* init(int, bool);
    bool validate(Core*, QString*);

protected:
    void init();

private:
    Ui::ScreenTask9B *ui;
    std::map<int, int> map;
    QString getRandInitialSymbols();
};

#endif // SCREENTASK9B_H
