#-------------------------------------------------
#
# Project created by QtCreator 2013-02-19T19:35:14
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SnakeGame
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    renderarea.cpp \
    graphicelement.cpp \
    snakepart.cpp

HEADERS  += mainwindow.h \
    renderarea.h \
    graphicelement.h \
    snakepart.h

FORMS    += mainwindow.ui
