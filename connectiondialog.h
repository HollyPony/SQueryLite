#ifndef CONNECTIONDIALOG_H
#define CONNECTIONDIALOG_H

#include <QDialog>

class QStandardItemModel;

namespace Ui {
class ConnectionDialog;
}

class ConnectionDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ConnectionDialog(QWidget *parent = 0);
    ~ConnectionDialog();

private slots:
    void on_toolButton_clicked();

    void on_connectionListView_activated(const QModelIndex &index);

private:
    Ui::ConnectionDialog *ui;

    QStandardItemModel *_connectionListModel;
};

#endif // CONNECTIONDIALOG_H
