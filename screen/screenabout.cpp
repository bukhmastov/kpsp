#include "screenabout.h"
#include "ui_screenabout.h"

ScreenAbout::ScreenAbout(QWidget *parent) : ScreenController(parent), ui(new Ui::ScreenAbout) {
    ui->setupUi(this);
}

ScreenAbout::~ScreenAbout() {
    delete ui;
}

void ScreenAbout::init() {}

bool ScreenAbout::validate(Core*, QString*) {
    return true;
}
