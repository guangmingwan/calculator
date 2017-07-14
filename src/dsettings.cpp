#include "dsettings.h"
#include <QApplication>

DSettings::DSettings(QObject *parent)
    : QObject(parent)
{
    settings = new QSettings(QApplication::applicationDirPath() + "/config.ini", QSettings::IniFormat);

    if (settings->value("mode").toString().isEmpty()) {
        settings->setValue("mode", "simple");
    }
}

QString DSettings::getDefaultMode()
{
    return settings->value("mode").toString();
}
