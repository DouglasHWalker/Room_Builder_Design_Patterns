TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        core/creatures/abstractcreature.cpp \
        core/dungeon/dungeonlevel.cpp \
        core/dungeon/dungeonlevelbuilder.cpp \
        core/dungeon/room.cpp \
        core/game.cpp \
        core/items/item.cpp \
        core/menuinterface.cpp \
        main.cpp

HEADERS += \
    core/creatures/abstractcreature.h \
    core/dungeon/dungeonlevel.h \
    core/dungeon/dungeonlevelbuilder.h \
    core/dungeon/room.h \
    core/game.h \
    core/items/item.h \
    core/menuinterface.h

DISTFILES += \
    Doxyfile
