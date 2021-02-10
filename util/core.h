#ifndef CORE_H
#define CORE_H

#include "static.h"
#include "windowcontroller.h"
#include "screencontroller.h"
#include "question.h"
#include "task.h"

class Core {
public:
    Core();
    void init(WindowController*);
    void generate();
    void generate(unsigned int);
    void next();
    void next(bool);
    void back(int);
    void back();
    void reset();
    void changeScore(int);
    int getScore();
    unsigned int getSeed();

private:
    ScreenController* getView(int);
    void show(QString);

    WindowController *window;

    std::vector<Question*> questions;
    std::vector<Task*> tasks;

    std::vector<int> questionsOrder;
    unsigned int showedTask = 0;
    unsigned int currentTask = 0;
    int score = 50;
    unsigned int seed = 0;
};

#endif // CORE_H
