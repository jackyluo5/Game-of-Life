TEMPLATE = app
CONFIG += console
#CONFIG -= app_bundle

#since we want to use qDebug, we
#will not subtract qt.
#CONFIG -= qt

CONFIG += c++11
#------------------------------------------
##Add these lines for SFML:



#WINDOWS
# put SFML file in the same location as project
#LIBS += -L"..\..\SFML-2.0\lib" #change this
#LIBS += -L"..\..\SFML-2.0\bin" #change this

#MAC
LIBS += -L"/usr/local/lib"

CONFIG(release, debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-system -lsfml-network -lsfml-window
CONFIG(debug  , debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-system -lsfml-network -lsfml-window

#WINDOWS
#INCLUDEPATH += "..\..\SFML-2.0\include" #change this
#DEPENDPATH  += "..\..\SFML-2.0\include" #change this

#MAC
INCLUDEPATH += "/usr/local/include"
DEPENDPATH += "/usr/local/include"

#-----------------------------------------

SOURCES += main.cpp \
    system.cpp \
    random.cpp \
    sidebar.cpp \
    animate.cpp


HEADERS += \
    constants.h \
    system.h \
    random.h \
    sidebar.h \
    animate.h
