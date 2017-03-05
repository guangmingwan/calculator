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

private:
    void initUI();
};

#endif
