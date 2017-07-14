#include "sc_button.h"

ScButton::ScButton(const QString &text)
{
    setText(text);
    setFixedHeight(45);
    setObjectName("TextButton");
}
