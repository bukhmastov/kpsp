#ifndef SCREENABOUT_H
#define SCREENABOUT_H

#include <QFrame>
#include "util/core.h"
#include "util/screencontroller.h"

namespace Ui {
    class ScreenAbout;
}

class ScreenAbout : public ScreenController {
    Q_OBJECT

public:
    explicit ScreenAbout(QWidget *parent = 0);
    ~ScreenAbout();
    ScreenController* init(int, bool);
    bool validate(Core*, QString*);

protected:
    void init();

private:
    Ui::ScreenAbout *ui;
};

#endif // SCREENABOUT_H
