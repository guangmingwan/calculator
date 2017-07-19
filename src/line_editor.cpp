#include "line_editor.h"

LineEditor::LineEditor(QWidget *parent)
    : QLineEdit(parent)
{
    m_evaluator = Evaluator::instance();

    connect(this, &QLineEdit::textChanged, this, &LineEditor::autoCalculator);
    connect(this, &QLineEdit::textChanged, this, &LineEditor::changeFontSize);
}

void LineEditor::autoCalculator()
{
    const auto str = m_evaluator->autoFix(this->text());

    if (str.isEmpty())
        return;

    m_evaluator->setExpression(str);
    auto quantity = m_evaluator->evalNoAssign();

    if (m_evaluator->error().isEmpty()) {
        if (quantity.isNan() && m_evaluator->isUserFunctionAssign()) {

        }else {
            auto formatted = NumberFormatter::format(quantity);
            auto message = QString("当前结果: %1").arg(formatted);
            emit autoCalculatorMessage(message);
        }
    }else
        emit autoCalculatorError(m_evaluator->error());
}

void LineEditor::changeFontSize()
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
