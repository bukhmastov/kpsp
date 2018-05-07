#ifndef SCREENTASK2_H
#define SCREENTASK2_H

#include <QFrame>
#include "util/core.h"
#include "util/screencontroller.h"
#include "view/chartview.h"

namespace Ui {
    class ScreenTask2;
}

class ScreenTask2 : public ScreenController {
    Q_OBJECT

public:
    explicit ScreenTask2(QWidget *parent = 0);
    ~ScreenTask2();
    ScreenController* init(int, bool);
    bool validate(Core*, QString*);

protected:
    void init();

private:
    Ui::ScreenTask2 *ui;
    std::vector<int> rm1;
    std::vector<int> rm2;
    std::vector<int> rm3;
};

#endif // SCREENTASK2_H

