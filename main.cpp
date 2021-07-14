#include "mainwindow.h"

#include <QApplication>


//#include <solver.h>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


   // QInputMethod *keyboard = QGuiApplication::inputMethod();
    //keyboard->show();
   // a.setAutoSipEnabled(true);

    MainWindow w;



    w.show();
    return a.exec();
}
