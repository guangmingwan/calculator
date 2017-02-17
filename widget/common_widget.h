#ifndef COMMONLAYOUT_H
#define COMMONLAYOUT_H

#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include "text_button.h"

class CommonWidget : public QWidget
{
    Q_OBJECT

public:
    explicit CommonWidget(QWidget *parent = 0);

private:
    QGridLayout *layout = new QGridLayout;

    QLabel *label = new QLabel("");
    QLineEdit *result = new QLineEdit();
    TextButton *btnClear = new TextButton("C");
    TextButton *btnBack = new TextButton("←");
    TextButton *btnDiv = new TextButton("÷");
    TextButton *btn7 = new TextButton("7");
    TextButton *btn8 = new TextButton("8");
    TextButton *btn9 = new TextButton("9");
    TextButton *btnMult = new TextButton("×");
    TextButton *btn4 = new TextButton("4");
    TextButton *btn5 = new TextButton("5");
    TextButton *btn6 = new TextButton("6");
    TextButton *btnMinus = new TextButton("－");
    TextButton *btn1 = new TextButton("1");
    TextButton *btn2 = new TextButton("2");
    TextButton *btn3 = new TextButton("3");
    TextButton *btnPlus = new TextButton("＋");
    TextButton *btn0 = new TextButton("0");
    TextButton *btnPoint = new TextButton(".");
    TextButton *btnIs = new TextButton("＝");
};

#endif // COMMONLAYOUT_H
