#include "text_button.h"

TextButton::TextButton(QString text)
{
    this->setText(text);
    this->setFixedSize(60, 45);
    this->setObjectName("TextButton");
}
