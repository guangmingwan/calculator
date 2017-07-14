#include "result_display.h"

ResultDisplay::ResultDisplay(QWidget *parent)
    : QPlainTextEdit(parent)
{
    setViewportMargins(0, 0, 0, 0);
    setBackgroundRole(QPalette::Base);
    setLayoutDirection(Qt::LeftToRight);
    setReadOnly(true);
    setFocusPolicy(Qt::NoFocus);
    setWordWrapMode(QTextOption::WrapAnywhere);

    QFont font;
    font.setFamily("Noto Mono");
    font.setPointSize(13);
    setFont(font);

    setStyleSheet("QPlainTextEdit { background: #EAEAEA; color: #4F4D4D; }");

    m_count = 0;
}

void ResultDisplay::append(const QString &text)
{
    ++m_count;

    appendPlainText(text);
}
