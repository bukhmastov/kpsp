#ifndef QUESTION_H
#define QUESTION_H

#include <QString>

class Question {
public:
    Question(QString, std::vector<QString>);
    QString getQustion();
    std::vector<QString> getAnswers();
private:
    QString question;
    std::vector<QString> answers;
};

#endif // QUESTION_H
