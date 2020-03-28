#ifndef ARCHIVEINFODIALOG_H
#define ARCHIVEINFODIALOG_H

#include <QDialog>
#include <QFile>
#include <QTextStream>
namespace Ui {
class ArchiveInfoDialog;
}

class ArchiveInfoDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ArchiveInfoDialog(QWidget *parent = nullptr);
    ~ArchiveInfoDialog();
    void displayText();

private:
    Ui::ArchiveInfoDialog *ui;
};

#endif // ARCHIVEINFODIALOG_H
