#include "simple_mode.h"
#include "utils.h"

typedef Quantity::Format Format;

SimpleMode::SimpleMode(QWidget *parent)
    : QWidget(parent)
{
    layout = new QGridLayout(this);
    editText = new QLineEdit();
    clearButton = new TextButton("AC");
    backButton = new TextButton("+/_");
    divButton = new TextButton("÷");
    multButton = new TextButton("×");

    sevenButton = new TextButton("7");
    eightButton = new TextButton("8");
    nineButton = new TextButton("9");
    minusButton = new TextButton("－");

    fourButton = new TextButton("4");
    fiveButton = new TextButton("5");
    sixButton = new TextButton("6");
    plusButton = new TextButton("＋");

    oneButton = new TextButton("1");
    twoButton = new TextButton("2");
    threeButton = new TextButton("3");

    zeroButton = new TextButton("0");
    pointButton = new TextButton(".");
    equalButton = new TextButton("＝");

    m_evaluator = Evaluator::instance();;


    layout->addWidget(editText, 1, 0, 1, 4);

    layout->addWidget(clearButton, 2, 0);
    layout->addWidget(backButton, 2, 1);
    layout->addWidget(divButton, 2, 2);
    layout->addWidget(multButton, 2, 3);

    layout->addWidget(sevenButton, 3, 0);
    layout->addWidget(eightButton, 3, 1);
    layout->addWidget(nineButton, 3, 2);
    layout->addWidget(minusButton, 3, 3);

    layout->addWidget(fourButton, 4, 0);
    layout->addWidget(fiveButton, 4, 1);
    layout->addWidget(sixButton, 4, 2);
    layout->addWidget(plusButton, 4, 3);

    layout->addWidget(oneButton, 5, 0);
    layout->addWidget(twoButton, 5, 1);
    layout->addWidget(threeButton, 5, 2);

    layout->addWidget(zeroButton, 6, 0, 1, 2);
    layout->addWidget(pointButton, 6, 2);
    layout->addWidget(equalButton, 5, 3, 2, 2);

    layout->setMargin(0);
    layout->setSpacing(0);
    layout->setContentsMargins(0, 0, 0, 0);

    connect(clearButton, SIGNAL(clicked(bool)), this, SLOT(on_clear_button_clicked()));
    connect(backButton, SIGNAL(clicked(bool)), this, SLOT(on_back_button_clicked()));
    connect(divButton, SIGNAL(clicked(bool)), this, SLOT(on_div_button_clicked()));
    connect(multButton, SIGNAL(clicked(bool)), this, SLOT(on_mult_button_clicked()));
    connect(minusButton, SIGNAL(clicked(bool)), this, SLOT(on_minus_button_clicked()));
    connect(plusButton, SIGNAL(clicked(bool)), this, SLOT(on_plus_button_clicked()));
    connect(pointButton, SIGNAL(clicked(bool)), this, SLOT(on_point_button_clicked()));
    connect(sevenButton, SIGNAL(clicked(bool)), this, SLOT(on_seven_button_clicked()));
    connect(eightButton, SIGNAL(clicked(bool)), this, SLOT(on_eight_button_clicked()));
    connect(nineButton, SIGNAL(clicked(bool)), this, SLOT(on_nine_button_clicked()));
    connect(fourButton, SIGNAL(clicked(bool)), this, SLOT(on_four_button_clicked()));
    connect(fiveButton, SIGNAL(clicked(bool)), this, SLOT(on_five_button_clicked()));
    connect(sixButton, SIGNAL(clicked(bool)), this, SLOT(on_six_button_clicked()));
    connect(oneButton, SIGNAL(clicked(bool)), this, SLOT(on_one_button_clicked()));
    connect(twoButton, SIGNAL(clicked(bool)), this, SLOT(on_two_button_clicked()));
    connect(threeButton, SIGNAL(clicked(bool)), this, SLOT(on_three_button_clicked()));
    connect(zeroButton, SIGNAL(clicked(bool)), this, SLOT(on_zero_button_clicked()));
    connect(equalButton, SIGNAL(clicked(bool)), this, SLOT(on_equal_button_clicked()));

    initUI();
}

