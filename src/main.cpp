#include <QApplication>
//#include <DWidgetUtil>
#include "main_window.h"
#include <QTranslator>
#include <QDebug>

//DWIDGET_USE_NAMESPACE

int main(int argc, char *argv[])
{
    //qputenv("QT_SCALE_FACTOR", "1.3");

    //DApplication::loadDXcbPlugin();
    QApplication app(argc, argv);

    const QString descriptionText = QApplication::tr("rekols calculator is a powerful calculator, beautiful and easy to use.");
    const QString acknowledgementLink = "https://github.com/rekols";

    //if (app.setSingleInstance("RCalc")) {
        app.setApplicationVersion("0.1");
        //app.setProductIcon(QPixmap::fromImage(QImage(":/image/icon.svg").scaled(80, 80)));
        //app.setApplicationDescription(descriptionText + "\n");
        //app.setApplicationAcknowledgementPage(acknowledgementLink);
        app.setWindowIcon(QIcon(":/image/icon.svg"));
        //app.loadTranslator();

        QLocale locale;
        QTranslator tr;
        tr.load(":/translations/zh_CN.qm");

        if (locale.language() == QLocale::Chinese) {
            app.installTranslator(&tr);
        }

        MainWindow w;
        w.show();

        //Dtk::Widget::moveToCenter(&w);

        return app.exec();
    //}

    //return 0;
}
