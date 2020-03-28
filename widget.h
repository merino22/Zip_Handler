#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QtCore>
#include <QtGui>
#include <QTreeWidgetItem>
#include <QTreeWidget>
#include "readZIP.h"
#include "pathdialog.h"
#include "archiveinfodialog.h"
QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

    void setLast(bool check, list<FileNode>::iterator it, QTreeWidget *itm);
public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    readZIP obj;
    PathDialog pathObj;
    ArchiveInfoDialog info_Obj;
private slots:
    void on_pushButton_clicked();

    void on_extractButton_clicked();

    void on_extractZIP_clicked();

    void on_archInfo_clicked();

private:
    Ui::Widget *ui;

    enum Column
    {
        NAME, SIZE, PACKED, TYPE, MODIFIED, CRC32
    };
};
#endif // WIDGET_H
