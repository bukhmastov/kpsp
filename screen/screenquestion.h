#ifndef SCREENQUESTION_H
#define SCREENQUESTION_H

#include <QFrame>
#include "util/core.h"
#include "util/screencontroller.h"
#include "util/question.h"

namespace Ui {
    class ScreenQuestion;
}

class ScreenQuestion : public ScreenController {
    Q_OBJECT

public:
    explicit ScreenQuestion(QWidget *parent = 0);
    ~ScreenQuestion();
    static ScreenQuestion* get(Core*, Question*);
    ScreenController* init(int, bool);
    bool validate(Core*, QString*);

protected:
    void init();

private slots:
    void onRightAnswer();
    void onWrongAnswer();

private:
    Ui::ScreenQuestion *ui;
    Core* core;
    Question* question;
    bool status = false;
};

#endif // SCREENQUESTION_H
