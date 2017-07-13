#include "main_window.h"
#include <DTitlebar>

MainWindow::MainWindow(QWidget *parent)
    : DMainWindow(parent)
{
    mainWidget = new QWidget;
    layout = new QStackedLayout;
    simpleMode = new SimpleMode;
    titleBar = new TitleBar;

    layout->addWidget(simpleMode);

    mainWidget->setLayout(layout);
    setCentralWidget(mainWidget);

    initUI();
}

void MainWindow::initUI()
{
    resize(260, 370);

    this->titlebar()->setCustomWidget(titleBar, Qt::AlignVCenter, false);
}
