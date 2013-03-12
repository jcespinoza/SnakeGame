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
    gamecontroller.cpp \
    snake.cpp \
    snakelist.cpp

HEADERS  += mainwindow.h \
    renderarea.h \
    graphicelement.h \
    gamecontroller.h \
    snakepart.h \
    snakelist.h \
    snake.h

FORMS    += mainwindow.ui
