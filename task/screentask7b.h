#ifndef SCREENTASK7B_H
#define SCREENTASK7B_H

#include <QFrame>
#include "util/core.h"
#include "util/screencontroller.h"
#include "view/chartview.h"

namespace Ui {
    class ScreenTask7B;
}

class ScreenTask7B : public ScreenController {
    Q_OBJECT

public:
    explicit ScreenTask7B(QWidget *parent = 0);
    ~ScreenTask7B();
    ScreenController* init(int, bool);
    bool validate(Core*, QString*);

protected:
    void init();

private:
    Ui::ScreenTask7B *ui;
    std::vector<int> rm12;
    std::map<int, int> map;
};

#endif // SCREENTASK7B_H
