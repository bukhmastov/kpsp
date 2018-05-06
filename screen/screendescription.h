#ifndef SCREENDESCRIPTION_H
#define SCREENDESCRIPTION_H

#include <QFrame>
#include "util/core.h"
#include "util/screencontroller.h"

namespace Ui {
    class ScreenDescription;
}

class ScreenDescription : public ScreenController {
    Q_OBJECT

public:
    explicit ScreenDescription(QWidget *parent = 0);
    ~ScreenDescription();
    ScreenController* init(int, bool);
    bool validate(Core*, QString*);

protected:
    void init();

private:
    Ui::ScreenDescription *ui;
};

#endif // SCREENDESCRIPTION_H
