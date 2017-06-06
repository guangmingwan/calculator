#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <DMainWindow>
#include "simple_page.h"

DWIDGET_USE_NAMESPACE

class MainWindow : public DMainWindow
{
    Q_OBJECT

public:
    MainWindow(DMainWindow *parent = 0);

    void keyPressEvent(QKeyEvent *event);

private:
    QWidget *mainWidget;
    SimplePage *simplePage;

    void showSimplePage();
};

#endif
