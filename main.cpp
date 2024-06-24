#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    app.setApplicationName("Chibyrinth");
    MainWindow w(app);
    w.show();
    return app.exec();
}
