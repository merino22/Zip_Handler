#include "widget.h"
#include "ui_widget.h"
#include "pathdialog.h"
#include "readZIP.h"
#include <iostream>
#include "JlCompress.h"
#include <string.h>
#include <QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    QStringList titles;
    titles << "Name" << "Size" << "Packed" << "Modified" << "CRC-32";
    ui->setupUi(this);
    setWindowTitle("AM_ZIP_DEMO");
    ui->treeWidget->setColumnCount(5);
    ui->treeWidget->setHeaderLabels(titles);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked()
{
    pathObj.setWindowTitle("Path Input Window");
    string pathExt = "/home/merino/";
    string finalPath = "";
    int result = pathObj.exec();

    if(result == QDialog::Rejected)
    {
        return;
    }

    ui->treeWidget->clear();
    std::string path2 = pathObj.getPath().toLocal8Bit().constData();
    finalPath = pathExt + path2;

    readZIP obj;

    if(obj.openFile(finalPath) == false)
    {
        QMessageBox::about(this, "Error Opening Zip", "Could not find path to Zipfile: " + pathObj.getPath());
        return;
    }


    if(obj.readFile() == false)
    {
        QMessageBox::about(this, "Error Zip Compression Method", "Compression Method not supported");
        return;
    }

    list<FileNode>::iterator it;
    QTreeWidgetItem *item;
    string tmpPrntName;
    QString xl;
    int sizePrntName = 0;
    for(it = obj.fl.begin(); it != obj.fl.end(); ++it)
    {
        bool check = false;
        if((*it).uncompressedSize == 0)//Check if Dir or File
        {
            tmpPrntName = (*it).checkPC;
            sizePrntName = tmpPrntName.size();
            item = new QTreeWidgetItem(ui->treeWidget);
            item->setText(0, QString::fromStdString((*it).name));
            item->setText(1, QString::number((*it).uncompressedSize));
            item->setText(2, QString::number((*it).compressedSize));
            item->setText(3, QString::fromStdString((*it).dateTime));
            item->setText(4, QString::fromStdString((*it).CRC32));
            ui->treeWidget->addTopLevelItem(item);
            check = true;
        }
        else
        {
            if(sizePrntName != 0)
            {
                string tmpPC = "";
                for(int i = 0; i < sizePrntName; i++)
                {
                    tmpPC += (*it).checkPC.at(i);
                }

                if(tmpPC == tmpPrntName)
                {
                    QTreeWidgetItem *item2 = new QTreeWidgetItem();
                    item2->setText(0, QString::fromStdString((*it).name));
                    item2->setText(1, QString::number((*it).uncompressedSize));
                    item2->setText(2, QString::number((*it).compressedSize));
                    item2->setText(3, QString::fromStdString((*it).dateTime));
                    item2->setText(4, QString::fromStdString((*it).CRC32));
                    item->addChild(item2);
                    check = true;
                }
                else
                {
                    item = new QTreeWidgetItem(ui->treeWidget);
                    item->setText(0, QString::fromStdString((*it).name));
                    item->setText(1, QString::number((*it).uncompressedSize));
                    item->setText(2, QString::number((*it).compressedSize));
                    item->setText(3, QString::fromStdString((*it).dateTime));
                    item->setText(4, QString::fromStdString((*it).CRC32));
                    ui->treeWidget->addTopLevelItem(item);
                    check = true;
                }
            }
        }
        if(check == false){
            string tmp = (*it).checkPC;
            (*it).name = tmp;
            item = new QTreeWidgetItem(ui->treeWidget);
            item->setText(0, QString::fromStdString((*it).name));
            item->setText(1, QString::number((*it).uncompressedSize));
            item->setText(2, QString::number((*it).compressedSize));
            item->setText(3, QString::fromStdString((*it).dateTime));
            item->setText(4, QString::fromStdString((*it).CRC32));
            ui->treeWidget->addTopLevelItem(item);
        }
    }

}

void Widget::on_extractButton_clicked()
{
    bool check = true;
    if(ui->treeWidget->currentItem()->text(1) != "0")
    {
        if(ui->treeWidget->currentItem()->parent() == nullptr)
        {
            QStringList listFiles;
            QString dirName = ui->treeWidget->currentItem()->text(0);
            QString tmp;
            QString zipPath = "/home/merino/" + pathObj.getPath();
            QString newDir = "/home/merino/Extracted/ExtractedDir_" + dirName;

            listFiles << dirName;
            QStringList list = JlCompress::extractFiles(zipPath, listFiles, newDir);
        }
        else
        {
            QString parentText = ui->treeWidget->currentItem()->parent()->text(0);
            QString txt = parentText + "/" +ui->treeWidget->currentItem()->text(0);
            QString zipPath = "/home/merino/" + pathObj.getPath();
            QString path = "/home/merino/Extracted/Extracted_" + ui->treeWidget->currentItem()->text(0);

            QStringList listFiles = JlCompress::extractFiles(zipPath, QStringList() << txt, path);
        }
    }
    else
    {
        QStringList listFiles;
        QString dirName = ui->treeWidget->currentItem()->text(0);
        QString tmp;
        QString zipPath = "/home/merino/" + pathObj.getPath();
        QString newDir = "/home/merino/Extracted/ExtractedDir_" + dirName;
        int childCount = ui->treeWidget->currentItem()->childCount();
        for(int i = 0; i < childCount; i++)
        {
            tmp = ui->treeWidget->currentItem()->child(i)->text(0);
            listFiles << dirName + "/" + tmp;
        }
        QStringList list = JlCompress::extractFiles(zipPath, listFiles, newDir);
        check = false;
    }
    if(check == true)
    {
        QMessageBox::about(this, "Extract Process", "File Extracted Successfully");
    }
    else
    {
        QMessageBox::about(this, "Extract Process", "Dir Extracted Successfully");
    }
}

void Widget::on_extractZIP_clicked()
{
    QString finalp = "/home/merino/" + pathObj.getPath();
    QString finalDirP = "/home/merino/Extracted/ExtractedArchive_" + pathObj.getPath();
    QStringList list = JlCompress::extractDir(finalp, finalDirP);
    QMessageBox::about(this, "Extract Process", "Archive Extracted Successfully");
    return;
}

void Widget::on_archInfo_clicked()
{
    info_Obj.setWindowTitle("Archive Info");
    info_Obj.displayText();
    info_Obj.exec();
}
