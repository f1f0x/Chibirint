#include "drawarea.h"

DrawArea::DrawArea()
{
    setFixedSize(407, 407);
    state = Start;
    maze.load(":/image/Maze.png");
    _X = 190;
    _Y = 212;
}

void DrawArea::setWin(){
    state = Win;
    releaseKeyboard();
    _X = 0;
    _Y = 0;
    update();
}
void DrawArea::setGame(){
    state = Game;
    _X = 190;
    _Y = 212;
    grabKeyboard();
    update();
}


void DrawArea::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setPen(QPen(Qt::black, 22));
    painter.setBrush(Qt::white);
    painter.drawRect(QRect(0, 0, width()-1, height()-1));
    if(state == Start){
        QFont font = painter.font();
        font.setPixelSize(64);
        painter.setFont(font);
        painter.drawText(QRect(50,150,300,100),0,"Чибиринт!");
    }
    else if(state == Win){
        QFont font = painter.font();
        font.setPixelSize(64);
        painter.setFont(font);
        painter.drawText(QRect(90,150,300,100),0,"Победа!");
    }
    else{
        painter.drawImage(0,0,maze);
        painter.setBrush(Qt::magenta);
        painter.setPen(QPen(Qt::magenta));

        painter.drawEllipse(_X, _Y,5,5);
    }
}

