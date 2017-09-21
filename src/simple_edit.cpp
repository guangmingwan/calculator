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
        font.setPointSize(18);
    } else if (text().size() > 10) {
        font.setPointSize(12);
    } else if (text().size() > 15) {
        font.setPointSize(9);
    }

    this->setFont(font);
}
