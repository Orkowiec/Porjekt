TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt


INCLUDEPATH += "C:/SFML-2.5.1/include"

        LIBS += -L"C:/SFML-2.5.1/lib"
        CONFIG(debug, debug|release){
            LIBS += -lsfml-audio-d -lsfml-graphics-d -lsfml-network-d -lsfml-system-d -lsfml-window-d
        } else {
            LIBS += -lsfml-audio -lsfml-graphics -lsfml-network -lsfml-system -lsfml-window
        }

SOURCES += \
Funkcje.cpp \
    Plansza.cpp \
    Zdarzenia.cpp \
    Zmienne.cpp \
figura.cpp \
main.cpp \
    przycisk.cpp \
    Struktury_danych.cpp


HEADERS += \
    Plansza.h \
    Zdarzenia.h \
    Zmienne.h \
    figura.h \
    funkcje.h \
    przycisk.h \
    Struktury_danych.h

