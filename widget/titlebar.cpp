#include "titlebar.h"
#include <QPainter>
#include <QHBoxLayout>
#include <QApplication>
#include <QFile>

TitleBar::TitleBar(QWidget *parent)
    : QWidget(parent) ,
      m_icon(new QLabel)
{
    closeButton = new QPushButton(this);
    closeButton->setObjectName("CloseButton");
    closeButton->setFixedSize(27, 23);
    closeButton->setAttribute(Qt::WA_NoMousePropagation);
    closeButton->setFocusPolicy(Qt::NoFocus);
    connect(closeButton, &QPushButton::clicked, this, [=]
    {
        qApp->quit();
    });

    miniButton = new QPushButton(this);
    miniButton->setObjectName("MinimizeButton");
    miniButton->setFixedSize(27, 23);
    miniButton->setAttribute(Qt::WA_NoMousePropagation);
    miniButton->setFocusPolicy(Qt::NoFocus);
    connect(miniButton, SIGNAL(clicked()), this, SIGNAL(on_minimised()));

    menuButton = new QPushButton(this);
    menuButton->setObjectName("MenuButton");
    menuButton->setFixedSize(27, 23);
    menuButton->setAttribute(Qt::WA_NoMousePropagation);
    menuButton->setFocusPolicy(Qt::NoFocus);

    connect(menuButton, &QPushButton::clicked, this, [=]
    {
        if (parentWidget())
        {
            const QPoint gp = this->mapToGlobal(QPoint(0, 0));
            const QSize ms = m_menu->sizeHint();
            const QPoint p(gp.x() + width() - ms.width() - 30,
            gp.y() + 36 - 10);
            m_menu->popup(p);
            menuButton->setVisible(false);
            menuButton->setVisible(true);
        }
    });
    
    m_icon->setStyleSheet("margin-left: 10px; margin-bottom: 10px;");
    m_icon->setPixmap(QPixmap(":/resources/icon.png"));

    m_title = new QLabel("Calculator");
    m_title->setStyleSheet("font-size: 14px; margin-bottom: 10px;");

    QHBoxLayout *layout = new QHBoxLayout;

    layout->setContentsMargins(0, 0, 5, 0);
    layout->addWidget(m_icon);
    layout->addWidget(m_title);
    layout->addStretch();

    layout->addWidget(menuButton);
    layout->addWidget(miniButton);
    layout->addWidget(closeButton);

    setLayout(layout);

    initMenu();
}

void TitleBar::initMenu()
{
    m_menu = new QMenu;

    QAction *style = m_menu->addAction("切换主题");
    QAction *history = m_menu->addAction("历史记录");
    QAction *aboutAction = m_menu->addAction("关于");

    connect(m_menu, &QMenu::triggered, [this, aboutAction, history, style](QAction *action)
    {
        if (style == action) {
            config->switch_style();
        }
    });
}

void TitleBar::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    QRect rect = this->rect();
    QPoint bottomLeft(rect.x(), rect.y() + rect.height());
    QPoint bottomRight(rect.x() + rect.width(), rect.y() + rect.height());

    QPen borderPen(QColor(0, 0, 0, 255*0.15));
    painter.setPen(borderPen);
    painter.drawLine(bottomLeft, bottomRight);
}

void TitleBar::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        m_isPressed = true;
        m_startMovePos = event->globalPos();
    }

    return QWidget::mousePressEvent(event);
}

void TitleBar::mouseMoveEvent(QMouseEvent *event)
{
    if (m_isPressed)
    {
        QPoint movePoint = event->globalPos() - m_startMovePos;
        QPoint widgetPos = this->parentWidget()->pos();
        m_startMovePos = event->globalPos();
        this->parentWidget()->move(widgetPos.x() + movePoint.x(), widgetPos.y() + movePoint.y());
    }

    return QWidget::mouseMoveEvent(event);
}

void TitleBar::mouseReleaseEvent(QMouseEvent *event)
{
    m_isPressed = false;

    return QWidget::mouseReleaseEvent(event);
}
