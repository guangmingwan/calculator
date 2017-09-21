#include "sc_button.h"

ScButton::ScButton(const QString &text)
{
    setText(text);
    setFixedHeight(45);
    setFixedWidth(550 / 9);
    setObjectName("TextButton");

    setFocusPolicy(Qt::NoFocus);
}
