#ifndef CHARTVIEW_H
#define CHARTVIEW_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QPen>
#include <QPointF>

namespace Ui {
    class ChartView;
}

class ChartView : public QGraphicsView {
    Q_OBJECT

public:
    explicit ChartView(QWidget *parent = 0);
    ~ChartView();
    void addPoint(int, int);
    void draw();

private:
    QGraphicsScene *scene;
    QPen *grid;
    QPen *axes;
    QPen *graph;
    std::vector<QPointF> points;
};

#endif // CHARTVIEW_H
