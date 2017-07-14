#include "scientific_mode.h"
#include <QToolTip>
#include <QKeyEvent>

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
    state = new QLabel(this);
    display = new ResultDisplay;
    editor = new LineEditor;

    editor->setObjectName("ScEdit");

    state->setPalette(QToolTip::palette());
    state->setAutoFillBackground(true);
    state->setFrameShape(QFrame::Box);
    state->hide();

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

    layout->addWidget(display);
    layout->addLayout(topLayout);
    layout->addLayout(layout1);
    layout->addLayout(layout2);
    layout->addLayout(layout3);
    layout->addLayout(layout4);

    layout->setContentsMargins(0, 0, 0, 0);

    setLayout(layout);

    connect(editor, SIGNAL(autoCalculatorMessage(QString)), this, SLOT(showStateLabel(QString)));
    connect(editor, SIGNAL(autoCalculatorError(QString)), this, SLOT(showStateLabel(QString)));
    connect(editor, SIGNAL(textChanged(QString)), this, SLOT(lineEditTextChanged(QString)));
    connect(btnIs, SIGNAL(clicked(bool)), this, SLOT(on_equal_button_clicked()));

    connect(btn7, &QPushButton::clicked, this, [=]{
        editor->insert("7");
    });
    connect(btn8, &QPushButton::clicked, this, [=]{
        editor->insert("8");
    });
    connect(btn9, &QPushButton::clicked, this, [=]{
        editor->insert("9");
    });
    connect(btnDiv, &QPushButton::clicked, this, [=]{
        editor->insert("÷");
    });
    connect(btnC, &QPushButton::clicked, this, [=]{
        editor->clear();
    });
    connect(btnRoot, &QPushButton::clicked, this, [=]{
        editor->insert("sqrt(");
    });
    connect(btnP, &QPushButton::clicked, this, [=]{
        editor->insert("pi");
    });
    connect(btnExp, &QPushButton::clicked, this, [=]{
        editor->insert("exp(");
    });
    connect(btnLn, &QPushButton::clicked, this, [=]{
        editor->insert("ln(");
    });

    connect(btn4, &QPushButton::clicked, this, [=]{
        editor->insert("4");
    });
    connect(btn5, &QPushButton::clicked, this, [=]{
        editor->insert("5");
    });
    connect(btn6, &QPushButton::clicked, this, [=]{
        editor->insert("6");
    });
    connect(btnMult, &QPushButton::clicked, this, [=]{
        editor->insert("÷");
    });
    connect(btnE, &QPushButton::clicked, this, [=]{
        editor->insert("e");
    });
    connect(btnS, &QPushButton::clicked, this, [=]{
        editor->insert("^");
    });
    connect(btnAns, &QPushButton::clicked, this, [=]{
        editor->insert("ans");
    });
    connect(btnSin, &QPushButton::clicked, this, [=]{
        editor->insert("sin(");
    });
    connect(btnArcsin, &QPushButton::clicked, this, [=]{
        editor->insert("arcsin(");
    });

    connect(btn1, &QPushButton::clicked, this, [=]{
        editor->insert("1");
    });
    connect(btn2, &QPushButton::clicked, this, [=]{
        editor->insert("2");
    });
    connect(btn3, &QPushButton::clicked, this, [=]{
        editor->insert("3");
    });
    connect(btnMinus, &QPushButton::clicked, this, [=]{
        editor->insert("-");
    });
    connect(btnLeft, &QPushButton::clicked, this, [=]{
        editor->insert("(");
    });
    connect(btnRight, &QPushButton::clicked, this, [=]{
        editor->insert(")");
    });
    connect(btnX, &QPushButton::clicked, this, [=]{
        editor->insert("x");
    });
    connect(btnCos, &QPushButton::clicked, this, [=]{
        editor->insert("cos(");
    });
    connect(btnArccos, &QPushButton::clicked, this, [=]{
        editor->insert("arccos(");
    });

    connect(btn0, &QPushButton::clicked, this, [=]{
        editor->insert("0");
    });
    connect(btnPoint, &QPushButton::clicked, this, [=]{
        editor->insert(".");
    });
    connect(btnPlus, &QPushButton::clicked, this, [=]{
        editor->insert("+");
    });
    connect(btnMod, &QPushButton::clicked, this, [=]{
        editor->insert("%");
    });
    connect(btnG, &QPushButton::clicked, this, [=]{
        editor->insert("!");
    });
    connect(btnXis, &QPushButton::clicked, this, [=]{
        editor->insert("x=");
    });
    connect(btnTan, &QPushButton::clicked, this, [=]{
        editor->insert("tan(");
    });
    connect(btnArctan, &QPushButton::clicked, this, [=]{
        editor->insert("arctan(");
    });

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

    display->append(editor->text());
    display->append(QString("= %1").arg(result));
    display->append(QLatin1String(""));

    editor->setText(result);
    editor->setFocus();
    display->moveCursor(QTextCursor::EndOfLine);

    editor->clear();
}

void ScientificMode::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Enter || event->key() == Qt::Key_Return) {
        btnIs->clicked(true);
    }
}

void ScientificMode::showStateLabel(const QString &text)
{
    state->setText(text);
    state->adjustSize();
    state->show();
    state->raise();

    const int height = state->height();
    QPoint pos= mapFromGlobal(editor->mapToGlobal(QPoint(0, -height)));
    state->move(pos);
}

void ScientificMode::lineEditTextChanged(const QString &text)
{
    if (text.isEmpty()) {
        state->hide();
    }
}
