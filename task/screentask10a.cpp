#include "screentask10a.h"
#include "ui_screentask10a.h"

ScreenTask10A::ScreenTask10A(QWidget *parent) : ScreenController(parent), ui(new Ui::ScreenTask10A) {
    ui->setupUi(this);
}

ScreenTask10A::~ScreenTask10A() {
    delete ui;
}

void ScreenTask10A::init() {
    QString n;
    switch(rnd() % 2) {
    case 0: n = "63"; r.append("-1"); r.append("7"); r.append("-9"); r.append("15"); r.append("-17"); break;
    case 1: n = "255"; r.append("-1"); r.append("15"); r.append("-17"); r.append("31"); r.append("-33"); break;
    }
    // setup ui
    ui->title->setText(ui->title->text().replace("%n%", n));
    if (readOnly) {
        int i = 0;
        for (const auto& el : r) {
            switch (i++) {
            case 0: ui->inputR1->setText(el); break;
            case 1: ui->inputR2->setText(el); break;
            case 2: ui->inputR3->setText(el); break;
            case 3: ui->inputR4->setText(el); break;
            case 4: ui->inputR5->setText(el); break;
            }
        }
        ui->inputR1->setReadOnly(true);
        ui->inputR2->setReadOnly(true);
        ui->inputR3->setReadOnly(true);
        ui->inputR4->setReadOnly(true);
        ui->inputR5->setReadOnly(true);
    }
}

bool ScreenTask10A::validate(Core* core, QString* message) {
    if (readOnly) {
        return true;
    }
    bool valid = true;
    for (const auto& el : r) {
        for (int i = 0; i < 5; i++) {
            switch (i) {
            case 0:
                if (ui->inputR1->text() == el) goto next;
                break;
            case 1:
                if (ui->inputR2->text() == el) goto next;
                break;
            case 2:
                if (ui->inputR3->text() == el) goto next;
                break;
            case 3:
                if (ui->inputR4->text() == el) goto next;
                break;
            case 4:
                if (ui->inputR5->text() == el) goto next;
                break;
            }
        }
        valid = false;
        next:;
    }
    if (valid) {
        message->append(Static::messageAnswerRight);
        core->changeScore(2);
    } else {
        message->append(Static::messageAnswerWrong);
        core->changeScore(-2);
    }
    return true;
}
