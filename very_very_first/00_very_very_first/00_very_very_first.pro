TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

CONFIG += c++11

#WINDOWS
# put SFML file in the same location as project
LIBS += -L"..\..\SFML-2.0\lib" #change this
LIBS += -L"..\..\SFML-2.0\bin" #change this

#MAC
#LIBS += -L"/usr/local/lib"

CONFIG(release, debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-system -lsfml-network -lsfml-window
CONFIG(debug  , debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-system -lsfml-network -lsfml-window

#WINDOWS
INCLUDEPATH += "..\..\SFML-2.0\include" #change this
DEPENDPATH  += "..\..\SFML-2.0\include" #change this

#MAC
#INCLUDEPATH += "/usr/local/include"
#DEPENDPATH += "/usr/local/include"



SOURCES += main.cpp \
    ../../../Desktop/CS2/!include/game_of_life/game.cpp

HEADERS += \
    ../../../Desktop/CS2/!include/game_of_life/game.h
