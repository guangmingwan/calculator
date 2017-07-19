#include "simple_edit.h"

SimpleEdit::SimpleEdit(QWidget *parent)
    : QLineEdit(parent)
{
    connect(this, &QLineEdit::textChanged, this, &SimpleEdit::changeFontSize);
}

void SimpleEdit::changeFontSize()
{
    QFont font;

    if (text().size() <= 10) {
        font.setPointSize(20);
    } else if (text().size() > 10) {
        font.setPointSize(15);
    } else if (text().size() > 15) {
        font.setPointSize(10);
    }

    this->setFont(font);
}
