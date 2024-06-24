#ifndef DRAWAREA_H
#define DRAWAREA_H

#include <QWidget>
#include <QtWidgets>

enum STATE{Start,Game,Win};

class DrawArea : public QWidget
{
    Q_OBJECT

    friend class MainWindow;
    STATE state;
    QImage maze;
    int _X, _Y;

public:
    DrawArea();
    void paintEvent(QPaintEvent *event);

public slots:
    void setWin();
    void setGame();
};

#endif // DRAWAREA_H
