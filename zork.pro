#-------------------------------------------------
#
# Project created by QtCreator 2018-10-05T16:41:17
#
#-------------------------------------------------

QT       += core gui widgets

TARGET = zork
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

CONFIG += c++11

SOURCES += \
        mainwindow.cpp \
    ZorkUL.cpp \
    Room.cpp \
    item.cpp \
    Character.cpp \
    main.cpp \
    board.cpp \
    enemy.cpp \
    healer.cpp \
    hero.cpp \
    sword.cpp \
    medaillon.cpp \
    shield.cpp \
    lantern.cpp \
    degree.cpp \
    key.cpp \
    CommandWords.cpp \
    Parser.cpp \
    Command.cpp

HEADERS += \
        mainwindow.h \
    ZorkUL.h \
    Room.h \
    item.h \
    Character.h \
    board.h \
    enemy.h \
    healer.h \
    hero.h \
    sword.h \
    medaillon.h \
    shield.h \
    lantern.h \
    degree.h \
    key.h \
    CommandWords.h \
    Parser.h \
    Command.h

FORMS += \
        mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
