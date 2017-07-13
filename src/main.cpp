#include <DApplication>
#include <dutility.h>
#include "main_window.h"

#include <QFile>
#include <QTextStream>

DWIDGET_USE_NAMESPACE

int main(int argc, char *argv[])
{
    DApplication::loadDXcbPlugin();
    DApplication app(argc, argv);

    app.setTheme("light");

    MainWindow w;
    w.show();

    DUtility::moveToCenter(&w);

    QFile file(":/qss/light.qss");
    file.open(QFile::ReadOnly);
    QTextStream qss(&file);

    qApp->setStyleSheet(qss.readAll());

    return app.exec();
}
