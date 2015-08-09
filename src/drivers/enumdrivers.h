#ifndef ENUMDRIVERS_H
#define ENUMDRIVERS_H

#include <QtCore/QString>

class Driver {

public:
    Driver(QString name) : _index(indexCounter++), _name(name) {}

    virtual int     index() const { return _index; }
    virtual QString name() const { return _name; }

private:
    const int _index;
    const QString _name;

    static int indexCounter;
};

int Driver::indexCounter = 0;

const Driver MONGODB = Driver("MongoDb");
const Driver MYSQL = Driver("MySql");
const Driver MSSQL = Driver("MSSql");
const Driver PGSQL = Driver("PostgreSql");

#endif // ENUMDRIVERS_H
