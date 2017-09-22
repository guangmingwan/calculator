#include "sc_edit.h"

ScEdit::ScEdit(QWidget *parent)
    : QLineEdit(parent)
{
    m_evaluator = Evaluator::instance();

    connect(this, &QLineEdit::textChanged, this, &ScEdit::autoCalculator);
}

void ScEdit::autoCalculator()
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
            auto message = QString(tr("Current result: %1")).arg(formatted);
            emit autoCalculatorMessage(message);
        }
    }else
        emit autoCalculatorError(m_evaluator->error());
}
