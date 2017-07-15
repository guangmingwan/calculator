#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <DMainWindow>
#include <QStackedLayout>
#include "titlebar.h"
#include "simple_mode.h"
#include "scientific_mode.h"
#include <QMenu>
#include "dsettings.h"
#include <ddialog.h>

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
    DDialog *dialog;

    QAction *simpleAction;
    QAction *scientificAction;
    QAction *clearRecord;
    QAction *hideAction;
    QAction *showAction;
    QAction *lightAction;
    QAction *darkAction;
    DSettings *config;

    void initUI();
    void initTheme();
    void initMode();
    void initMenu();
    void loadHistory();
    void switchToSimpleMode();
    void switchToScientificMode();
    void switchToLightTheme();
    void switchToDarkTheme();
    void clearHistory();
    void showKeyBoard();
    void hideKeyBoard();
    void dialogButtonClicked(int);

    QString histroyFilePath;

protected:
    void closeEvent(QCloseEvent *);

};

#endif // MAINWINDOW_H
