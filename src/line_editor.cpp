#include "line_editor.h"

LineEditor::LineEditor(QWidget *parent)
    : QLineEdit(parent)
{
    m_evaluator = Evaluator::instance();

    connect(this, &LineEditor::textChanged, this, &LineEditor::autoCalculator);
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
            this->setToolTip(message);
        }
    }else
        this->setToolTip(m_evaluator->error());
}
