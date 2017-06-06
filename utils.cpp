#include "utils.h"
#include <QDir>
#include <QFile>
#include <QTextStream>

namespace Utils
{
    QChar getLasterChar(QString text)
    {
        QString::const_iterator laster = text.replace("×", "*").replace("÷", "/").end();

        laster--;

        return *laster;
    }

    QString getImagePath(QString imageName)
    {
        QDir dir(qApp->applicationDirPath());
        dir.cdUp();

        return QDir(dir.filePath("image")).filePath(imageName);
    }

    QString getQssPath(QString qssName)
    {
        return QString(":/qss/%1").arg(qssName);
    }

    void applyQss(QWidget *widget, QString qssName)
    {
        QFile file(getQssPath(qssName));
        file.open(QFile::ReadOnly);
        QTextStream filetext(&file);
        QString stylesheet = filetext.readAll();
        widget->setStyleSheet(stylesheet);
        file.close();
    }
}
