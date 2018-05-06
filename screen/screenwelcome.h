#ifndef SCREENWELCOME_H
#define SCREENWELCOME_H

#include <QFrame>
#include "util/core.h"
#include "util/screencontroller.h"

namespace Ui {
    class ScreenWelcome;
}

class ScreenWelcome : public ScreenController {
    Q_OBJECT

public:
    explicit ScreenWelcome(QWidget *parent = 0);
    ~ScreenWelcome();
    ScreenController* init(int, bool);
    bool validate(Core*, QString*);

protected:
    void init();

private:
    Ui::ScreenWelcome *ui;
};

#endif // SCREENWELCOME_H
