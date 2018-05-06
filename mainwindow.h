#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QTimer>
#include "util/core.h"
#include "util/screencontroller.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow, public WindowController {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void init(Core);
    void setSeed(unsigned int);
    void setWidget(ScreenController*);
    ScreenController* getWidget();
    void setStep(int, QString);
    void setMaxProgress(int);
    void setProgress(int);
    void setNextEnabled(bool);
    void setBackEnabled(bool);
    void setResetEnabled(bool);
    void setScore(int);
    void setMessage(QString);

private slots:
    void on_nextButton_clicked(); // next question/step
    void on_backButton_clicked(); // prev question/step
    void on_resetButton_clicked(); // reset progress, start from the beginning (eg step -> 0)

private:
    Ui::MainWindow *ui;
    Core *core;
    ScreenController *screen;
    QTimer* messageTimer;
    void clearWidgets(QLayout*);
};

#endif // MAINWINDOW_H
