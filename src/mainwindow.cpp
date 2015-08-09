#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "propertiesdialog.h"
#include "basedblistmodel.h"

#include <QtCore/QDebug>

#include "drivers/genericserver.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    _baseDbListModel = new BaseDbListModel(this);

    ui->treeView->setModel(_baseDbListModel);
    ui->listView->setModel(_baseDbListModel);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionConnect_triggered()
{
    GenericServer *genericDb = 0;
    QDialog *connectionDialog = new PropertiesDialog(&genericDb, this);
    connectionDialog->exec();
    if (genericDb != 0) {
        _baseDbListModel->addDbItem(genericDb);
    } else {
    }
}
