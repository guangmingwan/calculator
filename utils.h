#include <QApplication>
#include <QWidget>

namespace Utils
{
    QChar getLasterChar(QString text);
    QString getImagePath(QString imageName);
    QString getQssPath(QString qssNmae);
    void applyQss(QWidget *widget, QString qssNmae);
}
