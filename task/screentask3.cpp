#include "screentask3.h"
#include "ui_screentask3.h"

ScreenTask3::ScreenTask3(QWidget *parent) : ScreenController(parent), ui(new Ui::ScreenTask3) {
    ui->setupUi(this);
}

ScreenTask3::~ScreenTask3() {
    delete ui;
}

void ScreenTask3::init() {
    for (int i = 0; i < 9; i++) {
        rm1.push_back(0);
        rm2.push_back(0);
    }
    /* Матрица Адамара 3
     * 0 +1+1+1+1+1+1+1+1
     * 1 +1-1+1-1+1-1+1-1
     * 2 +1+1-1-1+1+1-1-1
     * 3 +1-1-1+1+1-1-1+1
     * 4 +1+1+1+1-1-1-1-1
     * 5 +1-1+1-1-1+1-1+1
     * 6 +1+1-1-1-1-1+1+1
     * 7 +1-1-1+1-1+1+1-1
     * +1 -> 0
     * -1 -> 1
     */
    switch (/*rnd() % 6*/ 4) {
    case 0: k = 1; f = "01010101"; break;
    case 1: k = 2; f = "00110011"; break;
    case 2: k = 3; f = "01100110"; break;
    case 3: k = 4; f = "00001111"; break;
    case 4: k = 5; f = "01011010"; break;
    case 5: k = 6; f = "00111100"; break;
    case 6: k = 7; f = "01101001"; break;
    }
    rm1 = Static::getPAKF(f, 8);
    rm2 = Static::getAAKF(f, 8);
    ui->title->setText(ui->title->text().replace("%k%", QString::number(k)));
    if (readOnly) {
        ui->inputF1->setText(Static::alphabet01to11(f.at(0)));
        ui->inputF2->setText(Static::alphabet01to11(f.at(1)));
        ui->inputF3->setText(Static::alphabet01to11(f.at(2)));
        ui->inputF4->setText(Static::alphabet01to11(f.at(3)));
        ui->inputF5->setText(Static::alphabet01to11(f.at(4)));
        ui->inputF6->setText(Static::alphabet01to11(f.at(5)));
        ui->inputF7->setText(Static::alphabet01to11(f.at(6)));
        ui->inputF8->setText(Static::alphabet01to11(f.at(7)));

        ui->input11->setText(QString::number(rm1.at(0)));
        ui->input12->setText(QString::number(rm1.at(1)));
        ui->input13->setText(QString::number(rm1.at(2)));
        ui->input14->setText(QString::number(rm1.at(3)));
        ui->input15->setText(QString::number(rm1.at(4)));
        ui->input16->setText(QString::number(rm1.at(5)));
        ui->input17->setText(QString::number(rm1.at(6)));
        ui->input18->setText(QString::number(rm1.at(7)));
        ui->input19->setText(QString::number(rm1.at(8)));
        ChartView *chartRM1 = new ChartView(this);
        for (int i = 0; i < 9; i++) {
            chartRM1->addPoint(i, rm1.at(i));
        }
        chartRM1->draw();
        ui->charts->addWidget(chartRM1);

        ui->input21->setText(QString::number(rm2.at(0)));
        ui->input22->setText(QString::number(rm2.at(1)));
        ui->input23->setText(QString::number(rm2.at(2)));
        ui->input24->setText(QString::number(rm2.at(3)));
        ui->input25->setText(QString::number(rm2.at(4)));
        ui->input26->setText(QString::number(rm2.at(5)));
        ui->input27->setText(QString::number(rm2.at(6)));
        ui->input28->setText(QString::number(rm2.at(7)));
        ui->input29->setText(QString::number(rm2.at(8)));
        ChartView *chartRM2 = new ChartView(this);
        for (int i = 0; i < 9; i++) {
            chartRM2->addPoint(i, rm2.at(i));
        }
        chartRM2->draw();
        ui->charts->addWidget(chartRM2);
    }
}

bool ScreenTask3::validate(Core* core, QString* message) {
    if (readOnly) {
        return true;
    }
    if (
            Static::alphabet11to01(ui->inputF1->text()) == QString(f.at(0)) &&
            Static::alphabet11to01(ui->inputF2->text()) == QString(f.at(1)) &&
            Static::alphabet11to01(ui->inputF3->text()) == QString(f.at(2)) &&
            Static::alphabet11to01(ui->inputF4->text()) == QString(f.at(3)) &&
            Static::alphabet11to01(ui->inputF5->text()) == QString(f.at(4)) &&
            Static::alphabet11to01(ui->inputF6->text()) == QString(f.at(5)) &&
            Static::alphabet11to01(ui->inputF7->text()) == QString(f.at(6)) &&
            Static::alphabet11to01(ui->inputF8->text()) == QString(f.at(7)) &&

            ui->input11->text().toInt() == rm1.at(0) &&
            ui->input12->text().toInt() == rm1.at(1) &&
            ui->input13->text().toInt() == rm1.at(2) &&
            ui->input14->text().toInt() == rm1.at(3) &&
            ui->input15->text().toInt() == rm1.at(4) &&
            ui->input16->text().toInt() == rm1.at(5) &&
            ui->input17->text().toInt() == rm1.at(6) &&
            ui->input18->text().toInt() == rm1.at(7) &&
            ui->input19->text().toInt() == rm1.at(8) &&

            ui->input21->text().toInt() == rm2.at(0) &&
            ui->input22->text().toInt() == rm2.at(1) &&
            ui->input23->text().toInt() == rm2.at(2) &&
            ui->input24->text().toInt() == rm2.at(3) &&
            ui->input25->text().toInt() == rm2.at(4) &&
            ui->input26->text().toInt() == rm2.at(5) &&
            ui->input27->text().toInt() == rm2.at(6) &&
            ui->input28->text().toInt() == rm2.at(7) &&
            ui->input29->text().toInt() == rm2.at(8)
    ) {
        message->append(Static::messageAnswerRight);
        core->changeScore(2);
    } else {
        message->append(Static::messageAnswerWrong);
        core->changeScore(-2);
    }
    return true;
}
