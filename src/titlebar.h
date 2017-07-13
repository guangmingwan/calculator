#ifndef TITLEBAR_H
#define TITLEBAR_H

#include <QWidget>
#include <QHBoxLayout>

class TitleBar : public QWidget
{
    Q_OBJECT

public:
    TitleBar(QWidget *parent = 0);

private:
    QHBoxLayout *layout;
};

#endif // TITLEBAR_H
