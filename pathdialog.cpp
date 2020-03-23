#include "pathdialog.h"
#include "ui_pathdialog.h"

PathDialog::PathDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PathDialog)
{
    ui->setupUi(this);
}

PathDialog::~PathDialog()
{
    delete ui;
}

void PathDialog::on_buttonBox_accepted()
{
    accept();
}

void PathDialog::on_buttonBox_rejected()
{
    reject();
}

QString PathDialog::getPath()
{
    return ui->path->text();
}
