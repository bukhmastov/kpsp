#include "questionanswerlabel.h"
#include <QFont>

QuestionAnswerLabel::QuestionAnswerLabel(QWidget* parent) : QLabel(parent) {
    QFont font;
    font.setPointSize(12);
    this->setFont(font);
    this->setWordWrap(true);
    this->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    this->setCursor(Qt::PointingHandCursor);
}

void QuestionAnswerLabel::enterEvent(QEvent*) {
    QFont font = this->font();
    font.setUnderline(true);
    this->setFont(font);
}

void QuestionAnswerLabel::leaveEvent(QEvent*) {
    QFont font = this->font();
    font.setUnderline(false);
    this->setFont(font);
}

void QuestionAnswerLabel::mousePressEvent(QMouseEvent*) {
    emit clicked();
}
