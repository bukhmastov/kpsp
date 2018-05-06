#include "question.h"

Question::Question(QString question, std::vector<QString> answers) {
    this->question = question;
    this->answers = answers;
}

QString Question::getQustion() {
    return question;
}

std::vector<QString> Question::getAnswers() {
    return answers;
}
