#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <DMainWindow>
#include <QStackedLayout>
#include "titlebar.h"
#include "simple_mode.h"
#include "scientific_mode.h"
#include <QMenu>

DWIDGET_USE_NAMESPACE

class MainWindow : public DMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);

private:
    QMenu *menu;
    QWidget *mainWidget;
    QStackedLayout *layout;
    TitleBar *titleBar;

    SimpleMode *simpleMode;
    ScientificMode *scMode;

    void initUI();

private slots:
    void switchToSimpleMode();
    void switchToScientificMode();

};

#endif // MAINWINDOW_H
