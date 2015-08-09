#ifndef GENERICDBITEM_H
#define GENERICDBITEM_H

#include <QObject>

class GenericDbItem : public QObject
{
    Q_OBJECT
public:
    explicit GenericDbItem(GenericDbItem *parentItem, QObject *parent = 0);

    virtual QString name() const;
    virtual void name(const QString name);

    virtual int  childCount() const;
    virtual void appendChild(GenericDbItem *genericItem);

    virtual GenericDbItem *parentItem();
    virtual GenericDbItem *childs(int row);

protected:
    GenericDbItem *_parentItem;
    QString        _name;

private:
    QList<GenericDbItem *> _childs;
};

#endif // GENERICDBITEM_H
