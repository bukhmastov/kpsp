#include "mainwindow.h"
#include <QApplication>
#include <stdlib.h>

/*
 * Используемый компилятор: Qt 5.10.1 MinGW 32bit
 * Релизная версия собрана при помощи статичного окружения (https://wiki.qt.io/Building_a_static_Qt_for_Windows_using_MinGW)
 *
 * Вопросы и задания определены в классе Core (/util/core.cpp)
 * Реализация заданий находится в папке /task (ex: /task/screentask1.cpp .h .ui)
 */

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    MainWindow window;
    try {
        if (argc > 1) {
            int seed = atoi(argv[1]);
            if (seed > 0) {
                window.setSeed(seed);
            }
        }
    } catch (...) {}
    window.setWindowTitle("Исследование корреляционных свойств псевдослучайных последовательностей");
    window.setWindowIcon(QIcon(":img/icons/icon.ico"));
    window.show();
    return app.exec();
}
