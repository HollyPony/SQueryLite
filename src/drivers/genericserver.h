#ifndef GENERICDB_H
#define GENERICDB_H

#include "genericdbitem.h"

class GenericDatabase;

class GenericServer : public GenericDbItem
{
    Q_OBJECT

public:
    explicit GenericServer(GenericDbItem *parentItem, QObject *parent = 0)
        : GenericDbItem(parentItem, parent) {}

    // To OVERRIDE
    virtual QString                  toConnectionString() = 0;
    virtual bool                     connect() = 0;
    virtual QList<GenericDatabase *> databases() =0;

    // Shared infos
    virtual QString host() const { return _host; }
    virtual void    host(const QString &value) { _host = value; }

    virtual quint16 port() const { return _port; }
    virtual void    port(const quint16 &value) { _port = value; }

    virtual QString user() const { return _user; }
    virtual void    user(const QString &value) { _user = value; }

    virtual QString pass() const { return _pass; }
    virtual void    pass(const QString &value) { _pass = value; }

protected:
    QString _host = "";
    quint16 _port = 0;
    QString _user = "";
    QString _pass = "";

};

#endif // GENERICDB_H
