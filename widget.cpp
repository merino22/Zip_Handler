#include "widget.h"
#include "ui_widget.h"
#include "pathdialog.h"
#include "readZIP.h"
#include <iostream>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    QStringList titles;
    titles << "Name" << "Size" << "Packed" << "Type" << "Modified" << "CRC-32";
    ui->setupUi(this);
    setWindowTitle("AM_ZIP_DEMO");
    ui->tableWidget->setColumnCount(6);
    ui->tableWidget->setHorizontalHeaderLabels(titles);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked()
{
    PathDialog pathObj;
    pathObj.setWindowTitle("Path Input Window");
    string pathExt = "C:\\Users\\aaron\\source\\repos\\EstruII_ZipHandler\\EstruII_ZipHandler\\";
    string finalPath = "";
    int result = pathObj.exec();

    if(result == QDialog::Rejected)
    {
        return;
    }
    std::string path2 = pathObj.getPath().toLocal8Bit().constData();
    finalPath = pathExt + path2;

    readZIP obj;

    obj.openFile(finalPath);
    obj.readFile();


    list<FileNode>::iterator it;

    for(it = obj.fl.begin(); it != obj.fl.end(); ++it)
    {
        ui->tableWidget->insertRow(ui->tableWidget->rowCount());
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, NAME, new QTableWidgetItem(it->name));
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, SIZE, new QTableWidgetItem(QString::number(it->uncompressedSize)));
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, PACKED, new QTableWidgetItem(QString::number(it->compressedSize)));
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, TYPE, new QTableWidgetItem("N/a"));
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, MODIFIED, new QTableWidgetItem(QString::number(it->time)));
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, CRC32, new QTableWidgetItem(QString::number(it->CRC32)));
    }






}
