#include "screentask8c.h"
#include "ui_screentask8c.h"

ScreenTask8C::ScreenTask8C(QWidget *parent) : ScreenController(parent), ui(new Ui::ScreenTask8C) {
    ui->setupUi(this);
}

ScreenTask8C::~ScreenTask8C() {
    delete ui;
}

void ScreenTask8C::init() {
    QString f1;
    QString f2;
    QString fg1;
    QString fg2;
    std::vector<int> pvkf;
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
    pvkf = Static::getPVKF(fg1, fg2, 31);
    ChartView *chart = new ChartView(this);
    for (int i = 0; i < 31; i++) {
        chart->addPoint(i, pvkf.at(i));
        if (map.count(pvkf.at(i))) {
            map.at(pvkf.at(i))++;
        } else {
            map.insert({pvkf.at(i), 1});
        }
    }
    chart->draw();
    ui->charts->addWidget(chart);
    if (readOnly) {
        int i = 0;
        for (const auto& el : map) {
            switch (i++) {
            case 0:
                ui->inputR1->setText(QString::number(el.first));
                ui->inputN1->setText(QString::number(el.second));
                break;
            case 1:
                ui->inputR2->setText(QString::number(el.first));
                ui->inputN2->setText(QString::number(el.second));
                break;
            case 2:
                ui->inputR3->setText(QString::number(el.first));
                ui->inputN3->setText(QString::number(el.second));
                break;
            }
        }
        ui->inputR1->setReadOnly(true);
        ui->inputN1->setReadOnly(true);
        ui->inputR2->setReadOnly(true);
        ui->inputN2->setReadOnly(true);
        ui->inputR3->setReadOnly(true);
        ui->inputN3->setReadOnly(true);
    }
}

bool ScreenTask8C::validate(Core* core, QString* message) {
    if (readOnly) {
        return true;
    }
    bool valid = true;
    for (const auto& el : map) {
        for (int i = 0; i < 3; i++) {
            switch (i) {
            case 0:
                if (ui->inputR1->text() == QString::number(el.first) &&
                    ui->inputN1->text() == QString::number(el.second)) {
                    goto next;
                }
                break;
            case 1:
                if (ui->inputR2->text() == QString::number(el.first) &&
                    ui->inputN2->text() == QString::number(el.second)) {
                    goto next;
                }
                break;
            case 2:
                if (ui->inputR3->text() == QString::number(el.first) &&
                    ui->inputN3->text() == QString::number(el.second)) {
                    goto next;
                }
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
