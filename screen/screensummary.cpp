#include "screensummary.h"
#include "ui_screensummary.h"
#include <ctime>

ScreenSummary::ScreenSummary(QWidget *parent) : ScreenController(parent), ui(new Ui::ScreenSummary) {
    ui->setupUi(this);
}

ScreenSummary::~ScreenSummary() {
    delete ui;
}

ScreenSummary* ScreenSummary::get(Core *core) {
    ScreenSummary *screen = new ScreenSummary;
    QString mark = "";
    if (core->getScore() >= 85) {
        mark = "Отлично";
    } else if (core->getScore() >= 68) {
        mark = "Хорошо";
    } else if (core->getScore() >= 50) {
        mark = "Удовлетворительно";
    } else {
        mark = "Неудовлетворительно";
    }
    time_t now = time(0);
    tm *ltm = localtime(&now);
    QString date = QString::number(ltm->tm_mday) + "." + QString::number(1 + ltm->tm_mon) + "." + QString::number(1900 + ltm->tm_year) + " " + QString::number(ltm->tm_hour) + ":" + QString::number(ltm->tm_min);
    //delete ltm;
    screen->ui->score->setText(QString::number(core->getScore()));
    screen->ui->mark->setText(mark);
    screen->ui->date->setText(screen->ui->date->text().replace("%date%", date));
    screen->ui->seed->setText(screen->ui->seed->text().replace("%seed%", QString::number(core->getSeed())));
    return screen;
}

void ScreenSummary::init() {}

bool ScreenSummary::validate(Core*, QString*) {
    return false;
}
