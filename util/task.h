#ifndef ITASK_H
#define ITASK_H

#include <QtWidgets/qwidget.h>

class Task {
public:
    Task(int, int, QString, bool = true);
    int getId();
    int getNumber();
    QString getTitle();
    bool getNextButtonActive();
private:
    int id;
    int number;
    QString title;
    bool nextButtonActive;
};

#endif // ITASK_H
