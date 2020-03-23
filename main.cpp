#include "widget.h"

#include <QApplication>
#include <iostream>
#include "readZIP.h"
#include <string>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //readZIP obj;
    //string filename = "C:\\Users\\aaron\\source\\repos\\EstruII_ZipHandler\\EstruII_ZipHandler\\dir.zip";

    //cout << "Enter ZIP name: ";
    //cin >> filename;

    //obj.openFile(filename);
    //obj.readFile();

    Widget w;
    w.show();
    return a.exec();
}
