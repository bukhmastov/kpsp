#include "screenquestion.h"
#include "ui_screenquestion.h"
#include "view/questionanswerlabel.h"

ScreenQuestion::ScreenQuestion(QWidget *parent) : ScreenController(parent), ui(new Ui::ScreenQuestion) {
    ui->setupUi(this);
}

ScreenQuestion::~ScreenQuestion() {
    delete ui;
}

void ScreenQuestion::init() {
    ui->questionLabel->setText(question->getQustion());
    unsigned int start = rnd() % question->getAnswers().size();
    for (unsigned int i = start; i < question->getAnswers().size() + start; i++) {
        int index = i % question->getAnswers().size();
        QuestionAnswerLabel *label = new QuestionAnswerLabel;
        label->setText(question->getAnswers().at(index));
        if (readOnly && index == 0) {
            QFont font = label->font();
            font.setBold(true);
            label->setFont(font);
        }
        ui->answersLayout->addWidget(label);
        if (!readOnly) {
            QObject::connect(label, &QuestionAnswerLabel::clicked, this, index == 0 ? &ScreenQuestion::onRightAnswer : &ScreenQuestion::onWrongAnswer);
        }
    }
}

ScreenQuestion* ScreenQuestion::get(Core* core, Question* question) {
    ScreenQuestion *screen = new ScreenQuestion;
    screen->core = core;
    screen->question = question;
    return screen;
}

void ScreenQuestion::onRightAnswer() {
    this->status = true;
    this->core->next();
}

void ScreenQuestion::onWrongAnswer() {
    this->status = false;
    this->core->next();
}

bool ScreenQuestion::validate(Core* core, QString* message) {
    if (readOnly) {
        return true;
    }
    core->changeScore(status ? Static::score4quetion : -Static::score4quetion);
    message->append(status ? Static::messageAnswerRight : Static::messageAnswerWrong);
    return true;
}