void SimpleMode::initUI()
{
    editText->setFixedHeight(80);
    editText->setAlignment(Qt::AlignRight);

    equalButton->setFixedHeight(equalButton->height()*2);
    zeroButton->setFixedWidth(zeroButton->width()*2);
}

void SimpleMode::on_clear_button_clicked()
{
    editText->clear();
    editText->setFocus();

    StateNumber = true;
    StatePoint = true;
    StateSymbol = true;
}

void SimpleMode::on_back_button_clicked()
{
    if (editText->text().isEmpty())
        return;
}

void SimpleMode::on_number_button_clicked(const QString &text)
{
    if (!StateNumber) {
        editText->clear();
        editText->insert(text);
        StatePoint = true;
    }else {
        editText->insert(text);
    }

    editText->setFocus();

    StateNumber = true;
    StateSymbol = true;
}

void SimpleMode::on_div_button_clicked()
{
    on_symbol_button_clicked("÷");
}
void SimpleMode::on_mult_button_clicked()
{
    on_symbol_button_clicked("×");
}
void SimpleMode::on_seven_button_clicked()
{
    on_number_button_clicked("7");
}

void SimpleMode::on_eight_button_clicked()
{
    on_number_button_clicked("8");
}

void SimpleMode::on_nine_button_clicked()
{
    on_number_button_clicked("9");
}
void SimpleMode::on_minus_button_clicked()
{
    if (editText->text().isEmpty())
    {
        editText->insert("-");
        StateSymbol = false;
        return;
    }

    on_symbol_button_clicked("-");
}

void SimpleMode::on_four_button_clicked()
{
    on_number_button_clicked("4");
}

void SimpleMode::on_five_button_clicked()
{
    on_number_button_clicked("5");
}

void SimpleMode::on_six_button_clicked()
{
    on_number_button_clicked("6");
}

void SimpleMode::on_plus_button_clicked()
{
    on_symbol_button_clicked("+");
}

void SimpleMode::on_one_button_clicked()
{
    on_number_button_clicked("1");
}

void SimpleMode::on_two_button_clicked()
{
    on_number_button_clicked("2");
}

void SimpleMode::on_three_button_clicked()
{
    on_number_button_clicked("3");
}

void SimpleMode::on_zero_button_clicked()
{
    on_number_button_clicked("0");
}

void SimpleMode::on_point_button_clicked()
{
    QChar laster = Utils::getLasterChar(editText->text());

    if (editText->text().isEmpty())
    {
        editText->insert("0.");
        StatePoint = false;
    }

    if (laster == '+' ||
        laster == '-' ||
        laster == '*' ||
        laster == '/')
    {
        editText->insert("0");
    }

    if (StatePoint)
    {
        editText->insert(".");
    }

    if (!StateNumber)
    {
        editText->clear();
        editText->insert("0.");
        StateSymbol = false;
    }

    editText->setFocus();

    StatePoint = false;
    StateNumber = true;
}

void SimpleMode::on_symbol_button_clicked(const QString &text)
{
    QChar laster = Utils::getLasterChar(editText->text());

    if (laster == '+' ||
        laster == '-' ||
        laster == '*' ||
        laster == '/')
    {
        editText->backspace();
        editText->insert(text);
    }

    if (laster == '.')
    {
        editText->insert("0");
        StateSymbol = true;
    }

    if (!StateSymbol)
        return;

    if (editText->text().isEmpty())
        editText->insert("0");

    editText->insert(text);
    editText->setFocus();

    StateNumber = true;
    StatePoint = true;
    StateSymbol = false;
}

void SimpleMode::on_equal_button_clicked()
{
    if (editText->text().isEmpty())
        return;

    m_evaluator->initializeBuiltInVariables();
    m_evaluator->autoFix(editText->text());
    m_evaluator->setExpression(editText->text().replace("×", "*").replace("÷", "/"));

    Quantity rn = m_evaluator->evalUpdateAns();
    QString result = DMath::format(rn, Format::Fixed());

    editText->setText(result);
    editText->setFocus();

    StateNumber = false;
}
