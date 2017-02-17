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

void Settings::set_default_style()
{
    QString theme = config->value("/default/theme").toString();
    QFile qss(":/resources/" + theme + ".qss");
    qss.open(QFile::ReadOnly);
    qApp->setStyleSheet(qss.readAll());
    qss.close();
}

void Settings::switch_style()
{
    QString theme = config->value("/default/theme").toString();

    if (theme == "light")
    {
        config->setValue("/default/theme", "dark");
        this->set_default_style();
    }
    if (theme == "dark")
    {
        config->setValue("/default/theme", "light");
        this->set_default_style();
    }
}

void Settings::switch_mode()
{
    QString mode = config->value("/default/mode").toString();

    if (mode == "common")
    {
        config->setValue("/default/mode", "scientific");
    }
    if (mode == "scientific")
    {
        config->setValue("/default/mode", "common");
    }
}

QString Settings::get_mode()
{
    QString mode = config->value("/default/mode").toString();

    return mode;
}
