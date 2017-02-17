#pragma once

#include <QPushButton>

class TextButton : public QPushButton
{
    Q_OBJECT

public:
    explicit TextButton(QString set_text);
};

