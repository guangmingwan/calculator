#include "common_page.h"
#include "algorithm.h"
#include "utils.h"

CommonPage::CommonPage(QWidget *parent)
    : QWidget(parent)
{
    StateNumber = true;
    StatePoint = true;
    StateSymbol = true;

    layout = new QGridLayout(this);
    editText = new DLineEdit();
    clearButton = new TextButton("AC");
    backButton = new TextButton("←");
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

    initUI();

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
}

void CommonPage::initUI()
{
    layout->setMargin(0);
    layout->setSpacing(0);

    editText->setEnabled(false);
    editText->setFixedHeight(80);
    editText->setAlignment(Qt::AlignRight);

    editText->setObjectName("editTextText");

    equalButton->setFixedHeight(equalButton->height()*2);
    zeroButton->setFixedWidth(zeroButton->width()*2);
    equalButton->setObjectName("TextButtonIs");
}

void CommonPage::on_clear_button_clicked()
{
    editText->clear();

    StateNumber = true;
    StatePoint = true;
    StateSymbol = true;
}

void CommonPage::on_back_button_clicked()
{
    if (editText->text().isEmpty())
        return;
}

void CommonPage::on_number_button_clicked(QString text)
{
    if (!StateNumber) {
        editText->clear();
        editText->insert(text);
        StatePoint = true;
    }else {
        editText->insert(text);
    }

    StateNumber = true;
    StateSymbol = true;
}

void CommonPage::on_div_button_clicked()
{
    on_symbol_button_clicked("÷");
}
void CommonPage::on_mult_button_clicked()
{
    on_symbol_button_clicked("×");
}
void CommonPage::on_seven_button_clicked()
{
    on_number_button_clicked("7");
}

void CommonPage::on_eight_button_clicked()
{
    on_number_button_clicked("8");
}

void CommonPage::on_nine_button_clicked()
{
    on_number_button_clicked("9");
}
void CommonPage::on_minus_button_clicked()
{
    if (editText->text().isEmpty())
    {
        editText->insert("-");
        StateSymbol = false;
        return;
    }

    on_symbol_button_clicked("-");
}

void CommonPage::on_four_button_clicked()
{
    on_number_button_clicked("4");
}

void CommonPage::on_five_button_clicked()
{
    on_number_button_clicked("5");
}

void CommonPage::on_six_button_clicked()
{
    on_number_button_clicked("6");
}

void CommonPage::on_plus_button_clicked()
{
    on_symbol_button_clicked("+");
}

void CommonPage::on_one_button_clicked()
{
    on_number_button_clicked("1");
}

void CommonPage::on_two_button_clicked()
{
    on_number_button_clicked("2");
}

void CommonPage::on_three_button_clicked()
{
    on_number_button_clicked("3");
}

void CommonPage::on_zero_button_clicked()
{
    on_number_button_clicked("0");
}

void CommonPage::on_point_button_clicked()
{
    QChar laster = Utils::getlasterChar(editText->text());

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

    StatePoint = false;
    StateNumber = true;
}

void CommonPage::on_symbol_button_clicked(QString text)
{
    QChar laster = Utils::getlasterChar(editText->text());

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
    StateNumber = true;
    StatePoint = true;
    StateSymbol = false;
}

void CommonPage::on_equal_button_clicked()
{
    if (editText->text().isEmpty())
        return;

    Algorithm algorithm;
    QString expression = editText->text().replace("×", "*").replace("÷", "/");
    double get_result = algorithm.expressionCalculate(expression.toStdString());
    QString data = QString::number(get_result);

    editText->setText(data);

    StateNumber = false;
}
