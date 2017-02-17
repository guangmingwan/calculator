#ifndef COMMON_H
#define COMMON_H

#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include "algorithm.h"
#include "text_button.h"

class Common : public QWidget
{
    Q_OBJECT

public:
    explicit Common(QWidget *parent = 0);
    void on_num_clicked(QString text);
    void on_symbol_clicked(QString text);

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

    bool PointContinue = true;
    bool NumContinue = true;
    bool SymbolContinue = true;

    Algorithm *algorithm;

private slots:
    void on_btn0_clicked();
    void on_btn1_clicked();
    void on_btn2_clicked();
    void on_btn3_clicked();
    void on_btn4_clicked();
    void on_btn5_clicked();
    void on_btn6_clicked();
    void on_btn7_clicked();
    void on_btn8_clicked();
    void on_btn9_clicked();
    void on_btnClear_clicked();
    void on_btnBack_clicked();
    void on_btnPoint_clicked();
    void on_btnPlus_clicked();
    void on_btnMinus_clicked();
    void on_btnMult_clicked();
    void on_btnDiv_clicked();
    void on_btnIs_clicked();
};

#endif // COMMON_H
