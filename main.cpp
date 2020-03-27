#include "widget.h"

#include <QApplication>
#include <iostream>
#include "readZIP.h"
#include <string>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Widget w;
    w.show();
    return a.exec();
}
