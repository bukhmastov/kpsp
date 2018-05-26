#include "screentask8b.h"
#include "ui_screentask8b.h"

ScreenTask8B::ScreenTask8B(QWidget *parent) : ScreenController(parent), ui(new Ui::ScreenTask8B) {
    ui->setupUi(this);
}

ScreenTask8B::~ScreenTask8B() {
    delete ui;
}

void ScreenTask8B::init() {
    QString f1;
    QString f2;
    QString fg1;
    QString fg2;
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
    for (int i = 0; i < 2; i++) {
        m.push_back(-1);
    }
    for (int i = 0; i < 2;) {
        int mI = rnd() % 4;
        if (mI > 1) {
            mI = 31 - mI % 2;
        }
        for (int j = 0; j < 2; j++) {
            if (m.at(j) == mI) {
                goto next;
            }
        }
        m[i++] = mI;
        next:;
    }
    QString f1s = "";
    for (int j = f1.size() - 1; j < 2 * f1.size() - 1; j++) {
        f1s.append(f1.at(j % f1.size()));
    }
    fg1 = Static::getXOR(f1, f2);
    fg2 = Static::getXOR(f1s, f2);
    pvkf = Static::getPVKF(fg1, fg2, 31);
    // setup ui
    QString title = ui->title->text();
    title = title.replace("%m1%", QString::number(m.at(0)));
    title = title.replace("%m2%", QString::number(m.at(1)));
    title = title.replace("%fg1%", fg1);
    title = title.replace("%fg2%", fg2);
    ui->title->setText(title);
    ui->labelR12m1->setText(ui->labelR12m1->text().replace("%m1%", QString::number(m.at(0))));
    ui->labelR12m2->setText(ui->labelR12m2->text().replace("%m2%", QString::number(m.at(1))));
    if (readOnly) {
        ui->inputR12m1->setText(QString::number(pvkf.at(m.at(0))));
        ui->inputR12m2->setText(QString::number(pvkf.at(m.at(1))));
        ChartView *chart = new ChartView(this);
        for (int i = 0; i < 31; i++) {
            chart->addPoint(i, pvkf.at(i));
        }
        chart->draw();
        ui->charts->addWidget(chart);
    }
}

bool ScreenTask8B::validate(Core* core, QString* message) {
    if (readOnly) {
        return true;
    }
    if (
            QString::number(pvkf.at(m.at(0))) == ui->inputR12m1->text() &&
            QString::number(pvkf.at(m.at(1))) == ui->inputR12m2->text()
    ) {
        message->append(Static::messageAnswerRight);
        core->changeScore(2);
    } else {
        message->append(Static::messageAnswerWrong);
        core->changeScore(-2);
    }
    return true;
}
