#include "common_widget.h"

CommonWidget::CommonWidget(QWidget *parent) : QWidget(parent)
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

    this->setLayout(layout);
}
