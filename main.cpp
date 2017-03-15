#include <DApplication>
#include <dutility.h>
#include "main_window.h"
#include "utils.h"

DWIDGET_USE_NAMESPACE

int main(int argc, char *argv[])
{
    DApplication::loadDXcbPlugin();

    DApplication app(argc, argv);
    app.setTheme("light");

    MainWindow window;

    //Utils::applyQss(&window, "light.qss");

    window.setWindowTitle("engine-calculator");
    window.show();

    DUtility::moveToCenter(&window);

    return app.exec();
}
