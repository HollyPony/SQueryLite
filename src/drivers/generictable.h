#ifndef GENERICTABLE_H
#define GENERICTABLE_H

#include "genericdbitem.h"

class GenericTable : public GenericDbItem
{
    Q_OBJECT

public:
    explicit GenericTable(GenericDbItem *parentItem, QObject *parent = 0)
        : GenericDbItem(parentItem, parent) {}
};

#endif // GENERICTABLE_H
