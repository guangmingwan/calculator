#ifndef COMMONPAGE_H
#define COMMONPAGE_H

#include <QWidget>
#include <QGridLayout>
#include <dlineedit.h>
#include "text_button.h"

DWIDGET_USE_NAMESPACE

class CommonPage : public QWidget
{
    Q_OBJECT

public:
    CommonPage(QWidget *parent = 0);

    QGridLayout *layout;
    DLineEdit *edit;
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

    void on_number_button_clicked(QString text);
    void on_symbol_button_clicked(QString text);

private:
    void initUI();

    bool StateNumber;
    bool StatePoint;
    bool StateSymbol;
};

#endif
