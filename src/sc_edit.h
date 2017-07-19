#ifndef SCEDIT_H
#define SCEDIT_H

#include <QLineEdit>

#include "core/constants.h"
#include "core/evaluator.h"
#include "core/functions.h"
#include "core/numberformatter.h"
#include "core/settings.h"
#include "core/session.h"

class ScEdit : public QLineEdit
{
    Q_OBJECT

public:
    ScEdit(QWidget *parent = 0);

private:
    Evaluator* m_evaluator;

private slots:
    void autoCalculator();

signals:
    void autoCalculatorMessage(QString);
    void autoCalculatorError(QString);
};

#endif // LINEEDITOR_H
