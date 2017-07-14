#include "dsettings.h"
#include <QDir>

DSettings::DSettings(QObject *parent)
    : QObject(parent)
{
    settings = new QSettings("config.ini", QSettings::IniFormat);

    if (settings->value("mode").toString().isEmpty()) {
        settings->setValue("mode", "simple");
    }
}

QString DSettings::getDefaultMode()
{
    return settings->value("mode").toString();
}
