#include "dsettings.h"
#include <QApplication>
#include <QDir>
#include <QStandardPaths>

DSettings::DSettings(QObject *parent)
    : QObject(parent)
{
    settings = new QSettings(QDir(configPath()).filePath("config.conf") , QSettings::IniFormat);

    if (settings->value("mode").toString().isEmpty()) {
        settings->setValue("mode", "simple");
    }
    if (settings->value("keyboard").toString().isEmpty()) {
        settings->setValue("keyboard", "show");
    }
}

QString DSettings::getDefaultMode()
{
    return settings->value("mode").toString();
}

QString DSettings::configPath()
{
    return QDir(QDir(QStandardPaths::standardLocations(QStandardPaths::ConfigLocation).first()).filePath(qApp->organizationName())).filePath(qApp->applicationName());
}
