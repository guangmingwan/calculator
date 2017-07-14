#ifndef SCIENTIFICMODE_H
#define SCIENTIFICMODE_H

#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include "line_editor.h"
#include "result_display.h"
#include "sc_button.h"
#include "core/evaluator.h"

class ScientificMode : public QWidget
{
    Q_OBJECT

public:
    ScientificMode(QWidget *parent = 0);

protected:
    void keyPressEvent(QKeyEvent *);

private:
    Evaluator* m_evaluator;

    QVBoxLayout *layout;
    QHBoxLayout *topLayout;
    QHBoxLayout *layout1;
    QHBoxLayout *layout2;
    QHBoxLayout *layout3;
    QHBoxLayout *layout4;
    QLabel *state;
    ResultDisplay *display;
    QLineEdit *editor;

    ScButton *btn7;
    ScButton *btn8;
    ScButton *btn9;
    ScButton *btnDiv;
    ScButton *btnC;
    ScButton *btnRoot;
    ScButton *btnP;
    ScButton *btnExp;
    ScButton *btnLn;

    ScButton *btn4;
    ScButton *btn5;
    ScButton *btn6;
    ScButton *btnMult;
    ScButton *btnE;
    ScButton *btnS;
    ScButton *btnAns;
    ScButton *btnSin;
    ScButton *btnArcsin;

    ScButton *btn1;
    ScButton *btn2;
    ScButton *btn3;
    ScButton *btnMinus;
    ScButton *btnLeft;
    ScButton *btnRight;
    ScButton *btnX;
    ScButton *btnCos;
    ScButton *btnArccos;

    ScButton *btn0;
    ScButton *btnPoint;
    ScButton *btnIs;
    ScButton *btnPlus;
    ScButton *btnMod;
    ScButton *btnG;
    ScButton *btnXis;
    ScButton *btnTan;
    ScButton *btnArctan;

private slots:
    void on_equal_button_clicked();
    void showStateLabel(const QString &text);
    void lineEditTextChanged(const QString &text);
};

#endif // SCIENTIFICMODE_H
