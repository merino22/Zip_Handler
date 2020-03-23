#ifndef PATHDIALOG_H
#define PATHDIALOG_H

#include <QDialog>

namespace Ui {
class PathDialog;
}

class PathDialog : public QDialog
{
    Q_OBJECT

public:
    explicit PathDialog(QWidget *parent = nullptr);
    ~PathDialog();

    QString getPath();
private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::PathDialog *ui;
};

#endif // PATHDIALOG_H
