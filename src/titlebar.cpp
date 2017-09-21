#include "titlebar.h"
#include <QLabel>

TitleBar::TitleBar(QWidget *parent)
    : QWidget(parent)
{
    layout = new QHBoxLayout(this);
    layout->setContentsMargins(0, 0, 0, 0);

    QPixmap iconPixmap = QPixmap(":/image/icon.svg");
    QLabel *iconLabel = new QLabel;
    iconLabel->setPixmap(iconPixmap.scaled(22, 22));

    QLabel *title = new QLabel(tr("calculator"));

    layout->addWidget(iconLabel);
    layout->addWidget(title);
    layout->addStretch();

    setFixedHeight(35);
}
