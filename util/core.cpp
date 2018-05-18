#include "core.h"
#include "screen/screenwelcome.h"
#include "screen/screenabout.h"
#include "screen/screendescription.h"
#include "screen/screenquestion.h"
#include "screen/screensummary.h"
#include "task/screentask1.h"
#include "task/screentask2.h"
#include "task/screentask3.h"
#include "task/screentask4.h"
#include "task/screentask5.h"
#include "task/screentask6.h"
#include "task/ScreenTask7a.h"
#include "task/ScreenTask7b.h"
#include <iostream>
#include <chrono>
#include <algorithm>

Core::Core() {}

void Core::init(WindowController *window) {
    this->window = window;
}

void Core::generate() {
    std::chrono::milliseconds msec = std::chrono::duration_cast<std::chrono::milliseconds>(
        std::chrono::system_clock::now().time_since_epoch()
    );
    generate(msec.count());
}

void Core::generate(unsigned int seed) {
    // clear questions
    for (Question* question : this->questions) {
        delete question;
    }
    this->questions.clear();
    // clear tasks
    for (Task* task : this->tasks) {
        delete task;
    }
    this->tasks.clear();
    // reset progress
    this->questionsOrder.clear();
    this->currentTask = 0;
    this->showedTask = 0;
    this->score = Static::scoreInitial;
    this->seed = seed;
    ScreenController::clean();
    ScreenController::srnd(seed);
    // ------------------------------
    // HERE GOES DEFINITIONS OF QUESTIONS
    // EVERY QUESTION SHOULD BE ADDED TO QUESTIONS VECTOR BELOW
    // SHOULD BE MINIMUM 10 QUESTIONS
    // ------------------------------
    questions.push_back(new Question("Назовите основные виды корреляционных функций", std::vector<QString>{"Периодическая, апериодическая, автокорреляционная, взаимно корреляционная функция", "Циклическая, нециклическая, автокорреляционная, взаимно корреляционная функция", "Симметричная, асимметричная, автокорреляционная, взаимно корреляционная функция", "Стационарная, нестационарная, автокорреляционная, взаимно корреляционная функция"}));
    questions.push_back(new Question("Определить расстояние между концами векторов a1=exp(j2п/3) и a2=exp(j4п/3) в пространстве Евклида", std::vector<QString>{"√3", "√3/2", "√2", "√2/2"}));
    questions.push_back(new Question("Чему равен угол между соседними векторами для пятиричного комплекснозначного алфавита в пространстве Евклида?", std::vector<QString>{"72 град", "90 град", "60 град", "30 град"}));
    questions.push_back(new Question("Чему равен комплексно сопряженный элемент для элемента а=exp(j8п/5)?", std::vector<QString>{"exp(j2п/5)", "exp(j4п/5)", "exp(j3п/5)", "exp(jп/5)"}));
    questions.push_back(new Question("Определить значение ненормированной периодической ВКФ R12(m) двоичных ПСП для сдвига m=0 в пространстве Евклида:\nА1 = {a0 a1 a1 a0 a1 a0 a0}\nА2 = {a1 a0 a1 a1 a0 a0 a1}", std::vector<QString>{"R12(0)=-3", "R12(0)=-1", "R12(0)=+1", "R12(0)=+3"}));
    questions.push_back(new Question("Определить значение ненормированной периодической ВКФ R12(m) для двух троичных ПСП с алфавитом: a0=1, a1=exp(j2п/3), a2=exp(j4п/3) – для сдвига m=0 в пространстве Евклида:\nА1 = {a0 a1 a2 a0}\nА2 = {a1 a0 a0 a2}", std::vector<QString>{"R12(0)=-2", "R12(0)=-1", "R12(0)= 0", "R12(0)=+1"}));
    questions.push_back(new Question("Определить расстояние между двумя последовательностями в метрике Хэмминга для сдвига m=0:\nА1 = {0110100}\nА2 = {0101101}", std::vector<QString>{"D12=3", "D12=1", "D12=2", "D12=0"}));
    questions.push_back(new Question("Определить в метрике Ли расстояние между двумя 5-ричными последовательностями для сдвига m=0:\nА1 = {0140302}\nА2 = {1403101}", std::vector<QString>{"D12=9", "D12=8", "D12=7", "D12=10"}));
    questions.push_back(new Question("Определить значение ненормированной периодической ВКФ R12(m) троичных ПСП с периодом N=7 для сдвига m=0 в пространстве Ли:\nА1={1 1 2 1 2 1 0}\nА2={1 0 2 1 0 2 0}", std::vector<QString>{"R12(0)=3", "R12(0)=2", "R12(0)=1", "R12(0)=-1"}));
    questions.push_back(new Question("Определить значение ненормированной периодической ВКФ R12(m) двоичных ПСП с периодом N=7 для сдвига m=0 в пространстве Хэмминга:\nА1={1 1 0 1 0 1 0}\nА2={1 0 0 1 1 1 0} ", std::vector<QString>{"R12(0)=3", "R12(0)=4", "R12(0)=2", "R12(0)=1"}));
    questions.push_back(new Question("Для последовательности А = 02110122 определить диадный сдвиг на m=5", std::vector<QString>{"А(5)=10222011", "А(5)=01220211", "А(5)=20110122", "А(5)=10221120"}));
    questions.push_back(new Question("Для последовательности А = 02110122 определить диадный сдвиг на m=1", std::vector<QString>{"A(1)=20111022", "A(1)=20112201", "A(1)=20011122", "A(1)=20102201"}));
    questions.push_back(new Question("Для последовательности А = 021101221 определить триадный сдвиг на m=6", std::vector<QString>{"A(6)=101221021", "A(6)=210011212", "A(6)=221021012", "A(6)=221021101"}));
    questions.push_back(new Question("Определение М-последовательности с периодом N=63", std::vector<QString>{"Это двоичная ПСП с периодом N = 2<sup>6</sup>–1, построенная над полем Галуа GF(2<sup>6</sup>) и имеющая двухуровневую ПАКФ", "Это двоичная ПСП с периодом N = 2<sup>4</sup>–1, построенная над полем Галуа GF(2<sup>4</sup>) и имеющая одноуровневую ПАКФ", "Это двоичная ПСП с периодом N = 2<sup>6</sup>–1, построенная над полем Галуа GF(2<sup>4</sup>) и имеющая двухуровневую ПАКФ", "Это двоичная ПСП с периодом N = 2<sup>6</sup>–1, построенная над полем Галуа GF(2<sup>6</sup>) и имеющая трехуровневую ПАКФ"}));
    questions.push_back(new Question("В поле Галуа характеристики p=3 задан проверочный примитивный полином h(x)=x<sup>4</sup>+2x<sup>3</sup>+x<sup>2</sup>+2. Чему равен период формируемой ПСП?", std::vector<QString>{"N=80", "N=40", "N=20", "N=32"}));
    questions.push_back(new Question("В поле Галуа характеристики p=3 задан проверочный примитивный полином h(x)=x<sup>4</sup>+2x<sup>3</sup>+x<sup>2</sup>+2. Сколько сумматоров по модулю 3 содержит схема формирования МП?", std::vector<QString>{"2", "1", "3", "4"}));
    questions.push_back(new Question("В поле Галуа характеристики p=3 задан проверочный примитивный полином h(x)=x<sup>4</sup>+2x<sup>3</sup>+x<sup>2</sup>+2. Сколько умножителей содержит схема формирования МП, исключая умножители на 1?", std::vector<QString>{"1", "3", "2", "4"}));
    questions.push_back(new Question("Чему равен коэффициент корреляции последовательностей Уолша, являющихся первой и четвертой строками (начиная с первой) матрицы Адамара третьего порядка, для сдвига m=0?", std::vector<QString>{"R1,2=0", "R1,2=1", "R1,2=-1", "R1,2=0.5"}));
    questions.push_back(new Question("Над полем GF(2<sup>3</sup>) сформировать М-последовательность для примитивного полинома h(x)=x<sup>3</sup>+x<sup>2</sup>+1 для начального состояния С0 = 1, С1 = 1, С2 = 1", std::vector<QString>{"1110100", "1110010", "1110101", "1110011"}));
    questions.push_back(new Question("Над полем GF(3<sup>2</sup>) сформировать троичную МП для примитивного полинома h(x)=x<sup>2</sup>+2x+2 при условии С0 = 1, С1 = 1", std::vector<QString>{"11202210", "11021201", "11201022", "11021110"}));
    questions.push_back(new Question("Чему равна степень проверочного полинома последовательностей Голда с периодом N=127?", std::vector<QString>{"14", "12", "10", "8"}));
    questions.push_back(new Question("Чему равна степень проверочного полинома последовательностей малого множества Касами с периодом N=255?", std::vector<QString>{"12", "16", "14", "8"}));
    questions.push_back(new Question("Чему равна степень проверочного полинома последовательностей большого множества Касами с периодом N=1023?", std::vector<QString>{"25", "24", "10", "16"}));
    questions.push_back(new Question("Чему равна максимальная длина блока, состоящего из одних нулей, в М-последовательности с периодом N=255?", std::vector<QString>{"7", "8", "6", "5"}));
    questions.push_back(new Question("Чему равна максимальная длина блока, состоящего из одних единиц, в М-последовательности с периодом N=1023?", std::vector<QString>{"10", "9", "8", "6"}));
    questions.push_back(new Question("Какие значения может принимать ненормированная ААКФ последовательностей Баркера?", std::vector<QString>{"(-1, 0, +1)", "(-1, 0, +1, +2)", "(-2, -1, 0, +1)", "(-1, +1)"}));
    questions.push_back(new Question("Чему равно число последовательностей Уолша с периодом N=16?", std::vector<QString>{"16", "15", "8", "4"}));
    questions.push_back(new Question("Полиномы h1(x) и h2(x) задают предпочтительную пару М-последовательностей с периодом N=63, элемент а<sup>5</sup> поля GF(2<sup>6</sup>) – один из корней полинома h1(x). Определить корень полинома h2(x).", std::vector<QString>{"а<sup>2</sup>2", "а<sup>2</sup>0", "а<sup>1</sup>8", "а<sup>1</sup>5"}));
    questions.push_back(new Question("Полиномы h1(x) и h2(x) являются сомножителями проверочного полинома малого множества Касами с периодом N=63, элемент а<sup>5</sup> поля GF(2<sup>6</sup>) – один из корней примитивного полинома h1(x). Определить корень полинома h2(x).", std::vector<QString>{"а<sup>4</sup>5", "а<sup>5</sup>4", "а<sup>5</sup>5", "а<sup>3</sup>5"}));
    questions.push_back(new Question("Для последовательности F = 10111001 при диадном сдвиге получили F1 = 11100110. Определить значение сдвига m.", std::vector<QString>{"m=2", "m=4", "m=1", "m=3"}));
    questions.push_back(new Question("Для последовательности F = 101110010 при триадном сдвиге получили F1 = 010101110. Определить значение сдвига m.", std::vector<QString>{"m=3", "m=4", "m=2", "m=1"}));
    questions.push_back(new Question("Представить число 14 в троичной системе счисления.", std::vector<QString>{"112", "121", "211", "212"}));
    questions.push_back(new Question("Чему равно максимальное значение модуля бокового пика ПВКФ последовательностей Голда с периодом N=63?", std::vector<QString>{"17", "15", "13", "21"}));
    questions.push_back(new Question("Чему равно максимальное значение модуля бокового пика ПВКФ последовательностей малого множества Касами с периодом N=63?", std::vector<QString>{"9", "7", "11", "5"}));
    questions.push_back(new Question("Чему равно максимальное значение модуля бокового пика ПВКФ последовательностей большого множества Касами с периодом N=63?", std::vector<QString>{"17", "15", "13", "21"}));
    // ------------------------------
    unsigned int size = questions.size() < 10 ? questions.size() : 10;
    while (true) {
        int current = rand() % questions.size();
        if (!(std::find(questionsOrder.begin(), questionsOrder.end(), current) != questionsOrder.end())) {
            questionsOrder.push_back(current);
        }
        if (questionsOrder.size() >= size) {
            break;
        }
    }
    // ------------------------------
    // HERE GOES DEFINITIONS OF TASKS
    // EVERY TASK SHOULD BE ADDED TO TASKS VECTOR BELOW
    // TASK'S VIEWS DEFINES AT Core::getView(int id)
    // ------------------------------
    // intro part
    /*tasks.push_back(new Task(0,  0,  "Практическое занятие"));
    tasks.push_back(new Task(1,  0,  "Практическое занятие"));
    tasks.push_back(new Task(2,  0,  "Практическое занятие"));
    // questions part
    /*
    tasks.push_back(new Task(3,  1,  "Входной контрольный опрос: вопрос 1",  false));
    tasks.push_back(new Task(4,  2,  "Входной контрольный опрос: вопрос 2",  false));
    tasks.push_back(new Task(5,  3,  "Входной контрольный опрос: вопрос 3",  false));
    tasks.push_back(new Task(6,  4,  "Входной контрольный опрос: вопрос 4",  false));
    tasks.push_back(new Task(7,  5,  "Входной контрольный опрос: вопрос 5",  false));
    tasks.push_back(new Task(8,  6,  "Входной контрольный опрос: вопрос 6",  false));
    tasks.push_back(new Task(9,  7,  "Входной контрольный опрос: вопрос 7",  false));
    tasks.push_back(new Task(10, 8,  "Входной контрольный опрос: вопрос 8",  false));
    tasks.push_back(new Task(11, 9,  "Входной контрольный опрос: вопрос 9",  false));
    tasks.push_back(new Task(12, 10, "Входной контрольный опрос: вопрос 10", false));
    */
    // tasks part
    //tasks.push_back(new Task(13, 1,  "Определение ПАКФ ПСП с периодом N=7"));
    //tasks.push_back(new Task(14, 2,  "Определение ААКФ ПСП с периодом N=7"));
    //tasks.push_back(new Task(15, 3,  "Определение ПАКФ и ААКФ последовательностей Уолша"));
    //tasks.push_back(new Task(16, 4,  "Определение ПАКФ последовательностей Уолша при диадном сдвиге"));
    //tasks.push_back(new Task(17, 5,  "Определение ПАКФ троичной М-последовательности"));
    //tasks.push_back(new Task(18, 6,  "Определение ПАКФ троичной М-последовательности при диадном сдвиге"));
    //tasks.push_back(new Task(19, 7,  "А) Определение ПВКФ предпочтительной пары МП"));
    tasks.push_back(new Task(20, 7,  "Б) Определение ПВКФ предпочтительной пары МП"));

    // summary part
    tasks.push_back(new Task(99, 0, "Результат", false));
    // ------------------------------
    window->setMaxProgress(tasks.size());
    window->setNextEnabled(true);
    window->setResetEnabled(true);
}

