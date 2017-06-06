#include "main_window.h"
#include "titlebar.h"
#include "utils.h"
#include "settings.h"

#include <DTitlebar>
#include <QKeyEvent>
#include <QApplication>
#include <daboutdialog.h>

MainWindow::MainWindow(DMainWindow *parent)
    : DMainWindow(parent)
{
    mainWidget = new QWidget();

    Settings *settings = new Settings();
    Titlebar *titlebar = new Titlebar();

    this->titleBar()->setCustomWidget(titlebar, Qt::AlignVCenter, false);
    this->titleBar()->setWindowFlags(Qt::WindowTitleHint | Qt::WindowMinimizeButtonHint | Qt::WindowSystemMenuHint | Qt::WindowCloseButtonHint);

    setWindowFlags(Qt::FramelessWindowHint | Qt::Window);
    setCentralWidget(mainWidget);

    showSimplePage();
}

void MainWindow::showSimplePage()
{
    qDeleteAll(mainWidget->children());

    simplePage = new SimplePage();
    mainWidget->setLayout(simplePage->layout);

    this->setFixedSize(240, 345);
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    switch (event->key())
    {
    case Qt::Key_0:
        simplePage->zeroButton->clicked();
        break;
    case Qt::Key_1:
        simplePage->oneButton->clicked();
        break;
    case Qt::Key_2:
        simplePage->twoButton->clicked();
        break;
    case Qt::Key_3:
        simplePage->threeButton->clicked();
        break;
    case Qt::Key_4:
        simplePage->fourButton->clicked();
        break;
    case Qt::Key_5:
        simplePage->fiveButton->clicked();
        break;
    case Qt::Key_6:
        simplePage->sixButton->clicked();
        break;
    case Qt::Key_7:
        simplePage->sevenButton->clicked();
        break;
    case Qt::Key_8:
        simplePage->eightButton->clicked();
        break;
    case Qt::Key_9:
        simplePage->nineButton->clicked();
        break;
    case Qt::Key_Period:
        simplePage->pointButton->clicked();
        break;
    case Qt::Key_Enter:
        simplePage->equalButton->clicked();
        break;
    case Qt::Key_Plus:
        simplePage->plusButton->clicked();
        break;
    case Qt::Key_Minus:
        simplePage->minusButton->clicked();
        break;
    case Qt::Key_Asterisk:
        simplePage->multButton->clicked();
        break;
    case Qt::Key_Slash:
        simplePage->divButton->clicked();
        break;
    }
}
