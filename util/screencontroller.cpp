#include "screencontroller.h"

std::map<std::pair<int, int>, int> ScreenController::random = {};
std::map<QString, QString> ScreenController::store = {};

ScreenController* ScreenController::init(int id, bool readonly) {
    this->id = id;
    this->readOnly = readonly;
    init();
    return this;
}

void ScreenController::clean() {
    store.clear();
}

void ScreenController::srnd(int seed) {
    random.clear();
    srand(seed);
}

int ScreenController::rnd() {
    std::pair<int, int> pair = std::make_pair(id, rndId++);
    if (random.count(pair)) {
        return random.at(pair);
    } else {
        int a = rand();
        random[pair] = a;
        return a;
    }
}
