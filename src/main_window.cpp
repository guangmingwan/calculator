#include "main_window.h"
#include <DTitlebar>

MainWindow::MainWindow(QWidget *parent)
    : DMainWindow(parent)
{
    menu = new QMenu;
    mainWidget = new QWidget;
    layout = new QStackedLayout;
    simpleMode = new SimpleMode;
    scMode = new ScientificMode;
    titleBar = new TitleBar;

    layout->addWidget(simpleMode);
    layout->addWidget(scMode);

    mainWidget->setLayout(layout);
    setCentralWidget(mainWidget);

    initUI();
}

void MainWindow::initUI()
{
    setFixedSize(260, 370);

    this->titlebar()->setCustomWidget(titleBar, Qt::AlignVCenter, false);
    this->titlebar()->setWindowFlags(Qt::WindowTitleHint | Qt::WindowMinimizeButtonHint | Qt::WindowSystemMenuHint | Qt::WindowCloseButtonHint);
    this->titlebar()->setMenu(menu);

    QAction *simpleAction = new QAction("简单模式", this);
    QAction *scientificAction = new QAction("科学计算", this);

    menu->addAction(simpleAction);
    menu->addAction(scientificAction);

    connect(simpleAction, SIGNAL(triggered(bool)), this, SLOT(switchToSimpleMode()));
    connect(scientificAction, SIGNAL(triggered(bool)), this, SLOT(switchToScientificMode()));
}

void MainWindow::switchToSimpleMode()
{
    setFixedSize(260, 370);

    layout->setCurrentIndex(0);
}

void MainWindow::switchToScientificMode()
{
    setFixedSize(550, 450);

    layout->setCurrentIndex(1);
}
