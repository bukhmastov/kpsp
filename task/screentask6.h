#ifndef SCREENTASK6_H
#define SCREENTASK6_H

#include <QFrame>
#include "util/core.h"
#include "util/screencontroller.h"

namespace Ui {
    class ScreenTask6;
}

class ScreenTask6 : public ScreenController {
    Q_OBJECT

public:
    explicit ScreenTask6(QWidget *parent = 0);
    ~ScreenTask6();
    ScreenController* init(int, bool);
    bool validate(Core*, QString*);

protected:
    void init();

private:
    Ui::ScreenTask6 *ui;
    std::vector<int> m;
    std::vector<double> rmLI;
    std::vector<std::pair<double, double>> rmEV;
};

#endif // SCREENTASK6_H
