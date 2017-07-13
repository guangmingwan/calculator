#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <DMainWindow>
#include <QStackedLayout>
#include "titlebar.h"
#include "simple_mode.h"
#include "scientific_mode.h"

DWIDGET_USE_NAMESPACE

class MainWindow : public DMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);

private:
    QWidget *mainWidget;
    QStackedLayout *layout;
    TitleBar *titleBar;

    SimpleMode *simpleMode;
    ScientificMode *scMode;

    void initUI();

};

#endif // MAINWINDOW_H
