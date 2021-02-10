#include "screenwelcome.h"
#include "ui_screenwelcome.h"

ScreenWelcome::ScreenWelcome(QWidget *parent) : ScreenController(parent), ui(new Ui::ScreenWelcome) {
    ui->setupUi(this);
}

ScreenWelcome::~ScreenWelcome() {
    delete ui;
}

void ScreenWelcome::init() {
    ui->header->setText(Static::worktype);
}

bool ScreenWelcome::validate(Core*, QString*) {
    return true;
}
