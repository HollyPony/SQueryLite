#ifndef GENERICDATABASE_H
#define GENERICDATABASE_H

#include "genericdbitem.h"

#include <QObject>

class GenericDatabase : public GenericDbItem
{
    Q_OBJECT

public:
    explicit GenericDatabase(GenericDbItem *parentItem, QObject *parent = 0)
        : GenericDbItem(parentItem, parent) {}

};

#endif // GENERICDATABASE_H
