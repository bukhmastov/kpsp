#include "clickableqlabel.h"

ClickableQLabel::ClickableQLabel(QWidget *parent) : QLabel(parent) {}

ClickableQLabel::~ClickableQLabel() {}

void ClickableQLabel::mousePressEvent(QMouseEvent*) {
    emit clicked();
}

void ClickableQLabel::setVisible(bool visible) {
    QLabel::setVisible(visible);
}
