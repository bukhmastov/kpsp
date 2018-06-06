#include "screentask4.h"
#include "ui_screentask4.h"

ScreenTask4::ScreenTask4(QWidget *parent) : ScreenController(parent), ui(new Ui::ScreenTask4) {
    ui->setupUi(this);
}

ScreenTask4::~ScreenTask4() {
    delete ui;
}

void ScreenTask4::init() {
    for (int i = 0; i < 9; i++) {
        rm.push_back(0);
    }
    if (ScreenController::store.count("task3_f")) {
        f = ScreenController::store.at("task3_f");
    } else {
        switch (rnd() % 6) {
        case 0: f = "01010101"; break;
        case 1: f = "00110011"; break;
        case 2: f = "01100110"; break;
        case 3: f = "00001111"; break;
        case 4: f = "01011010"; break;
        case 5: f = "00111100"; break;
        case 6: f = "01101001"; break;
        }
    }
    rm = Static::getDPAKF(f, 8);
    ui->title->setText(ui->title->text().replace("%f%", Static::sequence01to11(f)));
    if (readOnly) {
        ui->input1->setText(QString::number(rm.at(0)));
        ui->input2->setText(QString::number(rm.at(1)));
        ui->input3->setText(QString::number(rm.at(2)));
        ui->input4->setText(QString::number(rm.at(3)));
        ui->input5->setText(QString::number(rm.at(4)));
        ui->input6->setText(QString::number(rm.at(5)));
        ui->input7->setText(QString::number(rm.at(6)));
        ui->input8->setText(QString::number(rm.at(7)));
        ui->input9->setText(QString::number(rm.at(8)));
        ChartView *chartRM = new ChartView(this);
        for (int i = 0; i < 9; i++) {
            chartRM->addPoint(i, rm.at(i));
            chartRM->addPoint(i + 1, rm.at(i));
        }
        chartRM->draw();
        ui->charts->addWidget(chartRM);
        ui->input1->setEnabled(false);
        ui->input2->setEnabled(false);
        ui->input3->setEnabled(false);
        ui->input4->setEnabled(false);
        ui->input5->setEnabled(false);
        ui->input6->setEnabled(false);
        ui->input7->setEnabled(false);
        ui->input8->setEnabled(false);
        ui->input9->setEnabled(false);
    }
}

bool ScreenTask4::validate(Core* core, QString* message) {
    if (readOnly) {
        return true;
    }
    if (
            ui->input1->text().toInt() == rm.at(0) &&
            ui->input2->text().toInt() == rm.at(1) &&
            ui->input3->text().toInt() == rm.at(2) &&
            ui->input4->text().toInt() == rm.at(3) &&
            ui->input5->text().toInt() == rm.at(4) &&
            ui->input6->text().toInt() == rm.at(5) &&
            ui->input7->text().toInt() == rm.at(6) &&
            ui->input8->text().toInt() == rm.at(7) &&
            ui->input9->text().toInt() == rm.at(8)
    ) {
        message->append(Static::messageAnswerRight);
        core->changeScore(2);
    } else {
        message->append(Static::messageAnswerWrong);
        core->changeScore(-2);
    }
    return true;
}
