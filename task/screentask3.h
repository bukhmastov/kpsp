#ifndef SCREENTASK3_H
#define SCREENTASK3_H

#include <QFrame>
#include "util/core.h"
#include "util/screencontroller.h"
#include "view/chartview.h"

namespace Ui {
    class ScreenTask3;
}

class ScreenTask3 : public ScreenController {
    Q_OBJECT

public:
    explicit ScreenTask3(QWidget *parent = 0);
    ~ScreenTask3();
    ScreenController* init(int, bool);
    bool validate(Core*, QString*);

protected:
    void init();

private:
    Ui::ScreenTask3 *ui;
    int k;
    QString f;
    std::vector<int> rm1;
    std::vector<int> rm2;
};

#endif // SCREENTASK3_H
