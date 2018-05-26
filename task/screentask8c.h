#ifndef SCREENTASK8C_H
#define SCREENTASK8C_H

#include <QFrame>
#include "util/core.h"
#include "util/screencontroller.h"
#include "view/chartview.h"

namespace Ui {
    class ScreenTask8C;
}

class ScreenTask8C : public ScreenController {
    Q_OBJECT

public:
    explicit ScreenTask8C(QWidget *parent = 0);
    ~ScreenTask8C();
    ScreenController* init(int, bool);
    bool validate(Core*, QString*);

protected:
    void init();

private:
    Ui::ScreenTask8C *ui;
    std::map<int, int> map;
};

#endif // SCREENTASK8C_H
