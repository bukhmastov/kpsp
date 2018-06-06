#include "screentask10b.h"
#include "ui_screentask10b.h"

ScreenTask10B::ScreenTask10B(QWidget *parent) : ScreenController(parent), ui(new Ui::ScreenTask10B) {
    ui->setupUi(this);
}

ScreenTask10B::~ScreenTask10B() {
    delete ui;
}

void ScreenTask10B::init() {
    QString h1;
    QString h2;
    QString h3;
    switch (rnd() % 6) {
    case 0: h1 = "1100001"; h2 = "1110011"; h3 = "1011"; break; // 1  17 9
    case 1: h1 = "1110011"; h2 = "1011011"; h3 = "1101"; break; // 5  22 27
    case 2: h1 = "1011011"; h2 = "1000011"; h3 = "1011"; break; // 11 61 9
    case 3: h1 = "1101101"; h2 = "1100001"; h3 = "1101"; break; // 13 32 27
    case 4: h1 = "1100111"; h2 = "1101101"; h3 = "1011"; break; // 23 13 9
    case 5: h1 = "1000011"; h2 = "1100111"; h3 = "1101"; break; // 31 23 27
    }
    QString m31i, m32i;
    do {
        m31i = getRandInitialSymbols();
        m32i = getRandInitialSymbols();
    } while (m31i == m32i);
    QString m1 = Static::getMSequence(h1, 63);
    QString m2 = Static::getMSequence(h2, 63);
    QString m31 = Static::getMSequence(h3, m31i, 7);
    QString m32 = Static::getMSequence(h3, m32i, 7);
    std::vector<int> pvkf = Static::getPVKF(
        Static::getXOR(Static::getXOR(m1, m2), m31),
        Static::getXOR(Static::getXOR(m1, m2), m32),
        63
    );
    ChartView *chart = new ChartView(this);
    for (int i = 0; i < 63; i++) {
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
            case 3:
                ui->inputR4->setText(QString::number(el.first));
                ui->inputN4->setText(QString::number(el.second));
                break;
            case 4:
                ui->inputR5->setText(QString::number(el.first));
                ui->inputN5->setText(QString::number(el.second));
                break;
            }
        }
        ui->inputR1->setEnabled(false);
        ui->inputN1->setEnabled(false);
        ui->inputR2->setEnabled(false);
        ui->inputN2->setEnabled(false);
        ui->inputR3->setEnabled(false);
        ui->inputN3->setEnabled(false);
        ui->inputR4->setEnabled(false);
        ui->inputN4->setEnabled(false);
        ui->inputR5->setEnabled(false);
        ui->inputN5->setEnabled(false);
    }
}

QString ScreenTask10B::getRandInitialSymbols() {
    int c0, c1, c2;
    do {
        c0 = rnd() % 2;
        c1 = rnd() % 2;
        c2 = rnd() % 2;
    } while (c0 == 0 && c1 == 0 && c2 == 0);
    return QString::number(c0) + QString::number(c1) + QString::number(c2);
}

bool ScreenTask10B::validate(Core* core, QString* message) {
    if (readOnly) {
        return true;
    }
    bool valid = true;
    for (const auto& el : map) {
        for (int i = 0; i < 5; i++) {
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
            case 3:
                if (ui->inputR4->text() == QString::number(el.first) &&
                    ui->inputN4->text() == QString::number(el.second)) {
                    goto next;
                }
                break;
            case 4:
                if (ui->inputR5->text() == QString::number(el.first) &&
                    ui->inputN5->text() == QString::number(el.second)) {
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
