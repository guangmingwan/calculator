#include "scientific_mode.h"

typedef Quantity::Format Format;

ScientificMode::ScientificMode(QWidget *parent)
    : QWidget(parent)
{
    m_evaluator = Evaluator::instance();;

    layout = new QVBoxLayout;
    topLayout = new QHBoxLayout;
    layout1 = new QHBoxLayout;
    layout2 = new QHBoxLayout;
    layout3 = new QHBoxLayout;
    layout4 = new QHBoxLayout;
    edit = new QPlainTextEdit;
    editor = new LineEditor;

    layout1->setSpacing(0);
    layout2->setSpacing(0);
    layout3->setSpacing(0);
    layout4->setSpacing(0);

    layout1->setMargin(0);
    layout2->setMargin(0);
    layout3->setMargin(0);
    layout4->setMargin(0);

    layout->setSpacing(0);
    layout->setMargin(0);

    layout->setContentsMargins(0, 0, 0, 0);

    edit->setFixedHeight(210);
    edit->setFocusPolicy(Qt::NoFocus);
    editor->setObjectName("ScEditor");

    btn7 = new ScButton("7");
    btn8 = new ScButton("8");
    btn9 = new ScButton("9");
    btnDiv = new ScButton("÷");
    btnC = new ScButton("C");
    btnRoot = new ScButton("√");
    btnP = new ScButton("π");
    btnExp = new ScButton("exp");
    btnLn = new ScButton("ln");

    btn4 = new ScButton("4");
    btn5 = new ScButton("5");
    btn6 = new ScButton("6");
    btnMult = new ScButton("×");
    btnE = new ScButton("E");
    btnS = new ScButton("^");
    btnAns = new ScButton("ans");
    btnSin = new ScButton("sin");
    btnArcsin = new ScButton("arcsin");

    btn1 = new ScButton("1");
    btn2 = new ScButton("2");
    btn3 = new ScButton("3");
    btnMinus = new ScButton("－");
    btnLeft = new ScButton("(");
    btnRight = new ScButton(")");
    btnX = new ScButton("x");
    btnCos = new ScButton("cos");
    btnArccos = new ScButton("arccos");

    btn0 = new ScButton("0");
    btnPoint = new ScButton(".");
    btnIs = new ScButton("＝");
    btnPlus = new ScButton("＋");
    btnMod = new ScButton("%");
    btnG = new ScButton("!");
    btnXis = new ScButton("x=");
    btnTan = new ScButton("tan");
    btnArctan = new ScButton("arctan");

    topLayout->addWidget(editor);

    layout1->addWidget(btn7);
    layout1->addWidget(btn8);
    layout1->addWidget(btn9);
    layout1->addWidget(btnDiv);
    layout1->addWidget(btnC);
    layout1->addWidget(btnRoot);
    layout1->addWidget(btnP);
    layout1->addWidget(btnExp);
    layout1->addWidget(btnLn);

    layout2->addWidget(btn4);
    layout2->addWidget(btn5);
    layout2->addWidget(btn6);
    layout2->addWidget(btnMult);
    layout2->addWidget(btnE);
    layout2->addWidget(btnS);
    layout2->addWidget(btnAns);
    layout2->addWidget(btnSin);
    layout2->addWidget(btnArcsin);

    layout3->addWidget(btn1);
    layout3->addWidget(btn2);
    layout3->addWidget(btn3);
    layout3->addWidget(btnMinus);
    layout3->addWidget(btnLeft);
    layout3->addWidget(btnRight);
    layout3->addWidget(btnX);
    layout3->addWidget(btnCos);
    layout3->addWidget(btnArccos);

    layout4->addWidget(btn0);
    layout4->addWidget(btnPoint);
    layout4->addWidget(btnIs);
    layout4->addWidget(btnPlus);
    layout4->addWidget(btnMod);
    layout4->addWidget(btnG);
    layout4->addWidget(btnXis);
    layout4->addWidget(btnTan);
    layout4->addWidget(btnArctan);

    layout->addWidget(edit);
    layout->addLayout(topLayout);
    layout->addLayout(layout1);
    layout->addLayout(layout2);
    layout->addLayout(layout3);
    layout->addLayout(layout4);

    layout->setContentsMargins(0, 0, 0, 0);

    setLayout(layout);

    connect(btnIs, SIGNAL(clicked(bool)), this, SLOT(on_equal_button_clicked()));
}

void ScientificMode::on_equal_button_clicked()
{
    if (editor->text().isEmpty())
        return;

    m_evaluator->initializeBuiltInVariables();
    m_evaluator->autoFix(editor->text());
    m_evaluator->setExpression(editor->text().replace("×", "*").replace("÷", "/"));

    Quantity rn = m_evaluator->evalUpdateAns();
    QString result = DMath::format(rn, Format::Fixed());

    edit->insertPlainText(editor->text());
    edit->insertPlainText("\n");
    edit->insertPlainText(QString("= %1").arg(result));
    edit->insertPlainText("\n\n");

    editor->setText(result);
    editor->setFocus();
    edit->moveCursor(QTextCursor::EndOfLine);
}
