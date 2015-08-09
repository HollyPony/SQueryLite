#ifndef GENERICCOLUMN_H
#define GENERICCOLUMN_H

#include "genericdbitem.h"

class GenericColumn : public GenericDbItem
{
    Q_OBJECT

public:
    explicit GenericColumn(GenericDbItem *parentItem, QObject *parent = 0)
        : GenericDbItem(parentItem, parent) {}
};

#endif // GENERICCOLUMN_H
