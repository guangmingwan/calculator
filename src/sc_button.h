#ifndef SCBUTTON_H
#define SCBUTTON_H


#include <dpushbutton.h>

DWIDGET_USE_NAMESPACE

class ScButton : public DPushButton
{
    Q_OBJECT

public:
    ScButton(const QString &text);
};
#endif // SCBUTTON_H
