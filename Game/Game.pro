#-------------------------------------------------
#
# Project created by QtCreator 2021-06-03T21:14:16
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Game
TEMPLATE = app


SOURCES += main.cpp\
        cmainwidget.cpp \
    cloginwidget.cpp \
    cscreenwidget.cpp \
    cbackgroundlab.cpp \
    cpushbutton.cpp \
    crole.cpp

HEADERS  += cmainwidget.h \
    cloginwidget.h \
    cscreenwidget.h \
    cbackgroundlab.h \
    cpushbutton.h \
    crole.h

FORMS    += cmainwidget.ui
