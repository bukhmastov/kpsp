#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
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
    void setCurrentTask(int, int);
    void setNextEnabled(bool);
    void setResetEnabled(bool);
    void setScore(int);
    void setMessage(QString);

private slots:
    void on_nextButton_clicked(); // next question/step
    void on_resetButton_clicked(); // reset progress, start from the beginning (eg step -> 0)
    void on_task0_clicked();
    void on_task1_clicked();
    void on_task2_clicked();
    void on_task3_clicked();
    void on_task4_clicked();
    void on_task5_clicked();
    void on_task6_clicked();
    void on_task7_clicked();
    void on_task8_clicked();
    void on_task9_clicked();
    void on_task10_clicked();
    void on_task11_clicked();
    void on_task12_clicked();
    void on_task13_clicked();
    void on_task14_clicked();
    void on_task15_clicked();
    void on_task16_clicked();
    void on_task17_clicked();
    void on_task18_clicked();
    void on_task19_clicked();
    void on_task20_clicked();
    void on_task21_clicked();
    void on_task22_clicked();
    void on_task23_clicked();
    void on_task24_clicked();
    void on_task25_clicked();
    void on_task26_clicked();
    void on_task27_clicked();
    void on_task28_clicked();

private:
    Ui::MainWindow *ui;
    Core *core;
    ScreenController *screen;
    QTimer* messageTimer;
    void clearWidgets(QLayout*);
    void taskButton(QPushButton*, int, int, int);
};

#endif // MAINWINDOW_H
