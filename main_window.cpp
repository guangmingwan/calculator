#include "main_window.h"
#include "titlebar.h"
#include "utils.h"

#include <DTitlebar>

MainWindow::MainWindow(DMainWindow *parent)
    : DMainWindow(parent)
{
    Titlebar *titlebar = new Titlebar();
    this->titleBar()->setCustomWidget(titlebar, Qt::AlignVCenter, false);

    layoutWidget = new QWidget();
    this->setCentralWidget(layoutWidget);

    showCommonPage();
}

void MainWindow::showCommonPage()
{
    Utils::removeChildren(layoutWidget);

    commonPage = new CommonPage();
    layoutWidget->setLayout(commonPage->layout);

    this->resize(280, 410);
}
