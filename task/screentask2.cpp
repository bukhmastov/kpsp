#include "screentask2.h"
#include "ui_screentask2.h"

ScreenTask2::ScreenTask2(QWidget *parent) : ScreenController(parent), ui(new Ui::ScreenTask2) {
    ui->setupUi(this);
}

ScreenTask2::~ScreenTask2() {
    delete ui;
}

void ScreenTask2::init() {
    QString h;
    QString f;
    for (int i = 0; i < 8; i++) {
        rm1.push_back(0);
        rm2.push_back(0);
        rm3.push_back(0);
    }
    // М-последовательность
    switch (rnd() % 2) {
    case 0: h = "1101"; break;
    case 1: h = "1011"; break;
    }
    rm1 = Static::getAAKF(Static::getMSequence(h, 7), 7);
    ui->title1->setText(ui->title1->text().replace("%h%", Static::getReadablePolynom(h)));
    if (readOnly) {
        ui->input11->setText(QString::number(rm1.at(0)));
        ui->input12->setText(QString::number(rm1.at(1)));
        ui->input13->setText(QString::number(rm1.at(2)));
        ui->input14->setText(QString::number(rm1.at(3)));
        ui->input15->setText(QString::number(rm1.at(4)));
        ui->input16->setText(QString::number(rm1.at(5)));
        ui->input17->setText(QString::number(rm1.at(6)));
        ui->input18->setText(QString::number(rm1.at(7)));
        ChartView *chart = new ChartView(this);
        for (int i = 0; i < 8; i++) {
            chart->addPoint(i, rm1.at(i));
        }
        chart->draw();
        ui->charts->addWidget(chart);
        ui->input11->setReadOnly(true);
        ui->input12->setReadOnly(true);
        ui->input13->setReadOnly(true);
        ui->input14->setReadOnly(true);
        ui->input15->setReadOnly(true);
        ui->input16->setReadOnly(true);
        ui->input17->setReadOnly(true);
        ui->input18->setReadOnly(true);
    }
    // последовательность Баркера
    f = "1110010";
    rm2 = Static::getAAKF(f, 7);
    ui->title2->setText(ui->title2->text().replace("%f2%", f));
    if (readOnly) {
        ui->input21->setText(QString::number(rm2.at(0)));
        ui->input22->setText(QString::number(rm2.at(1)));
        ui->input23->setText(QString::number(rm2.at(2)));
        ui->input24->setText(QString::number(rm2.at(3)));
        ui->input25->setText(QString::number(rm2.at(4)));
        ui->input26->setText(QString::number(rm2.at(5)));
        ui->input27->setText(QString::number(rm2.at(6)));
        ui->input28->setText(QString::number(rm2.at(7)));
        ChartView *chart = new ChartView(this);
        for (int i = 0; i < 8; i++) {
            chart->addPoint(i, rm2.at(i));
        }
        chart->draw();
        ui->charts->addWidget(chart);
        ui->input21->setReadOnly(true);
        ui->input22->setReadOnly(true);
        ui->input23->setReadOnly(true);
        ui->input24->setReadOnly(true);
        ui->input25->setReadOnly(true);
        ui->input26->setReadOnly(true);
        ui->input27->setReadOnly(true);
        ui->input28->setReadOnly(true);
    }
    // произвольная последовательность
    switch (rnd() % 4) {
    case 0: f = "1010101"; break;
    case 1: f = "1100110"; break;
    case 2: f = "0111100"; break;
    case 3: f = "0100110"; break;
    }
    rm3 = Static::getAAKF(f, 7);
    ui->title3->setText(ui->title3->text().replace("%f3%", f));
    if (readOnly) {
        ui->input31->setText(QString::number(rm3.at(0)));
        ui->input32->setText(QString::number(rm3.at(1)));
        ui->input33->setText(QString::number(rm3.at(2)));
        ui->input34->setText(QString::number(rm3.at(3)));
        ui->input35->setText(QString::number(rm3.at(4)));
        ui->input36->setText(QString::number(rm3.at(5)));
        ui->input37->setText(QString::number(rm3.at(6)));
        ui->input38->setText(QString::number(rm3.at(7)));
        ChartView *chart = new ChartView(this);
        for (int i = 0; i < 8; i++) {
            chart->addPoint(i, rm3.at(i));
        }
        chart->draw();
        ui->charts->addWidget(chart);
        ui->input31->setReadOnly(true);
        ui->input32->setReadOnly(true);
        ui->input33->setReadOnly(true);
        ui->input34->setReadOnly(true);
        ui->input35->setReadOnly(true);
        ui->input36->setReadOnly(true);
        ui->input37->setReadOnly(true);
        ui->input38->setReadOnly(true);
    }
}

bool ScreenTask2::validate(Core* core, QString* message) {
    if (readOnly) {
        return true;
    }
    if (
            ui->input11->text().toInt() == rm1.at(0) &&
            ui->input12->text().toInt() == rm1.at(1) &&
            ui->input13->text().toInt() == rm1.at(2) &&
            ui->input14->text().toInt() == rm1.at(3) &&
            ui->input15->text().toInt() == rm1.at(4) &&
            ui->input16->text().toInt() == rm1.at(5) &&
            ui->input17->text().toInt() == rm1.at(6) &&
            ui->input18->text().toInt() == rm1.at(7) &&

            ui->input21->text().toInt() == rm2.at(0) &&
            ui->input22->text().toInt() == rm2.at(1) &&
            ui->input23->text().toInt() == rm2.at(2) &&
            ui->input24->text().toInt() == rm2.at(3) &&
            ui->input25->text().toInt() == rm2.at(4) &&
            ui->input26->text().toInt() == rm2.at(5) &&
            ui->input27->text().toInt() == rm2.at(6) &&
            ui->input28->text().toInt() == rm2.at(7) &&

            ui->input31->text().toInt() == rm3.at(0) &&
            ui->input32->text().toInt() == rm3.at(1) &&
            ui->input33->text().toInt() == rm3.at(2) &&
            ui->input34->text().toInt() == rm3.at(3) &&
            ui->input35->text().toInt() == rm3.at(4) &&
            ui->input36->text().toInt() == rm3.at(5) &&
            ui->input37->text().toInt() == rm3.at(6) &&
            ui->input38->text().toInt() == rm3.at(7)
    ) {
        message->append(Static::messageAnswerRight);
        core->changeScore(2);
    } else {
        message->append(Static::messageAnswerWrong);
        core->changeScore(-2);
    }
    return true;
}
