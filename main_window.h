#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <DMainWindow>
#include "common_page.h"

DWIDGET_USE_NAMESPACE

class MainWindow : public DMainWindow
{
    Q_OBJECT

public:
    MainWindow(DMainWindow *parent = 0);

public slots:
    void showCommonPage();

private:
    QWidget *layoutWidget;
    CommonPage *commonPage;
};

#endif
