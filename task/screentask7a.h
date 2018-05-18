#ifndef SCREENTASK7A_H
#define SCREENTASK7A_H

#include <QFrame>
#include "util/core.h"
#include "util/screencontroller.h"

namespace Ui {
    class ScreenTask7A;
}

class ScreenTask7A : public ScreenController {
    Q_OBJECT

public:
    explicit ScreenTask7A(QWidget *parent = 0);
    ~ScreenTask7A();
    ScreenController* init(int, bool);
    bool validate(Core*, QString*);

protected:
    void init();

private:
    Ui::ScreenTask7A *ui;
    std::vector<int> m;
    std::vector<int> rm12;
};

#endif // SCREENTASK7A_H
