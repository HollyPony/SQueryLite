#include "basedblistmodel.h"

#include "drivers/genericdbitem.h"

BaseDbListModel::BaseDbListModel(QObject *parent) : QAbstractItemModel(parent)
{
    _rootItem = new GenericDbItem(0, this);
}

void BaseDbListModel::addDbItem(GenericDbItem *genericItem)
{
    beginInsertRows(QModelIndex(), 0, _rootItem->childCount() + 1);
    _rootItem->appendChild(genericItem);
    endInsertRows();
}

QVariant BaseDbListModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole)
    switch (section) {
    case 0:
        return "1";
    case 1:
        return "2";
    }

    return QVariant();
}

QVariant BaseDbListModel::data(const QModelIndex &index, int role) const
{
    int row = index.row();

    switch (role) {
    case Qt::DisplayRole:
        return _rootItem->childs(row)->name();
    default:
        return QVariant();
    }
}

QModelIndex BaseDbListModel::index(int row, int column, const QModelIndex &parent) const
{
    if (!hasIndex(row, column, parent))
        return QModelIndex();

    GenericDbItem *parentItem = (!parent.isValid()) ? _rootItem : static_cast<GenericDbItem *>(parent.internalPointer());
    GenericDbItem *childItem = parentItem->childs(row);

    return (childItem) ? createIndex(row, column, childItem) : QModelIndex();
}

int BaseDbListModel::rowCount(const QModelIndex &parent) const
{
    return _rootItem->childCount();
}

int BaseDbListModel::columnCount(const QModelIndex &parent) const
{
    return 1;
}

QModelIndex BaseDbListModel::parent(const QModelIndex &index) const
{

//    if (!index)
        return QModelIndex();

}
