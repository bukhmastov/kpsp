#include "screentask9b.h"
#include "ui_screentask9b.h"

ScreenTask9B::ScreenTask9B(QWidget *parent) : ScreenController(parent), ui(new Ui::ScreenTask9B) {
    ui->setupUi(this);
}

ScreenTask9B::~ScreenTask9B() {
    delete ui;
}

void ScreenTask9B::init() {
    QString h1;
    QString h2;
    switch (rnd() % 6) {
    case 0: h1 = "1100001"; h2 = "1011"; break; // 1  9
    case 1: h1 = "1110011"; h2 = "1101"; break; // 5  27
    case 2: h1 = "1011011"; h2 = "1011"; break; // 11 9
    case 3: h1 = "1101101"; h2 = "1101"; break; // 13 27
    case 4: h1 = "1100111"; h2 = "1011"; break; // 23 9
    case 5: h1 = "1000011"; h2 = "1101"; break; // 31 27
    }
    QString m21i, m22i;
    do {
        m21i = getRandInitialSymbols();
        m22i = getRandInitialSymbols();
    } while (m21i == m22i);
    QString m1 = Static::getMSequence(h1, 63);
    QString m21 = Static::getMSequence(h2, m21i, 7);
    QString m22 = Static::getMSequence(h2, m22i, 7);
    std::vector<int> pvkf = Static::getPVKF(
        Static::getXOR(m1, m21),
        Static::getXOR(m1, m22),
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
            }
        }
        ui->inputR1->setEnabled(false);
        ui->inputN1->setEnabled(false);
        ui->inputR2->setEnabled(false);
        ui->inputN2->setEnabled(false);
        ui->inputR3->setEnabled(false);
        ui->inputN3->setEnabled(false);
    }
}

QString ScreenTask9B::getRandInitialSymbols() {
    int c0, c1, c2;
    do {
        c0 = rnd() % 2;
        c1 = rnd() % 2;
        c2 = rnd() % 2;
    } while (c0 == 0 && c1 == 0 && c2 == 0);
    return QString::number(c0) + QString::number(c1) + QString::number(c2);
}

bool ScreenTask9B::validate(Core* core, QString* message) {
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
