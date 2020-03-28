#include "archiveinfodialog.h"
#include "ui_archiveinfodialog.h"
#include <QMessageBox>
#include <iostream>

ArchiveInfoDialog::ArchiveInfoDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ArchiveInfoDialog)
{
    ui->setupUi(this);

}

ArchiveInfoDialog::~ArchiveInfoDialog()
{
    delete ui;
}

void ArchiveInfoDialog::displayText()
{
    QFile file("/home/merino/Aaron/fileInfo.txt");

    if(!file.open(QIODevice::ReadOnly))
    {
        std::cout << "Did not find text File" << std::endl;
    }
    QTextStream in(&file);
    ui->textBrowser->setText(in.readAll());
}
