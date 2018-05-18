#include "screentask7a.h"
#include "ui_screentask7a.h"

ScreenTask7A::ScreenTask7A(QWidget *parent) : ScreenController(parent), ui(new Ui::ScreenTask7A) {
    ui->setupUi(this);
}

ScreenTask7A::~ScreenTask7A() {
    delete ui;
}

void ScreenTask7A::init() {
    QString f1;
    QString f2;
    switch (rnd() % 2) {
    case 0:
        f1 = "1111101000100101011000011100110";
        f2 = "1111100100110000101101010001110";
        break;
    case 1:
        f1 = "1111101110001010110100001100100";
        f2 = "1111100110100100001010111011000";
        break;
    }
    for (int i = 0; i < 4; i++) {
        m.push_back(-1);
    }
    for (int i = 0; i < 4;) {
        int mI = rnd() % 8;
        if (mI > 3) {
            mI = 31 - mI % 4;
        }
        for (int j = 0; j < 4; j++) {
            if (m.at(j) == mI) {
                goto next;
            }
        }
        m[i++] = mI;
        next:;
    }
    rm12 = Static::getPVKF(f1, f2, 31);
    ScreenController::store["task7a_f1"] = f1;
    ScreenController::store["task7a_f2"] = f2;
    // setup ui
    QString title = ui->title->text();
    title = title.replace("%m1%", QString::number(m.at(0)));
    title = title.replace("%m2%", QString::number(m.at(1)));
    title = title.replace("%m3%", QString::number(m.at(2)));
    title = title.replace("%m4%", QString::number(m.at(3)));
    title = title.replace("%f1%", f1);
    title = title.replace("%f2%", f2);
    ui->title->setText(title);
    ui->labelm1->setText(ui->labelm1->text().replace("%m1%", QString::number(m.at(0))));
    ui->labelm2->setText(ui->labelm2->text().replace("%m2%", QString::number(m.at(1))));
    ui->labelm3->setText(ui->labelm3->text().replace("%m3%", QString::number(m.at(2))));
    ui->labelm4->setText(ui->labelm4->text().replace("%m4%", QString::number(m.at(3))));
    if (readOnly) {
        ui->inputm1->setText(QString::number(rm12.at(m.at(0))));
        ui->inputm2->setText(QString::number(rm12.at(m.at(1))));
        ui->inputm3->setText(QString::number(rm12.at(m.at(2))));
        ui->inputm4->setText(QString::number(rm12.at(m.at(3))));
    }
}

bool ScreenTask7A::validate(Core* core, QString* message) {
    if (readOnly) {
        return true;
    }
    if (
            ui->inputm1->text().toDouble() == rm12.at(m.at(0)) &&
            ui->inputm2->text().toDouble() == rm12.at(m.at(1)) &&
            ui->inputm3->text().toDouble() == rm12.at(m.at(2)) &&
            ui->inputm4->text().toDouble() == rm12.at(m.at(3))
    ) {
        message->append(Static::messageAnswerRight);
        core->changeScore(2);
    } else {
        message->append(Static::messageAnswerWrong);
        core->changeScore(-2);
    }
    return true;
}
