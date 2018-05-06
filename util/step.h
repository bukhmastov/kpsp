#ifndef ISTEP_H
#define ISTEP_H

#include "task.h"
#include <QString>

class Step {
public:
    Step(int number, QString title, std::vector<Task*> tasks) {
        this->number = number;
        this->title = title;
        this->tasks = tasks;
    }
    int getNumber() {
        return number;
    }
    QString getTitle() {
        return title;
    }
    std::vector<Task*> getTasks() {
        return tasks;
    }
private:
    int number;
    QString title;
    std::vector<Task*> tasks;
};

#endif // ISTEP_H
