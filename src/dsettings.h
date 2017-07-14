#ifndef SETTTINGS_H
#define SETTTINGS_H

#include <QObject>
#include <QSettings>

class DSettings : public QObject
{
    Q_OBJECT

public:
    DSettings(QObject *parent = 0);

    QString getDefaultMode();

    QSettings *settings;
};

#endif // SETTTINGS_H
