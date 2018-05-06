#include "task.h"

Task::Task(int id, int number, QString title, bool nextButtonActive) {
    this->id = id;
    this->number = number;
    this->title = title;
    this->nextButtonActive = nextButtonActive;
}

int Task::getId() {
    return id;
}

int Task::getNumber() {
    return number;
}

QString Task::getTitle() {
    return title;
}

bool Task::getNextButtonActive() {
    return nextButtonActive;
}
