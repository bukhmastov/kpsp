#ifndef SCREENCONTROLLER_H
#define SCREENCONTROLLER_H

#include <QFrame>
#include <QString>
#include <map>

class Core;
class ScreenController : public QFrame {
public:
    explicit ScreenController(QWidget* parent = Q_NULLPTR) : QFrame(parent) {}
    virtual bool validate(Core*, QString*) = 0;
    static void clean();
    static void srnd(int);
    ScreenController* init(int, bool);

protected:
    virtual void init() = 0;
    int rnd();
    static std::map<std::pair<int, int>, int> random;
    static std::map<QString, QString> store;
    bool readOnly = false;
    int id;
    int rndId = 0;
};

#endif // SCREENCONTROLLER_H
