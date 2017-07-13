#include "utils.h"

namespace Utils
{
    QChar getLasterChar(QString text)
    {
        QString::const_iterator laster = text.replace("×", "*").replace("÷", "/").end();

        laster--;

        return *laster;
    }
}
