#include "connectiondialog.h"
#include "ui_connectiondialog.h"

#include <QStandardItemModel>

ConnectionDialog::ConnectionDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ConnectionDialog)
{
    ui->setupUi(this);

    _connectionListModel = new QStandardItemModel(ui->connectionListView);
    ui->connectionListView->setModel(_connectionListModel);
}

ConnectionDialog::~ConnectionDialog()
{
    delete ui;
}

void ConnectionDialog::on_toolButton_clicked()
{
    QStandardItem *item = new QStandardItem("Nouvelle connection");
    _connectionListModel->appendRow(item);
    QModelIndex idx = _connectionListModel->indexFromItem(item);
    ui->connectionListView->setCurrentIndex(idx);
}

void ConnectionDialog::on_connectionListView_activated(const QModelIndex &index)
{

}
