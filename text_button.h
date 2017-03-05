#ifndef TEXTBUTTON_H
#define TEXTBUTTON_H

#include <QPushButton>

class TextButton : public QPushButton
{
    Q_OBJECT

public:
    explicit TextButton(QString text);
};

#endif
