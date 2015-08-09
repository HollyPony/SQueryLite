#include "genericdbitem.h"

GenericDbItem::GenericDbItem(GenericDbItem *parentItem, QObject *parent) : QObject(parent)
{
    _parentItem = parentItem;
}

QString GenericDbItem::name() const
{
    return _name;
}

void GenericDbItem::name(const QString value)
{
    _name = value;
}

int GenericDbItem::childCount() const
{
    return _childs.count();
}

void GenericDbItem::appendChild(GenericDbItem *genericItem)
{
    _childs.append(genericItem);
}

GenericDbItem *GenericDbItem::parentItem()
{
    return _parentItem;
}

GenericDbItem *GenericDbItem::childs(int row)
{
    return (_childs.count() > row) ? _childs.at(row) : 0;
}
