#ifndef STATIC_H
#define STATIC_H

#include <QString>

class Static {
public:
    static int scoreInitial;
    static int score4quetion;
    static int score4task;
    static QString messageAnswerRight;
    static QString messageAnswerWrong;
    static QString getMSequence(QString, int);
    static QString getMSequence(QString, QString, int);
    static QString getXOR(QString, QString);
    static QString getReadablePolynom(QString);
};

#endif // STATIC_H
