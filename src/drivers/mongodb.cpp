/***
 * Informations about MongoDb connection http://docs.mongodb.org/ecosystem/tutorial/authenticate-with-cpp-driver/
 ***/

#include "mongodb.h"

#include "genericdatabase.h"

#include "mongo/client/dbclient.h"

#include <QtCore/QList>
#include <QtCore/QDebug>

MongoDb::MongoDb(QObject *parent) : GenericServer(0, parent)
{
}

QString MongoDb::toConnectionString()
{
    QString connectionString = "mongodb://";
    if (_user != "") {
        connectionString += user();
        if (_pass != "") {
            connectionString += ":" + pass();
        }
        connectionString += "@";
    }
    connectionString += host();
    if (_port > 0) {
        connectionString += ":" + QString::number(_port);
    }
    return connectionString;
}

bool MongoDb::connect()
{
    bool canConnect = false;

    std::string errMsg;
    try {
        mongo::ConnectionString cs = mongo::ConnectionString::parse(toConnectionString().toStdString(), errMsg);
        if (cs.isValid()) {
            _currentConnection = cs.connect(errMsg);
            if (_currentConnection) {
                canConnect = true;
            }
        } else {
            qDebug() << "error parsing url: " << QString::fromStdString(errMsg);
        }
    } catch (const mongo::DBException &e) {
        qDebug() << "couldn't connect: " << QString::fromStdString(errMsg);
    }

    return canConnect;
}

QList<GenericDatabase *> MongoDb::databases()
{
    QList<GenericDatabase *> databases;
    if (_currentConnection) {
        try {
            std::string errMsg;
            mongo::ConnectionString cs = mongo::ConnectionString::parse(toConnectionString().toStdString(), errMsg);
            if (cs.isValid()) {
                _currentConnection = cs.connect(errMsg);
                std::list<std::string> mongo_databases = _currentConnection->getDatabaseNames();

                int size = (int)mongo_databases.size();
                for(int i = 0; i < size ; i++) {
                    std::string str = mongo_databases.back();
                    GenericDatabase *database = new GenericDatabase(this, this);
                    database->name(QString::fromStdString(str));
                    databases.append(database);
                    mongo_databases.pop_back();
                }
            }
        } catch (const mongo::DBException &e) {
            std::cout << "caught " << e.what() << std::endl;
        }
    }

    return databases;
}
