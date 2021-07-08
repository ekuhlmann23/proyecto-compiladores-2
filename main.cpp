#include "mainwindow.h"

#include <QApplication>
#include "binary/lex.yy.h"
#include <cstdlib>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
