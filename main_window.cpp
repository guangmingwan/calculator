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
    Settings *settings = new Settings();
    Titlebar *titlebar = new Titlebar();
    this->titleBar()->setCustomWidget(titlebar, Qt::AlignVCenter, false);

    menu = new QMenu();
    aboutAction = new QAction(tr("About"), this);
    quitAction = new QAction(tr("Quit"), this);
    menu->addAction(aboutAction);
    menu->addAction(quitAction);
    connect(aboutAction, &QAction::triggered, this, &MainWindow::showAboutDialog);
    connect(quitAction, &QAction::triggered, this, [=] {
        QApplication::quit();
    });

    this->titleBar()->setWindowFlags(Qt::WindowTitleHint | Qt::WindowMinimizeButtonHint | Qt::WindowSystemMenuHint | Qt::WindowCloseButtonHint);
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::Window);
    this->titleBar()->setMenu(menu);

    layoutWidget = new QWidget();
    this->setCentralWidget(layoutWidget);

    showCommonPage();
}

void MainWindow::showCommonPage()
{
    Utils::removeChildren(layoutWidget);

    commonPage = new CommonPage();
    layoutWidget->setLayout(commonPage->layout);

    this->resize(280, 380);
}

void MainWindow::showAboutDialog()
{
    QString descriptionText = tr("A simple calculator for you.");
    QString acknowledgementLink = "https://github.com/rekols";

    auto *aboutDlg = new Dtk::Widget::DAboutDialog();
    aboutDlg->setWindowModality(Qt::WindowModal);
    aboutDlg->setWindowIcon(QPixmap::fromImage(QImage(Utils::getImagePath("logo.png"))));
    aboutDlg->setProductIcon(QPixmap::fromImage(QImage(Utils::getImagePath("logo.png"))));
    aboutDlg->setProductName(tr("Calculator"));
    aboutDlg->setVersion(QString("%1: 1.0").arg(tr("Version")));
    aboutDlg->setDescription(descriptionText + "\n");
    aboutDlg->setAcknowledgementLink(acknowledgementLink);
    aboutDlg->show();
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    switch (event->key())
    {
    case Qt::Key_0:
        commonPage->zeroButton->clicked();
        break;
    case Qt::Key_1:
        commonPage->oneButton->clicked();
        break;
    case Qt::Key_2:
        commonPage->twoButton->clicked();
        break;
    case Qt::Key_3:
        commonPage->threeButton->clicked();
        break;
    case Qt::Key_4:
        commonPage->fourButton->clicked();
        break;
    case Qt::Key_5:
        commonPage->fiveButton->clicked();
        break;
    case Qt::Key_6:
        commonPage->sixButton->clicked();
        break;
    case Qt::Key_7:
        commonPage->sevenButton->clicked();
        break;
    case Qt::Key_8:
        commonPage->eightButton->clicked();
        break;
    case Qt::Key_9:
        commonPage->nineButton->clicked();
        break;
    case Qt::Key_Period:
        commonPage->pointButton->clicked();
        break;
    case Qt::Key_Enter:
        commonPage->equalButton->clicked();
        break;
    case Qt::Key_Plus:
        commonPage->plusButton->clicked();
        break;
    case Qt::Key_Minus:
        commonPage->minusButton->clicked();
        break;
    case Qt::Key_Asterisk:
        commonPage->multButton->clicked();
        break;
    case Qt::Key_Slash:
        commonPage->divButton->clicked();
        break;
    }
}
