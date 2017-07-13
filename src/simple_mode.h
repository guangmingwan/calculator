#ifndef SIMPLEMODE_H
#define SIMPLEMODE_H

#include <QWidget>
#include <QGridLayout>
#include "line_editor.h"
#include <QKeyEvent>
#include "text_button.h"
#include "core/evaluator.h"

class SimpleMode : public QWidget
{
    Q_OBJECT

public:
    SimpleMode(QWidget *parent = 0);

private:
    QGridLayout *layout;
    LineEditor *editText;
    TextButton *clearButton;
    TextButton *backButton;
    TextButton *divButton;
    TextButton *multButton;
    TextButton *sevenButton;
    TextButton *eightButton;
    TextButton *nineButton;
    TextButton *minusButton;
    TextButton *fourButton;
    TextButton *fiveButton;
    TextButton *sixButton;
    TextButton *plusButton;
    TextButton *oneButton;
    TextButton *twoButton;
    TextButton *threeButton;
    TextButton *zeroButton;
    TextButton *pointButton;
    TextButton *equalButton;

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
