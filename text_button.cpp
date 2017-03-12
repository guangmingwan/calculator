#include "text_button.h"

TextButton::TextButton(QString text)
{
    this->setText(text);
    this->setFixedSize(70, 55);
    this->setObjectName("TextButton");
}
