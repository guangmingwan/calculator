#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <DMainWindow>
#include "common_page.h"
#include <QMenu>

DWIDGET_USE_NAMESPACE

class MainWindow : public DMainWindow
{
    Q_OBJECT

public:
    MainWindow(DMainWindow *parent = 0);

    void keyPressEvent(QKeyEvent *event);

public slots:
    void showCommonPage();
    void showAboutDialog();

private:
    QWidget *layoutWidget;
    CommonPage *commonPage;
    QMenu *menu;
    QAction *aboutAction;
    QAction *quitAction;
};

#endif
