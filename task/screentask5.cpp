#include "screentask5.h"
#include "ui_screentask5.h"

ScreenTask5::ScreenTask5(QWidget *parent) : ScreenController(parent), ui(new Ui::ScreenTask5) {
    ui->setupUi(this);
}

ScreenTask5::~ScreenTask5() {
    delete ui;
}

void ScreenTask5::init() {
    QString f;
    QString mSeq;
    int c0, c1;
    do {
        c0 = rnd() % 3;
        c1 = rnd() % 3;
    } while (c0 == 0 && c1 == 0);
    switch(rnd() % 2) {
    case 0:
        f = "2+x+x<sup>2</sup>";
        mSeq = Static::get3MSequence(c0, c1, 8, [](int c0, int c1) -> int { return 2 * c0 + c1; });
        break;
    case 1:
        f = "2+2x+x<sup>2</sup>";
        mSeq = Static::get3MSequence(c0, c1, 8, [](int c0, int c1) -> int { return c0 + c1; });
        break;
    }
    for (int i = 0; i < 3; i++) {
        m.push_back(-1);
    }
    for (int i = 0; i < 3;) {
        int mI = rnd() % 8;
        for (int j = 0; j < 3; j++) {
            if (m.at(j) == mI) {
                goto next;
            }
        }
        m[i++] = mI;
        next:;
    }
    rmLI = Static::getLIPAKF(mSeq, 3, 8);
    rmEV = Static::getEVPAKF(mSeq, 8);
    ScreenController::store["task5_mSeq"] = mSeq;
    // setup ui
    QString title = ui->title->text();
    title = title.replace("%h%", f);
    title = title.replace("%c0%", QString::number(c0));
    title = title.replace("%c1%", QString::number(c1));
    title = title.replace("%m1%", QString::number(m.at(0)));
    title = title.replace("%m2%", QString::number(m.at(1)));
    title = title.replace("%m3%", QString::number(m.at(2)));
    ui->title->setText(title);
    ui->labelLIm1->setText(ui->labelLIm1->text().replace("%m1%", QString::number(m.at(0))));
    ui->labelLIm2->setText(ui->labelLIm2->text().replace("%m2%", QString::number(m.at(1))));
    ui->labelLIm3->setText(ui->labelLIm3->text().replace("%m3%", QString::number(m.at(2))));
    ui->labelEVm1->setText(ui->labelEVm1->text().replace("%m1%", QString::number(m.at(0))));
    ui->labelEVm2->setText(ui->labelEVm2->text().replace("%m2%", QString::number(m.at(1))));
    ui->labelEVm3->setText(ui->labelEVm3->text().replace("%m3%", QString::number(m.at(2))));
    if (readOnly) {
        ui->inputLIm1->setText(QString::number(rmLI.at(m.at(0))));
        ui->inputLIm2->setText(QString::number(rmLI.at(m.at(1))));
        ui->inputLIm3->setText(QString::number(rmLI.at(m.at(2))));
        ui->inputEVm1->setText(QString::number(rmEV.at(m.at(0)).first));
        ui->inputEVm2->setText(QString::number(rmEV.at(m.at(1)).first));
        ui->inputEVm3->setText(QString::number(rmEV.at(m.at(2)).first));
    }
}

bool ScreenTask5::validate(Core* core, QString* message) {
    if (readOnly) {
        return true;
    }
    if (
            ui->inputLIm1->text().toInt() == rmLI.at(m.at(0)) &&
            ui->inputLIm2->text().toInt() == rmLI.at(m.at(1)) &&
            ui->inputLIm3->text().toInt() == rmLI.at(m.at(2)) &&
            ui->inputEVm1->text().toDouble() == rmEV.at(m.at(0)).first &&
            ui->inputEVm2->text().toDouble() == rmEV.at(m.at(1)).first &&
            ui->inputEVm3->text().toDouble() == rmEV.at(m.at(2)).first
    ) {
        message->append(Static::messageAnswerRight);
        core->changeScore(2);
    } else {
        message->append(Static::messageAnswerWrong);
        core->changeScore(-2);
    }
    return true;
}
