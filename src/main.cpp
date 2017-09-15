#include <DApplication>
#include <DWidgetUtil>
#include "main_window.h"

#include <QFile>
#include <QTextStream>

DWIDGET_USE_NAMESPACE

int main(int argc, char *argv[])
{
    qputenv("QT_SCALE_FACTOR", "1.35");

    DApplication::loadDXcbPlugin();
    DApplication app(argc, argv);

    const char *descriptionText = QT_TRANSLATE_NOOP("MainWindow", "Rekols计算器功能强大，支持各种表达式、公式输入");
    const QString acknowledgementLink = "https://github.com/rekols";

    if (app.setSingleInstance("rekols-calculator")) {
        app.setApplicationVersion("0.1");
        app.setProductIcon(QPixmap::fromImage(QImage(":/image/icon.svg").scaled(80, 80)));
        app.setApplicationDescription(DApplication::translate("MainWindow", descriptionText) + "\n");
        app.setApplicationAcknowledgementPage(acknowledgementLink);
        app.setWindowIcon(QIcon(":/image/icon.svg"));
        app.loadTranslator();

        MainWindow w;
        w.show();

        Dtk::Widget::moveToCenter(&w);

        return app.exec();
    }

    return 0;
}
