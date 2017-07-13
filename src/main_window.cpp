#include "main_window.h"
#include <DTitlebar>

MainWindow::MainWindow(QWidget *parent)
    : DMainWindow(parent)
{
    mainWidget = new QWidget;
    layout = new QStackedLayout;
    simpleMode = new SimpleMode;
    scMode = new ScientificMode;
    titleBar = new TitleBar;

    layout->addWidget(simpleMode);
    layout->addWidget(scMode);

    layout->setCurrentIndex(1);

    mainWidget->setLayout(layout);
    setCentralWidget(mainWidget);

    initUI();
}

void MainWindow::initUI()
{
    //resize(260, 370);
    resize(450, 400);

    this->titlebar()->setCustomWidget(titleBar, Qt::AlignVCenter, false);
}
