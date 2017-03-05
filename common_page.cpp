#include "common_page.h"

CommonPage::CommonPage(QWidget *parent)
    : QWidget(parent)
{
    layout = new QGridLayout(this);
    edit = new DLineEdit();
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

    layout->addWidget(edit, 1, 0, 1, 4);

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
}

void CommonPage::initUI()
{
    layout->setMargin(0);
    layout->setSpacing(0);

    edit->setFixedHeight(50);
}
