#include "common_widget.h"

Common::Common(QWidget *parent)
    : QWidget(parent)
{
    label->setAlignment(Qt::AlignRight);
    result->setAlignment(Qt::AlignRight);

    layout->addWidget(label, 0, 0, 1, 4);
    layout->addWidget(result, 1, 0, 1, 4);
    layout->addWidget(btnClear, 2, 0);
    layout->addWidget(btnBack, 2, 1);
    layout->addWidget(btnDiv, 2, 2);
    layout->addWidget(btnMult, 2, 3);
    layout->addWidget(btn7, 3, 0);
    layout->addWidget(btn8, 3, 1);
    layout->addWidget(btn9, 3, 2);
    layout->addWidget(btnMinus, 3, 3);
    layout->addWidget(btn4, 4, 0);
    layout->addWidget(btn5, 4, 1);
    layout->addWidget(btn6, 4, 2);
    layout->addWidget(btnPlus, 4, 3);
    layout->addWidget(btn1, 5, 0);
    layout->addWidget(btn2, 5, 1);
    layout->addWidget(btn3, 5, 2);
    layout->addWidget(btn0, 6, 0, 1, 2);
    layout->addWidget(btnPoint, 6, 2);
    layout->addWidget(btnIs, 5, 3, 2, 2);
    layout->setMargin(0);
    layout->setSpacing(0);
    btn0->setFixedSize(70*2 ,55);
    btnIs->setFixedSize(70, 55*2);
    btnIs->setObjectName("TextButtonIs");
    btnClear->setStyleSheet("color: #2CA7F8; outline: none;");

    connect(btn0, SIGNAL(clicked()), this, SLOT(on_btn0_clicked()));
    connect(btn1, SIGNAL(clicked()), this, SLOT(on_btn1_clicked()));
    connect(btn2, SIGNAL(clicked()), this, SLOT(on_btn2_clicked()));
    connect(btn3, SIGNAL(clicked()), this, SLOT(on_btn3_clicked()));
    connect(btn4, SIGNAL(clicked()), this, SLOT(on_btn4_clicked()));
    connect(btn5, SIGNAL(clicked()), this, SLOT(on_btn5_clicked()));
    connect(btn6, SIGNAL(clicked()), this, SLOT(on_btn6_clicked()));
    connect(btn7, SIGNAL(clicked()), this, SLOT(on_btn7_clicked()));
    connect(btn8, SIGNAL(clicked()), this, SLOT(on_btn8_clicked()));
    connect(btn9, SIGNAL(clicked()), this, SLOT(on_btn9_clicked()));
    connect(btnPoint, SIGNAL(clicked()), this, SLOT(on_btnPoint_clicked()));
    connect(btnClear, SIGNAL(clicked()), this, SLOT(on_btnClear_clicked()));
    connect(btnBack, SIGNAL(clicked()), this, SLOT(on_btnBack_clicked()));
    connect(btnPlus, SIGNAL(clicked()), this, SLOT(on_btnPlus_clicked()));
    connect(btnMinus, SIGNAL(clicked()), this, SLOT(on_btnMinus_clicked()));
    connect(btnMult, SIGNAL(clicked()), this, SLOT(on_btnMult_clicked()));
    connect(btnDiv, SIGNAL(clicked()), this, SLOT(on_btnDiv_clicked()));
    connect(btnIs, SIGNAL(clicked()), this, SLOT(on_btnIs_clicked()));

    this->setLayout(layout);
}

void Common::on_num_clicked(QString text)
{
    if (NumContinue == false)
    {
        label->clear();
        result->clear();
        result->insert(text);
        PointContinue = true;
    }
    else
    {
        result->insert(text);
    }

    NumContinue = true;
    SymbolContinue = true;
}

void Common::on_symbol_clicked(QString text)
{
    QString get = result->text().replace("×", "*").replace("÷", "/");
    QString::const_iterator i = get.end();
    i--;

    if (*i == '+' || *i == '-' || *i == '*' || *i == '/')
    {
        result->backspace();
        result->insert(text);
    }

    if (SymbolContinue == false)
        return;

    if (result->text() == "")
    {
        result->insert("0");
    }

    result->insert(text);
    NumContinue = true;
    PointContinue = true;
    SymbolContinue = false;
}

void Common::on_btnPoint_clicked()
{
    QString get = result->text().replace("×", "*").replace("÷", "/");
    QString::const_iterator i = get.end();
    i--;

    if (*i == '+' || *i == '-' || *i == '*' || *i == '/')
    {
        result->insert("0");
    }

    if (result->text() == "")
    {
        result->insert("0.");
        PointContinue = false;
    }

    if (*i == '.')
    {

    }

    if (PointContinue == true)
    {
        result->insert(".");
        PointContinue = false;
    }

    if (NumContinue == false)
    {
        label->clear();
        result->clear();
        result->insert("0.");
        NumContinue = true;
        SymbolContinue = false;
    }

    PointContinue = false;
    NumContinue = true;
}

void Common::on_btnPlus_clicked()
{
    on_symbol_clicked("+");
}

void Common::on_btnMinus_clicked()
{
    if (result->text() == "")
    {
        on_symbol_clicked("-");
        return;
    }
    on_symbol_clicked("-");
}

void Common::on_btnMult_clicked()
{
    on_symbol_clicked("×");
}

void Common::on_btnDiv_clicked()
{
    on_symbol_clicked("÷");
}

void Common::on_btnClear_clicked()
{
    result->clear();
    label->clear();

    PointContinue = true;
    NumContinue = true;
    SymbolContinue = true;
}

void Common::on_btnBack_clicked()
{
    if (result->text() == "") return;

    QString text = result->text().replace("×", "*").replace("÷", "/");
    QString::const_iterator i = text.end();
    i--;

    if (*i == '0' || *i == '1' || *i == '2' || *i == '3' ||
        *i == '4' || *i == '5' || *i == '6' || *i == '7' ||
        *i == '8' || *i == '9')
    {
        result->backspace();
        NumContinue = true;
    }
    
    if (*i == '.'){
        result->backspace();
        PointContinue = true;
    }
    
    if (*i == '+' || *i == '-' || *i == '*' || *i == '/') {
        result->backspace();
        SymbolContinue = true;
        PointContinue = true;
    }

    i--;
    if (*i == '+' || *i == '-' || *i == '*' || *i == '/')
    {
        SymbolContinue = false;
    }
    if (*i == '.')
    {
        SymbolContinue = false;
    }

    NumContinue = true;
}

void Common::on_btn0_clicked()
{
    on_num_clicked("0");
}

void Common::on_btn1_clicked()
{
    on_num_clicked("1");
}

void Common::on_btn2_clicked()
{
    on_num_clicked("2");
}

void Common::on_btn3_clicked()
{
    on_num_clicked("3");
}

void Common::on_btn4_clicked()
{
    on_num_clicked("4");
}

void Common::on_btn5_clicked()
{
    on_num_clicked("5");
}

void Common::on_btn6_clicked()
{
    on_num_clicked("6");
}

void Common::on_btn7_clicked()
{
    on_num_clicked("7");
}

void Common::on_btn8_clicked()
{
    on_num_clicked("8");
}

void Common::on_btn9_clicked()
{
    on_num_clicked("9");
}

void Common::on_btnIs_clicked()
{
    if(result->text() == "")
    {
        return;
    }

    label->setText(result->text());

    QString expression = label->text().replace("×", "*").replace("÷", "/");
    double get_result = algorithm->expressionCalculate(expression.toStdString());
    QString data = QString::number(get_result);

    result->setText(data);
    label->setToolTip(label->text());

    NumContinue = false;
}
