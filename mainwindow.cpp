#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "connectiondialog.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionConnect_triggered()
{
    QDialog *connectionDialog = new ConnectionDialog(this);
    connectionDialog->show();
}