ScreenController* Core::getView(int id) {
    // ------------------------------
    // HERE GOES VIEWS OF TASKS
    // EVERY TASK VIEW SHOULD BE ADDED BELOW
    // ------------------------------
    switch (id) {
        // intro part
        case 0:  return new ScreenWelcome; break;
        case 1:  return new ScreenAbout; break;
        case 2:  return new ScreenDescription; break;
        // questions part
        case 3:  return ScreenQuestion::get(this, questions.at(questionsOrder.at(0))); break;
        case 4:  return ScreenQuestion::get(this, questions.at(questionsOrder.at(1))); break;
        case 5:  return ScreenQuestion::get(this, questions.at(questionsOrder.at(2))); break;
        case 6:  return ScreenQuestion::get(this, questions.at(questionsOrder.at(3))); break;
        case 7:  return ScreenQuestion::get(this, questions.at(questionsOrder.at(4))); break;
        case 8:  return ScreenQuestion::get(this, questions.at(questionsOrder.at(5))); break;
        case 9:  return ScreenQuestion::get(this, questions.at(questionsOrder.at(6))); break;
        case 10: return ScreenQuestion::get(this, questions.at(questionsOrder.at(7))); break;
        case 11: return ScreenQuestion::get(this, questions.at(questionsOrder.at(8))); break;
        case 12: return ScreenQuestion::get(this, questions.at(questionsOrder.at(9))); break;
        // tasks part
        case 13: return new ScreenTask1;  break;
        case 14: return new ScreenTask2;  break;
        case 15: return new ScreenTask3;  break;
        case 16: return new ScreenTask4;  break;
        case 17: return new ScreenTask5;  break;
        case 18: return new ScreenTask6;  break;
        case 19: return new ScreenTask7A;  break;
        case 20: return new ScreenTask7B;  break;

        // summary part
        case 99: return ScreenSummary::get(this); break;
        default: return NULL;
    }
    // ------------------------------
}

void Core::next() {
    next(false);
}

void Core::next(bool force) {
    QString message;
    if (showedTask == 0 || window->getWidget() == nullptr || window->getWidget()->validate(this, &message)) {
        if (force || (score >= 0 && showedTask < tasks.size())) {
            showedTask++;
            show(message);
        } else {
            showedTask = tasks.size() - 1;
            next(true);
        }
    }
}

void Core::back() {
    if (showedTask > 0) {
        showedTask--;
        show("");
    }
}

void Core::reset() {
    generate();
    next();
}

void Core::changeScore(int delta) {
    this->score += delta;
}

int Core::getScore() {
    return score;
}

void Core::show(QString message) {
    if (currentTask < showedTask) {
        currentTask = showedTask;
    }
    Task *task = tasks.at(showedTask - 1);
    window->setStep(task->getNumber(), task->getTitle());
    window->setProgress(showedTask);
    window->setScore(score);
    window->setMessage(message);
    window->setWidget(getView(task->getId())->init(task->getId(), currentTask != showedTask));
    window->setNextEnabled(currentTask == showedTask ? task->getNextButtonActive() : true);
    window->setBackEnabled(showedTask > 1);
}

unsigned int Core::getSeed() {
    return seed;
}
