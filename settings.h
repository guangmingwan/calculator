#pragma once

#include <QObject>
#include <QSettings>

class Settings : public QObject
{
    Q_OBJECT

public:
    explicit Settings(QObject *parent = 0);
    QString get_mode();

    void set_default_style();
    void switch_style();
    void switch_mode();

    QSettings *config;
};

