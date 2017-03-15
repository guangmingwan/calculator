#include "titlebar.h"
#include "utils.h"
#include <QLabel>
#include <dlabel.h>

DWIDGET_USE_NAMESPACE

Titlebar::Titlebar(QWidget *parnet)
    : QWidget(parnet)
{
    QHBoxLayout *layout = new QHBoxLayout(this);

    QPixmap iconPixmap = QPixmap(Utils::getImagePath("logo.png"));
    QLabel *iconLabel = new QLabel();
    iconLabel->setPixmap(iconPixmap.scaled(16, 16));

    DLabel *title = new DLabel(tr("Calculator"));

    layout->addWidget(iconLabel);
    layout->addWidget(title);
    layout->addStretch();
}
