#include "text_button.h"

TextButton::TextButton(QString text)
{
    this->setText(text);
    this->setFixedSize(70, 55);
    this->setStyleSheet("color: #666666;"
                        "font-size: 15px;"
                        "font-weight: 400;");
}
