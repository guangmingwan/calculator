#include "main_window.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    settings = new Settings();
    titlebar = new TitleBar();

    settings->set_default_style();
    titlebar->setFixedHeight(40);

    this->setMenuWidget(titlebar);

    initUI();

    connect(titlebar, &TitleBar::on_minimised, this, &MainWindow::showMinimized);
}

void MainWindow::initUI()
{
    QString mode = settings->get_mode();

    common = new Common();
    this->setCentralWidget(common);
}
