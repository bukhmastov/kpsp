#ifndef SCREENTASK10B_H
#define SCREENTASK10B_H

#include <QFrame>
#include "util/core.h"
#include "util/screencontroller.h"
#include "view/chartview.h"

namespace Ui {
    class ScreenTask10B;
}

class ScreenTask10B : public ScreenController {
    Q_OBJECT

public:
    explicit ScreenTask10B(QWidget *parent = 0);
    ~ScreenTask10B();
    ScreenController* init(int, bool);
    bool validate(Core*, QString*);

protected:
    void init();

private:
    Ui::ScreenTask10B *ui;
    std::map<int, int> map;
    QString getRandInitialSymbols();
};

#endif // SCREENTASK10B_H
