#ifndef MONGODB_H
#define MONGODB_H

#include "genericserver.h"

#include <QObject>

namespace mongo {
class DBClientBase;
}

class MongoDb : public GenericServer
{
    Q_OBJECT

public:
    MongoDb(QObject *parent = 0);

    virtual QString                  toConnectionString();
    virtual bool                     connect();
    virtual QList<GenericDatabase *> databases();

protected:
    mongo::DBClientBase *_currentConnection = 0;
};

#endif // MONGODB_H
