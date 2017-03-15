QT += core
QT += widgets
QT += gui

TEMPLATE = app
TARGET = engine-calculator

CONFIG += link_pkgconfig
CONFIG += c++11
PKGCONFIG += dtkbase dtkwidget dtkutil

HEADERS +=  main_window.h titlebar.h utils.h common_page.h text_button.h algorithm.h settings.h

SOURCES +=  main.cpp main_window.cpp titlebar.cpp utils.cpp common_page.cpp text_button.cpp algorithm.cpp settings.cpp

RESOURCES = engine-calculator.qrc
