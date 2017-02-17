QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = engine-calculator
TEMPLATE = app
CONFIG += link_pkgconfig c++11

SOURCES  += main.cpp main_window.cpp settings.cpp widget/text_button.cpp widget/titlebar.cpp widget/common_widget.cpp 

HEADERS  += main_window.h settings.h widget/text_button.h widget/titlebar.h  widget/common_widget.h 

RESOURCES += resources.qrc
