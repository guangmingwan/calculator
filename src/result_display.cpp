#include "result_display.h"

ResultDisplay::ResultDisplay(QWidget *parent)
    : QPlainTextEdit(parent)
{
    setViewportMargins(0, 0, 0, 0);
    setReadOnly(true);
    setFocusPolicy(Qt::NoFocus);
    setWordWrapMode(QTextOption::WrapAnywhere);

    m_count = 0;
}

void ResultDisplay::append(const QString &text)
{
    ++m_count;

    appendPlainText(text);
}
