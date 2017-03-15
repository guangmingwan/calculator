#include <DApplication>
#include <dutility.h>
#include "main_window.h"
#include "utils.h"
#include "settings.h"

DWIDGET_USE_NAMESPACE

int main(int argc, char *argv[])
{
    DApplication::loadDXcbPlugin();

    DApplication app(argc, argv);

    MainWindow window;

    Settings *set = new Settings();
    QString theme = set->getDefaultTheme();

    if (theme == "light")
    {
        app.setTheme("light");
        Utils::applyQss(&window, "light.qss");
    }
    else
    {
        app.setTheme("dark");
        Utils::applyQss(&window, "dark.qss");
    }


    window.setWindowTitle("engine-calculator");
    window.show();

    DUtility::moveToCenter(&window);

    return app.exec();
}
