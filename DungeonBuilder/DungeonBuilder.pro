TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        core/game.cpp \
        core/menuinterface.cpp \
        main.cpp

HEADERS += \
    core/game.h \
    core/menuinterface.h

DISTFILES += \
    Doxyfile
