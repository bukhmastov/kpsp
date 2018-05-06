#ifndef QUESTIONANSWERLABEL_H
#define QUESTIONANSWERLABEL_H

#include <QLabel>

class QuestionAnswerLabel : public QLabel {
    Q_OBJECT

public:
    explicit QuestionAnswerLabel(QWidget *parent = 0);

signals:
    void clicked();

protected:
    void mousePressEvent(QMouseEvent* event);
    void enterEvent(QEvent *event);
    void leaveEvent(QEvent *event);
};

#endif // QUESTIONANSWERLABEL_H
