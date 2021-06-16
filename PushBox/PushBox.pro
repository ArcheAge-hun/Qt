#-------------------------------------------------
#
# Project created by QtCreator 2021-06-12T22:19:34
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PushBox
TEMPLATE = app
CONFIG += c++11


SOURCES += main.cpp\
        CWidget.cpp \
    CGameMap.cpp \
    CRole.cpp

HEADERS  += CWidget.h \
    CGameMap.h \
    CRole.h

FORMS    += CWidget.ui

RESOURCES += \
    images.qrc \
    maps.qrc
