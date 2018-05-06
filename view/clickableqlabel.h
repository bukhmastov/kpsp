#ifndef CLICKABLEQLABEL_H
#define CLICKABLEQLABEL_H

#include <QLabel>

namespace Ui {
    class ClickableQLabel;
}

class ClickableQLabel : public QLabel {
    Q_OBJECT

public:
    explicit ClickableQLabel(QWidget *parent = 0);
    ~ClickableQLabel();

public Q_SLOTS:
    void setVisible(bool);

signals:
    void clicked();

protected:
    void mousePressEvent(QMouseEvent* event);
};

#endif // CLICKABLEQLABEL_H
