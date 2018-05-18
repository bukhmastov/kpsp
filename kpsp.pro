#-------------------------------------------------
#
# Project created by QtCreator 2018-04-21T18:59:10
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = kpsp
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    util/core.cpp \
    util/static.cpp \
    util/task.cpp \
    util/question.cpp \
    util/screencontroller.cpp \
    view/questionanswerlabel.cpp \
    view/clickableqlabel.cpp \
    screen/screenwelcome.cpp \
    screen/screenabout.cpp \
    screen/screendescription.cpp \
    screen/screenquestion.cpp \
    screen/screensummary.cpp \
    task/screentask1.cpp \
    view/chartview.cpp \
    task/screentask2.cpp \
    task/screentask3.cpp \
    task/screentask4.cpp \
    task/screentask5.cpp \
    task/screentask6.cpp \
    task/screentask7a.cpp \
    task/screentask7b.cpp

HEADERS += \
        mainwindow.h \
    util/core.h \
    util/static.h \
    util/task.h \
    util/question.h \
    util/windowcontroller.h \
    util/screencontroller.h \
    view/questionanswerlabel.h \
    view/clickableqlabel.h \
    screen/screenwelcome.h \
    screen/screenabout.h \
    screen/screendescription.h \
    screen/screenquestion.h \
    screen/screensummary.h \
    task/screentask1.h \
    view/chartview.h \
    task/screentask2.h \
    task/screentask3.h \
    task/screentask4.h \
    task/screentask5.h \
    task/screentask6.h \
    task/screentask7a.h \
    task/screentask7b.h

FORMS += \
        mainwindow.ui \
    screen/screenwelcome.ui \
    screen/screenabout.ui \
    screen/screendescription.ui \
    screen/screenquestion.ui \
    screen/screensummary.ui \
    task/screentask1.ui \
    task/screentask2.ui \
    task/screentask3.ui \
    task/screentask4.ui \
    task/screentask5.ui \
    task/screentask6.ui \
    task/screentask7a.ui \
    task/screentask7b.ui
RESOURCES += \
    resources.qrc

win32:RC_ICONS += icons/icon.ico
