#pragma once

#include <QMainWindow>
#include "settings.h"
#include "widget/titlebar.h"
#include "widget/common_widget.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);

    void initUI();

private:
    Settings *settings;
    TitleBar *titlebar;

    CommonWidget *common;
};
