#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QtCore>
#include <QtGui>
#include <QTreeWidgetItem>
#include <QTreeWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

    void addRoot(QString name, int sizeUncomp, int sizeComp, QString type, int time, int CRC);
    void addChild(QTreeWidgetItem *parent, QString name, int sizeUncomp, int sizeComp, QString type, int time, int CRC);
public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Widget *ui;

    enum Column
    {
        NAME, SIZE, PACKED, TYPE, MODIFIED, CRC32
    };
};
#endif // WIDGET_H
