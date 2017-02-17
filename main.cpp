#include <QApplication>
#include <QDesktopWidget>
#include "main_window.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    app.setWindowIcon(QIcon(":/resources/calculator.png"));

    MainWindow window;
    window.setWindowFlags(Qt::FramelessWindowHint | Qt::Window);
    window.move ((QApplication::desktop()->width() - window.width())/2,
                 (QApplication::desktop()->height() - window.height())/2);
    window.resize(280, 410);
    window.show();

    return app.exec();
}
