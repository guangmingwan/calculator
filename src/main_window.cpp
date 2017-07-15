#include "main_window.h"
#include <DTitlebar>
#include <QApplication>
#include <QFile>
#include <QTextStream>
#include <dthememanager.h>

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
    dialog = new DDialog("提示", "您确定要清除历史记录吗？", this);
    histroyFilePath = config->configPath() + "/history.txt";

    layout->addWidget(simpleMode);
    layout->addWidget(scMode);

    mainWidget->setLayout(layout);
    setCentralWidget(mainWidget);

    initUI();
}

void MainWindow::initUI()
{
    this->titlebar()->setCustomWidget(titleBar, Qt::AlignVCenter, false);
    this->titlebar()->setWindowFlags(Qt::WindowTitleHint | Qt::WindowMinimizeButtonHint | Qt::WindowSystemMenuHint | Qt::WindowCloseButtonHint);
    this->titlebar()->setMenu(menu);

    dialog->addButton("取消");
    dialog->addButton("确定");

    simpleAction = new QAction("简单模式", this);
    scientificAction = new QAction("科学计算", this);
    clearRecord = new QAction("清除记录", this);
    hideAction = new QAction("隐藏按键", this);
    showAction = new QAction("显示按键", this);
    lightAction = new QAction("浅色主题", this);
    darkAction = new QAction("深色主题", this);

    menu->addAction(simpleAction);
    menu->addAction(scientificAction);
    menu->addAction(clearRecord);
    menu->addAction(hideAction);
    menu->addAction(showAction);
    menu->addAction(lightAction);
    menu->addAction(darkAction);

    initTheme();
    initMode();
    initMenu();
    loadHistory();

    connect(simpleAction, &QAction::triggered, this, &MainWindow::switchToSimpleMode);
    connect(scientificAction, &QAction::triggered, this, &MainWindow::switchToScientificMode);
    connect(clearRecord, &QAction::triggered, this, &MainWindow::clearHistory);
    connect(hideAction, &QAction::triggered, this, &MainWindow::hideKeyBoard);
    connect(showAction, &QAction::triggered, this, &MainWindow::showKeyBoard);
    connect(lightAction, &QAction::triggered, this, &MainWindow::switchToLightTheme);
    connect(darkAction, &QAction::triggered, this, &MainWindow::switchToDarkTheme);
    connect(dialog, &DDialog::buttonClicked, this, &MainWindow::dialogButtonClicked);

    scMode->display->moveCursor(QTextCursor::End);
}

void MainWindow::initTheme()
{
    if (config->settings->value("theme").toString() == "light") {
        lightAction->setVisible(false);
        darkAction->setVisible(true);
        switchToLightTheme();
    }else {
        lightAction->setVisible(true);
        darkAction->setVisible(false);
        switchToDarkTheme();
    }
}

void MainWindow::initMode()
{
    if (config->getDefaultMode() == "simple") {
        simpleAction->setVisible(false);
        scientificAction->setVisible(true);
        clearRecord->setVisible(false);
        switchToSimpleMode();
    }else {
        simpleAction->setVisible(true);
        scientificAction->setVisible(false);
        clearRecord->setVisible(true);
        switchToScientificMode();
    }
}

void MainWindow::initMenu()
{
    if (config->settings->value("keyboard").toString() == "show") {
        showAction->setVisible(false);
        hideAction->setVisible(true);
        showKeyBoard();
    }else {
        showAction->setVisible(true);
        hideAction->setVisible(false);
        hideKeyBoard();
    }

    if (config->settings->value("mode").toString() == "simple") {
        simpleAction->setVisible(false);
        scientificAction->setVisible(true);
        showAction->setVisible(false);
        hideAction->setVisible(false);
        clearRecord->setVisible(false);
    }else {
        simpleAction->setVisible(true);
        scientificAction->setVisible(false);
        clearRecord->setVisible(true);
    }

    if (config->settings->value("theme").toString() == "light") {
        lightAction->setVisible(false);
        darkAction->setVisible(true);
    }else {
        lightAction->setVisible(true);
        darkAction->setVisible(false);
    }
}

void MainWindow::loadHistory()
{
    QFile file(histroyFilePath);
    QTextStream out(&file);
    if (file.open(QFile::ReadOnly)) {
        scMode->display->setPlainText(file.readAll());
    }else {
        file.open(QFile::WriteOnly);
        out << "";
    }
    file.close();
}

void MainWindow::switchToSimpleMode()
{
    setFixedSize(260, 370);
    layout->setCurrentIndex(0);

    config->settings->setValue("mode", "simple");

    initMenu();
}

void MainWindow::switchToScientificMode()
{
    setFixedSize(550, 450);
    layout->setCurrentIndex(1);
    scMode->editor->setFocus();

    config->settings->setValue("mode", "scientific");

    initMenu();
}

