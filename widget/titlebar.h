#pragma once

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QMenu>
#include <QMouseEvent>
#include "settings.h"

class TitleBar : public QWidget
{
    Q_OBJECT

public:
    explicit TitleBar(QWidget *parent = 0);

    void initMenu();

    virtual void paintEvent(QPaintEvent *);

    Settings *config = new Settings();

private:
    QMenu *m_menu;
    QLabel *m_title;
    QPushButton *menuButton;
    QPushButton *miniButton;
    QPushButton *closeButton;

    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

    bool m_isPressed;
    QPoint m_startMovePos;

signals:
    void on_minimised();
    void on_history_dialog();

};
