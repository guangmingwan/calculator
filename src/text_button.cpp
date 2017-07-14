#include "text_button.h"

TextButton::TextButton(const QString &text)
{
    setText(text);
    setFixedSize(65, 50);
    setObjectName("TextButton");

    setFocusPolicy(Qt::NoFocus);
}
