QT -= gui
QT += core
CONFIG += c++17 console
CONFIG -= app_bundle

LIBS += -LC:\Qt\SFML\lib
LIBS += -LC:\Qt\SFML\bin
CONFIG(release, debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-main -lsfml-network -lsfml-window -lsfml-system

CONFIG(debug, debug|release): LIBS += -lsfml-audio-d -lsfml-graphics-d -lsfml-main-d -lsfml-network-d -lsfml-window-d -lsfml-system-d

INCLUDEPATH += C:/Qt/SFML/include
DEPENDPATH += C:/Qt/SFML/include


TEMPLATE = app

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        frog.cpp \
        main.cpp \
        map.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    Global.h \
    frog.h \
    map.h

OTHER_FILES += \
    assets/Sprite-0004.ase \
    assets/Sprite-0004.png \
    assets/frog.png \
    frog.png
