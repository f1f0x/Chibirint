#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QtWidgets>
#include <QPainter>
#include <QKeyEvent>
#include <QDebug>

#include "drawarea.h"

class MainWindow : public QWidget
{
    Q_OBJECT

    QPushButton *buttonQuit;
    QPushButton *buttonStart;
    DrawArea* area;
    bool godmode;
public:

    MainWindow(QApplication& app);
    ~MainWindow();
    void keyPressEvent(QKeyEvent *event);

};
#endif // MAINWINDOW_H
