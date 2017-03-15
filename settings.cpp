#include "settings.h"
#include <QApplication>
#include <QFile>

Settings::Settings(QObject *parent) : QObject(parent)
{
    config = new QSettings("config.ini", QSettings::IniFormat);

    QFile file("config.ini");

    if (!file.exists())
    {
        config->setValue("/default/theme", "light");
        config->setValue("/default/mode", "common");
    }
}

QString Settings::getDefaultTheme()
{
    QString theme = config->value("/default/theme").toString();

    return theme;
}
