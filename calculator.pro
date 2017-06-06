QT += core
QT += widgets
QT += gui

TEMPLATE = app
TARGET = calculator

CONFIG += link_pkgconfig
CONFIG += c++11
PKGCONFIG += dtkbase dtkwidget dtkutil

HEADERS +=  main_window.h titlebar.h utils.h text_button.h algorithm.h settings.h simple_page.h

SOURCES +=  main.cpp main_window.cpp titlebar.cpp utils.cpp text_button.cpp algorithm.cpp settings.cpp simple_page.cpp

RESOURCES += calculator.qrc
