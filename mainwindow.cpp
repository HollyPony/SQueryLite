#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "connectiondialog.h"

#include "mongo/client/dbclient.h"

#include <iostream>
#include <qlogging.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    mongo::client::initialize();
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

void MainWindow::on_actionQuick_connection_triggered()
{
    try {
        mongo::DBClientConnection *client = new mongo::DBClientConnection;
        client->connect("localhost");

        std::list<std::string> mongo_databases = client->getDatabaseNames();

        int size = (int)mongo_databases.size();
        for(int i = 0; i < size ; i++)
        {
            std::string str = mongo_databases.back();
            QString tmp = tmp.fromStdString(str);

            std::cout << str << std::endl;

            mongo_databases.pop_back();
        }

        delete client;
    } catch( const mongo::DBException &e ) {
        std::cout << "caught " << e.what() << std::endl;
    }
}
