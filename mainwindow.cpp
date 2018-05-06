#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow), core(new Core) {
    ui->setupUi(this);

    ui->currentResultLabel->setVisible(false);
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

void MainWindow::setMaxProgress(int max) {
    ui->progressBar->setRange(0, max);
}

void MainWindow::setProgress(int progress) {
    ui->progressBar->setValue(progress);
}

void MainWindow::setNextEnabled(bool enabled) {
    ui->nextButton->setEnabled(enabled);
}

void MainWindow::setBackEnabled(bool enabled) {
    ui->backButton->setEnabled(enabled);
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
    ui->currentResultLabel->setText(message);
    ui->currentResultLabel->setVisible(!message.isEmpty());
    if (!message.isEmpty()) {
        messageTimer->start(2000);
    }
}

void MainWindow::on_nextButton_clicked() {
    core->next();
}

void MainWindow::on_backButton_clicked() {
    core->back();
}

void MainWindow::on_resetButton_clicked() {
    core->reset();
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

