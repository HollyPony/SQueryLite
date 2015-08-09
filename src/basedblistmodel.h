#ifndef BASEDBLISTMODEL_H
#define BASEDBLISTMODEL_H

#include <QtCore/QAbstractItemModel>

class GenericDbItem;

class BaseDbListModel : public QAbstractItemModel
{
    Q_OBJECT
public:
    explicit BaseDbListModel(QObject *parent = 0);

    virtual void addDbItem(GenericDbItem *genericItem);

    virtual QVariant headerData(int section, Qt::Orientation orientation,
                                int role = Qt::DisplayRole) const Q_DECL_OVERRIDE;
    virtual QVariant data(const QModelIndex &index, int role) const Q_DECL_OVERRIDE;
    virtual QModelIndex index(int row, int column, const QModelIndex &parent) const Q_DECL_OVERRIDE;
    virtual int rowCount(const QModelIndex &parent) const Q_DECL_OVERRIDE;
    virtual int columnCount(const QModelIndex &parent) const Q_DECL_OVERRIDE;

    virtual QModelIndex parent(const QModelIndex &index) const Q_DECL_OVERRIDE;

private:
    GenericDbItem *_rootItem;
};

#endif // BASEDBLISTMODEL_H
