#ifndef SIMPLEMODE_H
#define SIMPLEMODE_H

#include <QWidget>
#include <QGridLayout>
#include "simple_edit.h"
#include <QKeyEvent>
#include "simple_button.h"
#include "core/evaluator.h"

class SimpleMode : public QWidget
{
    Q_OBJECT

public:
    SimpleMode(QWidget *parent = 0);

private:
    QGridLayout *layout;
    SimpleEdit *editText;
    SimpleButton *clearButton;
    SimpleButton *backButton;
    SimpleButton *divButton;
    SimpleButton *multButton;
    SimpleButton *sevenButton;
    SimpleButton *eightButton;
    SimpleButton *nineButton;
    SimpleButton *minusButton;
    SimpleButton *fourButton;
    SimpleButton *fiveButton;
    SimpleButton *sixButton;
    SimpleButton *plusButton;
    SimpleButton *oneButton;
    SimpleButton *twoButton;
    SimpleButton *threeButton;
    SimpleButton *zeroButton;
    SimpleButton *pointButton;
    SimpleButton *equalButton;

    Evaluator* m_evaluator;

    void initUI();

protected:
    void keyPressEvent(QKeyEvent *);

public slots:
    void on_clear_button_clicked();
    void on_back_button_clicked();
    void on_div_button_clicked();
    void on_mult_button_clicked();
    void on_seven_button_clicked();
    void on_eight_button_clicked();
    void on_nine_button_clicked();
    void on_minus_button_clicked();
    void on_four_button_clicked();
    void on_five_button_clicked();
    void on_six_button_clicked();
    void on_plus_button_clicked();
    void on_one_button_clicked();
    void on_two_button_clicked();
    void on_three_button_clicked();
    void on_zero_button_clicked();
    void on_point_button_clicked();
    void on_equal_button_clicked();

    void on_number_button_clicked(const QString &text);
    void on_symbol_button_clicked(const QString &text);
};

#endif // SIMPLEMODE_H
