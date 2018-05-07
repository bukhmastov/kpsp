#include "chartview.h"
#include <limits>

ChartView::ChartView(QWidget *parent) : QGraphicsView(parent) {
    scene = new QGraphicsScene(this);
    grid = new QPen(Qt::lightGray, 1);
    axes = new QPen(Qt::darkGray, 2);
    graph = new QPen(Qt::darkRed, 2);

}

ChartView::~ChartView() {
    delete scene;
    delete grid;
    delete axes;
    delete graph;
}

void ChartView::addPoint(int x, int y) {
    // y axe inverted
    points.push_back(QPointF(x * 10, -y * 10));
}

void ChartView::draw() {
    if (points.size() < 2) {
        return;
    }
    // seek for bounds
    int minX = std::numeric_limits<int>::max();
    int minY = std::numeric_limits<int>::max();
    int maxX = std::numeric_limits<int>::min();
    int maxY = std::numeric_limits<int>::min();
    for (unsigned int i = 0; i < points.size(); i++) {
        QPointF point = points.at(i);
        if (point.x() <= minX) {
            minX = point.x() - 10;
        }
        if (point.x() >= maxX) {
            maxX = point.x() + 10;
        }
        if (point.y() <= minY) {
            minY = point.y() - 10;
        }
        if (point.y() >= maxY) {
            maxY = point.y() + 10;
        }
    }
    if (minX > -10) {
        // set minimum left x bound
        minX = -10;
    }
    if (maxY < 10) {
        // set minimum bottom y bound
        maxY = 10;
    }
    // draw grid
    for (int i = minX; i < maxX + 10; i += 10) {
        scene->addLine(i, minY, i, maxY, i == 0 ? *axes : *grid);
    }
    for (int i = minY; i < maxY + 10; i += 10) {
        scene->addLine(minX, i, maxX, i, i == 0 ? *axes : *grid);
    }
    // draw graph
    for (int i = 1; i < points.size(); i++) {
        scene->addLine(QLineF(points.at(i - 1), points.at(i)), *graph);
    }

    // draw
    setScene(scene);
    setFixedHeight(maxY - minY + 5);
    setFixedWidth(maxX - minX + 5);
}
