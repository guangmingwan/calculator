#ifndef SETTTINGS_H
#define SETTTINGS_H

#include <QObject>
#include <QSettings>

class DSettings : public QObject
{
    Q_OBJECT

public:
    DSettings(QObject *parent = 0);

    QSettings *settings;
    QString configPath();
    QString getDefaultMode();
};

#endif // SETTTINGS_H
