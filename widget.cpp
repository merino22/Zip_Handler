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
    ui->treeWidget->setColumnCount(6);
    ui->treeWidget->setHeaderLabels(titles);
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
    QTreeWidgetItem *item;
    int pos = 0;
    string tmpName;
    for(it = obj.fl.begin(); it != obj.fl.end(); ++it)
    {
        tmpName = string((*it).name);
        pos = tmpName.size();
        if(tmpName.at(pos-1) == '/')
        {
            item = new QTreeWidgetItem(ui->treeWidget);
            item->setText(0, QString::fromStdString(tmpName));
            item->setText(1, QString::number((*it).uncompressedSize));
            item->setText(2, QString::number((*it).compressedSize));
            item->setText(3, QString::number(strlen((*it).name)));
            item->setText(4, QString::fromStdString((*it).dateTime));
            item->setText(5, QString::number((*it).CRC32));
            ui->treeWidget->addTopLevelItem(item);
        }
        else
        {
            QTreeWidgetItem *item2 = new QTreeWidgetItem();
            item2->setText(0, (*it).name);
            item2->setText(1, QString::number((*it).uncompressedSize));
            item2->setText(2, QString::number((*it).compressedSize));
            item2->setText(3,  QString::number(strlen((*it).name)));
            item2->setText(4, QString::fromStdString((*it).dateTime));
            item2->setText(5, QString::number((*it).CRC32));
            item->addChild(item2);
        }
    }

}

void Widget::addRoot(QString name, int sizeUncomp, int sizeComp, QString type, int time, int CRC)
{
    QTreeWidgetItem *item = new QTreeWidgetItem();
    item->setText(0, name);
    item->setText(1, QString::number(sizeUncomp));
    item->setText(2, QString::number(sizeComp));
    item->setText(3, type);
    item->setText(4, QString::number(time));
    item->setText(5, QString::number(CRC));
    ui->treeWidget->addTopLevelItem(item);
}

void Widget::addChild(QTreeWidgetItem *parent,  QString name, int sizeUncomp, int sizeComp, QString type, int time, int CRC)
{
    QTreeWidgetItem *item = new QTreeWidgetItem();
    item->setText(0, name);
    item->setText(1, QString::number(sizeUncomp));
    item->setText(2, QString::number(sizeComp));
    item->setText(3, type);
    item->setText(4, QString::number(time));
    item->setText(5, QString::number(CRC));
    parent->addChild(item);
}
