#ifndef SCREENTASK8B_H
#define SCREENTASK8B_H

#include <QFrame>
#include "util/core.h"
#include "util/screencontroller.h"
#include "view/chartview.h"

namespace Ui {
    class ScreenTask8B;
}

class ScreenTask8B : public ScreenController {
    Q_OBJECT

public:
    explicit ScreenTask8B(QWidget *parent = 0);
    ~ScreenTask8B();
    ScreenController* init(int, bool);
    bool validate(Core*, QString*);

protected:
    void init();

private:
    Ui::ScreenTask8B *ui;
    std::vector<int> m;
    std::vector<int> pvkf;
};

#endif // SCREENTASK8B_H