void MainWindow::switchToLightTheme()
{
    QFile file(":/qss/light.qss");
    file.open(QFile::ReadOnly);
    QTextStream qss(&file);
    qApp->setStyleSheet(qss.readAll());
    file.close();

    DThemeManager::instance()->setTheme("light");

    config->settings->setValue("theme", "light");

    initMenu();
}

void MainWindow::switchToDarkTheme()
{
    QFile file(":/qss/dark.qss");
    file.open(QFile::ReadOnly);
    QTextStream qss(&file);
    qApp->setStyleSheet(qss.readAll());
    file.close();

    DThemeManager::instance()->setTheme("dark");

    config->settings->setValue("theme", "dark");

    initMenu();
}

void MainWindow::closeEvent(QCloseEvent *)
{
    QFile file(histroyFilePath);

    if (file.open(QFile::WriteOnly)) {
        QTextStream out(&file);
        out << scMode->display->toPlainText();
    }

    file.close();
}

void MainWindow::clearHistory()
{
    if (scMode->display->toPlainText().isEmpty())
        return;

    dialog->exec();
}

void MainWindow::dialogButtonClicked(int index)
{
    if (index == 1) {
        QFile file(histroyFilePath);

        if (file.open(QFile::WriteOnly)) {
            QTextStream out(&file);
            out << "";
        }

        scMode->display->clear();
    }
}

void MainWindow::showKeyBoard()
{
    config->settings->setValue("keyboard", "show");

    hideAction->setVisible(true);
    showAction->setVisible(false);
    scMode->btn7->setVisible(true);
    scMode->btn8->setVisible(true);
    scMode->btn9->setVisible(true);
    scMode->btnDiv->setVisible(true);
    scMode->btnC->setVisible(true);
    scMode->btnRoot->setVisible(true);
    scMode->btnP->setVisible(true);
    scMode->btnExp->setVisible(true);
    scMode->btnLn->setVisible(true);
    scMode->btn4->setVisible(true);
    scMode->btn5->setVisible(true);
    scMode->btn6->setVisible(true);
    scMode->btnMult->setVisible(true);
    scMode->btnE->setVisible(true);
    scMode->btnS->setVisible(true);
    scMode->btnAns->setVisible(true);
    scMode->btnSin->setVisible(true);
    scMode->btnArcsin->setVisible(true);
    scMode->btn1->setVisible(true);
    scMode->btn2->setVisible(true);
    scMode->btn3->setVisible(true);
    scMode->btnMinus->setVisible(true);
    scMode->btnLeft->setVisible(true);
    scMode->btnRight->setVisible(true);
    scMode->btnX->setVisible(true);
    scMode->btnCos->setVisible(true);
    scMode->btnArccos->setVisible(true);
    scMode->btn0->setVisible(true);
    scMode->btnPoint->setVisible(true);
    scMode->btnIs->setVisible(true);
    scMode->btnPlus->setVisible(true);
    scMode->btnMod->setVisible(true);
    scMode->btnG->setVisible(true);
    scMode->btnXis->setVisible(true);
    scMode->btnTan->setVisible(true);
    scMode->btnArctan->setVisible(true);

    scMode->display->moveCursor(QTextCursor::End);
}

void MainWindow::hideKeyBoard()
{
    config->settings->setValue("keyboard", "hide");

    hideAction->setVisible(false);
    showAction->setVisible(true);
    scMode->btn7->setVisible(false);
    scMode->btn8->setVisible(false);
    scMode->btn9->setVisible(false);
    scMode->btnDiv->setVisible(false);
    scMode->btnC->setVisible(false);
    scMode->btnRoot->setVisible(false);
    scMode->btnP->setVisible(false);
    scMode->btnExp->setVisible(false);
    scMode->btnLn->setVisible(false);
    scMode->btn4->setVisible(false);
    scMode->btn5->setVisible(false);
    scMode->btn6->setVisible(false);
    scMode->btnMult->setVisible(false);
    scMode->btnE->setVisible(false);
    scMode->btnS->setVisible(false);
    scMode->btnAns->setVisible(false);
    scMode->btnSin->setVisible(false);
    scMode->btnArcsin->setVisible(false);
    scMode->btn1->setVisible(false);
    scMode->btn2->setVisible(false);
    scMode->btn3->setVisible(false);
    scMode->btnMinus->setVisible(false);
    scMode->btnLeft->setVisible(false);
    scMode->btnRight->setVisible(false);
    scMode->btnX->setVisible(false);
    scMode->btnCos->setVisible(false);
    scMode->btnArccos->setVisible(false);
    scMode->btn0->setVisible(false);
    scMode->btnPoint->setVisible(false);
    scMode->btnIs->setVisible(false);
    scMode->btnPlus->setVisible(false);
    scMode->btnMod->setVisible(false);
    scMode->btnG->setVisible(false);
    scMode->btnXis->setVisible(false);
    scMode->btnTan->setVisible(false);
    scMode->btnArctan->setVisible(false);

    scMode->editor->setFocus();
}
