#include "screentask8a.h"
#include "ui_screentask8a.h"

ScreenTask8A::ScreenTask8A(QWidget *parent) : ScreenController(parent), ui(new Ui::ScreenTask8A) {
    ui->setupUi(this);
}

ScreenTask8A::~ScreenTask8A() {
    delete ui;
}

void ScreenTask8A::init() {
    QString f1;
    QString f2;
    if (ScreenController::store.count("task7a_f1") && ScreenController::store.count("task7a_f2")) {
        f1 = ScreenController::store.at("task7a_f1");
        f2 = ScreenController::store.at("task7a_f2");
    } else {
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
    }
    QString f1s = "";
    for (int j = f1.size() - 1; j < 2 * f1.size() - 1; j++) {
        f1s.append(f1.at(j % f1.size()));
    }
    fg1 = Static::getXOR(f1, f2);
    fg2 = Static::getXOR(f1s, f2);
    // setup ui
    QString title = ui->title->text();
    title = title.replace("%f1%", f1);
    title = title.replace("%f2%", f2);
    ui->title->setText(title);
    if (readOnly) {
        ui->inputFG1->setText(fg1);
        ui->inputFG2->setText(fg2);
        ui->inputFG1->setReadOnly(true);
        ui->inputFG2->setReadOnly(true);
    }
}

bool ScreenTask8A::validate(Core* core, QString* message) {
    if (readOnly) {
        return true;
    }
    if (
            fg1.left(10) == ui->inputFG1->text().left(10) &&
            fg2.left(10) == ui->inputFG2->text().left(10)
    ) {
        message->append(Static::messageAnswerRight);
        core->changeScore(2);
    } else {
        message->append(Static::messageAnswerWrong);
        core->changeScore(-2);
    }
    return true;
}
