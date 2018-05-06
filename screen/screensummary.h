#ifndef SCREENSUMMARY_H
#define SCREENSUMMARY_H

#include <QFrame>
#include "util/core.h"
#include "util/screencontroller.h"

namespace Ui {
    class ScreenSummary;
}

class ScreenSummary : public ScreenController {
    Q_OBJECT

public:
    explicit ScreenSummary(QWidget *parent = 0);
    ~ScreenSummary();
    static ScreenSummary* get(Core*);
    ScreenController* init(int, bool);
    bool validate(Core*, QString*);

protected:
    void init();

private:
    Ui::ScreenSummary *ui;
};

#endif // SCREENSUMMARY_H
