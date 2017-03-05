#include "text_button.h"

TextButton::TextButton(QString text)
{
    this->setText(text);
    this->setObjectName("TextButton");
    this->setFixedSize(70, 55);
    this->setStyleSheet("outline: none;"
                        "#TextButton {"
                        "font-size: 15px;"
                        "background: #333333;"
                        "border: 1px solid #2D2D2D;"
                        "color: #CCCCCC;"
                        "}"
                        "#TextButton:hover {"
                        "    background: #414141;"
                        "    border: 1px solid #414141;"
                        "}"
                        "#TextButton:pressed {"
                         "   background: #252525;"
                        "    border: 1px solid #414141;"
                        "}"
    );
}
