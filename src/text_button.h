#ifndef TEXTBUTTON_H
#define TEXTBUTTON_H

#include <dpushbutton.h>

DWIDGET_USE_NAMESPACE

class TextButton : public DPushButton
{
    Q_OBJECT

public:
    TextButton(const QString &text);
};

#endif // TEXTBUTTON_H
