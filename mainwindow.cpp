#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow), core(new Core) {
    ui->setupUi(this);

    ui->currentResultLabelSuccess->setVisible(false);
    ui->currentResultLabelError->setVisible(false);
    ui->task0->setText(Static::worktypeShort);
    ui->task1->setText(Static::worktypeShort);
    ui->task2->setText(Static::worktypeShort);
    messageTimer = new QTimer(this);
    QObject::connect(messageTimer, &QTimer::timeout, [this]{ setMessage(""); });

    core->init(this);
    core->generate();
    core->next();
}

MainWindow::~MainWindow() {
    delete ui;
    delete messageTimer;
    delete core;
}

void MainWindow::setSeed(unsigned int seed) {
    core->generate(seed);
}

void MainWindow::setWidget(ScreenController* widget) {
    clearWidgets(ui->contentLayout);
    screen = widget;
    ui->contentLayout->addWidget(widget);
}

ScreenController* MainWindow::getWidget() {
    return screen;
}

void MainWindow::setStep(int step, QString text) {
    ui->stepLabel->setText(step > 0 ? QString("%1. " + text).arg(step) : text);
}

void MainWindow::setCurrentTask(int showedTask, int currentTask) {
    taskButton(ui->task0, 0, showedTask, currentTask);
    taskButton(ui->task1, 1, showedTask, currentTask);
    taskButton(ui->task2, 2, showedTask, currentTask);
    taskButton(ui->task3, 3, showedTask, currentTask);
    taskButton(ui->task4, 4, showedTask, currentTask);
    taskButton(ui->task5, 5, showedTask, currentTask);
    taskButton(ui->task6, 6, showedTask, currentTask);
    taskButton(ui->task7, 7, showedTask, currentTask);
    taskButton(ui->task8, 8, showedTask, currentTask);
    taskButton(ui->task9, 9, showedTask, currentTask);
    taskButton(ui->task10, 10, showedTask, currentTask);
    taskButton(ui->task11, 11, showedTask, currentTask);
    taskButton(ui->task12, 12, showedTask, currentTask);
    taskButton(ui->task13, 13, showedTask, currentTask);
    taskButton(ui->task14, 14, showedTask, currentTask);
    taskButton(ui->task15, 15, showedTask, currentTask);
    taskButton(ui->task16, 16, showedTask, currentTask);
    taskButton(ui->task17, 17, showedTask, currentTask);
    taskButton(ui->task18, 18, showedTask, currentTask);
    taskButton(ui->task19, 19, showedTask, currentTask);
    taskButton(ui->task20, 20, showedTask, currentTask);
    taskButton(ui->task21, 21, showedTask, currentTask);
    taskButton(ui->task22, 22, showedTask, currentTask);
    taskButton(ui->task23, 23, showedTask, currentTask);
    taskButton(ui->task24, 24, showedTask, currentTask);
    taskButton(ui->task25, 25, showedTask, currentTask);
    taskButton(ui->task26, 26, showedTask, currentTask);
    taskButton(ui->task27, 27, showedTask, currentTask);
    taskButton(ui->task28, 28, showedTask, currentTask);
}

void MainWindow::setNextEnabled(bool enabled) {
    ui->nextButton->setEnabled(enabled);
}

void MainWindow::setResetEnabled(bool enabled) {
    ui->resetButton->setEnabled(enabled);
}

void MainWindow::setScore(int score) {
    QString suffix = "ов";
    if (score % 100 < 10 || score % 100 > 20) {
        switch (score % 10) {
            case 1: suffix = ""; break;
            case 2: case 3: case 4: suffix = "a"; break;
        }
    }
    ui->scoreLabel->setText(QString("%1 балл" + suffix).arg(score));
}

void MainWindow::setMessage(QString message) {
    messageTimer->stop();
    bool isError = message.contains("-");
    ui->currentResultLabelSuccess->setVisible(false);
    ui->currentResultLabelError->setVisible(false);
    if (isError) {
        ui->currentResultLabelError->setText(message);
        ui->currentResultLabelError->setVisible(!message.isEmpty());
    } else {
        ui->currentResultLabelSuccess->setText(message);
        ui->currentResultLabelSuccess->setVisible(!message.isEmpty());
    }
    if (!message.isEmpty()) {
        messageTimer->start(2000);
    }
}

void MainWindow::clearWidgets(QLayout* layout) {
   if (!layout) {
      return;
   }
   while (auto item = layout->takeAt(0)) {
      layout->removeWidget(item->widget());
      layout->removeItem(item);
      delete item->widget();
      clearWidgets(item->layout());
   }
}

void MainWindow::taskButton(QPushButton* button, int taskNumber, int showedTask, int currentTask) {
    bool isActive = showedTask == taskNumber;
    bool isEnabled = currentTask >= taskNumber;
    QFont font = button->font();
    font.setUnderline(isActive);
    button->setFont(font);
    button->setEnabled(isEnabled);
    button->setDefault(isActive);
}

void MainWindow::on_nextButton_clicked() { core->next(); }
void MainWindow::on_resetButton_clicked() { core->reset(); }
void MainWindow::on_task0_clicked() { core->back(0); }
void MainWindow::on_task1_clicked() { core->back(1); }
void MainWindow::on_task2_clicked() { core->back(2); }
void MainWindow::on_task3_clicked() { core->back(3); }
void MainWindow::on_task4_clicked() { core->back(4); }
void MainWindow::on_task5_clicked() { core->back(5); }
void MainWindow::on_task6_clicked() { core->back(6); }
void MainWindow::on_task7_clicked() { core->back(7); }
void MainWindow::on_task8_clicked() { core->back(8); }
void MainWindow::on_task9_clicked() { core->back(9); }
void MainWindow::on_task10_clicked() { core->back(10); }
void MainWindow::on_task11_clicked() { core->back(11); }
void MainWindow::on_task12_clicked() { core->back(12); }
void MainWindow::on_task13_clicked() { core->back(13); }
void MainWindow::on_task14_clicked() { core->back(14); }
void MainWindow::on_task15_clicked() { core->back(15); }
void MainWindow::on_task16_clicked() { core->back(16); }
void MainWindow::on_task17_clicked() { core->back(17); }
void MainWindow::on_task18_clicked() { core->back(18); }
void MainWindow::on_task19_clicked() { core->back(19); }
void MainWindow::on_task20_clicked() { core->back(20); }
void MainWindow::on_task21_clicked() { core->back(21); }
void MainWindow::on_task22_clicked() { core->back(22); }
void MainWindow::on_task23_clicked() { core->back(23); }
void MainWindow::on_task24_clicked() { core->back(24); }
void MainWindow::on_task25_clicked() { core->back(25); }
void MainWindow::on_task26_clicked() { core->back(26); }
void MainWindow::on_task27_clicked() { core->back(27); }
void MainWindow::on_task28_clicked() { core->back(28); }

