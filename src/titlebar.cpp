#include "titlebar.h"
#include <QLabel>
#include <QSvgWidget>

TitleBar::TitleBar(QWidget *parent)
    : QWidget(parent)
{
    layout = new QHBoxLayout(this);
    layout->setContentsMargins(0, 0, 0, 0);

    QSvgWidget *iconWidget = new QSvgWidget(":/image/icon.svg");
    iconWidget->setFixedSize(22, 22);

    QLabel *title = new QLabel(tr("calculator"));

    layout->addWidget(iconWidget);
    layout->addWidget(title);
    layout->addStretch();

    setFixedHeight(35);
}
