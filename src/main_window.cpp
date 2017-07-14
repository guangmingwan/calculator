#include "main_window.h"
#include <DTitlebar>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : DMainWindow(parent)
{
    menu = new QMenu;
    mainWidget = new QWidget;
    layout = new QStackedLayout;
    simpleMode = new SimpleMode;
    scMode = new ScientificMode;
    titleBar = new TitleBar;
    config = new DSettings();

    layout->addWidget(simpleMode);
    layout->addWidget(scMode);

    mainWidget->setLayout(layout);
    setCentralWidget(mainWidget);

    initUI();
}

void MainWindow::initUI()
{
    QString defaultMode = config->getDefaultMode();

    if (defaultMode == "simple")
        switchToSimpleMode();
    else
        switchToScientificMode();


    this->titlebar()->setCustomWidget(titleBar, Qt::AlignVCenter, false);
    this->titlebar()->setWindowFlags(Qt::WindowTitleHint | Qt::WindowMinimizeButtonHint | Qt::WindowSystemMenuHint | Qt::WindowCloseButtonHint);
    this->titlebar()->setMenu(menu);

    QAction *simpleAction = new QAction("简单模式", this);
    QAction *scientificAction = new QAction("科学计算", this);
    clearRecord = new QAction("清除记录", this);

    menu->addAction(simpleAction);
    menu->addAction(scientificAction);
    menu->addAction(clearRecord);

    connect(simpleAction, &QAction::triggered, this, &MainWindow::switchToSimpleMode);
    connect(scientificAction, &QAction::triggered, this, &MainWindow::switchToScientificMode);
    connect(clearRecord, &QAction::triggered, this, [=]{
        scMode->display->clear();
    });
}

void MainWindow::switchToSimpleMode()
{
    setFixedSize(260, 370);

    layout->setCurrentIndex(0);

    config->settings->setValue("mode", "simple");
}

void MainWindow::switchToScientificMode()
{
    setFixedSize(550, 450);

    layout->setCurrentIndex(1);

    config->settings->setValue("mode", "scientific");
}
