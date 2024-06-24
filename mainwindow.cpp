#include "mainwindow.h"

MainWindow::MainWindow(QApplication& app):godmode(false)
{
    area = new DrawArea;

    QHBoxLayout *buttonLayout = new QHBoxLayout;
    buttonStart = new QPushButton("Старт!");
    buttonQuit = new QPushButton("Выход!");
    connect(buttonQuit, SIGNAL(clicked()), &app, SLOT(quit()));
    connect(buttonStart, SIGNAL(clicked()), area, SLOT(setGame()));
    buttonLayout->addWidget(buttonStart);
    buttonLayout->addWidget(buttonQuit);

    QGridLayout *mainLayout = new QGridLayout;
    mainLayout->addWidget(area,0,0);
    mainLayout->addLayout(buttonLayout,1,0);
    setLayout(mainLayout);

    setWindowTitle("Чибиринт");
};

MainWindow::~MainWindow(){
    delete area;
    delete buttonQuit;
    delete buttonStart;
}

void MainWindow::keyPressEvent(QKeyEvent *event){
    int helpx, helpy;
    bool check = true;
    switch (event->key()){
    case Qt::Key_G:
        godmode = !godmode;
        break;
    case Qt::Key_W:
    case Qt::Key_Up:
        helpx = area->_X;
        helpy = area->_Y - 11;
        if(!godmode && area->maze.pixelColor(helpx, helpy) == Qt::black){
            check = false;
        }
        if(check){
            area->_Y -= 11;
            update();
        }
        if(area->maze.pixelColor(helpx, helpy) == Qt::red){
            godmode = false;
            area->setWin();
        }
        break;
    case Qt::Key_A:
    case Qt::Key_Left:
        helpx = area->_X - 11;
        helpy = area->_Y;
        if(!godmode && area->maze.pixelColor(helpx, helpy) == Qt::black){
            check = false;
        }
        if(check){
            area->_X -= 11;
            update();
        }
        if(area->maze.pixelColor(helpx, helpy) == Qt::red){
            godmode = false;
            area->setWin();
        }
        break;
    case Qt::Key_S:
    case Qt::Key_Down:
        helpx = area->_X;
        helpy = area->_Y + 11;
        if(!godmode && area->maze.pixelColor(helpx, helpy) == Qt::black){
            check = false;
        }
        if(check){
            area->_Y += 11;
            update();
        }
        if(area->maze.pixelColor(helpx, helpy) == Qt::red){
            godmode = false;
            area->setWin();
        }
        break;
    case Qt::Key_D:
    case Qt::Key_Right:
        helpx = area->_X + 11;
        helpy = area->_Y;
        if(!godmode && area->maze.pixelColor(helpx, helpy) == Qt::black){
            check = false;
        }
        if(check){
            area->_X += 11;
            update();
        }
        if(area->maze.pixelColor(helpx, helpy) == Qt::red){
            godmode = false;
            area->setWin();
        }
        break;
    }
}
